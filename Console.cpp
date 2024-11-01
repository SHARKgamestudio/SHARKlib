#include "Console.h"

#pragma region External Dependencies

#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <cwchar>

#pragma endregion

void Console::SetFont(int size) {
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(fontInfo);
    fontInfo.nFont = 0;
    fontInfo.dwFontSize.X = 0;
    fontInfo.dwFontSize.Y = size;
    fontInfo.FontFamily = FF_DONTCARE;
    fontInfo.FontWeight = FW_NORMAL;
    std::wcscpy(fontInfo.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);
}

void Console::SetCursorVisibility(bool visible) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = visible;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void Console::SetCursorLocation(int x, int y) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { x, y };

    SetConsoleCursorPosition(out, position);
}

Vector2 Console::GetSize() {
    CONSOLE_SCREEN_BUFFER_INFO screenInfo;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screenInfo);
    columns = screenInfo.srWindow.Right - screenInfo.srWindow.Left + 1;
    rows = screenInfo.srWindow.Bottom - screenInfo.srWindow.Top + 1;

    return Vector2(columns, rows);
}