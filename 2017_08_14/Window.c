#include <windows.h>
#include <stdio.h>

#include "Window.h"

#define MSG(m) {\
	MessageBoxA(NULL,m,NULL,MB_OK);}

//ウィンドウ横幅
#define WIDTH 480
#define HEIGHT 500

double c_prsp; // InitSettings::PRESENTATION_SPEED
int c_nuam; // InitSettings::NUM_AMOUNT
int* c_numbers; // NumGenerator::numbers
int c_flag = 0; // 回答と画像表示を同期

//ウィンドウハンドル
HWND hwnd;
//インスタンスハンドル
HINSTANCE hinst;

//コンソールウィンドウのハンドルを取得
HWND GetConsoleHwnd(void)
{
#define MY_BUFSIZE 1024 // コンソール ウィンドウのタイトル用のバッファサイズ
	HWND hwndFound;         // 呼び出し側へ返される値
	char pszNewWindowTitle[MY_BUFSIZE];
	// 作成されるウィンドウのタイトルが入ります
	char pszOldWindowTitle[MY_BUFSIZE]; // 元のウィンドウタイトルが入ります

	// 現在のウィンドウタイトルを取得します

	GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);

	// 独自に、ウィンドウの新規タイトルをフォーマットします

	wsprintf(pszNewWindowTitle, "%d/%d",
		GetTickCount(),
		GetCurrentProcessId());

	// 現在のウィンドウタイトルを変更します

	SetConsoleTitle(pszNewWindowTitle);

	// ウィンドウタイトルのアップデートを確実なものにさせます

	Sleep(40);

	// ウィンドウの新規タイトルを探しにいきます

	hwndFound = FindWindow(NULL, pszNewWindowTitle);

	// 元のウィンドウタイトルへ戻します

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

	//左上が(10,10）、右下が（200,200)の領域を指定
	rect.left=10;
	rect.top=10;
	rect.right=200;
	rect.bottom=200;
		

	switch(msg){
		case WM_CREATE:
			while (c_flag == 0) { ; } // 回答と画像表示を同期
			c_flag = 0;
			SetTimer(hwnd, 1, c_prsp * 1000 , NULL);
			ShowWindow(hwnd, SW_HIDE);
			ShowWindow(hwnd, SW_SHOWNOACTIVATE);
			return 0;

		case WM_DESTROY:
			//PostQuitMessage(0);
			return 0;

		case WM_TIMER:
			while (c_flag == 0) { ; } // 回答と画像表示を同期
			c_flag = 0;
			InvalidateRect(hwnd, NULL, TRUE);
			//DestroyWindow(hwnd);
			return 0;

		case WM_PAINT:
			hdc=BeginPaint(hwnd,&ps);

			//ブラシを設定（四角形の色塗り）
			brush = CreateSolidBrush(RGB(0, 0, 0));
			SelectObject(hdc, brush);
			
			//四角形を描画
			for (i = 0; i < c_nuam; i++) {
				Rectangle(hdc, c_numbers[i]/3*150+10, c_numbers[i]%3*150+10, c_numbers[i] / 3 * 150 + 150, c_numbers[i] % 3 * 150 + 150);
			}

			EndPaint(hwnd,&ps);

			//ブラシを破棄
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
		MSG("クラスの登録失敗");
		return -1;
	}

	hwnd=CreateWindowA("test","テストウィンドウ",WS_VISIBLE,
		0,0,WIDTH,HEIGHT,NULL,NULL,hInstance,NULL);


	if(hwnd==NULL){
		MSG("ウィンドウ作成失敗");
		return -1;
	}

	//インスタンスハンドル
	hinst=hInstance;

	//エラーチェック用変数
	int check;

	while(check=GetMessage(&msg,NULL,0,0)){
		if(check==-1){
			break;
		}
		DispatchMessage(&msg);
	}

	//クラス解放
	UnregisterClass("test",hinst);

	return 0;

}