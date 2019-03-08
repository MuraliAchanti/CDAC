#include<iostream>
#include<windows.h>
using namespace std;
HANDLE hEvent;
DWORD WINAPI CountWords(LPVOID lpParam);
DWORD WINAPI CheckSpellings(LPVOID lpParam);
DWORD WINAPI CheckGrammar(LPVOID lpParam);
int main()
{
	HANDLE hThread1, hThread2, hThread3;
	HANDLE hThreads[3];
	HANDLE hFile;
	DWORD dwThreadId;
	hEvent = CreateEventA(NULL, TRUE, FALSE, "ResetEvent");
	hFile = CreateFileA("testfile.txt", GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == NULL)
	{
		cout << "Could not create a File" << endl;
		return 0;
	}
	//else
	//{
	//	SetEvent(hEvent);
	//}
	hThread1 = CreateThread(NULL, 0, CountWords, NULL, 0, &dwThreadId);
	if (hThread1 == NULL)
	{
		cout << "Couldn't Create Thread 1" << endl;
	}
	hThread2 = CreateThread(NULL, 0, CheckSpellings, NULL, 0, &dwThreadId);
	if (hThread2 == NULL)
	{
		cout << "Couldn't Create Thread 2" << endl;
	}
	hThread3 = CreateThread(NULL, 0, CheckGrammar, NULL, 0, &dwThreadId);
	if (hThread3 == NULL)
	{
		cout << "Could not Create Thread 3" << endl;
	}
	hThreads[0] = hThread1;
	hThreads[1] = hThread2;
	hThreads[2] = hThread3;
	WaitForMultipleObjects(3, hThreads, TRUE, INFINITE);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	CloseHandle(hThread3);
	CloseHandle(hFile);
	system("pause");
}
DWORD WINAPI CountWords(LPVOID lpParam)
{
	if (!SetEvent(hEvent))
	{
		cout << "Failed to Set Event" << endl;
		return 0;
	}
	Sleep(1000);
	cout << "Counting the Number of Words" << endl;
	ResetEvent(hEvent);
	return 0;
}
DWORD WINAPI CheckSpellings(LPVOID lpParam)
{
	if (!SetEvent(hEvent))
	{
		cout << "Failed to Set Event" << endl;
		return 0;
	}
	Sleep(1000);
	cout << "Checking the Spellings" << endl;
	ResetEvent(hEvent);
	return 0;
}
DWORD WINAPI CheckGrammar(LPVOID lpParam)
{
	if (!SetEvent(hEvent))
	{
		cout << "Failed to Set Event" << endl;
		return 0;
	}
	Sleep(100);
	cout << "Checking the Grammar" << endl;
	ResetEvent(hEvent);
	return 0;
}