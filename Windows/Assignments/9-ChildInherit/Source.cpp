/*9.Write a program to create a child process.Use GetCurrentProcessId, GetCurrentThreadId, GetProcessId, GetThreadId,
GetProcessIdOfThread to print process and thread information in each of the process.*/
#include<iostream>
#include<Windows.h>
using namespace std;
//want to find whether the file operation needs to find if any handle is inherited
int main(int argc,char *argv[])
{
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if (argc != 2)
		cout << "Couldn't Create a Process" << endl;
	else
	{
		bool flag = CreateProcessA(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
		if (flag == FALSE)
		{
			cout << "Could not Create a Process" << endl;
		}
		else
		{	
			WaitForSingleObject(pi.hThread, INFINITE);
			cout << "Current Process ID - " << GetCurrentProcessId() << endl;
			cout << "Current Thread ID - " << GetCurrentThreadId() << endl;
			cout << "Child Process ID - " << GetProcessId(pi.hProcess) << endl;
			cout << "Child Thread ID - " << GetThreadId(pi.hThread) << endl;
			cout << "Process Id of given Thread is - " << GetProcessIdOfThread(pi.hThread)<<endl;
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);
		}
	}
	system("pause");
}