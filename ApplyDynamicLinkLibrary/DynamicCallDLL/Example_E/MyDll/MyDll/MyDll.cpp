// MyDll.cpp
#include <iostream>
#include "MyDll.h"

HelloDll::HelloDll()
{

}

HelloDll::~HelloDll()
{

}

void HelloDll::hello()
{
    std::cout << "Hello, this is my DLL ^_^ " << std::endl;
}