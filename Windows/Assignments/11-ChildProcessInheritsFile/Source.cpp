/*10.Write a program to create child process which inherits handle of the object (say file object or event object) created 
in the parent process. This can be done via setting SECURITY_ATTRIBUTES structures lpSecurityDescriptor parameter when 
creating object and CreateProcess’s bInheritHandles parameter when creating child process. Note that child process has 
no idea of what handles are inherited by it.*/
#include<iostream>
#include<Windows.h>
using namespace std;
int main(int argc,char *argv[])
{
	_SECURITY_ATTRIBUTES  sa;
	sa.nLength = sizeof(sa);
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;
	HANDLE hFile = CreateFileA("test.txt", GENERIC_READ | GENERIC_WRITE, 0, &sa, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	cout << "Parent" << hFile << endl;
	if (hFile == NULL)
	{
		cout << "Could not Create a Handle to the File" << endl;
	}
	else
	{
		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		ZeroMemory(&pi, sizeof(pi));
		//hardcoded as calling FileOperations1
		char arguments[100];
		sprintf(arguments, "%s %s %p",argv[1],"Random", hFile);
		cout << "Arguments - "<<arguments<<endl;
		int flag = CreateProcessA(NULL, arguments, &sa, NULL, TRUE, 0, NULL, NULL, &si, &pi);
		if (flag == 0)
		{
			cout << "Could not Create a Process" << endl;
		}
		else
		{
			WaitForSingleObject(pi.hProcess, INFINITE);
			cout << "Parent Process ID - " << GetCurrentProcessId()<<endl;
			cout << "Child Process ID - " << GetProcessId(pi.hProcess)<<endl;
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);
		}
	}
	system("pause");
}