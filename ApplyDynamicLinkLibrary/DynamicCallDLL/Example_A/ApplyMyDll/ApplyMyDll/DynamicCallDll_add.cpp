//#undef UNICODE
#include <iostream>
#include <Windows.h>

using namespace std;
typedef int(*LPGETNUMBER)(int, int);

int main() {
	LPGETNUMBER lp;
	int result = -99999; 
	HINSTANCE hInstance = LoadLibrary(L"mydll.dll");
	if (NULL != hInstance) {
		lp = (LPGETNUMBER)GetProcAddress(hInstance, "add");
		if (NULL != lp) {
			result = lp(4, 6);
			std::cout << result << std::endl;
		}
		else std::cout << " GetProcAddress failed!" << endl;
		FreeLibrary(hInstance);
	}
	else std::cout << "LoadLibrary failed!" << std::endl;

	std::cout << "Test end " << std::endl;
	system("pause"); 
	return 0;
}