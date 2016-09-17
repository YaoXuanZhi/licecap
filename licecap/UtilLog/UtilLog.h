#ifndef __UTILLOG_H
#define __UTILLOG_H
#include <tchar.h>
#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)
//打印GUI程序的后台日志
#define LOG_OPENOUT {AllocConsole();}//开启后台打印
#define LOG_CLOSEOUT {FreeConsole();}//关闭后台打印
#define LOG_STOPOUT {system("pause");}//暂停后台打印
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
//格式化输出日志
void LOG_FORMATOUTA(const char* lpszFormat, ...);
void LOG_FORMATOUTW(const wchar_t* lpszFormat, ...);
#endif

/*
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	LOG_OPENOUT;//开启后台打印
	LOG_FORMATOUT(_T("Age	%d\n	Left%s\n"),245,_T("左边"));//格式化输出到后台
	LOG_CLOSEOUT;//关闭后台打印
	return 0;
}
*/