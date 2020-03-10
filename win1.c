#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
extern HINSTANCE hInstt;
extern HINSTANCE hPrev;
extern PSTR szCmd;
extern int iCmd;
extern struct stu{

    int number;
    char name[50];
    char sex;
    double score[3];
    double sum;
    struct stu *next;

};
extern HINSTANCE ioioi;
///
HINSTANCE hInst;
///
LRESULT CALLBACK WndProc1(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain1(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR szCmdLine,
    int iCmdShow
){
    static TCHAR szClassName[] = TEXT("HelloWin");  //窗口类名
    HWND     hwnd;  //窗口句柄
    MSG      msg;  //消息
    WNDCLASS wndclass;  //窗口类


    /**********第①步：注册窗口类**********/
    //为窗口类的各个字段赋值
    wndclass.style = CS_HREDRAW | CS_VREDRAW;  //窗口风格
    wndclass.lpfnWndProc  = WndProc1;  //窗口过程
    wndclass.cbClsExtra   = 0;  //暂时不需要理解
    wndclass.cbWndExtra   = 0;  //暂时不需要理解
    wndclass.hInstance    = hInstance;  //当前窗口句柄
    wndclass.hIcon        = LoadIcon (NULL, IDI_APPLICATION);  //窗口图标
    wndclass.hCursor      = LoadCursor (NULL, IDC_ARROW);  //鼠标样式
    wndclass.hbrBackground= (HBRUSH) GetStockObject (WHITE_BRUSH);  //窗口背景画刷
    wndclass.lpszMenuName = NULL ;  //窗口菜单
    wndclass.lpszClassName= szClassName;  //窗口类名

    //注册窗口
    RegisterClass(&wndclass);

    /*****第②步：创建窗口(并让窗口显示出来)*****/
    hwnd = CreateWindow(
        szClassName,  //窗口类的名字
        TEXT("学生成绩管理系统1"),  //窗口标题（出现在标题栏）
        WS_OVERLAPPEDWINDOW,  //窗口风格
        CW_USEDEFAULT,  //初始化时x轴的位置
        CW_USEDEFAULT,  //初始化时y轴的位置
        GetSystemMetrics(SM_CXSCREEN),  //窗口宽度
        GetSystemMetrics(SM_CYSCREEN),  //窗口高度
        NULL,  //父窗口句柄
        NULL,  //窗口菜单句柄
        hInstance,  //当前窗口的句柄
        NULL  //不使用该值
    );

    //显示窗口
    ShowWindow (hwnd, iCmdShow);
    //更新（绘制）窗口
    UpdateWindow (hwnd);

    /**********第③步：消息循环**********/
    while( GetMessage(&msg, NULL, 0, 0) ){
        TranslateMessage(&msg);  //翻译消息
        DispatchMessage (&msg);  //分派消息
    }



    return msg.wParam;
}

/**********第④步：窗口过程**********/
LRESULT CALLBACK WndProc1(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC         hdc;  //设备环境句柄
    PAINTSTRUCT ps;
    RECT        rect;
    HWND        hStatic;
    HDC hdcWnd;
    HDC hdcStatic;
    static HFONT hFont1,hFont2;
    static HWND hBtn1,hBtn2,hBtn3;
    static HBRUSH hBrush1,hBrush2;  //画刷
    int wmId, wmEvent;
    int xinjianfou =0;



    switch (message){

        case  WM_CREATE:
            //创建画刷
            hBrush1 = CreateSolidBrush( RGB(255, 255, 255) );

            //创建逻辑字体
            hFont1 = CreateFont(
                -20/*高度*/, -10/*宽度*/, 0, 0, 900 /*一般这个值设为400*/,
                FALSE/*不带斜体*/, FALSE/*不带下划线*/, FALSE/*不带删除线*/,
                DEFAULT_CHARSET,  //使用默认字符集
                OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,  //这行参数不用管
                DEFAULT_QUALITY,  //默认输出质量
                FF_DONTCARE,  //不指定字体族*/
                TEXT("黑体")  //字体名
            );
            hFont2 = CreateFont(
                -45/*高度*/, -22.5/*宽度*/, 0, 0, 400 /*一般这个值设为400*/,
                FALSE/*不带斜体*/, FALSE/*不带下划线*/, FALSE/*不带删除线*/,
                DEFAULT_CHARSET,  //使用默认字符集
                OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,  //这行参数不用管
                DEFAULT_QUALITY,  //默认输出质量
                FF_DONTCARE,  //不指定字体族*/
                TEXT("黑体")  //字体名
            );
            //左侧文本框
            hStatic = CreateWindow(
                TEXT("static"), //静态文本框的类名
                TEXT("\n\n\n学生成绩管理系统\n\n     2018级5班段源川"),  //控件的文本
                WS_CHILD /*子窗口*/ | WS_VISIBLE /*创建时显示*/ | SS_CENTER /*水平居中*/ ,
                GetSystemMetrics(SM_CXSCREEN)*10/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*20/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*30/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*40/100 /*高度*/,
                hwnd,  //父窗口句柄
                (HMENU)4,  //为控件指定一个唯一标识符
                hInst,  //当前程序实例句柄
                NULL
            );
             //创建按钮1控件
             hBtn1 = CreateWindow(
                TEXT("button"), //按钮控件的类名
                TEXT("新建"),
                WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                GetSystemMetrics(SM_CXSCREEN)*60/100 /*X坐标*/, GetSystemMetrics(SM_CYSCREEN)*10/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*15/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*10/100/*高度*/,
                hwnd, (HMENU)1 /*控件唯一标识符*/, hInst, NULL
            );
             hBtn2 = CreateWindow(
                TEXT("button"), //按钮控件的类名
                TEXT("打开"),
                WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                GetSystemMetrics(SM_CXSCREEN)*60/100  /*X坐标*/, GetSystemMetrics(SM_CYSCREEN)*40/100/*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*15/100  /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*10/100/*高度*/,
                hwnd, (HMENU)2/*控件唯一标识符*/, hInst, NULL
            );
             hBtn3= CreateWindow(
                TEXT("button"), //按钮控件的类名
                TEXT("退出"),
                WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                GetSystemMetrics(SM_CXSCREEN)*60/100  /*X坐标*/,GetSystemMetrics(SM_CYSCREEN)* 70/100/*Y坐标*/ , GetSystemMetrics(SM_CXSCREEN)*15/100  /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*10/100/*高度*/,
                hwnd, (HMENU)3 /*控件唯一标识符*/, hInst, NULL
            );


            //设置按钮字体
            SendMessage(hBtn1, WM_SETFONT, (WPARAM)hFont1, NULL);
            SendMessage(hBtn2, WM_SETFONT, (WPARAM)hFont1, NULL);
            SendMessage(hBtn3, WM_SETFONT, (WPARAM)hFont1, NULL);
            SendMessage(hStatic, WM_SETFONT, (WPARAM)hFont2, NULL);

            break;
          case WM_CTLCOLORSTATIC:
            hdcStatic = (HDC)wParam;
            SetTextColor( hdcStatic, RGB(0, 0, 139) );  //白色
            SetBkColor( hdcStatic, RGB(255, 255, 255) );  //翠绿色
            return (INT_PTR)GetStockObject(NULL_BRUSH);  //这里必须返回画刷句柄

        ///按下按钮
          case WM_COMMAND:
            wmId    = LOWORD(wParam);
            wmEvent = HIWORD(wParam);
            switch (wmId){
                case 1: //按下按钮1 xinjian
                DestroyWindow(hwnd);
                WinMain2(hInstt,hPrev,szCmd,iCmd,0);
                break;
                case 2:  //按下按钮2 dakai
                DestroyWindow(hwnd);
                WinMain2(hInstt,hPrev,szCmd,iCmd,1);
                break;
                case 3:
                DestroyWindow(hwnd);
                break;
                default:
                    //不处理的消息一定要交给 DefWindowProc 处理。
                    return DefWindowProc(hwnd, message, wParam, lParam);
            }
            break;


        //窗口销毁消息
        case WM_DESTROY:
            PostQuitMessage(0) ;

            return 0 ;
    }





    return DefWindowProc(hwnd, message, wParam, lParam) ;
}
