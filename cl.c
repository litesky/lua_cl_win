/********************************************************************
	author:		litesky@github.com
*********************************************************************/

#include <stdlib.h>
#include <stdio.h> 
#include <stdarg.h>
#include <assert.h>
#include <wtypes.h>
#include <wincon.h>
#include <locale.h>

#include "lua.h"
#include "lauxlib.h"
#include "mylib.h"

static int lua_DLU(lua_State *L)
{
	int LEN;
	SMALL_RECT Rect;
	COORD Pos;
	CHAR_INFO  CharInfo;
	CONSOLE_SCREEN_BUFFER_INFO Info;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	LEN = luaL_checknumber(L, 1);
	//printf("O");
	//printf("S");
    if (GetConsoleScreenBufferInfo(hStdOut, &Info)==0)
    {
	    printf("ERROR");
        return 1;
    }

	Rect.Left   = 0;
	Rect.Top    = Info.dwCursorPosition.Y + LEN;
	Rect.Right  = Info.dwSize.X - 1;
	Rect.Bottom = Info.dwSize.Y - 1;

	Pos.X = 0;
	Pos.Y = Info.dwCursorPosition.Y;

	CharInfo.Char.UnicodeChar = ' ';
	CharInfo.Attributes = Info.wAttributes;
	ScrollConsoleScreenBuffer(hStdOut, &Rect, NULL, Pos, &CharInfo );
	return 0;
}

static int lua_DLA(lua_State *L)
{
	int LEN;
	SMALL_RECT Rect;
	COORD Pos;
	CHAR_INFO  CharInfo;
	CONSOLE_SCREEN_BUFFER_INFO Info;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	LEN = luaL_checknumber(L, 1);
	//printf("O");
	//printf("S");
    if (GetConsoleScreenBufferInfo(hStdOut, &Info)==0)
    {
	    printf("ERROR");
        return 1;
    }

	Rect.Left   = 0;
	Rect.Top    = Info.dwCursorPosition.Y + LEN;
	Rect.Right  = Info.dwSize.X - 1;
	Rect.Bottom = Info.dwSize.Y - 1;

	Pos.X = 0;
	Pos.Y = Info.dwCursorPosition.Y;

	CharInfo.Char.AsciiChar = ' ';
	CharInfo.Attributes = Info.wAttributes;
	ScrollConsoleScreenBuffer(hStdOut, &Rect, NULL, Pos, &CharInfo );
	return 0;
}

static int lua_CP(lua_State *L)
{
	COORD CurPos;
	CurPos.X = luaL_checknumber(L, 2);
	CurPos.Y = luaL_checknumber(L, 1);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CurPos);
	//printf("YES");
	return 0;
}

static const struct luaL_Reg cl[] = 
{
	{"CP",			lua_CP},
	{"DLA",			lua_DLA},
	{"DLU",			lua_DLU},
	{NULL,		NULL}
};

MYLIB_API int luaopen_cl(lua_State *L)
{
	luaL_newlib(L, cl);
	return 1;
}
