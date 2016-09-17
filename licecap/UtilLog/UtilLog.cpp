#include "UtilLog.h"

void LOG_FORMATOUTA(const char* lpszFormat, ...)
{
	va_list args;
	char szText[1024];
	va_start(args, lpszFormat);
	vsprintf(szText, lpszFormat, args);
	LOG_LINEOUTA(szText);
	va_end(args);
}

void LOG_FORMATOUTW(const wchar_t* lpszFormat, ...)
{
	va_list args;
	wchar_t szText[1024];
	va_start(args, lpszFormat);
	vswprintf(szText, lpszFormat, args);
	LOG_LINEOUTW(szText);
	va_end(args);
}