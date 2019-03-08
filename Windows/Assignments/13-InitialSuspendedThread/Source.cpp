#include<windows.h>
#include<iostream>
using namespace std;
DWORD WINAPI ThreadFunction(LPVOID lpParam);
int main()
{
	HANDLE hThread;
	DWORD dwThreadId;
	char content[100];
	cout << "-----In Main-----" << endl;
	cout << "Enter the arguments to be passed to the Thread" << endl;
	cin >> content;
	hThread = CreateThread(NULL, 0, ThreadFunction,content,CREATE_SUSPENDED, &dwThreadId);
	if (hThread == NULL)
	{
		cout << "Could not create a Thread" << endl;
	}
	cout << "Wait for 5 Seconds" << endl;
	Sleep(5000);
	ResumeThread(hThread);
	Sleep(500);
	CloseHandle(hThread);
	system("pause");
}
DWORD WINAPI ThreadFunction(LPVOID lpParam)
{
	cout << "-----In Thread-----" << endl;
	cout << "Parameter passed to thread is - " << (char*)lpParam; 
	for (int i = 0; i < 1000; i++)
		cout << i << " " << endl;
	return 0;
}