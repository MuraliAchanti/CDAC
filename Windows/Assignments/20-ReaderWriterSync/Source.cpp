#include<iostream>
#include<windows.h>
#include<queue>
#define SIZE 6
using namespace std;
long int g_x = 0;
queue<int> Queue;
SRWLOCK readerLock, writerLock;
CONDITION_VARIABLE qFull, qEmpty;
DWORD WINAPI ReaderFunction(LPVOID lpParam);
DWORD WINAPI WriterFunction(LPVOID lpParam);
int main()
{
	HANDLE hThreads[6];
	InitializeConditionVariable(&qFull);
	InitializeConditionVariable(&qEmpty);
	InitializeSRWLock(&readerLock);
	InitializeSRWLock(&writerLock);
	DWORD dwThreadId;
	for (int i = 0; i < 2; i++)
	{
		hThreads[i] = CreateThread(NULL, 0, ReaderFunction, NULL, 0, &dwThreadId);
		if (hThreads[i] == NULL)
		{
			cout << "Creation of Thread Failed" << endl;
			return 0;
		}
	}
	for (int i = 2; i < 6; i++)
	{
		hThreads[i] = CreateThread(NULL, 0, WriterFunction, NULL, 0, &dwThreadId);
		if (hThreads[i] == NULL)
		{
			cout << "Creation of Thread Failed" << endl;
			return 0;
		}
	}
	WaitForMultipleObjects(6, hThreads, TRUE, INFINITE);
	system("pause");
}
DWORD WINAPI ReaderFunction(LPVOID lpParam)
{
	while (true)
	{
		AcquireSRWLockShared(&readerLock);
		if (Queue.size() == 0)
		{
			SleepConditionVariableSRW(&qEmpty, &readerLock, INFINITE, CONDITION_VARIABLE_LOCKMODE_SHARED);
		}
		else
		{ 
			cout << "The value read by Thread with id - " << GetCurrentThreadId() << " is " << Queue.front() << endl;
			Queue.pop();
			WakeConditionVariable(&qFull);
		}
		Sleep(200);
		ReleaseSRWLockShared(&readerLock);
	}
}
DWORD WINAPI WriterFunction(LPVOID lpParam)
{
	while (true)
	{	
		Sleep(200);
		AcquireSRWLockExclusive(&writerLock);
		if (Queue.size() == SIZE)
		{
			SleepConditionVariableSRW(&qFull, &writerLock, INFINITE, 0);
		}
		else
		{
			InterlockedAdd(&g_x, 1);
			Queue.push(g_x);
			cout << "The value written by Thread with id - " << GetCurrentThreadId() << " is " << g_x << endl;
			WakeAllConditionVariable(&qEmpty);
		}
		ReleaseSRWLockExclusive(&writerLock);
	}
}
