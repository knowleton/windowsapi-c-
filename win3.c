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
    static TCHAR szClassName[] = TEXT("HelloWin3");  //��������
    HWND     hwnd;  //���ھ��
    MSG      msg;  //��Ϣ
    WNDCLASS wndclass;  //������

    ///

    FileNames=FileName;

    ///
    /**********�ڢٲ���ע�ᴰ����**********/
    //Ϊ������ĸ����ֶθ�ֵ
    wndclass.style = CS_HREDRAW | CS_VREDRAW;  //���ڷ��
    wndclass.lpfnWndProc  = WndProc3;  //���ڹ���
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
               TEXT("ѧ���ɼ�����ϵͳ3"),  //���ڱ��⣨�����ڱ�������
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


char outter[10000];
char getter[10000];
/**********�ڢܲ������ڹ���**********/
LRESULT CALLBACK WndProc3(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static TCHAR szBuf11[10];  //��������
    static TCHAR szBuf22[10];  //���淽ʽ
    int wmId, wmEvent;
    HDC         hdc;  //�豸�������
    PAINTSTRUCT ps;
    RECT        rect;
    HDC hdcWnd;
    HDC hdcStatic;
    HWND         hStatic1,hStatic2,hStatic3,hStatic4,hStatic5,hStatic6,hStatic7;
    static HWND hStatic0,hEdit1,hEdit2,hEdit3,hEdit4,hEdit5,hEdit6,hEdit7 ;
    static HWND hBtn1,hBtn2,hBtn3,hBtn4,hBtn5,hBtn6;//��ť

    static HWND upper;  //��ѡ��ť--����
    static HWND lower;  //��ѡ��ť-- ����

    static HWND numberer;//��ѡ��ť--ѧ��
    static HWND namer;//��ѡ��ť--����
    static HWND summer;//��ѡ��ť--�ܳɼ�
    // ��¼ ��ѡ��״̬
    static int uplow;
    static int nunasu;
    // ��ȡ ɸѡ�༭�� ״̬
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
                     -20/*�߶�*/, -10/*���*/, 0, 0, 900 /*һ�����ֵ��Ϊ400*/,
                     FALSE/*����б��*/, FALSE/*�����»���*/, FALSE/*����ɾ����*/,
                     DEFAULT_CHARSET,  //ʹ��Ĭ���ַ���
                     OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,  //���в������ù�
                     DEFAULT_QUALITY,  //Ĭ���������
                     FF_DONTCARE,  //��ָ��������*/
                     TEXT("����")  //������
                 );
        hFont2 = CreateFont(
                     -20/*�߶�*/, -10/*���*/, 0, 0, 400 /*һ�����ֵ��Ϊ400*/,
                     FALSE/*����б��*/, FALSE/*�����»���*/, FALSE/*����ɾ����*/,
                     DEFAULT_CHARSET,  //ʹ��Ĭ���ַ���
                     OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,  //���в������ù�
                     DEFAULT_QUALITY,  //Ĭ���������
                     FF_DONTCARE,  //��ָ��������*/
                     TEXT("����")  //������
                 );

        ///�����ļ�///��ȡ�ļ�����
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


