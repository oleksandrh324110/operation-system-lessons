#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <windows.h>
#include <lmcons.h>

int main(void) {
	SYSTEM_INFO s;
	GetSystemInfo(&s);

	// processor type
	char processorType[23];
	switch (s.dwProcessorType) {
		case 9:
			strcpy(processorType, "x64 (Intel)");
			break;
		case 8664:
			strcpy(processorType, "x64 (AMD64)");
			break;
		case 5:
			strcpy(processorType, "ARM");
			break;
		case 12:
			strcpy(processorType, "ARM64");
			break;
		case 6:
			strcpy(processorType, "Based on Intel Itanium");
			break;
		case 0:
			strcpy(processorType, "x86");
			break;
		case 0xffff:
		default:
			strcpy(processorType, "Unknown architecture");
			break;
	}

	// computer name
	unsigned long int computerNameSize = MAX_COMPUTERNAME_LENGTH + 1;
	char computerName[computerNameSize];
	GetComputerName(computerName, &computerNameSize);

	// user name
	unsigned long int userNameSize = UNLEN + 1;
	char userName[userNameSize];
	GetUserName(userName, &userNameSize);

	// printing
	printf("Processor type: %s\n", processorType);
	printf("Number of processors: %ld\n", s.dwNumberOfProcessors);
	printf("Page size: %ld\n", s.dwPageSize);
	printf("Computer name: %s\n", computerName);
	printf("User name: %s\n", userName);
	printf("Active processor mask: %lld\n", s.dwActiveProcessorMask);
	printf("Minimum application address: %p\n", s.lpMinimumApplicationAddress);
	printf("Maximum application address: %p\n", s.lpMaximumApplicationAddress);
	printf("Allocation granularity: %ld\n", s.dwAllocationGranularity);
	printf("Processor level: %d\n", s.wProcessorLevel);
	printf("Processor revision: %d\n", s.wProcessorRevision);
}
