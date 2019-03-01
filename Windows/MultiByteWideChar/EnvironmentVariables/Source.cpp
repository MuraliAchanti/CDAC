#include<iostream>
#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	//LPCH variables;
	//variables = GetEnvironmentStringsA();
	//while (*variables)
	//{
	//	cout<<variables;
	//	cout << endl;
	//	variables += strlen(variables) + 1;
	//}
	//FreeEnvironmentStrings(variables);
	const DWORD buffSize = 50;
	char *buffer = new char[buffSize];
	int flag = GetEnvironmentVariableA("TEMP", buffer, buffSize);
	if (flag != 0 && flag < buffSize)
	{
		buffer[flag + 1] = '\0';
		cout << buffer;
	}
	else if (buffSize < flag)
	{	
		cout << "aaa"<<endl;
		buffer = new char[flag + 1];
		buffer[flag + 1] = '\0';
		GetEnvironmentVariableA("TEMP", buffer, buffSize);
		cout << buffer;
	}
	else
		cout << "Failed";
	system("pause");
}