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
    static TCHAR szClassName[] = TEXT("HelloWin");  //��������
    HWND     hwnd;  //���ھ��
    MSG      msg;  //��Ϣ
    WNDCLASS wndclass;  //������


    /**********�ڢٲ���ע�ᴰ����**********/
    //Ϊ������ĸ����ֶθ�ֵ
    wndclass.style = CS_HREDRAW | CS_VREDRAW;  //���ڷ��
    wndclass.lpfnWndProc  = WndProc1;  //���ڹ���
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
        TEXT("ѧ���ɼ�����ϵͳ1"),  //���ڱ��⣨�����ڱ�������
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
    while( GetMessage(&msg, NULL, 0, 0) ){
        TranslateMessage(&msg);  //������Ϣ
        DispatchMessage (&msg);  //������Ϣ
    }



    return msg.wParam;
}

/**********�ڢܲ������ڹ���**********/
LRESULT CALLBACK WndProc1(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC         hdc;  //�豸�������
    PAINTSTRUCT ps;
    RECT        rect;
    HWND        hStatic;
    HDC hdcWnd;
    HDC hdcStatic;
    static HFONT hFont1,hFont2;
    static HWND hBtn1,hBtn2,hBtn3;
    static HBRUSH hBrush1,hBrush2;  //��ˢ
    int wmId, wmEvent;
    int xinjianfou =0;



    switch (message){

        case  WM_CREATE:
            //������ˢ
            hBrush1 = CreateSolidBrush( RGB(255, 255, 255) );

            //�����߼�����
            hFont1 = CreateFont(
                -20/*�߶�*/, -10/*���*/, 0, 0, 900 /*һ�����ֵ��Ϊ400*/,
                FALSE/*����б��*/, FALSE/*�����»���*/, FALSE/*����ɾ����*/,
                DEFAULT_CHARSET,  //ʹ��Ĭ���ַ���
                OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,  //���в������ù�
                DEFAULT_QUALITY,  //Ĭ���������
                FF_DONTCARE,  //��ָ��������*/
                TEXT("����")  //������
            );
            hFont2 = CreateFont(
                -45/*�߶�*/, -22.5/*���*/, 0, 0, 400 /*һ�����ֵ��Ϊ400*/,
                FALSE/*����б��*/, FALSE/*�����»���*/, FALSE/*����ɾ����*/,
                DEFAULT_CHARSET,  //ʹ��Ĭ���ַ���
                OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,  //���в������ù�
                DEFAULT_QUALITY,  //Ĭ���������
                FF_DONTCARE,  //��ָ��������*/
                TEXT("����")  //������
            );
            //����ı���
            hStatic = CreateWindow(
                TEXT("static"), //��̬�ı��������
                TEXT("\n\n\nѧ���ɼ�����ϵͳ\n\n     2018��5���Դ��"),  //�ؼ����ı�
                WS_CHILD /*�Ӵ���*/ | WS_VISIBLE /*����ʱ��ʾ*/ | SS_CENTER /*ˮƽ����*/ ,
                GetSystemMetrics(SM_CXSCREEN)*10/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*20/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*30/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*40/100 /*�߶�*/,
                hwnd,  //�����ھ��
                (HMENU)4,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��
                hInst,  //��ǰ����ʵ�����
                NULL
            );
             //������ť1�ؼ�
             hBtn1 = CreateWindow(
                TEXT("button"), //��ť�ؼ�������
                TEXT("�½�"),
                WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,
                GetSystemMetrics(SM_CXSCREEN)*60/100 /*X����*/, GetSystemMetrics(SM_CYSCREEN)*10/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*15/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*10/100/*�߶�*/,
                hwnd, (HMENU)1 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL
            );
             hBtn2 = CreateWindow(
                TEXT("button"), //��ť�ؼ�������
                TEXT("��"),
                WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,
                GetSystemMetrics(SM_CXSCREEN)*60/100  /*X����*/, GetSystemMetrics(SM_CYSCREEN)*40/100/*Y����*/, GetSystemMetrics(SM_CXSCREEN)*15/100  /*���*/, GetSystemMetrics(SM_CYSCREEN)*10/100/*�߶�*/,
                hwnd, (HMENU)2/*�ؼ�Ψһ��ʶ��*/, hInst, NULL
            );
             hBtn3= CreateWindow(
                TEXT("button"), //��ť�ؼ�������
                TEXT("�˳�"),
                WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,
                GetSystemMetrics(SM_CXSCREEN)*60/100  /*X����*/,GetSystemMetrics(SM_CYSCREEN)* 70/100/*Y����*/ , GetSystemMetrics(SM_CXSCREEN)*15/100  /*���*/, GetSystemMetrics(SM_CYSCREEN)*10/100/*�߶�*/,
                hwnd, (HMENU)3 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL
            );


            //���ð�ť����
            SendMessage(hBtn1, WM_SETFONT, (WPARAM)hFont1, NULL);
            SendMessage(hBtn2, WM_SETFONT, (WPARAM)hFont1, NULL);
            SendMessage(hBtn3, WM_SETFONT, (WPARAM)hFont1, NULL);
            SendMessage(hStatic, WM_SETFONT, (WPARAM)hFont2, NULL);

            break;
          case WM_CTLCOLORSTATIC:
            hdcStatic = (HDC)wParam;
            SetTextColor( hdcStatic, RGB(0, 0, 139) );  //��ɫ
            SetBkColor( hdcStatic, RGB(255, 255, 255) );  //����ɫ
            return (INT_PTR)GetStockObject(NULL_BRUSH);  //������뷵�ػ�ˢ���

        ///���°�ť
          case WM_COMMAND:
            wmId    = LOWORD(wParam);
            wmEvent = HIWORD(wParam);
            switch (wmId){
                case 1: //���°�ť1 xinjian
                DestroyWindow(hwnd);
                WinMain2(hInstt,hPrev,szCmd,iCmd,0);
                break;
                case 2:  //���°�ť2 dakai
                DestroyWindow(hwnd);
                WinMain2(hInstt,hPrev,szCmd,iCmd,1);
                break;
                case 3:
                DestroyWindow(hwnd);
                break;
                default:
                    //���������Ϣһ��Ҫ���� DefWindowProc ����
                    return DefWindowProc(hwnd, message, wParam, lParam);
            }
            break;


        //����������Ϣ
        case WM_DESTROY:
            PostQuitMessage(0) ;

            return 0 ;
    }





    return DefWindowProc(hwnd, message, wParam, lParam) ;
}
