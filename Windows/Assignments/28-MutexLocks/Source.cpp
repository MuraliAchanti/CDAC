#include<iostream>
#include<windows.h>
#define THREADCOUNT 8
using namespace std;
DWORD WINAPI ThreadFunction(LPVOID lpParam);
int main()
{
	HANDLE hThreads[THREADCOUNT];
	DWORD dwThreadId;
	for (int i = 0; i < THREADCOUNT; i++)
	{
		hThreads[i] = CreateThread(NULL, 0, ThreadFunction, NULL, 0, &dwThreadId);
	}
}