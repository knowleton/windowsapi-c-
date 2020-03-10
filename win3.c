#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
extern struct stu
{

    int number;
    char name[50];
    char sex;
    double score[3];
    double sum;
    struct stu *next;

};

///
HINSTANCE hInst;
///
extern HINSTANCE hInstt;
extern HINSTANCE hPrev;
extern PSTR szCmd;
extern int iCmd;
LRESULT CALLBACK WndProc3(HWND, UINT, WPARAM, LPARAM);
char *FileNames;
int WINAPI WinMain3(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR szCmdLine,
    int iCmdShow,
    char FileName[]
)
{
    static TCHAR szClassName[] = TEXT("HelloWin3");  //窗口类名
    HWND     hwnd;  //窗口句柄
    MSG      msg;  //消息
    WNDCLASS wndclass;  //窗口类

    ///

    FileNames=FileName;

    ///
    /**********第①步：注册窗口类**********/
    //为窗口类的各个字段赋值
    wndclass.style = CS_HREDRAW | CS_VREDRAW;  //窗口风格
    wndclass.lpfnWndProc  = WndProc3;  //窗口过程
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
               TEXT("学生成绩管理系统3"),  //窗口标题（出现在标题栏）
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
    while( GetMessage(&msg, NULL, 0, 0) )
    {
        TranslateMessage(&msg);  //翻译消息
        DispatchMessage (&msg);  //分派消息
    }

    return msg.wParam;
}


