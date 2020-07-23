#include <iostream>
#include <windows.h>
using namespace std;

class CDLL
{
public:
	virtual int MyPrint() = 0;

};


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