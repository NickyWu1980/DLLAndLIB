// DynamicCallDll.cpp
#include <windows.h>
#include <cstdlib>
#include <iostream>
#include "MyDllBase.h"


// using pfGetInst = MyDllBase* (*)()
// pfGetInst ��һ��ָ�룬ָ��һ������������������� MyDllBase ��ָ��
typedef MyDllBase* (*pfGetInst)();

int main()
{
    HMODULE hMod = LoadLibrary(L"MyDll.dll");
    if (hMod) {
        pfGetInst pfGetInstance = (pfGetInst)GetProcAddress(hMod, "GetInstance");
        if (pfGetInstance) {
            // ͨ������ָ��ָ����������Ķ���
            MyDllBase* pInst = pfGetInstance();
            if (NULL != pInst) {
                pInst->hello();
				std::cout << "Dinamic call MyDll successed ^_^" << std::endl;
            }
            if (NULL == pInst) {
                std::cout << "Dinamic call MyDll failed T_T" << std::endl;
                delete pInst;
            }
        }
    }
    system("pause");
    return 0;
}