///7���ı� //////////////////////////////////////////////////////////////////////
        hStatic1 = CreateWindow(
                       TEXT("static"), //��̬�ı��������
                       TEXT("ѧ��"),   //�ؼ����ı�
                       WS_CHILD /*�Ӵ���*/| WS_VISIBLE /*����ʱ��ʾ*/ | SS_CENTERIMAGE /*��ֱ����*/| SS_CENTER /*ˮƽ����*/,
                       GetSystemMetrics(SM_CXSCREEN)*5/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*5/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*�߶�*/,
                       hwnd,  //�����ھ��
                       (HMENU)1,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��
                       hInst,  //��ǰ����ʵ�����
                       NULL
                   );
        hStatic2 = CreateWindow(
                       TEXT("static"), //��̬�ı��������
                       TEXT("����"),   //�ؼ����ı�
                       WS_CHILD /*�Ӵ���*/ | WS_VISIBLE /*����ʱ��ʾ*/ | SS_CENTERIMAGE /*��ֱ����*/| SS_CENTER /*ˮƽ����*/,
                       GetSystemMetrics(SM_CXSCREEN)*15/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*5/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*�߶�*/,
                       hwnd,  //�����ھ��
                       (HMENU)2,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��
                       hInst,  //��ǰ����ʵ�����
                       NULL
                   );
        hStatic3 = CreateWindow(
                       TEXT("static"), //��̬�ı��������
                       TEXT("�Ա�"),   //�ؼ����ı�
                       WS_CHILD /*�Ӵ���*/ | WS_VISIBLE /*����ʱ��ʾ*/ | SS_CENTERIMAGE /*��ֱ����*/| SS_CENTER /*ˮƽ����*/,
                       GetSystemMetrics(SM_CXSCREEN)*25/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*5/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*�߶�*/,
                       hwnd,  //�����ھ��
                       (HMENU)3,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��
                       hInst,  //��ǰ����ʵ�����
                       NULL
                   );
        hStatic4 = CreateWindow(
                       TEXT("static"), //��̬�ı��������
                       TEXT("FOX"),   //�ؼ����ı�
                       WS_CHILD /*�Ӵ���*/| WS_VISIBLE /*����ʱ��ʾ*/ | SS_CENTERIMAGE /*��ֱ����*/| SS_CENTER /*ˮƽ����*/,
                       GetSystemMetrics(SM_CXSCREEN)*35/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*5/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*�߶�*/,
                       hwnd,  //�����ھ��
                       (HMENU)4,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��
                       hInst,  //��ǰ����ʵ�����
                       NULL
                   );
        hStatic5 = CreateWindow(
                       TEXT("static"), //��̬�ı��������
                       TEXT("ENGLISH"),   //�ؼ����ı�
                       WS_CHILD /*�Ӵ���*/| WS_VISIBLE /*����ʱ��ʾ*/ | SS_CENTERIMAGE /*��ֱ����*/| SS_CENTER /*ˮƽ����*/,
                       GetSystemMetrics(SM_CXSCREEN)*45/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*5/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*�߶�*/,
                       hwnd,  //�����ھ��
                       (HMENU)5,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��
                       hInst,  //��ǰ����ʵ�����
                       NULL
                   );
        hStatic6 = CreateWindow(
                       TEXT("static"), //��̬�ı��������
                       TEXT("C"),   //�ؼ����ı�
                       WS_CHILD /*�Ӵ���*/| WS_VISIBLE /*����ʱ��ʾ*/ | SS_CENTERIMAGE /*��ֱ����*/| SS_CENTER /*ˮƽ����*/,
                       GetSystemMetrics(SM_CXSCREEN)*55/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*5/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*�߶�*/,
                       hwnd,  //�����ھ��
                       (HMENU)6,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��
                       hInst,  //��ǰ����ʵ�����
                       NULL
                   );
        hStatic7 = CreateWindow(
                       TEXT("static"), //��̬�ı��������
                       TEXT("�ܳɼ�"),   //�ؼ����ı�
                       WS_CHILD /*�Ӵ���*/| WS_VISIBLE /*����ʱ��ʾ*/ | SS_CENTERIMAGE /*��ֱ����*/| SS_CENTER /*ˮƽ����*/,
                       GetSystemMetrics(SM_CXSCREEN)*65/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*5/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*�߶�*/,
                       hwnd,  //�����ھ��
                       (HMENU)7,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��
                       hInst,  //��ǰ����ʵ�����
                       NULL
                   );
