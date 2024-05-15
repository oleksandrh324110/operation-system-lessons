#include <iostream>

#include <windows.h>

int main(void) {
  std::cout << 12 << '\n';
  MessageBox(NULL, "Hello World!", "Hello", MB_OK);
  return 0;
}