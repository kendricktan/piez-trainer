#include <Windows.h>
#include "Form4.h"
#include "Pointers.h"
#include "Botting.h"
#include "Main.h"
#include "Func.h"
using namespace PiezTrainer;

//Auto Hp
DWORD HpCount;
wchar_t HpPotKey;
bool AutoHp = false;
void Form4::checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox1->Checked == true)
	{
		AutoHp = true;
		HpCount = Convert::ToInt32(textBox1->Text);
		HpPotKey = Convert::ToChar(comboBox1->SelectedIndex);
		if (HpPotKey == 0)
		    HpPotKey = 0x41;
		else if (HpPotKey == 1)
			HpPotKey = 0x42;
		else if (HpPotKey == 2)
			HpPotKey = 0x43;
		else if (HpPotKey == 3)
			HpPotKey = 0x44;
		else if (HpPotKey == 4)
			HpPotKey = 0x45;
		else if (HpPotKey == 5)
			HpPotKey = 0x46;
		else if (HpPotKey == 6)
			HpPotKey = 0x47;
		else if (HpPotKey == 7)
			HpPotKey = 0x48;
		else if (HpPotKey == 8)
			HpPotKey = 0x49;
		else if (HpPotKey == 9)
			HpPotKey = 0x4A;
		else if (HpPotKey == 10)
			HpPotKey = 0x4B;
		else if (HpPotKey == 11)
			HpPotKey = 0x4C;
		else if (HpPotKey == 12)
			HpPotKey = 0x4D;
		else if (HpPotKey == 13)
			HpPotKey = 0x4E;
		else if (HpPotKey == 14)
			HpPotKey = 0x4F;
		else if (HpPotKey == 15)
			HpPotKey = 0x50;
		else if (HpPotKey == 16)
			HpPotKey = 0x51;
		else if (HpPotKey == 17)
			HpPotKey = 0x52;
		else if (HpPotKey == 18)
			HpPotKey = 0x53;
		else if (HpPotKey == 19)
			HpPotKey = 0x54;
		else if (HpPotKey == 20)
			HpPotKey = 0x55;
		else if (HpPotKey == 21)
			HpPotKey = 0x56;
		else if (HpPotKey == 22)
			HpPotKey = 0x57;
		else if (HpPotKey == 23)
			HpPotKey = 0x58;
		else if (HpPotKey == 24)
			HpPotKey = 0x59;
		else if (HpPotKey == 25)
			HpPotKey = 0x5A;
		else if (HpPotKey == 26)
			HpPotKey = 0x2D;
		else if (HpPotKey == 27)
			HpPotKey = 0x24;
		else if (HpPotKey == 28)
			HpPotKey = 0x2E;
		else if (HpPotKey == 29)
			HpPotKey = 0x23;
		else if (HpPotKey == 30)
			HpPotKey = 0x21;
		else if (HpPotKey == 31)
			HpPotKey = 0x22;
		else if (HpPotKey == 32)
			HpPotKey = 0x10;
		else if (HpPotKey == 33)
			HpPotKey = 0x11;
		else if (HpPotKey == 34)
			HpPotKey = 0x12;
		NewThread(ValuedPotterHP);
	}
	else if (checkBox1->Checked == false)
	{
		AutoHp = false;
	}
}

//Auto Mp
DWORD MpCount;
wchar_t MpPotKey;
bool AutoMp = false;
void Form4::checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox2->Checked == true)
	{
		AutoMp = true;
		MpCount = Convert::ToInt32(textBox2->Text);
		MpPotKey = Convert::ToChar(comboBox2->SelectedIndex);
		if (MpPotKey == 0)
		    MpPotKey = 0x41;
		else if (MpPotKey == 1)
			MpPotKey = 0x42;
		else if (MpPotKey == 2)
			MpPotKey = 0x43;
		else if (MpPotKey == 3)
			MpPotKey = 0x44;
		else if (MpPotKey == 4)
			MpPotKey = 0x45;
		else if (MpPotKey == 5)
			MpPotKey = 0x46;
		else if (MpPotKey == 6)
			MpPotKey = 0x47;
		else if (MpPotKey == 7)
			MpPotKey = 0x48;
		else if (MpPotKey == 8)
			MpPotKey = 0x49;
		else if (MpPotKey == 9)
			MpPotKey = 0x4A;
		else if (MpPotKey == 10)
			MpPotKey = 0x4B;
		else if (MpPotKey == 11)
			MpPotKey = 0x4C;
		else if (MpPotKey == 12)
			MpPotKey = 0x4D;
		else if (MpPotKey == 13)
			MpPotKey = 0x4E;
		else if (MpPotKey == 14)
			MpPotKey = 0x4F;
		else if (MpPotKey == 15)
			MpPotKey = 0x50;
		else if (MpPotKey == 16)
			MpPotKey = 0x51;
		else if (MpPotKey == 17)
			MpPotKey = 0x52;
		else if (MpPotKey == 18)
			MpPotKey = 0x53;
		else if (MpPotKey == 19)
			MpPotKey = 0x54;
		else if (MpPotKey == 20)
			MpPotKey = 0x55;
		else if (MpPotKey == 21)
			MpPotKey = 0x56;
		else if (MpPotKey == 22)
			MpPotKey = 0x57;
		else if (MpPotKey == 23)
			MpPotKey = 0x58;
		else if (MpPotKey == 24)
			MpPotKey = 0x59;
		else if (MpPotKey == 25)
			MpPotKey = 0x5A;
		else if (MpPotKey == 26)
			MpPotKey = 0x2D;
		else if (MpPotKey == 27)
			MpPotKey = 0x24;
		else if (MpPotKey == 28)
			MpPotKey = 0x2E;
		else if (MpPotKey == 29)
			MpPotKey = 0x23;
		else if (MpPotKey == 30)
			MpPotKey = 0x21;
		else if (MpPotKey == 31)
			MpPotKey = 0x22;
		else if (MpPotKey == 32)
			MpPotKey = 0x10;
		else if (MpPotKey == 33)
			MpPotKey = 0x11;
		else if (MpPotKey == 34)
			MpPotKey = 0x12;
		NewThread(ValuedPotterMP);
	}
		else if (checkBox2->Checked == false)
	{
		AutoMp = false;
	}
}

void Form4::Form4_Load(System::Object^  sender, System::EventArgs^  e) 
{
	this->comboBox1->SelectedIndex = 3;
	this->comboBox2->SelectedIndex = 5;
}