/// 7���༭�� //////////////////////////////////////////////////////////////////////////
        hEdit1 =CreateWindow(TEXT("edit"), TEXT(""),
                             WS_CHILD | WS_VISIBLE | WS_BORDER /*�߿�*/ | ES_AUTOHSCROLL /*ˮƽ����*/,
                             GetSystemMetrics(SM_CXSCREEN)*5/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*7.5/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*�߶�*/,
                             hwnd, (HMENU)71, hInst, NULL
                            );
        hEdit2 =CreateWindow(TEXT("edit"), TEXT(""),
                             WS_CHILD | WS_VISIBLE | WS_BORDER /*�߿�*/ | ES_AUTOHSCROLL /*ˮƽ����*/,
                             GetSystemMetrics(SM_CXSCREEN)*15/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*7.5/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*�߶�*/,
                             hwnd, (HMENU)72, hInst, NULL
                            );
        hEdit3 =CreateWindow(TEXT("edit"), TEXT(""),
                             WS_CHILD | WS_VISIBLE | WS_BORDER /*�߿�*/ | ES_AUTOHSCROLL /*ˮƽ����*/,
                             GetSystemMetrics(SM_CXSCREEN)*25/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*7.5/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*�߶�*/,
                             hwnd, (HMENU)73, hInst, NULL
                            );
        hEdit4 =CreateWindow(TEXT("edit"), TEXT(""),
                             WS_CHILD | WS_VISIBLE | WS_BORDER /*�߿�*/ | ES_AUTOHSCROLL /*ˮƽ����*/,
                             GetSystemMetrics(SM_CXSCREEN)*35/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*7.5/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*�߶�*/,
                             hwnd, (HMENU)74, hInst, NULL
                            );
        hEdit5 =CreateWindow(TEXT("edit"), TEXT(""),
                             WS_CHILD | WS_VISIBLE | WS_BORDER /*�߿�*/ | ES_AUTOHSCROLL /*ˮƽ����*/,
                             GetSystemMetrics(SM_CXSCREEN)*45/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*7.5/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*�߶�*/,
                             hwnd, (HMENU)75, hInst, NULL
                            );
        hEdit6 =CreateWindow(TEXT("edit"), TEXT(""),
                             WS_CHILD | WS_VISIBLE | WS_BORDER /*�߿�*/ | ES_AUTOHSCROLL /*ˮƽ����*/,
                             GetSystemMetrics(SM_CXSCREEN)*55/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*7.5/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*�߶�*/,
                             hwnd, (HMENU)76, hInst, NULL
                            );
        hEdit7 =CreateWindow(TEXT("edit"), TEXT(""),
                             WS_CHILD | WS_VISIBLE | WS_BORDER /*�߿�*/ | ES_AUTOHSCROLL /*ˮƽ����*/,
                             GetSystemMetrics(SM_CXSCREEN)*65/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*7.5/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*�߶�*/,
                             hwnd, (HMENU)77, hInst, NULL
                            );