char outter[10000];
char getter[10000];
/**********第④步：窗口过程**********/
LRESULT CALLBACK WndProc3(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static TCHAR szBuf11[10];  //保存升降
    static TCHAR szBuf22[10];  //保存方式
    int wmId, wmEvent;
    HDC         hdc;  //设备环境句柄
    PAINTSTRUCT ps;
    RECT        rect;
    HDC hdcWnd;
    HDC hdcStatic;
    HWND         hStatic1,hStatic2,hStatic3,hStatic4,hStatic5,hStatic6,hStatic7;
    static HWND hStatic0,hEdit1,hEdit2,hEdit3,hEdit4,hEdit5,hEdit6,hEdit7 ;
    static HWND hBtn1,hBtn2,hBtn3,hBtn4,hBtn5,hBtn6;//按钮

    static HWND upper;  //单选按钮--降序
    static HWND lower;  //单选按钮-- 升序

    static HWND numberer;//单选按钮--学号
    static HWND namer;//单选按钮--名称
    static HWND summer;//单选按钮--总成绩
    // 记录 单选框状态
    static int uplow;
    static int nunasu;
    // 获取 筛选编辑框 状态
    static char NameBuf[100];
    static char NumberBuf[100];
    static char SexBuf[2];
    static char ScoreMathBuf[100];
    static char ScoreLinerBuf[100];
    static char ScoreCBuf[100];
    static char ScoreSumBuf[100];
    static int ifvoid[7];
    static struct stu  *head, *p, *up,*buff;
    static HFONT hFont1,hFont2;
    static HBRUSH hBrush1;
    switch (message)
    {
    case WM_CREATE:
        hBrush1 = CreateSolidBrush( RGB(255, 255, 255) );
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
                     -20/*高度*/, -10/*宽度*/, 0, 0, 400 /*一般这个值设为400*/,
                     FALSE/*不带斜体*/, FALSE/*不带下划线*/, FALSE/*不带删除线*/,
                     DEFAULT_CHARSET,  //使用默认字符集
                     OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,  //这行参数不用管
                     DEFAULT_QUALITY,  //默认输出质量
                     FF_DONTCARE,  //不指定字体族*/
                     TEXT("黑体")  //字体名
                 );

        ///加载文件///读取文件内容
        up=p=head=StuLoad(FileLoad(FileNames));

//AllocConsole();
//freopen("conin$", "r+t", stdin);
//freopen("conout$", "w+t", stdout);
//freopen("conout$", "w+t", stderr);
//    while(p->next!=NULL)
//    {
//
//        p=p->next;
//        printf("%d %s %c %.2lf %.2lf %.2lf %.2lf\n",p->number,p->name,p->sex,p->score[0],p->score[1],p->score[2],p->sum);
//
//    }
        ///


///7个文本 //////////////////////////////////////////////////////////////////////
        hStatic1 = CreateWindow(
                       TEXT("static"), //静态文本框的类名
                       TEXT("学号"),   //控件的文本
                       WS_CHILD /*子窗口*/| WS_VISIBLE /*创建时显示*/ | SS_CENTERIMAGE /*垂直居中*/| SS_CENTER /*水平居中*/,
                       GetSystemMetrics(SM_CXSCREEN)*5/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*5/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*高度*/,
                       hwnd,  //父窗口句柄
                       (HMENU)1,  //为控件指定一个唯一标识符
                       hInst,  //当前程序实例句柄
                       NULL
                   );
        hStatic2 = CreateWindow(
                       TEXT("static"), //静态文本框的类名
                       TEXT("姓名"),   //控件的文本
                       WS_CHILD /*子窗口*/ | WS_VISIBLE /*创建时显示*/ | SS_CENTERIMAGE /*垂直居中*/| SS_CENTER /*水平居中*/,
                       GetSystemMetrics(SM_CXSCREEN)*15/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*5/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*高度*/,
                       hwnd,  //父窗口句柄
                       (HMENU)2,  //为控件指定一个唯一标识符
                       hInst,  //当前程序实例句柄
                       NULL
                   );
        hStatic3 = CreateWindow(
                       TEXT("static"), //静态文本框的类名
                       TEXT("性别"),   //控件的文本
                       WS_CHILD /*子窗口*/ | WS_VISIBLE /*创建时显示*/ | SS_CENTERIMAGE /*垂直居中*/| SS_CENTER /*水平居中*/,
                       GetSystemMetrics(SM_CXSCREEN)*25/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*5/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*高度*/,
                       hwnd,  //父窗口句柄
                       (HMENU)3,  //为控件指定一个唯一标识符
                       hInst,  //当前程序实例句柄
                       NULL
                   );
        hStatic4 = CreateWindow(
                       TEXT("static"), //静态文本框的类名
                       TEXT("FOX"),   //控件的文本
                       WS_CHILD /*子窗口*/| WS_VISIBLE /*创建时显示*/ | SS_CENTERIMAGE /*垂直居中*/| SS_CENTER /*水平居中*/,
                       GetSystemMetrics(SM_CXSCREEN)*35/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*5/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*高度*/,
                       hwnd,  //父窗口句柄
                       (HMENU)4,  //为控件指定一个唯一标识符
                       hInst,  //当前程序实例句柄
                       NULL
                   );
        hStatic5 = CreateWindow(
                       TEXT("static"), //静态文本框的类名
                       TEXT("ENGLISH"),   //控件的文本
                       WS_CHILD /*子窗口*/| WS_VISIBLE /*创建时显示*/ | SS_CENTERIMAGE /*垂直居中*/| SS_CENTER /*水平居中*/,
                       GetSystemMetrics(SM_CXSCREEN)*45/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*5/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*高度*/,
                       hwnd,  //父窗口句柄
                       (HMENU)5,  //为控件指定一个唯一标识符
                       hInst,  //当前程序实例句柄
                       NULL
                   );
        hStatic6 = CreateWindow(
                       TEXT("static"), //静态文本框的类名
                       TEXT("C"),   //控件的文本
                       WS_CHILD /*子窗口*/| WS_VISIBLE /*创建时显示*/ | SS_CENTERIMAGE /*垂直居中*/| SS_CENTER /*水平居中*/,
                       GetSystemMetrics(SM_CXSCREEN)*55/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*5/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*高度*/,
                       hwnd,  //父窗口句柄
                       (HMENU)6,  //为控件指定一个唯一标识符
                       hInst,  //当前程序实例句柄
                       NULL
                   );
        hStatic7 = CreateWindow(
                       TEXT("static"), //静态文本框的类名
                       TEXT("总成绩"),   //控件的文本
                       WS_CHILD /*子窗口*/| WS_VISIBLE /*创建时显示*/ | SS_CENTERIMAGE /*垂直居中*/| SS_CENTER /*水平居中*/,
                       GetSystemMetrics(SM_CXSCREEN)*65/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*5/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*高度*/,
                       hwnd,  //父窗口句柄
                       (HMENU)7,  //为控件指定一个唯一标识符
                       hInst,  //当前程序实例句柄
                       NULL
                   );
/// 7个编辑框 //////////////////////////////////////////////////////////////////////////
        hEdit1 =CreateWindow(TEXT("edit"), TEXT(""),
                             WS_CHILD | WS_VISIBLE | WS_BORDER /*边框*/ | ES_AUTOHSCROLL /*水平滚动*/,
                             GetSystemMetrics(SM_CXSCREEN)*5/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*7.5/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*高度*/,
                             hwnd, (HMENU)71, hInst, NULL
                            );
        hEdit2 =CreateWindow(TEXT("edit"), TEXT(""),
                             WS_CHILD | WS_VISIBLE | WS_BORDER /*边框*/ | ES_AUTOHSCROLL /*水平滚动*/,
                             GetSystemMetrics(SM_CXSCREEN)*15/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*7.5/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*高度*/,
                             hwnd, (HMENU)72, hInst, NULL
                            );
        hEdit3 =CreateWindow(TEXT("edit"), TEXT(""),
                             WS_CHILD | WS_VISIBLE | WS_BORDER /*边框*/ | ES_AUTOHSCROLL /*水平滚动*/,
                             GetSystemMetrics(SM_CXSCREEN)*25/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*7.5/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*高度*/,
                             hwnd, (HMENU)73, hInst, NULL
                            );
        hEdit4 =CreateWindow(TEXT("edit"), TEXT(""),
                             WS_CHILD | WS_VISIBLE | WS_BORDER /*边框*/ | ES_AUTOHSCROLL /*水平滚动*/,
                             GetSystemMetrics(SM_CXSCREEN)*35/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*7.5/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*高度*/,
                             hwnd, (HMENU)74, hInst, NULL
                            );
        hEdit5 =CreateWindow(TEXT("edit"), TEXT(""),
                             WS_CHILD | WS_VISIBLE | WS_BORDER /*边框*/ | ES_AUTOHSCROLL /*水平滚动*/,
                             GetSystemMetrics(SM_CXSCREEN)*45/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*7.5/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*高度*/,
                             hwnd, (HMENU)75, hInst, NULL
                            );
        hEdit6 =CreateWindow(TEXT("edit"), TEXT(""),
                             WS_CHILD | WS_VISIBLE | WS_BORDER /*边框*/ | ES_AUTOHSCROLL /*水平滚动*/,
                             GetSystemMetrics(SM_CXSCREEN)*55/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*7.5/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*高度*/,
                             hwnd, (HMENU)76, hInst, NULL
                            );
        hEdit7 =CreateWindow(TEXT("edit"), TEXT(""),
                             WS_CHILD | WS_VISIBLE | WS_BORDER /*边框*/ | ES_AUTOHSCROLL /*水平滚动*/,
                             GetSystemMetrics(SM_CXSCREEN)*65/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*7.5/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*高度*/,
                             hwnd, (HMENU)77, hInst, NULL
                            );

/// 五个按钮 /////////////////////////////////////////////////////////////////////////////////////////
        hBtn1 = CreateWindow(
                    TEXT("button"), //按钮控件的类名
                    TEXT("查询"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                    GetSystemMetrics(SM_CXSCREEN)*75/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*7.5/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*高度*/,
                    hwnd, (HMENU)11 /*控件唯一标识符*/, hInst, NULL
                );
        hBtn2 = CreateWindow(
                    TEXT("button"), //按钮控件的类名
                    TEXT("排序"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                    GetSystemMetrics(SM_CXSCREEN)*60/100 /*X坐标*/, GetSystemMetrics(SM_CYSCREEN)*40/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*15/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*高度*/,
                    hwnd, (HMENU)20 /*控件唯一标识符*/, hInst, NULL
                );
        hBtn3 = CreateWindow(
                    TEXT("button"), //按钮控件的类名
                    TEXT("增加人员信息"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                    GetSystemMetrics(SM_CXSCREEN)*60/100 /*X坐标*/, GetSystemMetrics(SM_CYSCREEN)*50/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*15/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*高度*/,
                    hwnd, (HMENU)33 /*控件唯一标识符*/, hInst, NULL
                );
        hBtn4 = CreateWindow(
                    TEXT("button"), //按钮控件的类名
                    TEXT("删除已显示人员信息"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                    GetSystemMetrics(SM_CXSCREEN)*60/100 /*X坐标*/, GetSystemMetrics(SM_CYSCREEN)*60/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*15/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*高度*/,
                    hwnd, (HMENU)44 /*控件唯一标识符*/, hInst, NULL
                );
        hBtn5 = CreateWindow(
                    TEXT("button"), //按钮控件的类名
                    TEXT("修改已显示人员信息"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                    GetSystemMetrics(SM_CXSCREEN)*60/100 /*X坐标*/, GetSystemMetrics(SM_CYSCREEN)*70/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*15/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*高度*/,
                    hwnd, (HMENU)55 /*控件唯一标识符*/, hInst, NULL
                );
        hBtn6 = CreateWindow(
                    TEXT("button"), //按钮控件的类名
                    TEXT("保存至文件并返回"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                    GetSystemMetrics(SM_CXSCREEN)*60/100 /*X坐标*/, GetSystemMetrics(SM_CYSCREEN)*80/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*15/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*高度*/,
                    hwnd, (HMENU)66 /*控件唯一标识符*/, hInst, NULL
                );
/// ///////////////////////////////////////////////////
        hStatic0 = CreateWindow(
                       TEXT("edit"), //静态文本框的类名
                       TEXT(outter),   //控件的文本
                       WS_CHILD /*子窗口*/| WS_VISIBLE /*创建时显示*/|ES_MULTILINE/*多行编辑控件*/ |WS_VSCROLL| WS_BORDER /*带边框*/,
                       GetSystemMetrics(SM_CXSCREEN)*5/100/*X坐标*/,GetSystemMetrics(SM_CYSCREEN)*12.5/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*50/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*70/100 /*高度*/,
                       hwnd,  //父窗口句柄
                       (HMENU)0,  //为控件指定一个唯一标识符
                       hInst,  //当前程序实例句柄
                       NULL
                   );
/// /////////////////////////////////////////////////////////////////
/// 复选框
        upper = CreateWindow(
                    TEXT("button"), TEXT("升序"),
                    WS_CHILD | WS_VISIBLE | BS_LEFT/*文字居左*/ | BS_AUTORADIOBUTTON /*单选按钮*/ | WS_GROUP,
                    GetSystemMetrics(SM_CXSCREEN)*60/100 /*X坐标*/, GetSystemMetrics(SM_CYSCREEN)*20/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*高度*/,
                    hwnd, (HMENU)21, hInst, NULL
                );
        lower = CreateWindow(
                    TEXT("button"), TEXT("降序"),
                    WS_CHILD | WS_VISIBLE | BS_LEFT/*文字居左*/ | BS_AUTORADIOBUTTON /*单选按钮*/,
                    GetSystemMetrics(SM_CXSCREEN)*80/100 /*X坐标*/, GetSystemMetrics(SM_CYSCREEN)*20/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*高度*/,
                    hwnd, (HMENU)22, hInst, NULL
                );

        numberer = CreateWindow(
                       TEXT("button"), TEXT("学号"),
                       WS_CHILD | WS_VISIBLE | BS_LEFT/*文字居左*/ | BS_AUTORADIOBUTTON /*单选按钮*/ | WS_GROUP,
                       GetSystemMetrics(SM_CXSCREEN)*60/100 /*X坐标*/, GetSystemMetrics(SM_CYSCREEN)*30/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*高度*/,
                       hwnd, (HMENU)23, hInst, NULL
                   );
        namer=CreateWindow(
                  TEXT("button"), TEXT("姓名"),
                  WS_CHILD | WS_VISIBLE | BS_LEFT/*文字居左*/ | BS_AUTORADIOBUTTON /*单选按钮*/,
                  GetSystemMetrics(SM_CXSCREEN)*70/100 /*X坐标*/, GetSystemMetrics(SM_CYSCREEN)*30/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*高度*/,
                  hwnd, (HMENU)24, hInst, NULL
              );
        summer=CreateWindow(
                   TEXT("button"), TEXT("总成绩"),
                   WS_CHILD | WS_VISIBLE | BS_LEFT/*文字居左*/ | BS_AUTORADIOBUTTON /*单选按钮*/,
                   GetSystemMetrics(SM_CXSCREEN)*80/100 /*X坐标*/, GetSystemMetrics(SM_CYSCREEN)*30/100 /*Y坐标*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*宽度*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*高度*/,
                   hwnd, (HMENU)25, hInst, NULL
               );



/// 控制字体
        SendMessage(hStatic1, WM_SETFONT, (WPARAM)hFont1, NULL);
        SendMessage(hStatic2, WM_SETFONT, (WPARAM)hFont1, NULL);
        SendMessage(hStatic3, WM_SETFONT, (WPARAM)hFont1, NULL);
        SendMessage(hStatic4, WM_SETFONT, (WPARAM)hFont1, NULL);
        SendMessage(hStatic5, WM_SETFONT, (WPARAM)hFont1, NULL);
        SendMessage(hStatic6, WM_SETFONT, (WPARAM)hFont1, NULL);
        SendMessage(hStatic7, WM_SETFONT, (WPARAM)hFont1, NULL);
        SendMessage(hBtn1, WM_SETFONT, (WPARAM)hFont2, NULL);
        SendMessage(hBtn2, WM_SETFONT, (WPARAM)hFont2, NULL);
        SendMessage(hBtn3, WM_SETFONT, (WPARAM)hFont2, NULL);
        SendMessage(hBtn4, WM_SETFONT, (WPARAM)hFont2, NULL);
        SendMessage(hBtn5, WM_SETFONT, (WPARAM)hFont2, NULL);
        SendMessage(hBtn6, WM_SETFONT, (WPARAM)hFont2, NULL);
        SendMessage(hStatic0, WM_SETFONT, (WPARAM)hFont2, NULL);

        break;



    case WM_COMMAND:
        wmId    = LOWORD(wParam);
        wmEvent = HIWORD(wParam);
        switch (wmId)
        {
        //单选框 升降
        case 21 :
        case 22 :
            if (SendMessage(upper, BM_GETCHECK, 0, 0) == BST_CHECKED)
            {
                uplow=0;
            }
            if (SendMessage(lower, BM_GETCHECK, 0, 0) == BST_CHECKED)
            {
                uplow=1;
            }
            break;
        //单选框 方式
        case 23 :
        case 24 :
        case 25 :
            if (SendMessage(numberer, BM_GETCHECK, 0, 0) == BST_CHECKED)
            {
                nunasu=0;
            }
            if (SendMessage(namer, BM_GETCHECK, 0, 0) == BST_CHECKED)
            {
                nunasu=1;
            }
            if (SendMessage(summer, BM_GETCHECK, 0, 0) == BST_CHECKED)
            {
                nunasu=2;
            }
            break;
        case 11: //按下按钮 查询
            ///初始化，并获取1-7的信息;
            //up=p=head=StuLoad(FileLoad(FileNames));
            memset(NameBuf,'\0',100);
            memset(ScoreCBuf,'\0',100);
            memset(ScoreLinerBuf,'\0',100);
            memset(ScoreMathBuf,'\0',100);
            memset(ScoreSumBuf,'\0',100);
            memset(NumberBuf,'\0',100);
            memset(SexBuf,'\0',2);
            memset(ifvoid,1,7);
            ifvoid[0]=GetWindowText(hEdit1,NumberBuf,100);
            ifvoid[1]=GetWindowText(hEdit2,NameBuf,100);
            ifvoid[2]=GetWindowText(hEdit3,SexBuf,2);
            ifvoid[3]=GetWindowText(hEdit4,ScoreMathBuf,100);
            ifvoid[4]=GetWindowText(hEdit5,ScoreLinerBuf,100);
            ifvoid[5]=GetWindowText(hEdit6,ScoreCBuf,100);
            ifvoid[6]=GetWindowText(hEdit7,ScoreSumBuf,100);
            ///
            up=ShaiXuanNumber(p,ifvoid[0],NumberBuf);
            up=ShaiXuanName(up,ifvoid[1],NameBuf);
            up=ShaiXuanSex(up,ifvoid[2],SexBuf);
            up=ShaiXuanScoreMath(up,ifvoid[3],ScoreMathBuf);
            up=ShaiXuanScoreLiner(up,ifvoid[4],ScoreLinerBuf);
            up=ShaiXuanScoreC(up,ifvoid[5],ScoreCBuf);
            up=ShaiXuanSum(up,ifvoid[6],ScoreSumBuf);
            ///将up输出进outter并输出进框

            ShowMessage(up,outter);
            SetWindowText(hStatic0,outter);
            break;
        case 20: //按下按钮 排序
            if(uplow==0&&nunasu==0)
            {
                sortNumberU(up);

            }
            if(uplow==0&&nunasu==1)
            {
                sortNameU(up);

            }
            if(uplow==0&&nunasu==2)
            {
                sortSumU(up);

            }
            if(uplow==1&&nunasu==0)
            {
                sortNumberL(up);

            }
            if(uplow==1&&nunasu==1)
            {
                sortNameL(up);

            }
            if(uplow==1&&nunasu==2)
            {
                sortSumL(up);

            }
            ShowMessage(up,outter);
            SetWindowText(hStatic0,outter);

            break;

        case 33: //按下按钮 增加
            StuInsert(p);
            FreeConsole();
            break;
        case 44: //按下按钮 删除
            StuDel(p,up);
            up=p;
            ShowMessage(up,outter);
            SetWindowText(hStatic0,outter);

            break;
        case 55: //按下按钮 修改
            StuEdit(p,up);
            FreeConsole();
            break;
        case 66: //按下按钮 保存
            FileSave(p,FileNames);
            DestroyWindow(hwnd);
            WinMain2(hInstt,hPrev,szCmd,iCmd,1);
            break;
        default:
            //不处理的消息交给 DefWindowProc 处理。
            return DefWindowProc(hwnd, message, wParam, lParam);
        }
        break;





    case WM_CTLCOLORSTATIC:
        hdcStatic = (HDC)wParam;
        SetTextColor( hdcStatic, RGB(0, 0, 139) );  //白色
        SetBkColor( hdcStatic, RGB(255, 255, 255) );  //翠绿色
        return (INT_PTR)GetStockObject(NULL_BRUSH);  //这里必须返回画刷句柄

    //窗口销毁消息
    case WM_DESTROY:
        PostQuitMessage(0) ;
        return 0 ;
    }
    return DefWindowProc(hwnd, message, wParam, lParam) ;
}

