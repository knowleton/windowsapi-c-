#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
extern struct stu{

    int number;
    char name[50];
    char sex;
    double score[3];
    double sum;
    struct stu *next;

};
    HINSTANCE hInstt;
    HINSTANCE hPrev;
    PSTR szCmd;
    int iCmd;
    HINSTANCE ioioi ;
int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR szCmdLine,
    int iCmdShow
){
    ioioi = hInstance;


    ///       为引用函数进行 设备变量处理                    ///
    hInstt = hInstance;
    hPrev = hPrevInstance;
    szCmd = szCmdLine;
    iCmd =iCmdShow;
    ///                /////

    WinMain1(hInstance,hPrevInstance,szCmdLine,iCmdShow);







    return 0;
}