/// �����ť /////////////////////////////////////////////////////////////////////////////////////////
        hBtn1 = CreateWindow(
                    TEXT("button"), //��ť�ؼ�������
                    TEXT("��ѯ"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,
                    GetSystemMetrics(SM_CXSCREEN)*75/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*7.5/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*2.5/100 /*�߶�*/,
                    hwnd, (HMENU)11 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL
                );
        hBtn2 = CreateWindow(
                    TEXT("button"), //��ť�ؼ�������
                    TEXT("����"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,
                    GetSystemMetrics(SM_CXSCREEN)*60/100 /*X����*/, GetSystemMetrics(SM_CYSCREEN)*40/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*15/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*�߶�*/,
                    hwnd, (HMENU)20 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL
                );
        hBtn3 = CreateWindow(
                    TEXT("button"), //��ť�ؼ�������
                    TEXT("������Ա��Ϣ"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,
                    GetSystemMetrics(SM_CXSCREEN)*60/100 /*X����*/, GetSystemMetrics(SM_CYSCREEN)*50/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*15/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*�߶�*/,
                    hwnd, (HMENU)33 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL
                );
        hBtn4 = CreateWindow(
                    TEXT("button"), //��ť�ؼ�������
                    TEXT("ɾ������ʾ��Ա��Ϣ"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,
                    GetSystemMetrics(SM_CXSCREEN)*60/100 /*X����*/, GetSystemMetrics(SM_CYSCREEN)*60/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*15/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*�߶�*/,
                    hwnd, (HMENU)44 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL
                );
        hBtn5 = CreateWindow(
                    TEXT("button"), //��ť�ؼ�������
                    TEXT("�޸�����ʾ��Ա��Ϣ"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,
                    GetSystemMetrics(SM_CXSCREEN)*60/100 /*X����*/, GetSystemMetrics(SM_CYSCREEN)*70/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*15/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*�߶�*/,
                    hwnd, (HMENU)55 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL
                );
        hBtn6 = CreateWindow(
                    TEXT("button"), //��ť�ؼ�������
                    TEXT("�������ļ�������"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,
                    GetSystemMetrics(SM_CXSCREEN)*60/100 /*X����*/, GetSystemMetrics(SM_CYSCREEN)*80/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*15/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*�߶�*/,
                    hwnd, (HMENU)66 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL
                );
/// ///////////////////////////////////////////////////
        hStatic0 = CreateWindow(
                       TEXT("edit"), //��̬�ı��������
                       TEXT(outter),   //�ؼ����ı�
                       WS_CHILD /*�Ӵ���*/| WS_VISIBLE /*����ʱ��ʾ*/|ES_MULTILINE/*���б༭�ؼ�*/ |WS_VSCROLL| WS_BORDER /*���߿�*/,
                       GetSystemMetrics(SM_CXSCREEN)*5/100/*X����*/,GetSystemMetrics(SM_CYSCREEN)*12.5/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*50/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*70/100 /*�߶�*/,
                       hwnd,  //�����ھ��
                       (HMENU)0,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��
                       hInst,  //��ǰ����ʵ�����
                       NULL
                   );
/// /////////////////////////////////////////////////////////////////
/// ��ѡ��
        upper = CreateWindow(
                    TEXT("button"), TEXT("����"),
                    WS_CHILD | WS_VISIBLE | BS_LEFT/*���־���*/ | BS_AUTORADIOBUTTON /*��ѡ��ť*/ | WS_GROUP,
                    GetSystemMetrics(SM_CXSCREEN)*60/100 /*X����*/, GetSystemMetrics(SM_CYSCREEN)*20/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*�߶�*/,
                    hwnd, (HMENU)21, hInst, NULL
                );
        lower = CreateWindow(
                    TEXT("button"), TEXT("����"),
                    WS_CHILD | WS_VISIBLE | BS_LEFT/*���־���*/ | BS_AUTORADIOBUTTON /*��ѡ��ť*/,
                    GetSystemMetrics(SM_CXSCREEN)*80/100 /*X����*/, GetSystemMetrics(SM_CYSCREEN)*20/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*�߶�*/,
                    hwnd, (HMENU)22, hInst, NULL
                );

        numberer = CreateWindow(
                       TEXT("button"), TEXT("ѧ��"),
                       WS_CHILD | WS_VISIBLE | BS_LEFT/*���־���*/ | BS_AUTORADIOBUTTON /*��ѡ��ť*/ | WS_GROUP,
                       GetSystemMetrics(SM_CXSCREEN)*60/100 /*X����*/, GetSystemMetrics(SM_CYSCREEN)*30/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*�߶�*/,
                       hwnd, (HMENU)23, hInst, NULL
                   );
        namer=CreateWindow(
                  TEXT("button"), TEXT("����"),
                  WS_CHILD | WS_VISIBLE | BS_LEFT/*���־���*/ | BS_AUTORADIOBUTTON /*��ѡ��ť*/,
                  GetSystemMetrics(SM_CXSCREEN)*70/100 /*X����*/, GetSystemMetrics(SM_CYSCREEN)*30/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*�߶�*/,
                  hwnd, (HMENU)24, hInst, NULL
              );
        summer=CreateWindow(
                   TEXT("button"), TEXT("�ܳɼ�"),
                   WS_CHILD | WS_VISIBLE | BS_LEFT/*���־���*/ | BS_AUTORADIOBUTTON /*��ѡ��ť*/,
                   GetSystemMetrics(SM_CXSCREEN)*80/100 /*X����*/, GetSystemMetrics(SM_CYSCREEN)*30/100 /*Y����*/, GetSystemMetrics(SM_CXSCREEN)*5/100 /*���*/, GetSystemMetrics(SM_CYSCREEN)*5/100/*�߶�*/,
                   hwnd, (HMENU)25, hInst, NULL
               );



/// ��������
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
        //��ѡ�� ����
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
        //��ѡ�� ��ʽ
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
        case 11: //���°�ť ��ѯ
            ///��ʼ��������ȡ1-7����Ϣ;
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
            ///��up�����outter���������

            ShowMessage(up,outter);
            SetWindowText(hStatic0,outter);
            break;
        case 20: //���°�ť ����
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

        case 33: //���°�ť ����
            StuInsert(p);
            FreeConsole();
            break;
        case 44: //���°�ť ɾ��
            StuDel(p,up);
            up=p;
            ShowMessage(up,outter);
            SetWindowText(hStatic0,outter);

            break;
        case 55: //���°�ť �޸�
            StuEdit(p,up);
            FreeConsole();
            break;
        case 66: //���°�ť ����
            FileSave(p,FileNames);
            DestroyWindow(hwnd);
            WinMain2(hInstt,hPrev,szCmd,iCmd,1);
            break;
        default:
            //���������Ϣ���� DefWindowProc ����
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

