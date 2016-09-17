#ifndef __UTILLOG_H
#define __UTILLOG_H
#include <tchar.h>
#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)
//��ӡGUI����ĺ�̨��־
#define LOG_OPENOUT {AllocConsole();}//������̨��ӡ
#define LOG_CLOSEOUT {FreeConsole();}//�رպ�̨��ӡ
#define LOG_STOPOUT {system("pause");}//��ͣ��̨��ӡ
#define STOP_OUT
#define LOG_LINEOUTA(c)  	{HANDLE hstdWrite = GetStdHandle(STD_OUTPUT_HANDLE); WriteConsoleA(hstdWrite, c, strlen(c), NULL, NULL); WriteConsoleA(hstdWrite, "\n", 1, NULL, NULL);}
#define LOG_LINEOUTW(c)  	{ HANDLE hstdWrite = GetStdHandle(STD_OUTPUT_HANDLE);WriteConsoleW(hstdWrite, c, wcslen(c), NULL, NULL);  WriteConsoleW(hstdWrite, L"\n",1, NULL, NULL);}
#ifdef _UNICODE
#define LOG_FORMATOUT	LOG_FORMATOUTW
#define LOG_LINEOUT		LOG_LINEOUTW
#else
#define LOG_FORMATOUT	LOG_FORMATOUTA
#define LOG_LINEOUT		LOG_LINEOUTA
#endif
//��ʽ�������־
void LOG_FORMATOUTA(const char* lpszFormat, ...);
void LOG_FORMATOUTW(const wchar_t* lpszFormat, ...);
#endif

/*
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	LOG_OPENOUT;//������̨��ӡ
	LOG_FORMATOUT(_T("Age	%d\n	Left%s\n"),245,_T("���"));//��ʽ���������̨
	LOG_CLOSEOUT;//�رպ�̨��ӡ
	return 0;
}
*/