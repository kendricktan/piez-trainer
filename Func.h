#include <Windows.h>

//Acts as a medium between all used functions in all forms with Func.cpp

#define jmp(frm, to) (int)(((int)to - (int)frm) - 5);
unsigned long ReadPointer(unsigned long ulBase, int iOffset);
DOUBLE ReadDOUBLEPointer(DWORD ulBase, INT iOffset);
bool WriteDOUBLEPointer(unsigned long ulBase, int iOffset, double iValue);
bool WritePointer(unsigned long ulBase, int iOffset, int iValue);
bool WriteValue(CONST LPDWORD lpdwBase, CONST INT iOffset, CONST INT iValue);
unsigned long WriteDoubleValue(unsigned long ulBase, double iValue);
DWORD ReadIndefinitePointer(CONST LPDWORD lpdwBase, size_t cLevels, ...);
HWND FindProcessWindow();
void WriteMemory(unsigned long ulAddress, unsigned long ulAmount, ...);
void Jump(  unsigned long ulAddress,void* Function,unsigned Nops);
bool Write (LPVOID Hook , LPCVOID Joke , size_t uSize);
#define NewThread(Function) CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&Function, NULL, 0, NULL);