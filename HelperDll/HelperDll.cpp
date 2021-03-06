// HelperDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#pragma warning(disable:4996)

#define DECLDIR __declspec(dllexport)

extern "C"
{
	DECLDIR HANDLE getProcess(void)
	{
#ifdef _DEBUG
		printf("getProcessHandle\n");
#endif
		return GetCurrentProcess();
	}

	DECLDIR HANDLE getThread(void)
	{
#ifdef _DEBUG
		printf("getThreadHandle\n");
#endif
		return GetCurrentThread();
	}

	DECLDIR HANDLE getAccessToken(void)
	{
#ifdef _DEBUG
		printf("getAccessToken\n");
#endif
		HANDLE handle;
		OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &handle);
		return handle;
	}

	DECLDIR HANDLE getEvent()
	{
#ifdef _DEBUG
		printf("getEvent\n");
#endif
		return CreateEventA(NULL, true, true, NULL);
	}

	DECLDIR HANDLE getNamestEvent(int nr)
	{
#ifdef _DEBUG
		printf("getNamestEvent\n");
#endif
		char name[16];
		sprintf(name, "event%d", nr);
		return CreateEventA(NULL, true, true, name);
	}

	DECLDIR HANDLE getMutex()
	{
#ifdef _DEBUG
		printf("getMutex\n");
#endif
		return CreateMutexA(NULL, true, NULL);
	}

	DECLDIR HANDLE getNamestMutex(int nr)
	{
#ifdef _DEBUG
		printf("getNamestMutex\n");
#endif
		char name[16];
		sprintf(name, "mutex%d", nr);
		return CreateMutexA(NULL, true, name);
	}

	DECLDIR HANDLE getPipeRead()
	{
#ifdef _DEBUG
		printf("getPipeRead\n");
#endif
		HANDLE pipeRead;
		HANDLE pipeWrite;
		CreatePipe(&pipeRead, &pipeWrite, NULL, 256);
		return pipeRead;
	}

	DECLDIR HANDLE getPipeWrite()
	{
#ifdef _DEBUG
		printf("getPipeWrite\n");
#endif
		HANDLE pipeRead;
		HANDLE pipeWrite;
		CreatePipe(&pipeRead, &pipeWrite, NULL, 256);
		return pipeWrite;
	}

	DECLDIR HANDLE getFile()
	{
#ifdef _DEBUG
		printf("getFile\n");
#endif
		return CreateFileA("file.txt", GENERIC_READ | GENERIC_WRITE, 0, 0, 2, 128, NULL);
	}

	DECLDIR HANDLE getWindow()
	{
#ifdef _DEBUG
		printf("getWindow\n");
#endif
		HWND hwnd = CreateWindowExA(NULL, "Static", NULL, 13565952, rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000, NULL, NULL, 0, 0);
		ShowWindow(hwnd, 5);
		return hwnd;
	}
}