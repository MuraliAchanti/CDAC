#include<iostream>
#include<windows.h>
#define THREADCOUNT 4
#define SEM_COUNT 2
HANDLE ghSemaphore;
using namespace std;
DWORD WINAPI ThreadFunction(LPVOID lpParam);
int main()
{
	HANDLE hThreads[THREADCOUNT];
	DWORD dwThreadId;
	ghSemaphore = CreateSemaphore(
		NULL,           // default security attributes
		SEM_COUNT,  // initial count
		SEM_COUNT,  // maximum count
		NULL);
	if (ghSemaphore == NULL)
	{
		cout << "Creation of Semaphore Failed" << endl;
	}
	for (int i = 0; i < THREADCOUNT; i++)
	{
		hThreads[i] = CreateThread(NULL, 0, ThreadFunction, NULL, 0, &dwThreadId);
		if (hThreads[i] == NULL)
		{
			cout << "Creation of Thread " << (i + 1) << " Failed" << endl;
		}
	}
	WaitForMultipleObjects(THREADCOUNT, hThreads, TRUE, INFINITE);
	for (int i = 0; i < THREADCOUNT; i++)
	{
		CloseHandle(hThreads[i]);
	}
	CloseHandle(ghSemaphore);
	system("pause");
}
DWORD WINAPI ThreadFunction(LPVOID lpParam)
{
	DWORD dwResult;
	dwResult = WaitForSingleObject(ghSemaphore, 0);
	switch (dwResult)
	{
	case WAIT_OBJECT_0:cout << "Inside the Thread with Id " << GetCurrentThreadId() << endl;
		Sleep(700);
		long count;
		if (!ReleaseSemaphore(ghSemaphore, 1, &count))
		{
			cout << "Failed to Release Semaphore" << endl;
		}
		cout << "Semaphore Count is - " << count << endl;
		break;
	case WAIT_TIMEOUT:cout << "Wait Timeout..Id - " << GetCurrentThreadId()<<endl;
		break;
	}
	return 0;
}