#ifndef WINDOW_H
#define WINDOW_H

#include<windows.h>

//�R���\�[���E�B���h�E�̃n���h����ύX�A��
HWND GetConsoleHwnd(void);

LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

int WINAPI openWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);

#endif