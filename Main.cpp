#include <Windows.h>
#include <WinInet.h>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "Main.h"
#include "Func.h"
#include "Pointers.h"
#pragma comment (lib, "WinInet.lib")
#pragma comment(lib, "urlmon.lib")
using namespace std;
extern int Main();
//Get() Function
//--------------------------------------------------------------------

int GetCharHp()
{
	return(int)ReadPointer(ulStatBase, ulHpOffset);
}

int GetCharMp()
{
	return(int)ReadPointer(ulStatBase, ulMpOffset);
}

double GetExp()
{
    return ReadDOUBLEPointer(ulStatBase, ulExpOffset);
}

int GetCharX()
{
	return(int)ReadPointer(ulCharRelated, ulCharItemX);
}

int GetCharY()
{
	return(int)ReadPointer(ulCharRelated, ulCharItemY);
}

int GetAnimationDelay()
{
	return(int)ReadPointer(ulCharRelated, ulAnimationDelay);
}

int GetAnimationToggle()
{
	return(int)ReadPointer(ulCharRelated, ulAnimationToggle);
}

int GetMouseX()
{
	int RealMouse = 0;
	RealMouse = *((DWORD*)ulMouseBase) + ulMouseLocation;
	return (int)ReadPointer(RealMouse, ulMouseXOffset);
}

int GetMouseY()
{
	int RealMouse = 0;
	RealMouse = *((DWORD*)ulMouseBase) + ulMouseLocation;
	return (int)ReadPointer(RealMouse, ulMouseYOffset);
}

int GetMapId()
{
	return (int)ReadPointer(ulMapBase, ulMapOffset);
}

int GetAttackCount()
{
	return (int)ReadPointer(ulCharRelated, ulAttackCount);
}

int GetPeopleCount()
{
	return (int)ReadPointer(ulPeopleBase, ulPeopleOffset);
}

int GetMobCount()
{
	return (int)ReadPointer(ulMobBase, ulMobCountOffset);
}

int GetBreathCount()
{
	return (int)ReadPointer(ulCharRelated , ulBreathCount);
}

int GetItemCount()
{
	return (int)ReadPointer(ulItemBase , ulItemOffset);
}

int GetLeftWall()
{
	return (int)ReadPointer(ulWallBase , ulLeftWallOffset);
}

int GetRightWall()
{
	return (int)ReadPointer(ulWallBase , ulRightWallOffset);
}

int GetTopWall()
{
	return (int)ReadPointer(ulWallBase , ulTopWallOffset);
}

int GetBottomWall()
{
	return (int)ReadPointer(ulWallBase , ulBottomWallOffset);
}

int GetCurrentChannel()
{
	return (int)ReadPointer(ulServerBase , ulChannelOffset);
}

int GetCurrentWorld()
{
	return (int)ReadPointer(ulServerBase , ulChannelOffset);
}

int GetMobX()
{
	DWORD Mob1;
	DWORD Mob2;
	DWORD Mob3;
	DWORD Mob4;
	Mob1 = *((DWORD*)ulMobBase) + ulMobOffset1;
	Mob2 = *((DWORD*)Mob1) + ulMobOffset2;
	Mob3 = *((DWORD*)Mob2) + ulMobOffset3;
	Mob4 = *((DWORD*)Mob3) + ulMobOffset4;
	return (int)ReadPointer(Mob4 , ulMobXOffset);
}

