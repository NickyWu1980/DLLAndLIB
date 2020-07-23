#if 1
// DynamicCallDll.cpp
//#undef UNICODE
#include <windows.h>
#include <iostream>
using namespace std;


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

#else
#include <iostream>
#include <windows.h>
using namespace std;
/*
class CDLL
{
public:
	virtual int MyPrint() = 0;

};
*/

int main()
{
	HINSTANCE hDll;//���

	typedef CDLL*(*MyGetInstance)();
	MyGetInstance instance;//����ָ��
	hDll = ::LoadLibrary(L"MyDll.dll");//��̬����DLLģ����
	if (hDll)
	{
		instance = (MyGetInstance)GetProcAddress(hDll, "getInstance");//�õ�������DLLģ���к����ĵ�ַ
		
		CDLL *dll = instance();
		int ret = dll->MyPrint();
		cout << "ret=" << ret << endl;
		FreeLibrary(hDll);//�ͷ��Ѿ����ص�DLLģ��
	}

	system("pause");
	return 0;
}
#endif