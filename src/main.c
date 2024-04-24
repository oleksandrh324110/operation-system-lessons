#include <stdio.h>
#include <windows.h>
#include <psapi.h>

int main(void) {
  MEMORYSTATUSEX statex;
  statex.dwLength = sizeof(statex);

  if (!GlobalMemoryStatusEx(&statex)) {
    printf("Could not get memory status.\n");
    return 1;
  }

  PERFORMANCE_INFORMATION perfInfo;
  perfInfo.cb = sizeof(perfInfo);

  if (!GetPerformanceInfo(&perfInfo, sizeof(perfInfo))) {
    printf("Could not get performance info.\n");
    return 1;
  }

  printf("Memory comparison:\n");
  printf("Total physical memory (GlobalMemoryStatusEx): %fgb\n", (float)statex.ullTotalPhys / 1024 / 1024 / 1024);
  printf("Total physical memory (GetPerformanceInfo): %fgb\n", (float)perfInfo.PhysicalTotal * perfInfo.PageSize / 1024 / 1024 / 1024);
  printf("Available physical memory (GlobalMemoryStatusEx): %fgb\n", (float)statex.ullAvailPhys / 1024 / 1024 / 1024);
  printf("Available physical memory (GetPerformanceInfo): %fgb\n", (float)perfInfo.PhysicalAvailable * perfInfo.PageSize / 1024 / 1024 / 1024);

  return 0;
}