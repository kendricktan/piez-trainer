#include <Windows.h>
#include "Form2.h"
#include "Botting.h"
#include "Func.h"
#include "Main.h"
#include "Pointers.h"
using namespace PiezTrainer;

//SS Mouse Fly
extern bool bSSMouseFly , iESSMF;
void Form2::checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox3->Checked == true)
	{
		iESSMF = true;
		bSSMouseFly = true;
		NewThread(SSMouseFly);
	}
	else if(this->checkBox3->Checked == false)
	{
		iESSMF = false;
		bSSMouseFly = false;
		TerminateThread(SSMouseFly, 0);
	}
}

//FLACC ( Always Face Left )
extern bool bFLACC;
void Form2::checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox4->Checked == true)
	{
		bFLACC = true;
		NewThread(FLACC);
	}
	else if(this->checkBox4->Checked == false)
	{
		bFLACC = false;
		TerminateThread(FLACC,0);
	}
}

//WallVac
extern bool iEWV;
extern bool bWallVacHookCharXY , bWallVacCustomXY;
void Form2::checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox6->Checked == true)
	{
		iEWV = true;
		if(this->radioButton1->Checked == true)
		{
			bWallVacHookCharXY = true;
			NewThread(WallVacHookCharXY);
		}
		else 
		{
			bWallVacCustomXY = true;
			NewThread(WallVacCustomXY);
		}
	}
	else if(this->checkBox6->Checked == false)
	{
		iEWV = false;
		bWallVacHookCharXY = false;
		bWallVacCustomXY = false;
		TerminateThread(WallVacHookCharXY,0);
		TerminateThread(WallVacCustomXY,0);
	}
}

void Form2::radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->radioButton1->Checked == true)
	{
		textBox4->Enabled = false;
		textBox5->Enabled = false;
	}
	else if (this->radioButton1->Checked == true && this->checkBox6->Checked == true && bWallVacHookCharXY == false)
	{
		bWallVacCustomXY = false;
		TerminateThread(WallVacCustomXY,0);
		bWallVacHookCharXY = true;	
		NewThread(WallVacHookCharXY);
	}
}

void Form2::radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->radioButton2->Checked == true)
	{
		textBox4->Enabled = true;
		textBox5->Enabled = true;
	}
	else if (this->radioButton2->Checked == true && this->checkBox6->Checked == true && bWallVacCustomXY == false)
	{
		bWallVacHookCharXY = false;	
		TerminateThread(WallVacHookCharXY,0);
		bWallVacCustomXY = true;
		NewThread(WallVacCustomXY);
	}
}

int WallVacCustomX , WallVacCustomY = 0;
void Form2::textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(textBox4->Text->Length != NULL)
	{
    	WallVacCustomX = Convert::ToInt32(this->textBox4->Text);
	}
}

void Form2::textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(textBox5->Text->Length != NULL)
	{
    	WallVacCustomY = Convert::ToInt32(this->textBox5->Text);
	}
}

void Form2::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->textBox4->Text = Convert::ToString(GetCharX());
	this->textBox5->Text = Convert::ToString(GetCharY());
}

//Kami Loot
int itemX , itemY , iLootReq , iiCharX , iiCharY = 0;
const unsigned long ItemXYHookAddy = 0x12345;
bool bKamiLoot , bB4KamiLoot , iEKL = false;
unsigned long ulPtInRect;
void __declspec(naked) ItemHookAsm()
{
	__asm
	{
		push eax
		mov eax,[esp+0x0C]
		mov [itemX],eax
		mov eax,[esp+0x10]
		mov [itemY],eax
		pop eax
		jmp dword ptr [ulPtInRect]
   }
}

void Form2::checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox2->Checked == true)
	{
		iEKL = true;
		iiCharX = GetCharX();
		iiCharY = GetCharY();
		iLootReq = Convert::ToInt32(textBox2->Text);
		ulPtInRect = (unsigned long)GetProcAddress(GetModuleHandle("user32.dll"), "PtInRect");
		*(unsigned long*)ItemXYHookAddy = (unsigned long)ItemHookAsm;
		bB4KamiLoot = true;
		NewThread(B4KamiLoot);
	}
	else if(this->checkBox2->Checked == false)
	{
		iEKL = false;
		bKamiLoot = false;
		bB4KamiLoot = false;
		TerminateThread(KamiLoot,0);
		TerminateThread(B4KamiLoot,0);
		Teleport(iiCharX , iiCharY);
	}
}

