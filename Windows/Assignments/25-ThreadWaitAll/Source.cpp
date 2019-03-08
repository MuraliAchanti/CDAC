#include<iostream>
#include<Windows.h>
using namespace std;
//DWORD WINAPI ThreadFunction1(LPVOID lpParam)
//{
//	cout << "IN Thread Function" << endl;
//	return 0;
//}
DWORD WINAPI ThreadFunction1(LPVOID lpParam)
{
	cout << "IN Thread Function 1 " << endl;
	Sleep(4000);
	return 0;
}
DWORD WINAPI ThreadFunction2(LPVOID lpParam)
{
	cout << "IN Thread Function 2 " << endl;
	Sleep(000);
	return 0;
}
int main()
{
	DWORD dwThreadId;
	HANDLE hThread1, hThread2;
	HANDLE hThreads[2];
	//--------------------------1------------------------hThread1 = CreateThread(NULL, 0, ThreadFunction, NULL, 0, &dwThreadId);
	//if (hThread1 == NULL)
	//{
	//	cout << "Creation of Thread 1 Failed" << endl;
	//}
	//hThread2 = CreateThread(NULL, 0, ThreadFunction, NULL, 0, &dwThreadId);
	//if (hThread2 == NULL)
	//{
	//	cout << "Creation of Thread 2 Failed" << endl;
	//}
	//hThreads[0] = hThread1;
	//hThreads[1] = hThread2;
	//DWORD returnvalue = WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);
	hThreads[0] = CreateThread(NULL, 0, ThreadFunction1, NULL, 0, &dwThreadId);
	hThreads[1] = CreateThread(NULL, 0, ThreadFunction2, NULL, 0, &dwThreadId);
	DWORD returnvalue = WaitForMultipleObjects(2, hThreads, FALSE, INFINITE);
	switch (returnvalue)
	{
	case WAIT_OBJECT_0:cout << "Signalled" << endl;
		break;
	case WAIT_ABANDONED:cout << "Wait Abandoned" << endl;
		break;
	case WAIT_TIMEOUT:cout << "Wait Timeout Expired" << endl;
		break;
	case WAIT_FAILED:cout << "Wait Failed with Error - " << GetLastError() << endl;
		break;
	default:cout << "The return value is " << (returnvalue-WAIT_OBJECT_0);
		break;
	}
	system("pause");
}