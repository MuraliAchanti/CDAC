#include<iostream>
#include<Windows.h>
using namespace std;
DWORD WINAPI ThreadFunction(LPVOID lpParam);
long int balance = 0;
CRITICAL_SECTION criticalsection;
int main()
{	
	DWORD dwThreadId1, dwThreadId2;
	HANDLE hThread1, hThread2;
	HANDLE hThreads[2];
	hThread1 = CreateThread(NULL, 0, ThreadFunction, NULL, 0, &dwThreadId1);
	hThread2 = CreateThread(NULL, 0, ThreadFunction, NULL, 0, &dwThreadId2);
	if (hThread1 == NULL || hThread2 == NULL)
	{
		cout << "Could not create Threads" << endl;
	}
	else
	{	
		DWORD dwReturn;
		hThreads[0] = hThread1;
		hThreads[1] = hThread2;
		InitializeCriticalSection(&criticalsection);
		WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);
		GetExitCodeThread(hThread1, &dwReturn);
		cout << "Exit Code Thread 1 - " << dwReturn << endl;
		GetExitCodeThread(hThread2, &dwReturn);
		cout << "Exit Code Thread 2 - " << dwReturn << endl;
	}
	cout << "The Final Balance is - " << balance << endl;
	//WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	system("pause");
}
DWORD WINAPI ThreadFunction(LPVOID lpParam)
{
	EnterCriticalSection(&criticalsection);
	for (int i = 0; i < 100000; i++)
	{
		balance = balance + 1;
	}
	cout << "The Balance is - " << balance<<endl;
	LeaveCriticalSection(&criticalsection);
	return 999;
}