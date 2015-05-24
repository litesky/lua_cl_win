/********************************************************************
	author:		litesky@github.com
*********************************************************************/
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <assert.h>

#include <wtypes.h>
#include <wincon.h>
#include <locale.h>
#include "lua.h"
#include "lauxlib.h"
#include "mylib.h"

static int lua_lcp( lua_State* L )
{
    COORD CurPos;
    CurPos.X = luaL_checknumber( L, 2 );
    CurPos.Y = luaL_checknumber( L, 1 );
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), CurPos );
    return 0;
}

static int lua_dla( lua_State* L )
{
    int LEN;
    SMALL_RECT Rect;
    COORD Pos;
    CHAR_INFO  CharInfo;
    CONSOLE_SCREEN_BUFFER_INFO Info;

    HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    LEN = luaL_checknumber( L, 1 );
    if ( GetConsoleScreenBufferInfo( hStdOut, &Info ) == 0 ) { return 1; }

    Rect.Left   = 0;
    Rect.Top    = Info.dwCursorPosition.Y + LEN;
    Rect.Right  = Info.dwSize.X - 1;
    Rect.Bottom = Info.dwSize.Y - 1;

    Pos.X = 0;
    Pos.Y = Info.dwCursorPosition.Y;

    CharInfo.Char.AsciiChar = ' ';
    CharInfo.Attributes = Info.wAttributes;
    ScrollConsoleScreenBuffer( hStdOut, &Rect, NULL, Pos, &CharInfo );
    return 0;
}

static int lua_dlu( lua_State* L )
{
    int LEN;
    SMALL_RECT Rect;
    COORD Pos;
    CHAR_INFO  CharInfo;
    CONSOLE_SCREEN_BUFFER_INFO Info;

    HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    LEN = luaL_checknumber( L, 1 );
    if ( GetConsoleScreenBufferInfo( hStdOut, &Info ) == 0 ) { return 1; }

    Rect.Left   = 0;
    Rect.Top    = Info.dwCursorPosition.Y + LEN;
    Rect.Right  = Info.dwSize.X - 1;
    Rect.Bottom = Info.dwSize.Y - 1;

    Pos.X = 0;
    Pos.Y = Info.dwCursorPosition.Y;

    CharInfo.Char.UnicodeChar = ' ';
    CharInfo.Attributes = Info.wAttributes;
    ScrollConsoleScreenBuffer( hStdOut, &Rect, NULL, Pos, &CharInfo );
    return 0;
}

static int lua_dca( lua_State* L )
{
    int LEN;
    SMALL_RECT Rect;
    CHAR_INFO  CharInfo;
    CONSOLE_SCREEN_BUFFER_INFO Info;

    HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    LEN = luaL_checknumber( L, 1 );
    if ( GetConsoleScreenBufferInfo( hStdOut, &Info ) == 0 ) { return 1; }

    Rect.Left   = Info.dwCursorPosition.X + LEN;
    Rect.Top    = Info.dwCursorPosition.Y;
    Rect.Right  = Info.dwSize.X - 1;
    Rect.Bottom = Info.dwCursorPosition.Y;

    CharInfo.Char.AsciiChar = ' ';
    CharInfo.Attributes = Info.wAttributes;
    ScrollConsoleScreenBuffer( hStdOut, &Rect, NULL, Info.dwCursorPosition, &CharInfo );
    return 0;
}

static int lua_dcu( lua_State* L )
{
    int LEN;
    SMALL_RECT Rect;
    CHAR_INFO  CharInfo;
    CONSOLE_SCREEN_BUFFER_INFO Info;

    HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    LEN = luaL_checknumber( L, 1 );
    if ( GetConsoleScreenBufferInfo( hStdOut, &Info ) == 0 ) { return 1; }

    Rect.Left   = Info.dwCursorPosition.X + LEN;
    Rect.Top    = Info.dwCursorPosition.Y;
    Rect.Right  = Info.dwSize.X - 1;
    Rect.Bottom = Info.dwCursorPosition.Y;

    CharInfo.Char.UnicodeChar = ' ';
    CharInfo.Attributes = Info.wAttributes;
    ScrollConsoleScreenBuffer( hStdOut, &Rect, NULL, Info.dwCursorPosition, &CharInfo );
    return 0;
}

