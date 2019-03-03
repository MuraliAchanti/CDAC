#include<iostream>
#include<Windows.h>
using namespace std;
int main(int argc,char *argv[])
{
	STARTUPINFO si[2];
	PROCESS_INFORMATION pi[2];
	int No_of_Processes = 2;
	for (int i = 0; i < 2; i++)
	{	
		ZeroMemory(&si[i], sizeof(si[i]));
		si[i].cb = sizeof(si[i]);
		ZeroMemory(&pi[i], sizeof(pi[i]));
		CreateProcessA(NULL, argv[i + 1], NULL, NULL, FALSE, 0, NULL, NULL, &si[i], &pi[i]);
		cout << "Process Id - " << pi[i].dwProcessId << endl;
		cout << "Handle Id - " << pi[i].hProcess << endl;
		DWORD dwRet = WaitForSingleObject(pi[i].hProcess, INFINITE);
		switch (dwRet)
		{
		case WAIT_ABANDONED:

			cout<<"Mutex object was not released by the thread that owned the mutex object before the owning thread terminates...\n"<<endl;

			break;

		case WAIT_OBJECT_0:

			cout<<"The child thread state was signaled!\n";

			break;

		case WAIT_TIMEOUT:

			cout<<"Time - out interval elapsed, and the child thread's state is nonsignaled.\n";

				break;

		case WAIT_FAILED:

			cout<<"WaitForSingleObject() failed, error %u\n, GetLastError()";

			break;

		}
		CloseHandle(pi[i].hProcess);
		CloseHandle(pi[i].hThread);
	}
	system("pause");
}