int GetMobY()
{
	DWORD Mob1;
	DWORD Mob2;
	DWORD Mob3;
	DWORD Mob4;
	Mob1 = *((DWORD*)ulMobBase) + ulMobOffset1;
	Mob2 = *((DWORD*)Mob1) + ulMobOffset2;
	Mob3 = *((DWORD*)Mob2) + ulMobOffset3;
	Mob4 = *((DWORD*)Mob3) + ulMobOffset4;
	return (int)ReadPointer(Mob4 , ulMobYOffset);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
//Hacks Function

//Teleport Function
__inline void Teleport(int CharX, int CharY)
{
	WritePointer(ulCharRelated, ulTeleOffset  + 8, CharX );
	WritePointer(ulCharRelated, ulTeleOffset  + 12, CharY );
	WritePointer(ulCharRelated, ulTeleOffset , 1);
}

//Morph Hack
bool bMorph , bAntiMorph , bMorphHack = false;
extern int iMorphId;
void MorphHack()
{
	while(bMorph)
	{
    	while(bAntiMorph)
    	{
			if(ReadPointer(ulCharRelated, ulMorphOffset) == 0)
			{
				NULL;
			}
			if(ReadPointer(ulCharRelated, ulMorphOffset) != 0)
    		{
    			WritePointer(ulCharRelated, ulMorphOffset , 0);
     	    	Sleep(1);
    		}
    	}
		while(bMorphHack)
    	{
    		if(ReadPointer(ulCharRelated, ulMorphOffset) != iMorphId)
    		{
    			WritePointer(ulCharRelated, ulMorphOffset , iMorphId);
     	    	Sleep(1);
    		}
    	}
	}
}

//NoBreath
bool bNoBreath = false;
void NoBreath()
{
	while(bNoBreath == true)
	{
		WritePointer(ulCharRelated, ulBreathCount , 0);
		Sleep(1);
	}
}

//FLACC < Always Face Left >
bool bFLACC = false;
void FLACC()
{
	while(bFLACC == true)
	{
		WritePointer(ulCharRelated, ulCharFacingOffset , 0);
		Sleep(1);
	}
}

//iEatSteroids
bool biEatSteroids = false;
void iEatSteroids()
{
	while(biEatSteroids == true)
	{
		WritePointer(ulCharRelated, ulAnimationDelay2 , 0);
		Sleep(1);
	}
}

//Wall Vac
bool iEWV = false;
bool bWallVacHookCharXY = false;
void WallVacHookCharXY()
{
	while(bWallVacHookCharXY == true)
	{
		WritePointer(ulWallBase , ulLeftWallOffset ,  GetCharX());
		WritePointer(ulWallBase , ulRightWallOffset ,  GetCharX());
		WritePointer(ulWallBase , ulTopWallOffset ,  GetCharY());
		WritePointer(ulWallBase , ulBottomWallOffset ,  GetCharY());
		Sleep(1);
	}
}

extern int WallVacCustomX , WallVacCustomY;
bool bWallVacCustomXY = false;
void WallVacCustomXY()
{
	while(bWallVacCustomXY == true)
	{
		WritePointer(ulWallBase , ulLeftWallOffset ,  WallVacCustomX);
		WritePointer(ulWallBase , ulRightWallOffset ,  WallVacCustomX);
		WritePointer(ulWallBase , ulTopWallOffset ,  WallVacCustomY);
		WritePointer(ulWallBase , ulBottomWallOffset ,  WallVacCustomY);
		Sleep(1);
	}
}

//SSMouseFly
bool bSSMouseFly , iESSMF = false;
void SSMouseFly()
{
	while(bSSMouseFly == true)
	{
    	Teleport(GetMouseX(),GetMouseY());
   	    Sleep(1);
	}
}

//Offmap
bool bOffMap , bB4OffMap , iEOM = false;
extern int iPplCount;
extern int iiOriginalX , iiOriginalY ;
void OffMap()
{
	while(bOffMap == true)
	{
		if(GetPeopleCount() >= iPplCount)
		{
			bB4OffMap = false;
        	Teleport((GetLeftWall() - 1000),(GetTopWall() - 1000));
   	        Sleep(1);
		}
		else
		{
			Teleport(iiOriginalX,iiOriginalY);
			bB4OffMap = true;
			NewThread(B4OffMap);
			TerminateThread(OffMap, 0);
			Sleep(1);
		}
	}
}

void B4OffMap()
{
	while(bB4OffMap == true)
	{
		if(GetPeopleCount() >= iPplCount)
		{
        	bOffMap = true;
   	        NewThread(OffMap);
			TerminateThread(B4OffMap, 0);
			Sleep(1);
		}
		else
		{
			bOffMap = false;
			iiOriginalX = GetCharX();
			iiOriginalY = GetCharY();
			Sleep(1);
		}
	}
}

//RefreshMap
int iCharX , iCharY = 0;
bool bRefreshMap = false;
void RefreshMap()
{
	while(bRefreshMap == true)
	{
		iCharX = GetCharX();
		iCharY = GetCharY();
        Teleport(GetLeftWall(),GetBottomWall());
   	    Sleep(5000);
		Teleport(iCharX,iCharY);
		bRefreshMap = false;
	}
}

//Auto Refresh Map
int iRMCharX , iRMCharY = 0;
extern int iARMDelay , iARMAC;
extern bool bAutoRefreshMapDelay , bAutoRefreshMapAC ;
bool bAutoRefreshMap ,bAfterAutoRefreshMap = false;
void AutoRefreshMap()
{
	while(bAutoRefreshMap == true)
	{
        Teleport(GetCharX(),GetBottomWall());
		bAfterAutoRefreshMap = true;
   	    Sleep(5000);
		Teleport(iRMCharX,iRMCharY);
		bAutoRefreshMap = false;
	}
}

void AfterAutoRefreshMap()
{
	while(bAfterAutoRefreshMap == true)
	{
		while(bAutoRefreshMapDelay == true)
		{
			Sleep(iARMDelay);
		    iRMCharX = GetCharX();
		    iRMCharY = GetCharY();
		    bAutoRefreshMap = true;
			NewThread(AutoRefreshMap);
			bAfterAutoRefreshMap = false;
		}
		while(bAutoRefreshMapAC == true)
    	{
	    	if(GetAttackCount() >= iARMAC)
	    	{
				Sleep(750);
	    		iRMCharX = GetCharX();
	            iRMCharY = GetCharY();
	            bAutoRefreshMap = true;
		    	NewThread(AutoRefreshMap);
			    bAfterAutoRefreshMap = false;
		    }
    	}
	}
}

//Kami loot
extern bool bKamiLoot , bB4KamiLoot , iEKL ;
extern int iLootReq , itemX , itemY , iiCharX , iiCharY ;
void KamiLoot()
{
	while(bKamiLoot == true)
	{
		if(GetItemCount() >= iLootReq)
		{
			bB4KamiLoot = false;
	    	Teleport(itemX,itemY);
			Sleep(1);
		}
		else
		{
			Teleport(iiCharX,iiCharY);
			bB4KamiLoot = true;
			NewThread(B4KamiLoot);
			TerminateThread(KamiLoot, 0);
			Sleep(1);
		}
	}
}
void B4KamiLoot()
{
	while(bB4KamiLoot == true)
	{
		if(GetItemCount() >= iLootReq)
		{
        	bKamiLoot = true;
   	        NewThread(KamiLoot);
			TerminateThread(B4KamiLoot, 0);
			Sleep(1);
		}
		else
		{
			bKamiLoot = false;
			iiCharX = GetCharX();
			iiCharY = GetCharY();
			Sleep(1);
		}
	}
}

//Kami Vac
extern bool iCheckForCC;
bool bKamiVac , iEKV = false;
bool bB4KamiVac = false;
extern int iMobCount , PlusRangeX , PlusRangeY , iOriginalX , iOriginalY;
void KamiVac()
{
	while(bKamiVac == true)
	{
		if(iCheckForCC == false)
		{
		if(GetMobCount() >= iMobCount)
		{
			bB4KamiVac = false;
	    	Teleport((GetMobX()+PlusRangeX),(GetMobY()+PlusRangeY));
			Sleep(1);
		}
		else
		{
			Teleport(iOriginalX,iOriginalY);
			bB4KamiVac = true;
			NewThread(B4KamiVac);
			TerminateThread(KamiVac, 0);
			Sleep(1);
		}
		}
		else if(iCheckForCC == true)
		{
			Teleport(iOriginalX,iOriginalY);
			Sleep(5500);
			iCheckForCC = false;
		}
	}
}

void B4KamiVac()
{
	while(bB4KamiVac == true)
	{
		if(iCheckForCC == false)
		{
		if(GetMobCount() >= iMobCount)
		{
        	bKamiVac = true;
   	        NewThread(KamiVac);
			TerminateThread(B4KamiVac, 0);
			Sleep(1);
		}
		else
		{
			bKamiVac = false;
			iOriginalX = GetCharX();
			iOriginalY = GetCharY();
			Sleep(1);
		}
		}
		else if(iCheckForCC == true)
		{
			Teleport(iOriginalX,iOriginalY);
			Sleep(5500);
			iCheckForCC = false;
		}
	}
}

//Super Tubi
extern bool eSuperTubi;
void SuperTubi()
{
	while(eSuperTubi == true)
	{
		WritePointer(ulServerBase , ulTubiOffset , 0);
		Sleep(1);
	}
}

//CC Stuff


//-------------------------------------------------------------------
//--------------------------------------------------------------------
//Hotkeys
bool eHotKeys = false;
void vHotKeys()
{
	while(eHotKeys == true)
	{
	if(GetAsyncKeyState(VK_F8))
	{
		if (iEOM == false)
		{
			iEOM = true;
			Sleep(150);
		}
		else
		{
			iEOM = false;
			Sleep(150);
		}
	}
	if(GetAsyncKeyState(VK_F9))
	{
		if (iEKL == false)
		{
			iEKL = true;
			Sleep(150);
		}
		else
		{
			iEKL = false;
			Sleep(150);
		}
	}
	if(GetAsyncKeyState(VK_F10))
	{
		if (iEKV == false)
		{
			iEKV = true;
			Sleep(150);
		}
		else
		{
			iEKV = false;
			Sleep(150);
		}
	}
	if(GetAsyncKeyState(VK_F11))
	{
		if (iEWV == false)
		{
			iEWV = false;
			Sleep(150);
		}
		else
		{
			iEWV = false;
			Sleep(150);
		}
	}
	if(GetAsyncKeyState(VK_F12))
	{
		if (iESSMF == false)
		{
			iESSMF = true;
			Sleep(150);
		}
		else
		{
			iESSMF = false;
			Sleep(150);
		}
	}
	}
}
//--------------------------------------------------------------------


//-------------------------------------------------------------------
//In-Game data info hook
int MouseX , MouseY , Breath , AttackCount , MapID , PeopleCount , HP , MP ,  ItemX , ItemY , MobCount , ItemCount , Channel = 0;
double Exp = 0;
void InfoHook()
{
	for(;;)
	{
		HP = GetCharHp();
		MP = GetCharMp();
		Exp = GetExp();
		MobCount = GetMobCount();
		MapID = GetMapId();
		PeopleCount = GetPeopleCount();
		Breath = GetBreathCount();
		AttackCount = GetAttackCount();
		MouseX = GetMouseX();
		MouseY = GetMouseY();
		ItemX = GetCharX();
		ItemY = GetCharY();
		ItemCount = GetItemCount();
		Channel = GetCurrentChannel();
		Sleep (1);
	}
}

char *convertStringToChar(const string &str)
{
	char *retPtr(new char[str.length() + 1]);
	copy(str.begin(), str.end(), retPtr);
	retPtr[str.length()] = '\0';
	return retPtr;
}

//Check if folder exists , if not , make one
void FolderExists()
{
	if(CreateDirectory("C:\\PiezTrainer\\", NULL))
	{
		CreateDirectory("C:\\PiezTrainer\\Settings\\", NULL);
	}
	else
	{
		CreateDirectory("C:\\PiezTrainer\\Settings\\", NULL);
	}
}

void WINAPI MainThread( )
{
	FolderExists();
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&InfoHook, NULL, 0, NULL);
    Main();	
}

BOOL WINAPI DllMain ( HMODULE hModule, DWORD dwReason, LPVOID lpvReserved )
{
    switch ( dwReason ) {
        case DLL_PROCESS_ATTACH:

            DisableThreadLibraryCalls(hModule);

            if ( CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&MainThread, NULL, 0, NULL) == NULL ) 
			{
                return FALSE;
            }
            break;
            
        case DLL_PROCESS_DETACH:
            break;

        case DLL_THREAD_ATTACH:
            break;

        case DLL_THREAD_DETACH:
            break;
    }
    return TRUE;
}

//-------------------------------------------------------------------