static int lua_ila( lua_State* L )
{
    int LEN;
    SMALL_RECT Rect;
    COORD Pos;
    CHAR_INFO  CharInfo;
    CONSOLE_SCREEN_BUFFER_INFO Info;

    HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    LEN = luaL_checknumber( L, 1 );
    if ( GetConsoleScreenBufferInfo( hStdOut, &Info ) == 0 ) { return 1; }

    Rect.Left   = 0;
    Rect.Top    = Info.dwCursorPosition.Y;
    Rect.Right  = Info.dwSize.X - 1;
    Rect.Bottom = Info.dwSize.Y - 1;

    Pos.X = 0;
    Pos.Y = Info.dwCursorPosition.Y + LEN;

    CharInfo.Char.AsciiChar = ' ';
    CharInfo.Attributes = Info.wAttributes;
    ScrollConsoleScreenBuffer( hStdOut, &Rect, NULL, Pos, &CharInfo );
    return 0;
}

static int lua_ilu( lua_State* L )
{
    int LEN;
    SMALL_RECT Rect;
    COORD Pos;
    CHAR_INFO  CharInfo;
    CONSOLE_SCREEN_BUFFER_INFO Info;

    HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    LEN = luaL_checknumber( L, 1 );
    if ( GetConsoleScreenBufferInfo( hStdOut, &Info ) == 0 ) { return 1; }

    Rect.Left   = 0;
    Rect.Top    = Info.dwCursorPosition.Y;
    Rect.Right  = Info.dwSize.X - 1;
    Rect.Bottom = Info.dwSize.Y - 1;

    Pos.X = 0;
    Pos.Y = Info.dwCursorPosition.Y + LEN;

    CharInfo.Char.UnicodeChar = ' ';
    CharInfo.Attributes = Info.wAttributes;
    ScrollConsoleScreenBuffer( hStdOut, &Rect, NULL, Pos, &CharInfo );
    return 0;
}

static int lua_ica( lua_State* L )
{
    int LEN;
    COORD Pos;
    SMALL_RECT Rect;
    CHAR_INFO  CharInfo;
    CONSOLE_SCREEN_BUFFER_INFO Info;

    HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    LEN = luaL_checknumber( L, 1 );
    if ( GetConsoleScreenBufferInfo( hStdOut, &Info ) == 0 ) { return 1; }

    Rect.Left   = Info.dwCursorPosition.X;
    Rect.Top    = Info.dwCursorPosition.Y;
    Rect.Right  = Info.dwSize.X - 1 - LEN;
    Rect.Bottom = Info.dwCursorPosition.Y;
    Pos.X = Info.dwCursorPosition.X + LEN;
    Pos.Y = Info.dwCursorPosition.Y;

    CharInfo.Char.AsciiChar = ' ';
    CharInfo.Attributes = Info.wAttributes;
    ScrollConsoleScreenBuffer( hStdOut, &Rect, NULL, Pos, &CharInfo );
    return 0;
}

static int lua_icu( lua_State* L )
{
    int LEN;
    COORD Pos;
    SMALL_RECT Rect;
    CHAR_INFO  CharInfo;
    CONSOLE_SCREEN_BUFFER_INFO Info;

    HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    LEN = luaL_checknumber( L, 1 );
    if ( GetConsoleScreenBufferInfo( hStdOut, &Info ) == 0 ) { return 1; }

    Rect.Left   = Info.dwCursorPosition.X;
    Rect.Top    = Info.dwCursorPosition.Y;
    Rect.Right  = Info.dwSize.X - 1 - LEN;
    Rect.Bottom = Info.dwCursorPosition.Y;
    Pos.X = Info.dwCursorPosition.X + LEN;
    Pos.Y = Info.dwCursorPosition.Y;

    CharInfo.Char.UnicodeChar = ' ';
    CharInfo.Attributes = Info.wAttributes;
    ScrollConsoleScreenBuffer( hStdOut, &Rect, NULL, Pos, &CharInfo );
    return 0;
}

static int lua_hlp( lua_State* L )
{
    puts(
        "lcp(X,Y)\tCur Ln X Col Y\n"
        "dla( N )\tDelete N Lines\n"
        "dlu( N )\tDelete N Lines\n"
        "dca( N )\tDelete N Chars\n"
        "dcu( N )\tDelete N Chars\n"
        "ila( N )\tInsert N Lines\n"
        "ilu( N )\tInsert N Lines\n"
        "ica( N )\tInsert N Chars\n"
        "icu( N )\tInsert N Chars\n"
    );
    return 0;
}
static const struct luaL_Reg cl[] =
{
    {"lcp",         lua_lcp},
    {"dla",         lua_dla},
    {"dlu",         lua_dlu},
    {"ila",         lua_ila},
    {"ilu",         lua_ilu},
    {"dca",         lua_dca},
    {"dcu",         lua_dcu},
    {"ica",         lua_ica},
    {"icu",         lua_icu},
    {"hlp",         lua_hlp},
    {NULL,      NULL}
};

MYLIB_API int luaopen_cl( lua_State* L )
{
    luaL_newlib( L, cl );
    return 1;
}
