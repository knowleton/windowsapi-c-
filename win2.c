#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
extern HINSTANCE hInstt;
extern HINSTANCE hPrev;
extern PSTR szCmd;
extern int iCmd;
int xin;  /// ���ļ��������ж��Ƿ��½�
//
extern struct stu{

    int number;
    char name[50];
    char sex;
    double score[3];
    double sum;
    struct stu *next;

};


LRESULT CALLBACK WndProc2(HWND, UINT, WPARAM, LPARAM);
///
HINSTANCE hInst;
///
int WINAPI WinMain2(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR szCmdLine,
    int iCmdShow,
    int xinjianfou
)
{
    xin =xinjianfou;
    static TCHAR szClassName[] = TEXT("HelloWin2");  //��������
    HWND     hwnd;  //���ھ��
    MSG      msg;  //��Ϣ
    WNDCLASS wndclass;  //������

    /**********�ڢٲ���ע�ᴰ����**********/
    //Ϊ������ĸ����ֶθ�ֵ
    wndclass.style = CS_HREDRAW | CS_VREDRAW;  //���ڷ��
    wndclass.lpfnWndProc  = WndProc2;  //���ڹ���
    wndclass.cbClsExtra   = 0;  //��ʱ����Ҫ���
    wndclass.cbWndExtra   = 0;  //��ʱ����Ҫ���
    wndclass.hInstance    = hInstance;  //��ǰ���ھ��
    wndclass.hIcon        = LoadIcon (NULL, IDI_APPLICATION);  //����ͼ��
    wndclass.hCursor      = LoadCursor (NULL, IDC_ARROW);  //�����ʽ
    wndclass.hbrBackground= (HBRUSH) GetStockObject (WHITE_BRUSH);  //���ڱ�����ˢ
    wndclass.lpszMenuName = NULL ;  //���ڲ˵�
    wndclass.lpszClassName= szClassName;  //��������

    //ע�ᴰ��
    RegisterClass(&wndclass);

    /*****�ڢڲ�����������(���ô�����ʾ����)*****/
    hwnd = CreateWindow(
                szClassName,  //�����������
                TEXT("ѧ���ɼ�����ϵͳ2"),  //���ڱ��⣨�����ڱ�������
                WS_OVERLAPPEDWINDOW,  //���ڷ��
                CW_USEDEFAULT,  //��ʼ��ʱx���λ��
                CW_USEDEFAULT,  //��ʼ��ʱy���λ��
                GetSystemMetrics(SM_CXSCREEN),  //���ڿ��
                GetSystemMetrics(SM_CYSCREEN),  //���ڸ߶�
                NULL,  //�����ھ��
                NULL,  //���ڲ˵����
                hInstance,  //��ǰ���ڵľ��
                NULL  //��ʹ�ø�ֵ
            );

    //��ʾ����
    ShowWindow (hwnd, iCmdShow);
    //���£����ƣ�����
    UpdateWindow (hwnd);

    /**********�ڢ۲�����Ϣѭ��**********/
    while( GetMessage(&msg, NULL, 0, 0) )
    {
        TranslateMessage(&msg);  //������Ϣ
        DispatchMessage (&msg);  //������Ϣ
    }

    return msg.wParam;
}

char buf[1000]={'\0'};
char buf2[1000]={'\0'};

