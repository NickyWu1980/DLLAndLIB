// MyDll.cpp
#include <iostream>
#include "DLLTest.h"

CDLLTest::CDLLTest()
{

}

CDLLTest::~CDLLTest()
{

}

int CDLLTest::Add(int a, int b)
{
	return (a + b);
}

CDLLTest* GetInstance()
{
    return new CDLLTest;
}