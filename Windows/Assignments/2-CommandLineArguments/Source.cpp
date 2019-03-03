#include<iostream>
#include<Windows.h>
using namespace std;
int main()
{
	LPWSTR *CommandLineArguments;
	int NoofArgs;
	CommandLineArguments = CommandLineToArgvW(GetCommandLineW(), &NoofArgs);
	if (CommandLineArguments == NULL)
		cout << "Failed"<<endl;
	else
	{	
		cout << "The Command Line Arguments are - " << endl;
		for (int i = 0; i < NoofArgs; i++)	
		{
			wcout << CommandLineArguments[i] << endl;
		}
	}
	system("pause");
}