/**********�ڢܲ������ڹ���**********/
LRESULT CALLBACK WndProc2(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC         hdc;  //�豸�������
    PAINTSTRUCT ps;
    RECT        rect;
    HWND        hStatic,hStatic2;
    HDC hdcWnd;
    HDC hdcStatic;
    static HWND hEdit;
    int wmId, wmEvent;
    static HBRUSH hBrush1,hBrush2;  //��ˢ
    static HFONT hFont1,hFont2;//����
    static HWND hBtn1,hBtn2;//��ť
    switch (message)
    {

    case  WM_CREATE:

        //�����ļ�������buf���ļ���
        FileSearch(buf);

        hBrush1 = CreateSolidBrush( RGB(255, 255, 255) );

        hFont1 = CreateFont(
                -20/*�߶�*/, -10/*���*/, 0, 0, 900 /*һ�����ֵ��Ϊ400*/,
                FALSE/*����б��*/, FALSE/*�����»���*/, FALSE/*����ɾ����*/,
                DEFAULT_CHARSET,  //ʹ��Ĭ���ַ���
                OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,  //���в������ù�
                DEFAULT_QUALITY,  //Ĭ���������
                FF_DONTCARE,  //��ָ��������*/
                TEXT("����")  //������
            );

        //�ļ��������
        hEdit = CreateWindow(TEXT("edit"), TEXT(""),
                WS_CHILD | WS_VISIBLE | WS_BORDER /*�߿�*/ | ES_AUTOHSCROLL /*ˮƽ����*/,
                GetSystemMetrics(SM_CXSCREEN)*60/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*20/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*15/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*3/100 /*�߶�*/,
                hwnd, (HMENU)3, hInst, NULL
            );

        hStatic = CreateWindow(
                TEXT("static"), //��̬�ı��������
                TEXT(buf) ,  //�ؼ����ı�
                WS_CHILD /*�Ӵ���*/ | WS_BORDER /*���߿�*/| WS_VISIBLE /*����ʱ��ʾ*/ |WS_VSCROLL/*����һ���д�ֱ�������Ĵ��ڡ�*/ ,
                GetSystemMetrics(SM_CXSCREEN)*10/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*20/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*30/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*40/100 /*�߶�*/,
                hwnd,  //�����ھ��
                (HMENU)4,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��
                hInst,  //��ǰ����ʵ�����
                NULL
            );
        hStatic2 = CreateWindow(
                TEXT("static"), //��̬�ı��������
                TEXT(".csv") ,  //�ؼ����ı�
                WS_CHILD /*�Ӵ���*/ | WS_VISIBLE /*����ʱ��ʾ*/ ,
                GetSystemMetrics(SM_CXSCREEN)*75/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*20/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*3/100 /*�߶�*/,
                hwnd,  //�����ھ��
                (HMENU)5,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��
                hInst,  //��ǰ����ʵ�����
                NULL
            );
            if(xin==0)
            {
                hBtn1 = CreateWindow(
                TEXT("button"), //��ť�ؼ�������
                TEXT("�½�"),
                WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,
                GetSystemMetrics(SM_CXSCREEN)*60/100 /*X����*/, GetSystemMetrics(SM_CYSCREEN)*40/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*15/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*10/100/*�߶�*/,
                hwnd, (HMENU)1 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL
            );


            }
            else{
                hBtn1 = CreateWindow(
                TEXT("button"), //��ť�ؼ�������
                TEXT("��"),
                WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,
                GetSystemMetrics(SM_CXSCREEN)*60/100 /*X����*/, GetSystemMetrics(SM_CYSCREEN)*40/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*15/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*10/100/*�߶�*/,
                hwnd, (HMENU)1 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL
            );



            }
             hBtn2 = CreateWindow(
                TEXT("button"), //��ť�ؼ�������
                TEXT("����"),
                WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,
                GetSystemMetrics(SM_CXSCREEN)*60/100  /*X����*/, GetSystemMetrics(SM_CYSCREEN)*60/100/*Y����*/, GetSystemMetrics(SM_CXSCREEN)*15/100  /*���*/, GetSystemMetrics(SM_CYSCREEN)*10/100/*�߶�*/,
                hwnd, (HMENU)2/*�ؼ�Ψһ��ʶ��*/, hInst, NULL
            );



           SendMessage(hStatic, WM_SETFONT, (WPARAM)hFont1, NULL);
           SendMessage(hStatic2, WM_SETFONT, (WPARAM)hFont1, NULL);
            break;


            ///���°�ť
          case WM_COMMAND:
            wmId    = LOWORD(wParam);
            wmEvent = HIWORD(wParam);
            switch (wmId){
                case 1: //���°�ť1
            ///��ȡ�ļ���
                    GetWindowText(hEdit,buf2,1000);
                    if(buf2[0]=='\0')
                    {
                        MessageBox(NULL, TEXT("�ļ�������Ϊ��"), TEXT("error"), MB_OK);

                    }
                    else{
                    strcat(buf2,".csv");

            ///����2����3�������ļ���
                    DestroyWindow(hwnd);
                    WinMain3(hInstt,hPrev,szCmd,iCmd,buf2);
                    }


                break;
                case 2:  //���°�ť2
                DestroyWindow(hwnd);
                WinMain1(hInstt,hPrev,szCmd,iCmd);
                break;
                default:
                    //���������Ϣһ��Ҫ���� DefWindowProc ����
                    return DefWindowProc(hwnd, message, wParam, lParam);
            }
            break;

            case WM_CTLCOLORSTATIC:
            hdcStatic = (HDC)wParam;
            SetTextColor( hdcStatic, RGB(0, 0, 139) );  //��ɫ
            SetBkColor( hdcStatic, RGB(255, 255, 255) );  //����ɫ
            return (INT_PTR)GetStockObject(NULL_BRUSH);  //������뷵�ػ�ˢ���










    //����������Ϣ
    case WM_DESTROY:
        PostQuitMessage(0) ;
        return 0 ;

    }
    return DefWindowProc(hwnd, message, wParam, lParam) ;
}