//Items Required Till Kami Loots Enabled
void Form2::textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(textBox2->Text->Length != NULL)
	{
    	iLootReq = Convert::ToInt32(this->textBox2->Text);
	}
}

//Kami Vac
extern bool bKamiVac , bB4KamiVac , iEKV;
int iMobCount = 0;
int PlusRangeX = -50; 
int PlusRangeY = 0;
int iOriginalX = 0;
int iOriginalY = 0;
void Form2::checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox1->Checked == true)
	{
		iEKV = true;
		bB4KamiVac = true;
		iMobCount = Convert::ToInt32(textBox1->Text);
		NewThread(B4KamiVac);
		iOriginalX = GetCharX();
		iOriginalY = GetCharY();
	}
	else if(this->checkBox1->Checked == false)
	{
		iEKV = false;
		bKamiVac = false;
		bB4KamiVac = false;
		TerminateThread(KamiVac, 0);
		TerminateThread(B4KamiVac, 0);
		Teleport(iOriginalX,iOriginalY);
	}
}

//Mob Count Required To Activate Kami Vac
void Form2::textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(textBox1->Text->Length != NULL)
	{
    	iMobCount = Convert::ToInt32(this->textBox1->Text);
	}
}

// Difference in X Range < Kami Vac >
void Form2::trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	PlusRangeX = this->trackBar1->Value;
}

// Difference in Y Range < Kami Vac >
void Form2::trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	PlusRangeY = this->trackBar2->Value;
}

//OffMap
extern bool bOffMap , bB4OffMap , iEOM;
int iPplCount = 0;
int iiOriginalX , iiOriginalY = 0;
void Form2::checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox5->Checked == true)
	{
		iPplCount = Convert::ToInt32(textBox3->Text);
		iiOriginalX = GetCharX();
		iiOriginalY = GetCharY();
		iEOM = true;
		bB4OffMap = true;
		NewThread(B4OffMap);
	}
	else if(this->checkBox5->Checked == false)
	{
		iEOM = false;
		bOffMap = false;
		bB4OffMap = false;
		TerminateThread(OffMap, 0);
		TerminateThread(B4OffMap, 0);
		Teleport(iiOriginalX,iiOriginalY);
	}
}

//People Count Till OffMap Enables
void Form2::textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(textBox3->Text->Length != NULL)
	{
    	iPplCount = Convert::ToInt32(this->textBox3->Text);
	}
}

//iEatSteroids
extern bool biEatSteroids;
void Form2::checkBox9_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox9->Checked == true)
	{
		biEatSteroids = true;
		NewThread(iEatSteroids);
	}
	else if(this->checkBox9->Checked == false)
	{
		biEatSteroids = false;
		TerminateThread(iEatSteroids,0);
	}
}

//Morph Hack
extern bool bMorph , bAntiMorph , bMorphHack;
int iMorphId = 111;
void Form2::checkBox8_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox8->Checked == true)
	{
		if(this->radioButton5->Checked ==  true)
    	{
        	bMorphHack = false;
	    	bAntiMorph = true;
    	}
		if(this->radioButton6->Checked ==  true)
    	{
        	bAntiMorph = false;
	    	bMorphHack = true;
		}
		bMorph = true;
		NewThread(MorphHack);
	}
	else
	{
		bMorph = false;
		bAntiMorph = false; 
		bMorphHack = false;
		TerminateThread(MorphHack,0);
	}
}

void Form2::radioButton5_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(radioButton5->Checked ==  true)
	{
		if(this->checkBox8->Checked == true)
		{
        	bMorphHack = false;
	    	bAntiMorph = true;
		}
		else
		{
			bMorph = false;
	    	bAntiMorph = false; 
	    	bMorphHack = false;
			TerminateThread(MorphHack,0);
		}
	}
}

void Form2::radioButton6_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(radioButton6->Checked ==  true)
	{
		if(this->checkBox8->Checked == true)
		{
        	bAntiMorph = false;
	    	bMorphHack = true;
		}
		else
		{
			bMorph = false;
	    	bAntiMorph = false; 
	    	bMorphHack = false;
			TerminateThread(MorphHack,0);
		}
	}
}

void Form2::textBox8_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(textBox8->Text->Length != NULL)
	{
    	iMorphId = Convert::ToInt32(this->textBox8->Text);
	}
}

//No Breath
extern bool bNoBreath;
void Form2::checkBox10_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox10->Checked == true)
	{
		bNoBreath = true;
		NewThread(NoBreath);
	}
	else if(this->checkBox10->Checked == false)
	{
		bNoBreath = false;
		TerminateThread(NoBreath, 0);
	}
}

