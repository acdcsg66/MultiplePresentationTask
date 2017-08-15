#include <windows.h>
#include <stdio.h>

#include "Window.h"

#define MSG(m) {\
	MessageBoxA(NULL,m,NULL,MB_OK);}

//�E�B���h�E����
#define WIDTH 480
#define HEIGHT 500

double c_prsp; // InitSettings::PRESENTATION_SPEED
int c_nuam; // InitSettings::NUM_AMOUNT
int* c_numbers; // NumGenerator::numbers
int c_flag = 0; // �񓚂Ɖ摜�\���𓯊�

//�E�B���h�E�n���h��
HWND hwnd;
//�C���X�^���X�n���h��
HINSTANCE hinst;

//�R���\�[���E�B���h�E�̃n���h�����擾
HWND GetConsoleHwnd(void)
{
#define MY_BUFSIZE 1024 // �R���\�[�� �E�B���h�E�̃^�C�g���p�̃o�b�t�@�T�C�Y
	HWND hwndFound;         // �Ăяo�����֕Ԃ����l
	char pszNewWindowTitle[MY_BUFSIZE];
	// �쐬�����E�B���h�E�̃^�C�g��������܂�
	char pszOldWindowTitle[MY_BUFSIZE]; // ���̃E�B���h�E�^�C�g��������܂�

	// ���݂̃E�B���h�E�^�C�g�����擾���܂�

	GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);

	// �Ǝ��ɁA�E�B���h�E�̐V�K�^�C�g�����t�H�[�}�b�g���܂�

	wsprintf(pszNewWindowTitle, "%d/%d",
		GetTickCount(),
		GetCurrentProcessId());

	// ���݂̃E�B���h�E�^�C�g����ύX���܂�

	SetConsoleTitle(pszNewWindowTitle);

	// �E�B���h�E�^�C�g���̃A�b�v�f�[�g���m���Ȃ��̂ɂ����܂�

	Sleep(40);

	// �E�B���h�E�̐V�K�^�C�g����T���ɂ����܂�

	hwndFound = FindWindow(NULL, pszNewWindowTitle);

	// ���̃E�B���h�E�^�C�g���֖߂��܂�

	SetConsoleTitle(pszOldWindowTitle);

	return(hwndFound);
}

LRESULT CALLBACK WinProc(HWND hwnd,UINT msg,WPARAM wp,LPARAM lp)
{
	HDC hdc;


	PAINTSTRUCT ps;

	RECT rect;

	static HBRUSH brush;

	int i;

	//���オ(10,10�j�A�E�����i200,200)�̗̈���w��
	rect.left=10;
	rect.top=10;
	rect.right=200;
	rect.bottom=200;
		

	switch(msg){
		case WM_CREATE:
			while (c_flag == 0) { ; } // �񓚂Ɖ摜�\���𓯊�
			c_flag = 0;
			SetTimer(hwnd, 1, c_prsp * 1000 , NULL);
			ShowWindow(hwnd, SW_HIDE);
			ShowWindow(hwnd, SW_SHOWNOACTIVATE);
			return 0;

		case WM_DESTROY:
			//PostQuitMessage(0);
			return 0;

		case WM_TIMER:
			while (c_flag == 0) { ; } // �񓚂Ɖ摜�\���𓯊�
			c_flag = 0;
			InvalidateRect(hwnd, NULL, TRUE);
			//DestroyWindow(hwnd);
			return 0;

		case WM_PAINT:
			hdc=BeginPaint(hwnd,&ps);

			//�u���V��ݒ�i�l�p�`�̐F�h��j
			brush = CreateSolidBrush(RGB(0, 0, 0));
			SelectObject(hdc, brush);
			
			//�l�p�`��`��
			for (i = 0; i < c_nuam; i++) {
				Rectangle(hdc, c_numbers[i]/3*150+10, c_numbers[i]%3*150+10, c_numbers[i] / 3 * 150 + 150, c_numbers[i] % 3 * 150 + 150);
			}

			EndPaint(hwnd,&ps);

			//�u���V��j��
			DeleteObject(brush);

			return 0;

		
	}
	return DefWindowProc(hwnd,msg,wp,lp);
}

int WINAPI openWindow(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
	MSG msg;
	WNDCLASS wc;

	wc.style=CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc=WinProc;
	wc.cbClsExtra=wc.cbWndExtra=0;
	wc.hInstance=hInstance;
	wc.hCursor=wc.hIcon=NULL;
	wc.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszClassName="test";
	wc.lpszMenuName=NULL;
	
	if(!RegisterClass(&wc)){
		MSG("�N���X�̓o�^���s");
		return -1;
	}

	hwnd=CreateWindowA("test","�e�X�g�E�B���h�E",WS_VISIBLE,
		0,0,WIDTH,HEIGHT,NULL,NULL,hInstance,NULL);


	if(hwnd==NULL){
		MSG("�E�B���h�E�쐬���s");
		return -1;
	}

	//�C���X�^���X�n���h��
	hinst=hInstance;

	//�G���[�`�F�b�N�p�ϐ�
	int check;

	while(check=GetMessage(&msg,NULL,0,0)){
		if(check==-1){
			break;
		}
		DispatchMessage(&msg);
	}

	//�N���X���
	UnregisterClass("test",hinst);

	return 0;

}