#include <Windows.h>
#include "Func.h"

void MakePageWritable(unsigned long ulAddress, unsigned long ulSize)
{
	MEMORY_BASIC_INFORMATION* mbi = new MEMORY_BASIC_INFORMATION;
	VirtualQuery((void*)ulAddress, mbi, ulSize);
	if (mbi->Protect != PAGE_EXECUTE_READWRITE)
	{
		unsigned long* ulProtect = new unsigned long;
		VirtualProtect((void*)ulAddress, ulSize, PAGE_EXECUTE_READWRITE, ulProtect);
      delete ulProtect;
	}

   delete mbi;
}

//Use this as the JMP in ASM
void Jump(  unsigned long ulAddress,void* Function,unsigned Nops) 
{
   MakePageWritable(ulAddress, Nops + 5); //Make memory writable before any modifications are attempted

   *(unsigned char*)ulAddress = 0xE9; //E9 is the opcode for a long jump
   *(unsigned long*)(ulAddress + 1) = jmp(ulAddress, Function);//The next 4 bytes indicate the DISPLACEMENT of the destination
   memset((void*)(ulAddress + 5), 0x90, Nops); //nop the rest of the opcode
}

void WriteMemory(unsigned long ulAddress, unsigned long ulAmount, ...)
{
   va_list va;
   va_start(va, ulAmount);

	MakePageWritable(ulAddress, ulAmount);
	for (unsigned long ulIndex = 0; ulIndex < ulAmount; ulIndex++)
	{
		*(unsigned char*)(ulAddress + ulIndex) = va_arg(va, unsigned char);
	}
	va_end(va);
}

//Reads a 4Byte Pointer
unsigned long ReadPointer(unsigned long ulBase, int iOffset)
{
   __try { return *(unsigned long*)(*(unsigned long*)ulBase + iOffset); }
   __except (EXCEPTION_EXECUTE_HANDLER) { return 0; }
}

//Reads a double Pointer
double ReadDOUBLEPointer(DWORD ulBase, INT iOffset)
{
  __try { return (*(DOUBLE*)(*(DWORD*)ulBase + iOffset)); }
  __except (EXCEPTION_EXECUTE_HANDLER) { return 0.0; }
}

//Writes a 4Byte Pointer
bool WritePointer(unsigned long ulBase, int iOffset, int iValue)
{
   __try { *(int*)(*(unsigned long*)ulBase + iOffset) = iValue; return true; }
   __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
}

//Writes a double Pointer
bool WriteDOUBLEPointer(unsigned long ulBase, int iOffset, double iValue)
{
   __try { *(DOUBLE*)(*(DWORD*)ulBase + iOffset) = iValue; return true; }
   __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
}

bool WriteValue(CONST LPDWORD lpdwBase, CONST INT iOffset, CONST INT iValue)
{
   __try { *(INT*)((LPBYTE)lpdwBase + iOffset) = iValue; return true; }
   __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
}

DWORD GetValue(CONST LPDWORD lpdwBase, CONST INT iOffset)
{
   __try { return *(LPDWORD)((LPBYTE)lpdwBase + iOffset); }
   __except (EXCEPTION_EXECUTE_HANDLER) { return NULL; }
}

bool Write (LPVOID Hook , LPCVOID Joke , size_t uSize)
{
	DWORD old = 0;
	__try
	{
		if(VirtualProtect(Hook , uSize , PAGE_READWRITE , &old))
		{
			memcpy_s(Hook , uSize , Joke , uSize);
			VirtualProtect(Hook , uSize , PAGE_READWRITE , &old);
		}
		else
			return false;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		return false;
	}
	return true;
}

DWORD ReadIndefinitePointer(CONST LPDWORD lpdwBase, size_t cLevels, ...)
{
   DWORD dwRetValue = *lpdwBase;

   va_list va;
   va_start(va, cLevels);

   for (size_t cLevel = 0; cLevel < cLevels; cLevel++)
   {
      dwRetValue = GetValue((LPDWORD)dwRetValue, va_arg(va, int));
   }

   va_end(va);
   return dwRetValue;
}

//Find MapleStory Window
HWND FindProcessWindow()
{
  TCHAR szBuffer[200];
  DWORD dwTemp;

  for (HWND hWnd = GetTopWindow(NULL); hWnd != NULL; hWnd = GetNextWindow(hWnd, GW_HWNDNEXT))
  {
	if (!GetClassName(hWnd, szBuffer, 200))
	  continue;

	if (strcmp(szBuffer, "MapleStoryClass") != 0)
	  continue;

	GetWindowThreadProcessId(hWnd, &dwTemp);

	if (dwTemp == GetCurrentProcessId())
	  return hWnd;
  }

  return NULL;
}
