// MyDll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "MyDll.h"
#include <stdio.h>


// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� MyDll.h
CMyDll::CMyDll()
{
    return;
}

int CMyDll::MyPrint()
{
	printf("����DLL�еĺ���");
	return 100;
}

CDLL * getInstance()
{
	return new CMyDll();
}