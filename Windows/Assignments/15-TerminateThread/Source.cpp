#include<iostream>
#include<windows.h>
using namespace std;
DWORD WINAPI ThreadFunction(LPVOID lpParam);
int main()
{
	HANDLE hThread;
	DWORD dwThreadId;
	char content[100];
	SECURITY_ATTRIBUTES sa;
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;
	cout << "Enter the parameter to be passed to thread" << endl;
	cin >> content;
	hThread = CreateThread(&sa,0, ThreadFunction, content, 0, &dwThreadId);
	if (hThread == NULL)
		cout << "Could not create a Thread" << endl;
	else
	{
		//WaitForSingleObject(hThread, INFINITE);
	}
	DWORD dwExitCode;
	TerminateThread(hThread, 1001010);
	Sleep(2000);
	GetExitCodeThread(hThread, &dwExitCode);
	cout << "The Exit Code is - " << dwExitCode;
	system("pause");
}
DWORD WINAPI ThreadFunction(LPVOID lpParam)
{
	cout << "----In Thread----" << endl;
	cout << "Parameters passed to Thread are - " << (char *)lpParam << endl;
	Sleep(5000);
	//DWORD ExitCode;
	//cout << "Enter the exit code to be passed to primary process" << endl;
	//cin >> ExitCode;
	//ExitThread(ExitCode);
	return 0;
}