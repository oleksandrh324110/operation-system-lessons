#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <windows.h>
#include <lmcons.h>

void getDayOfWeekName(char weekName[10], SYSTEMTIME systemTime) {
	const char* days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	strcpy(weekName, days[systemTime.wDayOfWeek]);
}

void getMonthName(char monthName[10], SYSTEMTIME systemTime) {
	const char* months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	strcpy(monthName, months[systemTime.wMonth - 1]);
}

long long unsigned int factorial(unsigned int n) {
	if (n <= 1) return 1;
	return n * factorial(n - 1);
}


int main(void) {
	{
		SYSTEMTIME systemTime;
		GetSystemTime(&systemTime);

		char dayOfWeekName[10];
		getDayOfWeekName(dayOfWeekName, systemTime);
		char monthName[10];
		getMonthName(monthName, systemTime);

		printf("%s, %d-%s-%d %02d:%02d:%02d\n", dayOfWeekName, systemTime.wDay, monthName, systemTime.wYear, systemTime.wHour, systemTime.wMinute, systemTime.wSecond);

		GetLocalTime(&systemTime);
		getDayOfWeekName(dayOfWeekName, systemTime);
		getMonthName(monthName, systemTime);

		printf("%s, %d-%s-%d %02d:%02d:%02d\n", dayOfWeekName, systemTime.wDay, monthName, systemTime.wYear, systemTime.wHour, systemTime.wMinute, systemTime.wSecond);
	}

	{
		ULONGLONG startTime = GetTickCount();
		long long unsigned int res = factorial(10);
		ULONGLONG endTime = GetTickCount() - startTime;

		printf("factorial of 10 is: %llu\n", res);

		printf("execution time of factorial in milliseconds is: %llu\n", endTime);

		startTime = GetTickCount();
		Sleep(1000);
		endTime = GetTickCount() - startTime;

		printf("Sleep(1000) took: %llums\n", endTime);
	}

	{
		LARGE_INTEGER frequency;
		LARGE_INTEGER startTime;
		LARGE_INTEGER endTime;

		double elapsedTime;
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&startTime);

		factorial(1000);

		QueryPerformanceCounter(&endTime);

		elapsedTime = (double)(endTime.QuadPart - startTime.QuadPart) /
			frequency.QuadPart * 1000;

		printf("factorial of 64 took: %lfms\n", elapsedTime);
	}
}
