// MyDll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "MyDll.h"
#include <stdio.h>


// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 MyDll.h
CMyDll::CMyDll()
{
    return;
}

int CMyDll::MyPrint()
{
	printf("我是DLL中的函数");
	return 100;
}

CDLL * getInstance()
{
	return new CMyDll();
}