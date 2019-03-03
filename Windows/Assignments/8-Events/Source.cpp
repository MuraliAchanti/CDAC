#include <windows.h>
#include <stdio.h>
#define THREADCOUNT 4 
HANDLE ghWriteEvent;
HANDLE ghThreads[THREADCOUNT];
DWORD WINAPI ThreadProc(LPVOID);
void CreateEventsAndThreads(void)
{
	int i;
	DWORD dwThreadID;
	ghWriteEvent = CreateEvent(
		NULL,               // default security attributes
		TRUE,               // manual-reset event
		FALSE,              // initial state is nonsignaled
		TEXT("WriteEvent")  // object name
	);
	if (ghWriteEvent == NULL)
	{
		printf("CreateEvent failed (%d)\n", GetLastError());
		return;
	}
	for (i = 0; i < THREADCOUNT; i++)
	{
		ghThreads[i] = CreateThread(
			NULL,              // default security
			0,                 // default stack size
			ThreadProc,        // name of the thread function
			NULL,              // no thread parameters
			0,                 // default startup flags
			&dwThreadID);
		if (ghThreads[i] == NULL)
		{
			printf("CreateThread failed (%d)\n", GetLastError());
			return;
		}
	}
}

void WriteToBuffer(VOID)
{
	printf("Main thread writing to the shared buffer...\n");
	if (!SetEvent(ghWriteEvent))
	{
		printf("SetEvent failed (%d)\n", GetLastError());
		return;
	}
}
void CloseEvents()
{
	CloseHandle(ghWriteEvent);
}
int main(void)
{
	DWORD dwWaitResult;
	CreateEventsAndThreads();
	WriteToBuffer();
	printf("Main thread waiting for threads to exit...\n");
	dwWaitResult = WaitForMultipleObjects(
		THREADCOUNT,   // number of handles in array
		ghThreads,     // array of thread handles
		TRUE,          // wait until all are signaled
		INFINITE);
	switch (dwWaitResult)
	{
	case WAIT_OBJECT_0:
		printf("All threads ended, cleaning up for application exit...\n");
		break;
	default:
		printf("WaitForMultipleObjects failed (%d)\n", GetLastError());
		return 1;
	}
	CloseEvents();
	system("pause");
}
DWORD WINAPI ThreadProc(LPVOID lpParam)
{
	UNREFERENCED_PARAMETER(lpParam);
	DWORD dwWaitResult;
	printf("Thread %d waiting for write event...\n", GetCurrentThreadId());
	dwWaitResult = WaitForSingleObject(
		ghWriteEvent, // event handle
		INFINITE);    // indefinite wait
	switch (dwWaitResult)
	{
	case WAIT_OBJECT_0:
		printf("Thread %d reading from buffer\n",
			GetCurrentThreadId());
		break;
	default:
		printf("Wait error (%d)\n", GetLastError());
		return 0;
	}
	printf("Thread %d exiting\n", GetCurrentThreadId());
	return 1;
}