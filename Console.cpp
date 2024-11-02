#include "Console.h"

#pragma region External Dependencies

#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <cwchar>

#pragma endregion

namespace Graphics {
    namespace Console {

        void SetWindowMode(WindowMode mode) {
            if(mode != Normal) { system("mode con COLS=700"); }
            if(mode == Fullscreen) { ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); }
            else { ShowWindow(GetConsoleWindow(), mode); }
        }

        void SetFont(int size) {
            SetFont(0, size);
        }
        void SetFont(Vector2 size) {
            SetFont(size.x, size.y);
        }
        void SetFont(int width, int height) {
            CONSOLE_FONT_INFOEX fontInfo;
            fontInfo.cbSize = sizeof(fontInfo);
            fontInfo.nFont = 0;
            fontInfo.dwFontSize.X = width;
            fontInfo.dwFontSize.Y = height;
            fontInfo.FontFamily = FF_DONTCARE;
            fontInfo.FontWeight = FW_NORMAL;
            std::wcscpy(fontInfo.FaceName, L"Consolas");
            SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);
        }

        void SetCursorVisibility(bool visible) {
            HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

            CONSOLE_CURSOR_INFO cursorInfo;

            GetConsoleCursorInfo(out, &cursorInfo);
            cursorInfo.bVisible = visible;
            SetConsoleCursorInfo(out, &cursorInfo);
        }

        void SetCursorLocation(int x, int y) {
            HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD position = { (short)x, (short)y };

            SetConsoleCursorPosition(out, position);
        }
        void SetCursorLocation(Vector2 location) {
            SetCursorLocation(location.x, location.y);
        }

        Vector2 GetSize() {
            CONSOLE_SCREEN_BUFFER_INFO screenInfo;
            int columns, rows;

            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screenInfo);
            columns = screenInfo.srWindow.Right - screenInfo.srWindow.Left + 1;
            rows = screenInfo.srWindow.Bottom - screenInfo.srWindow.Top + 1;

            return Vector2(columns, rows);
        }
    }
}