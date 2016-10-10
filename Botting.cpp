#include <Windows.h>
#include "Main.h"
#include "Pointers.h"
#include "Func.h"
#include "Botting.h"
extern bool iCheckForCC;

//Sendkeys Function < Down >
void msSendDownKey(wchar_t MyDownKey)
{
	HWND MShWnd;
	MShWnd = FindProcessWindow();
	LPARAM lparam = ( MapVirtualKey( MyDownKey, 0 ) << 16 ) + 1;
	PostMessage(MShWnd, WM_KEYDOWN, MyDownKey, MapVirtualKey(MyDownKey, 0) << 16);
}

//Sendkeys Function < Up >
void msSendUpKey(wchar_t MyUpKey)
{
	HWND MShWnd;
	MShWnd = FindProcessWindow();
	LPARAM lparam = ( MapVirtualKey( MyUpKey, 0 ) << 16 ) + 1;
	PostMessage(MShWnd, WM_KEYUP, MyUpKey, MapVirtualKey(MyUpKey, 0) << 16);
}

//-------------------------------------------Attack-------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------


HWND MShWnd;
extern DWORD iAttackDelay;
extern DWORD iMobCount;
extern wchar_t cAttackKey;
//Normal Attack
void Attack()
{
	for (; ; Sleep(iAttackDelay))
	{
		if(iCheckForCC == false)
    	{
	    	if (iMobCount <= GetMobCount())
    		{
        		msSendDownKey(cAttackKey);
	    	}
    	}
    	else if (iCheckForCC == true)
    	{
    		Sleep(5500);
    		iCheckForCC = false;
    	}
	}
}

//Double Swing
void DSAttack()
{
	for (; ; Sleep(iAttackDelay))
	{
		if(iCheckForCC == false)
    	{
    		if (iMobCount <= GetMobCount())
    		{
				msSendDownKey(cAttackKey);
				Sleep(50);
				msSendUpKey(cAttackKey);
				Sleep(50);
				msSendDownKey(cAttackKey);
				Sleep(50);
				msSendUpKey(cAttackKey);
			}
		}
		else if (iCheckForCC == true)
    	{
    		Sleep(5500);
    		iCheckForCC = false;
    	}
	}
}

//Triple Swing
void TSAttack()
{
	MShWnd = FindProcessWindow();
	for (; ; Sleep(iAttackDelay))
	{
		if(iCheckForCC == false)
		{
			if (iMobCount <= GetMobCount())
			{
				msSendDownKey(cAttackKey);
				Sleep(50);
				msSendUpKey(cAttackKey);
				Sleep(50);
				msSendDownKey(cAttackKey);
				Sleep(50);
				msSendUpKey(cAttackKey);
				Sleep(50);
				msSendDownKey(cAttackKey);
				Sleep(50);
				msSendUpKey(cAttackKey);
			}
		}
		else if (iCheckForCC == true)
		{
			Sleep(5500);
			iCheckForCC = false;
		}
	}
}

//Charge Attack
void ChargeAttack()
{
	MShWnd = FindProcessWindow();
	for (; ; Sleep(50))
	{
		if (iCheckForCC == false)
		{
			if (iMobCount <= GetMobCount())
			{
   		 		msSendDownKey(cAttackKey);
				Sleep(iAttackDelay);
				msSendUpKey(cAttackKey);
			}
		}
		else if (iCheckForCC == true)
		{
			Sleep(5500);
			iCheckForCC = false;
		}
	}
}

//-------------------------------------------------------------------------------------------------

//---------------------------------------------Skill---------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

//Skill1
extern bool iSkill1;
extern DWORD SkillDelay;
extern wchar_t MySkill1;
void USkill1()
{
	 while(iSkill1)
	{
        msSendDownKey(MySkill1);
        Sleep(50);
        msSendUpKey(MySkill1);
		Sleep(SkillDelay);
	}
}

//Skill2
extern bool iSkill2;
extern DWORD SkillDelay2;
extern wchar_t MySkill2;
void USkill2()
{
	HWND MapleHWND = FindProcessWindow();
	while(iSkill2)
	{
        	msSendDownKey(MySkill2);
        	Sleep(1);
        	msSendUpKey(MySkill2);
			Sleep(SkillDelay2);
	}
}

//Skill3
extern bool iSkill3;
extern DWORD SkillDelay3;
extern wchar_t MySkill3;
void USkill3()
{
	 HWND MapleHWND = FindProcessWindow();
	 while(iSkill3)
	 {
        	msSendDownKey(MySkill3);
        	Sleep(1);
        	msSendUpKey(MySkill3);
			Sleep(SkillDelay3);
	}
}

//Skill4
extern bool iSkill4;
extern DWORD SkillDelay4;
extern wchar_t MySkill4;
void USkill4()
{
	HWND MapleHWND = FindProcessWindow();
	while(iSkill4)
	{
        msSendDownKey(MySkill4);
        Sleep(1);
        msSendUpKey(MySkill4);
		Sleep(SkillDelay4);
	}
}

//-------------------------------------------------------------------------------------------------

//---------------------------------------------Loot---------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

//AutoLoot
extern DWORD LootD;
extern DWORD ICount;
extern wchar_t Skill1;
extern bool NoLoot;
void Loot()
{
    	while(!NoLoot)
    	{
			if(iCheckForCC == false)
    	{
        		if(ICount <= GetItemCount())
        		{
            	    msSendDownKey(Skill1);
        	        Sleep(1);
        	        msSendUpKey(Skill1);
	        	}
	        	Sleep(LootD);
	    }
		else if(iCheckForCC == true)
    	{
    		Sleep(5500);
    		iCheckForCC = false;
    	}
    }
}

//-------------------------------------------------------------------------------------------------

//---------------------------------------------Pot---------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

//AutoHp
extern bool AutoHp;
extern DWORD HpCount;
extern wchar_t HpPotKey;
void ValuedPotterHP()
{
	while (AutoHp)
	{
		Sleep (1000);
		if (HpCount >= ReadPointer(ulStatBase ,ulHpOffset))	
		{
			msSendDownKey(HpPotKey);
			msSendUpKey(HpPotKey);
			Sleep (200);
		}				
	}
}

//AutoMp
extern DWORD MpCount;
extern wchar_t MpPotKey;
extern bool AutoMp;
void ValuedPotterMP()
{
	while(AutoMp)
	{
		Sleep (1000);
		if (MpCount >= ReadPointer(ulStatBase ,ulMpOffset))	
		{
			msSendDownKey(MpPotKey);
			msSendUpKey(MpPotKey);
			Sleep (200);
		}				
	}
}

//-------------------------------------------------------------------------------------------------