//Super Tubi
bool eSuperTubi = false;
void Form2::checkBox19_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox19->Checked == true)
	{
		eSuperTubi = true;
		NewThread(SuperTubi);
	}
	else if(this->checkBox19->Checked == false)
	{
		eSuperTubi = false;
		TerminateThread(SuperTubi, 0);
	}
}

//Refresh Map
extern bool bRefreshMap;
void Form2::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	bRefreshMap = true;
	NewThread (RefreshMap);
}

//Auto Refresh Map
int iARMDelay , iARMAC = 0;
bool bAutoRefreshMapDelay , bAutoRefreshMapAC = false;
extern int iRMCharX , iRMCharY;
extern bool bAutoRefreshMap , bAfterAutoRefreshMap ;
void Form2::checkBox7_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox7->Checked == true)
	{
		iARMDelay = Convert::ToInt32(this->textBox6->Text);
		iARMAC = Convert::ToInt32(this->textBox7->Text);
		if(radioButton3->Checked ==  true)
    	{
	    	bAutoRefreshMapAC = true;
			bAfterAutoRefreshMap = true;
			NewThread(AfterAutoRefreshMap);
    	}
		if(radioButton4->Checked ==  true)
    	{
	    	bAutoRefreshMapDelay = true;
			bAfterAutoRefreshMap = true;
			NewThread(AfterAutoRefreshMap);
    	}
	}
	else if(this->checkBox7->Checked == false)
	{
		bAutoRefreshMapAC = false;
		bAutoRefreshMapDelay = false;
		bAutoRefreshMap = false;
		bAfterAutoRefreshMap = false;
		TerminateThread(AfterAutoRefreshMap,0);
		TerminateThread(AutoRefreshMap,0);
	}
}

//RefreshMap Delay
void Form2::textBox7_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(textBox7->Text->Length != NULL)
	{
    	iARMDelay = Convert::ToInt32(this->textBox7->Text);
	}
}

//RefreshMap Attack Count
void Form2::textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(textBox6->Text->Length != NULL)
	{
    	iARMAC = Convert::ToInt32(this->textBox6->Text);
	}
}

//Choose AutoRefreshMap Via Attack Count
void Form2::radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(radioButton3->Checked ==  true)
	{
		if(this->checkBox7->Checked == true)
		{
        	bAutoRefreshMapDelay = false;
	    	bAutoRefreshMapAC = true;
		}
	}
}

//Choose AutoRefreshMap Via Delay
void Form2::radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(radioButton4->Checked ==  true)
	{
		if(this->checkBox7->Checked == true)
		{
	    	bAutoRefreshMapAC = false;
        	bAutoRefreshMapDelay = true;
		}
	}
}

//Hotkeys
extern bool eHotKeys;
void Form2::checkBox24_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox24->Checked == true)
	{
		eHotKeys = true;
		NewThread(vHotKeys);
	}
	else
	{
		eHotKeys = false;
		TerminateThread(vHotKeys, 0);
	}

}

//What Happens when Form2 Loads
void Form2::Form2_Load(System::Object^  sender, System::EventArgs^  e)
{
	this->radioButton1->Checked = true;
	this->radioButton4->Checked = true;
	this->radioButton6->Checked = true;
}

//Hotkey Interface Changer
void Form2::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	if(iEKL == true && this->checkBox2->Checked == false)
	{
		this->checkBox2->Checked = true;
	}
	else if (iEKL == false && this->checkBox2->Checked == true)
	{
		this->checkBox2->Checked = false;
	}
	if(iEOM == true && this->checkBox5->Checked == false)
	{
		this->checkBox5->Checked = true;
	}
	else if (iEOM == false && this->checkBox5->Checked == true)
	{
		this->checkBox5->Checked = false;
	}
	if(iESSMF == true && this->checkBox3->Checked == false)
	{
		this->checkBox3->Checked = true;
	}
	else if(iESSMF == false && this->checkBox3->Checked == true)
	{
		this->checkBox3->Checked = false;
	}
	if(iEKV == true && this->checkBox1->Checked == false)
	{
		this->checkBox1->Checked = true;
	}
	else if(iEKV == false && this->checkBox1->Checked == true)
	{
		this->checkBox1->Checked = false;
	}
	if(iEWV == true && this->checkBox6->Checked == false)
	{
		this->checkBox6->Checked = true;
	}
	else if(iEWV == false && this->checkBox6->Checked == true)
	{
		this->checkBox6->Checked = false;
	}
}