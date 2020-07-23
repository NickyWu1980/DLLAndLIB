#include <windows.h>
#include <iostream>
using namespace std;
#if 1
class CDLLTestBase {
public:
	 virtual ~CDLLTestBase(){};			//��������������Ϊ��������
     virtual int Add(int a, int b) = 0; //
};

// using pfGetInst = MyDllBase* (*)()
// pfGetInst ��һ��ָ�룬ָ��һ������������������� MyDllBase ��ָ��
typedef CDLLTestBase* (*pfGetInst)();

int main()
{
	HMODULE hMod = LoadLibrary(L"DLLTest.dll");
	if (hMod) {
		  pfGetInst pfGetInstance = (pfGetInst)GetProcAddress(hMod, "GetInstance");
		  if (pfGetInstance) {
		  
				//ͨ������ָ��ָ�����������
				CDLLTestBase* pInst = pfGetInstance();
				if (NULL != pInst ){
					pInst->Add(1,2);
					std::cout << "Dinamic call MyDll Ok! ^-^" << std::endl;
				}

				if (NULL == pInst)  {
					std::cout << "Dinamic call MyDll failed T_T" << std::endl;
					//�ͷŶ���
					delete pInst;
				}
		  }
	}
	system("pause");
	return 0;
}

#else

class MyDllBase {
public:
    virtual ~MyDllBase() {};
    virtual void hello() = 0;
};

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

#endif
