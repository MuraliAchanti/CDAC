#include<iostream>
#include<windows.h>
using namespace std;
DWORD WINAPI ThreadFunction1(LPVOID lpParam);
DWORD WINAPI ThreadFunction2(LPVOID lpParam);
DWORD WINAPI ThreadFunction3(LPVOID lpParam);
void CheckReturn(DWORD returnvalue)
{	
	switch (returnvalue)
	{
	case WAIT_ABANDONED: cout << "Wait Abandoned Id - " <<GetCurrentThreadId()<< endl;
						 break;
	case WAIT_TIMEOUT:cout << "TimeOut Expired Id - " <<GetCurrentThreadId()<< endl;
					  break;
	case WAIT_OBJECT_0:cout << "Object Signalled Id - "<<GetCurrentThreadId()<< endl;
					   break;
	case WAIT_FAILED:cout << "Wait Failed Id - " <<GetCurrentThreadId()<< " Error - "<<GetLastError() << endl;
					 break;
	}
}
int main()
{
	HANDLE hThread1,hThread2,hThread3;
	DWORD dwThreadId;
	hThread1 = CreateThread(NULL, 0, ThreadFunction1, NULL, 0, &dwThreadId);
	cout << "Thread 1 - " << GetThreadId(hThread1);
	CheckReturn(WaitForSingleObject(hThread1, INFINITE));
	hThread2 = CreateThread(NULL, 0,ThreadFunction2, NULL, 0, &dwThreadId); 
	cout << "Thread 2 - " << GetThreadId(hThread2);
	CheckReturn(WaitForSingleObject(hThread2, 1000));
	hThread3 = CreateThread(NULL, 0, ThreadFunction3, NULL, 0, &dwThreadId);
	cout << "Thread 3 - " << GetThreadId(hThread3);
	CheckReturn(WaitForSingleObject(hThread3, 1000));
	system("pause");

}
DWORD ThreadFunction1(LPVOID lpParam)
{
	cout << "In Thread 1" << endl;
	return 0;
}
DWORD ThreadFunction2(LPVOID lpParam)
{
	cout << "In Thread 2" << endl;
	return 0;
}
DWORD ThreadFunction3(LPVOID lpParam)
{
	cout << "In Thread 3" << endl;
	Sleep(2000);
	return 0;
}