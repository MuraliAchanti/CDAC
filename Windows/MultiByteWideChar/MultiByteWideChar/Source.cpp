#include<iostream>
#include<Windows.h>
using namespace std;
int main()
{
	char ANSIString[100];
	cout << "Enter the ANSI String to be converted" << endl;
	cin >> ANSIString;
	wchar_t WCHARString[100];
	cout << "Enter the wide character string to be converted" <<endl;
	wcin >> WCHARString;
	char *ConvertedWCHAR;
	wchar_t *ConvertedANSI;
	int buffer_size;
	//IsTextUnicode();
	buffer_size = MultiByteToWideChar(CP_UTF8, 0, ANSIString, -1, NULL, 0);
	ConvertedANSI = new wchar_t[buffer_size];
	int flag = MultiByteToWideChar(CP_UTF8, 0, ANSIString,-1, ConvertedANSI, buffer_size);
	if (flag == 0)
		cout << "Conversion to Wide_Char failed" << endl;
	else
		wcout << "Corresponding Wide Character String for ANSI String is - " << ConvertedANSI<<endl;
	buffer_size = WideCharToMultiByte(CP_UTF8, 0, WCHARString, -1, NULL, 0,NULL,NULL);
	ConvertedWCHAR = new char[buffer_size];
	//cout << buffer_size;
	flag = WideCharToMultiByte(CP_UTF8, 0, WCHARString, -1, ConvertedWCHAR, buffer_size, NULL, NULL);
	if (flag == 0)
		wcout << "Conversion to ANSI Failed"<<endl;
	else
		cout << "Corresponding ANSI Character String for Wide Character is -" << ConvertedWCHAR << endl;
	system("pause");
}