#include <Windows.h>
#include "SendPacket.h"
#include "Pointers.h"
#include <stdio.h>
#include <String>
#include <iostream>
 
struct PACKET {
        DWORD Null;
        LPVOID lpData;
        DWORD nSize;
        DWORD Null2;
};
 
typedef DWORD (__stdcall *SENDPACKET)(PACKET *Buffer);
 
SENDPACKET SendPacket;
 
char* Buffer = NULL;
DWORD SendAddy = 0x0; 
DWORD ClassAddy = 0x0;

//DWORD PEClass = 0x0; 
unsigned long PESendJmp = SendAddy;
DWORD PEClass = *(PDWORD)(ClassAddy+2);
//unsigned long PEClass = *(DWORD*)&Buffer[ClassAddy+2];
 
 
//----------------------------------------------------------
 
inline char* atohx(char* dst, const char * src)
{      
        char *ret = dst;
        for(int lsb, msb; *src; src += 2)
        {      
                msb = tolower(*src);
                lsb = tolower(*(src + 1));
                msb -= isdigit(msb) ? 0x30 : 0x57;
                lsb -= isdigit(lsb) ? 0x30 : 0x57;
                if((msb < 0x0 || msb > 0xf) || (lsb < 0x0 || lsb > 0xf))
                {
                        *ret = 0;
                        return NULL;
                }
                *dst++ = (char)(lsb | (msb << 4));  
        }
        *dst = 0;
        return ret;
}
 
//-------------Sending Packet Functions --------------------

void WINAPI msSendPacketA(__in LPCSTR lpPacketStr)
{
        SIZE_T stLen = strlen( lpPacketStr );
        SendPacket = (SENDPACKET)PESendJmp;
        PACKET Packet;
        Packet.Null = 0;
        Packet.Null2 = 0;      
        Packet.nSize = stLen/2;
        byte bPacket[150];
        Packet.lpData = atohx((char*)bPacket, lpPacketStr);
 
        _asm
        {
                mov ecx, PEClass
                mov ecx, [ecx]
        }
        SendPacket( &Packet );
}
 
void WINAPI msSendBuffer(__inout LPVOID lpPacket, __in SIZE_T cb)
{
        SendPacket = (SENDPACKET)PESendJmp;
        PACKET Packet;
        ZeroMemory(&Packet, sizeof(PACKET));
        Packet.nSize = cb;
        Packet.lpData = lpPacket;
        _asm
        {
                mov ecx, PEClass
                mov ecx, [ecx]
        }
        SendPacket( &Packet );
}
 
BOOL WINAPI IsPacketSniffed()
{
        HMODULE         hWS2_32 = GetModuleHandleA("WS2_32.dll");
        if (!hWS2_32)
                return FALSE;
        byte*           f_send = (byte*)GetProcAddress(hWS2_32, "send");
        if (!f_send)
                return FALSE;
        if (*f_send == 0xE9)
                return TRUE;
        byte*           f_mssend = (byte*)SendAddy;
        if (!f_mssend)
                return FALSE;
        if (*f_mssend == 0xE9)
                return TRUE;
}
