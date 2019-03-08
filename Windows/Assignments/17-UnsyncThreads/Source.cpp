#include<iostream>
#include<Windows.h>
using namespace std;
DWORD WINAPI ThreadFunction(LPVOID lpParam);
volatile long int balance = 0;
int main()
{
	DWORD dwThreadId1, dwThreadId2;
	HANDLE hThread1, hThread2;
	HANDLE hThreads[2];
	do
	{	
		balance = 0;
		hThread1 = CreateThread(NULL, 0, ThreadFunction, NULL, 0, &dwThreadId1);
		Sleep(100);
		hThread2 = CreateThread(NULL, 0, ThreadFunction, NULL, 0, &dwThreadId2);
		Sleep(100);
		if (hThread1 == NULL || hThread2 == NULL)
		{
			cout << "Could not create Threads" << endl;
		}
		else
		{
			DWORD dwReturn;
			//hThreads[0] = hThread1;
			//hThreads[1] = hThread2;
			//WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);
			//GetExitCodeThread(hThread1, &dwReturn);
			//cout << "Exit Code Thread 1 - " << dwReturn << endl;
			//GetExitCodeThread(hThread2, &dwReturn);
			//cout << "Exit Code Thread 2 - " << dwReturn << endl;
		}
		cout << "The Final Balance is - " << balance << endl;
	} while (balance == 200000);
	Sleep(500);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	system("pause");
}
DWORD WINAPI ThreadFunction(LPVOID lpParam)
{
	for (int i = 0; i < 100000; i++)
	{
		balance = balance + 1;
	}
	//cout << "The Balance is - " << balance << endl;
	return 999;
}
/*#include<iostream>
#include<windows.h>
using namespace std;
#define MAX 64
int g_x = 0;
DWORD WINAPI ThreadFunction(LPVOID lpParam);
int main()
{
	for (int i = 0; i < MAX && g_x != 1; i++)
	{
		g_x = 0;
		DWORD dwThreadId, dwThreadId1;
		CreateThread(NULL, 0, ThreadFunction, NULL, 0, &dwThreadId);
		Sleep(1000);
		cout << "After Thread 1 - " << g_x << " ";
		CreateThread(NULL, 0, ThreadFunction, NULL, 0, &dwThreadId1);
		Sleep(1000);
		cout << "After Thread 2 - " << g_x << endl;
	}
	if (g_x == 1)
	{
		cout << "Thread Inconsistency" << endl;
	}
	system("pause");
}
DWORD WINAPI ThreadFunction(LPVOID lpParam)
{
	g_x = g_x + 1;
	return 0;
}*/