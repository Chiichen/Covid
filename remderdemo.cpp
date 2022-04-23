//#include<Windows.h>
//#include<iostream>
//#include"time.h"
//typedef HWND(WINAPI* PROCGETCONSOLEWINDOW)();
//PROCGETCONSOLEWINDOW ToGetConsoleWindow;
//using namespace std;
//LPCWSTR pchartopwstr(const char* szStr)
//{
//    WCHAR wszClassName[256];
//    memset(wszClassName, 0, sizeof(wszClassName));
//    MultiByteToWideChar(CP_ACP,
//        0,
//        szStr,
//        strlen(szStr) + 1,
//        wszClassName,
//        sizeof(wszClassName) / sizeof(wszClassName[0]));
//    return wszClassName;
//}
//
//bool RenderCharToBuffer(int x, int y, HDC BufferDC, HFONT font, wstring str, int size)
//{
//    //HWND hWnd = GetConsoleWindow();
//    //HDC hdc = GetDC(hWnd);
//    auto tempfont = font;
//    SelectObject(BufferDC, tempfont);
//    SetBkColor(BufferDC, 0x000000);
//    SetTextColor(BufferDC, RGB(100, 149, 237));
//    LPCWSTR str2 = str.c_str();
//    TextOut(BufferDC, x, y, str2, size);
//    DeleteObject(tempfont);
//    //ValidateRect(hWnd, 0);
//
//    return 1;
//}
//
//void RendrFromDC(HDC OutDC, HDC BufferDC, int width, int height, HBITMAP Hbmp)//BufferDC必须有一个画布Hbmp,作为参数传入防止忘记析构
//{
//
//    BitBlt(OutDC, 0, 0, width, height, BufferDC, 0, 0, SRCCOPY);
//    DeleteObject(Hbmp);
//}
//
//
//HDC NtkGetDC()
//{
//    TCHAR title[256];
//    HDC hdc = NULL;
//
//    GetConsoleTitle(title, 256);
//    hdc = GetDC(FindWindow(0, title));
//    return hdc;
//}
//
//void NtkLoadImage(HBITMAP* pImg, const char* filename, int width, int height)
//{
//    *pImg = (HBITMAP)LoadImage(NULL, (LPCWSTR)filename, IMAGE_BITMAP, width, height, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_CREATEDIBSECTION);
//}
//
////int main()
////{
////        TCHAR title[256];
////        HDC hdc, hdcMem;
////        HBITMAP img, hOldBmp;
////        HWND console = GetConsoleWindow();
////        hdc = GetDC(console);
////        hdcMem = CreateCompatibleDC(hdc);
////        img = (HBITMAP)LoadImage(NULL, L"image.bmp", IMAGE_BITMAP, 226, 229, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_CREATEDIBSECTION);
////        hOldBmp = (HBITMAP)SelectObject(hdcMem, img);
////        StretchBlt(hdc, 12, 13, 100, 300, hdcMem, 0, 0, 226, 229, SRCCOPY);
////        SelectObject(hdcMem, hOldBmp);
////        DeleteDC(hdcMem)
////        return 0;
////}
//
//bool ShowCube(int x, int y, int width, int height, int chwidth, int chheight)
//{
//    HANDLE output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    HWND hWnd = GetConsoleWindow();
//    HDC hdc = GetDC(hWnd);
//
//
//    HFONT font = CreateFont(
//        chheight, // nHeight
//        chwidth, // nWidth
//        0, // nEscapement
//        0, // nOrientation
//        FW_BOLD, // nWeight
//        TRUE, // bItalic
//        TRUE, // bUnderline
//        0, // cStrikeOut
//        ANSI_CHARSET, // nCharSet
//        OUT_DEFAULT_PRECIS, // nOutPrecision
//        CLIP_DEFAULT_PRECIS, // nClipPrecision
//        DEFAULT_QUALITY, // nQuality
//        DEFAULT_PITCH | FF_SWISS,
//        L"Arial" // nPitchAndFamily Arial
//    );
//    SelectObject(hdc, font);
//
//    SetBkColor(hdc, TRANSPARENT);
//    SetTextColor(hdc, RGB(100, 149, 237));
//    TextOut(hdc, x, y, L"■", 1);
//
//    ValidateRect(hWnd, 0);
//
//    return 1;
//}
//
//int main() {
//    clock_t start, end;
//    start = clock();
//    HWND hWnd = GetConsoleWindow();
//    HDC hdc = GetDC(hWnd);
//
//    for (int j = 0; j < 100; j++)
//    {
//        HDC MemDC = CreateCompatibleDC(hdc);
//        HFONT font = CreateFont(
//            60, // nHeight
//            0, // nWidth
//            0, // nEscapement
//            0, // nOrientation
//            FW_BOLD, // nWeight
//            TRUE, // bItalic
//            FALSE, // bUnderline
//            0, // cStrikeOut
//            ANSI_CHARSET, // nCharSet
//            OUT_DEFAULT_PRECIS, // nOutPrecision
//            CLIP_DEFAULT_PRECIS, // nClipPrecision
//            DEFAULT_QUALITY, // nQuality
//            DEFAULT_PITCH | FF_SWISS,
//            L"(普通文本)"// nPitchAndFamily Arial
//        );
//
//        HFONT font2 = CreateFont(
//            100, // nHeight
//            0, // nWidth
//            0, // nEscapement
//            0, // nOrientation
//            FW_BOLD, // nWeight
//            TRUE, // bItalic
//            FALSE, // bUnderline
//            0, // cStrikeOut
//            ANSI_CHARSET, // nCharSet
//            OUT_DEFAULT_PRECIS, // nOutPrecision
//            CLIP_DEFAULT_PRECIS, // nClipPrecision
//            DEFAULT_QUALITY, // nQuality
//            DEFAULT_PITCH | FF_SWISS,
//            L"Arial" // nPitchAndFamily Arial
//        );
//        //auto hbmp = CreateCompatibleBitmap(MemDC, 3000, 3000);
//        // SelectObject(MemDC, font);
//        //SelectObject(MemDC, tempbmp);
//        //SetBkColor(MemDC, RGB(230, 122, 38));
//        //SetTextColor(MemDC, RGB(225,25,21));
//        //for (int i = 0; i < 100; i++)
//        //{
//        //    RenderCharToBuffer(50+(i%10)*600, 100+(i/10)*600, MemDC, font, L"   ", 4);
//        //}
//        //Sleep(10);
//        //RendrFromDC(hdc, MemDC, 3000, 3000, tempbmp);
//        //Sleep(10);
//        //auto hbmp = CreateCompatibleBitmap(hdc, 3000, 3000);
//        //auto oldhbmp = SelectObject(MemDC, hbmp);
//        //auto oldfont = SelectObject(MemDC, font);
//        //SetBkColor(MemDC, RGB(0 + 10 * j, 0 + 10 * j, 0 + 10 * j));
//        //SetTextColor(MemDC, RGB(100+10*j , 255-10*j , 255-10*j ));
//        //for (int i = 0; i < 100; i++)
//        //{
//        //    TextOut(MemDC, 30 + (i % 10) * 100+j*100, 60 + (i / 10) * 100, L" 123 ", 4);
//        //}
//        //BitBlt(hdc, 0, 0, 3000, 3000, MemDC, 0, 0, SRCCOPY | CAPTUREBLT);
//        //DeleteObject(hbmp);
//        //SelectObject(MemDC, oldhbmp);
//        //DeleteObject(font);
//        //SelectObject(MemDC, oldfont);
//        //DeleteDC(MemDC);
//        //Sleep(500);
//        auto hbmp = CreateCompatibleBitmap(hdc, 3000, 3000);
//        auto oldhbmp = SelectObject(MemDC, hbmp);
//        auto oldfont = SelectObject(MemDC, font);
//        SetBkColor(MemDC, RGB(0 + j, 0 + j, 0 + j));
//        SetTextColor(MemDC, RGB(100 + j, 255 - j, 255 - j));
//        for (int i = 0; i < 100; i++)
//        {
//            TextOut(MemDC, 30 + (i % 10) * 200, 60 + (i / 10) * 200, L"  ", 2);
//        }
//        BitBlt(hdc, 0, 0, 3000, 3000, MemDC, 0, 0, SRCCOPY | CAPTUREBLT);
//        //DeleteObject(hbmp);
//        //SelectObject(MemDC, oldhbmp);
//        //DeleteObject(font);
//        //SelectObject(MemDC, oldfont);
//        //DeleteDC(MemDC);
//        Sleep(100);
//
//
//
//    }
//
//
//
//    //ValidateRect(hWnd, 0);
//    end = clock();
//    cout << "运行时间" << (double)(end - start) / CLOCKS_PER_SEC;
//    return 0;
//}
////int main() {
////    HWND hWnd = GetConsoleWindow();
////    HFONT font = CreateFont(
////        20, // nHeight
////        0, // nWidth
////        0, // nEscapement
////        0, // nOrientation
////        FW_NORMAL, // nWeight
////        FALSE, // bItalic
////        FALSE, // bUnderline
////        0, // cStrikeOut
////        ANSI_CHARSET, // nCharSet
////        OUT_DEFAULT_PRECIS, // nOutPrecision
////        CLIP_DEFAULT_PRECIS, // nClipPrecision
////        DEFAULT_QUALITY, // nQuality
////        DEFAULT_PITCH | FF_SWISS,
////        L"新宋体" // nPitchAndFamily Arial
////    );
////
////
////
////    HWND b1 = CreateWindow(
////        L"BUTTON",   // predefined class
////        L"确定",       // button text
////        WS_VISIBLE | WS_CHILD,  //values for buttons.
////        100,         // starting x position
////        100,         // starting y position
////        100,        // button width
////        40,        // button height
////        hWnd,       // parent window
////        0,       // No menu
////        (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
////        NULL);
////
////    HWND b2 = CreateWindow(
////        L"BUTTON",   // predefined class
////        L"取消",       // button text
////        WS_VISIBLE | WS_CHILD,  //values for buttons.
////        240,         // starting x position
////        100,         // starting y position
////        100,        // button width
////        40,        // button height
////        hWnd,       // parent window
////        0,       // No menu
////        (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
////        NULL);
////
////    SendMessage(b1, WM_SETFONT, (WPARAM)font, 1);
////    SendMessage(b2, WM_SETFONT, (WPARAM)font, 1);
////
////
////    MSG msg;
////    while (GetMessage(&msg, 0, 0, 0)) {
////
////        TranslateMessage(&msg);
////        DispatchMessage(&msg);
////
////        if (msg.hwnd == b1 && msg.message == WM_LBUTTONDOWN) {
////            MessageBox(hWnd, L"点击了确定按钮", L"Hello", MB_ICONINFORMATION);
////        }
////
////        if (msg.hwnd == b2 && msg.message == WM_LBUTTONDOWN) {
////            MessageBox(hWnd, L"点击了取消按钮", L"Hello", MB_ICONINFORMATION);
////        }
////    }
////}