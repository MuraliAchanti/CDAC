#include<windows.h>
#include<iostream>
using namespace std;
DWORD WINAPI ThreadFunction(LPVOID lpParam);
int main()
{
	DWORD dwThreadId;
	HANDLE hThread;
	char content[100];
	cout << "-----IN MAIN-----" << endl;
	cout << "Enter the parameter to be passed to the thread";
	cin >> content; 
	hThread = CreateThread(NULL, 0, ThreadFunction, content, 0, &dwThreadId);
	if (hThread == NULL)
	{
		cout << "Could not Create a Thread" << endl;
	}
	system("pause");
}
DWORD WINAPI ThreadFunction(LPVOID lpParam)
{
	cout << "-----IN Thread-----" << endl;
	cout << "The Parameters Passed to thread are - " <<(char *)lpParam; 
	return 0;
}