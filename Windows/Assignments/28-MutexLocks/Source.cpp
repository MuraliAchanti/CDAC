#include<iostream>
#include<windows.h>
#define THREADCOUNT 8
using namespace std;
HANDLE hMutex;
DWORD WINAPI ThreadFunction(LPVOID lpParam);
int main()
{
	HANDLE hThreads[THREADCOUNT];
	DWORD dwThreadId;
	hMutex = CreateMutexA(NULL, FALSE, "Global_Mutex");
	if (hMutex == NULL)
	{
		cout << "Creation of Mutex Failed" << endl;
	}
	for (int i = 0; i < THREADCOUNT; i++)
	{
		hThreads[i] = CreateThread(NULL, 0, ThreadFunction, NULL, 0, &dwThreadId);
		if (hThreads[i] == NULL)
		{
			cout << "Creation of Thread " << (i + 1) << " Failed" << endl;
		}
	}
	WaitForMultipleObjects(8, hThreads, TRUE, INFINITE);
	for (int i = 0; i < THREADCOUNT; i++)
		CloseHandle(hThreads[i]);
	CloseHandle(hMutex);
	for (int i = 0; i < 8; i++)
		CloseHandle(hThreads[i]);
	system("pause");
}
DWORD WINAPI ThreadFunction(LPVOID lpParam)
{	
	DWORD dwWaitResult;
	dwWaitResult = WaitForSingleObject(hMutex, INFINITE);
	switch (dwWaitResult)
	{
	case WAIT_OBJECT_0:cout << "In Thread ...With Id " << GetCurrentThreadId() << endl;
		ReleaseMutex(hMutex);
		break;
	case WAIT_ABANDONED:return FALSE;
		break;
	}	
	return TRUE;
}