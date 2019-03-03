#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{	
	HANDLE File_Ptr;
	File_Ptr = CreateFileA("TextFile.txt", GENERIC_READ,0,NULL, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY,NULL);
}