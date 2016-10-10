#include <Windows.h>
#include "Form3.h"
#include "Func.h"
#include "Botting.h"
#include "Main.h"
#include "Pointers.h"
using namespace PiezTrainer;

//Empty Event .__.
void Form3::groupBox2_Enter(System::Object^  sender, System::EventArgs^  e)
{
}

//When The AutoAttack checkBox is check it determines what keys you chose , the delay , etc
HANDLE hAttack;
DWORD iAttackDelay;
DWORD iMobCount;
wchar_t cAttackKey;
void Form3::checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox1->Checked == true)
	{
		iMobCount = Convert::ToInt32(this->textBox1->Text);//MobCount
		iAttackDelay = Convert::ToInt32(this->textBox2->Text);//Attack Delay
		cAttackKey = Convert::ToChar(this->comboBox2->SelectedIndex);//What keys you chose
			if (cAttackKey == 0)
		    cAttackKey = 0x41;
		else if (cAttackKey == 1)
			cAttackKey = 0x42;
		else if (cAttackKey == 2)
			cAttackKey = 0x43;
		else if (cAttackKey == 3)
			cAttackKey = 0x44;
		else if (cAttackKey == 4)
			cAttackKey = 0x45;
		else if (cAttackKey == 5)
			cAttackKey = 0x46;
		else if (cAttackKey == 6)
			cAttackKey = 0x47;
		else if (cAttackKey == 7)
			cAttackKey = 0x48;
		else if (cAttackKey == 8)
			cAttackKey = 0x49;
		else if (cAttackKey == 9)
			cAttackKey = 0x4A;
		else if (cAttackKey == 10)
			cAttackKey = 0x4B;
		else if (cAttackKey == 11)
			cAttackKey = 0x4C;
		else if (cAttackKey == 12)
			cAttackKey = 0x4D;
		else if (cAttackKey == 13)
			cAttackKey = 0x4E;
		else if (cAttackKey == 14)
			cAttackKey = 0x4F;
		else if (cAttackKey == 15)
			cAttackKey = 0x50;
		else if (cAttackKey == 16)
			cAttackKey = 0x51;
		else if (cAttackKey == 17)
			cAttackKey = 0x52;
		else if (cAttackKey == 18)
			cAttackKey = 0x53;
		else if (cAttackKey == 19)
			cAttackKey = 0x54;
		else if (cAttackKey == 20)
			cAttackKey = 0x55;
		else if (cAttackKey == 21)
			cAttackKey = 0x56;
		else if (cAttackKey == 22)
			cAttackKey = 0x57;
		else if (cAttackKey == 23)
			cAttackKey = 0x58;
		else if (cAttackKey == 24)
			cAttackKey = 0x59;
		else if (cAttackKey == 25)
			cAttackKey = 0x5A;
		else if (cAttackKey == 26)
			cAttackKey = 0x2D;
		else if (cAttackKey == 27)
			cAttackKey = 0x24;
		else if (cAttackKey == 28)
			cAttackKey = 0x2E;
		else if (cAttackKey == 29)
			cAttackKey = 0x23;
		else if (cAttackKey == 30)
			cAttackKey = 0x21;
		else if (cAttackKey == 31)
			cAttackKey = 0x22;
		else if (cAttackKey == 32)
			cAttackKey = 0x10;
		else if (cAttackKey == 33)
			cAttackKey = 0x11;
		else if (cAttackKey == 34)
			cAttackKey = 0x12;
		if(this->comboBox1->SelectedIndex == 0)
		{
			hAttack = NewThread(Attack);
		}
		else if(this->comboBox1->SelectedIndex == 1)
		{
			hAttack = NewThread(DSAttack);
		}
		else if(this->comboBox1->SelectedIndex == 2)
		{
			hAttack = NewThread(TSAttack);
		}
		else if(this->comboBox1->SelectedIndex == 3)
		{
			hAttack = NewThread(ChargeAttack);
		}
	}
	else if (this->checkBox1->Checked == false)
	{
		TerminateThread(hAttack, 0);
	}
}

//Skill1
DWORD SkillDelay2;
wchar_t MySkill2;
bool iSkill2 = false;
void Form3::checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox2->Checked == true)
	{
		iSkill2 = true;
		SkillDelay2 = Convert::ToInt32(textBox3->Text);
		MySkill2 = Convert::ToChar(comboBox3->SelectedIndex);
		if (MySkill2 == 0)
		    MySkill2 = 0x41;
		else if (MySkill2 == 1)
			MySkill2 = 0x42;
		else if (MySkill2 == 2)
			MySkill2 = 0x43;
		else if (MySkill2 == 3)
			MySkill2 = 0x44;
		else if (MySkill2 == 4)
			MySkill2 = 0x45;
		else if (MySkill2 == 5)
			MySkill2 = 0x46;
		else if (MySkill2 == 6)
			MySkill2 = 0x47;
		else if (MySkill2 == 7)
			MySkill2 = 0x48;
		else if (MySkill2 == 8)
			MySkill2 = 0x49;
		else if (MySkill2 == 9)
			MySkill2 = 0x4A;
		else if (MySkill2 == 10)
			MySkill2 = 0x4B;
		else if (MySkill2 == 11)
			MySkill2 = 0x4C;
		else if (MySkill2 == 12)
			MySkill2 = 0x4D;
		else if (MySkill2 == 13)
			MySkill2 = 0x4E;
		else if (MySkill2 == 14)
			MySkill2 = 0x4F;
		else if (MySkill2 == 15)
			MySkill2 = 0x50;
		else if (MySkill2 == 16)
			MySkill2 = 0x51;
		else if (MySkill2 == 17)
			cAttackKey = 0x52;
		else if (MySkill2 == 18)
			MySkill2 = 0x53;
		else if (MySkill2 == 19)
			MySkill2 = 0x54;
		else if (MySkill2 == 20)
			MySkill2 = 0x55;
		else if (MySkill2 == 21)
			MySkill2 = 0x56;
		else if (MySkill2 == 22)
			MySkill2 = 0x57;
		else if (MySkill2 == 23)
			MySkill2 = 0x58;
		else if (MySkill2 == 24)
			MySkill2 = 0x59;
		else if (MySkill2 == 25)
			MySkill2 = 0x5A;
		else if (MySkill2 == 26)
			MySkill2 = 0x2D;
		else if (MySkill2 == 27)
			MySkill2 = 0x24;
		else if (MySkill2 == 28)
			MySkill2 = 0x2E;
		else if (MySkill2 == 29)
			MySkill2 = 0x23;
		else if (MySkill2 == 30)
			MySkill2 = 0x21;
		else if (MySkill2 == 31)
			MySkill2 = 0x22;
		else if (MySkill2 == 32)
			MySkill2 = 0x10;
		else if (MySkill2 == 33)
			MySkill2 = 0x11;
		else if (MySkill2 == 34)
			MySkill2 = 0x12;
		NewThread(USkill2);
	}
	else
	{
		iSkill2 = false;
		TerminateThread(USkill2, 0);
	}
}	

//Skill2
DWORD SkillDelay;
wchar_t MySkill1;
bool iSkill1 = false;
void Form3::checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox3->Checked == true)
	{
		iSkill1 = true;
		SkillDelay = Convert::ToInt32(this->textBox4->Text);
	    MySkill1 = Convert::ToChar(this->comboBox4->SelectedIndex);
		if (MySkill1 == 0)
		    MySkill1 = 0x41;
		else if (MySkill1 == 1)
			MySkill1 = 0x42;
		else if (MySkill1 == 2)
			MySkill1 = 0x43;
		else if (MySkill1 == 3)
			MySkill1 = 0x44;
		else if (MySkill1 == 4)
			MySkill1 = 0x45;
		else if (MySkill1 == 5)
			MySkill1 = 0x46;
		else if (MySkill1 == 6)
			MySkill1 = 0x47;
		else if (MySkill1 == 7)
			MySkill1 = 0x48;
		else if (MySkill1 == 8)
			MySkill1 = 0x49;
		else if (MySkill1 == 9)
			MySkill1 = 0x4A;
		else if (MySkill1 == 10)
			MySkill1 = 0x4B;
		else if (MySkill1 == 11)
			MySkill1 = 0x4C;
		else if (MySkill1 == 12)
			MySkill1 = 0x4D;
		else if (MySkill1 == 13)
			MySkill1 = 0x4E;
		else if (MySkill1 == 14)
			MySkill1 = 0x4F;
		else if (MySkill1 == 15)
			MySkill1 = 0x50;
		else if (MySkill1 == 16)
			MySkill1 = 0x51;
		else if (MySkill1 == 17)
			MySkill1 = 0x52;
		else if (MySkill1 == 18)
			MySkill1 = 0x53;
		else if (MySkill1 == 19)
			MySkill1 = 0x54;
		else if (MySkill1 == 20)
			MySkill1 = 0x55;
		else if (MySkill1 == 21)
			MySkill1 = 0x56;
		else if (MySkill1 == 22)
			MySkill1 = 0x57;
		else if (MySkill1 == 23)
			MySkill1 = 0x58;
		else if (MySkill1 == 24)
			MySkill1 = 0x59;
		else if (MySkill1 == 25)
			MySkill1 = 0x5A;
		else if (MySkill1 == 26)
			MySkill1 = 0x2D;
		else if (MySkill1 == 27)
			MySkill1 = 0x24;
		else if (MySkill1 == 28)
			MySkill1 = 0x2E;
		else if (MySkill1 == 29)
			MySkill1 = 0x23;
		else if (MySkill1 == 30)
			MySkill1 = 0x21;
		else if (MySkill1 == 31)
			MySkill1 = 0x22;
		else if (MySkill1 == 32)
			MySkill1 = 0x10;
		else if (MySkill1 == 33)
			MySkill1 = 0x11;
		else if (MySkill1 == 34)
			MySkill1 = 0x12;
		NewThread(USkill1);
	}
	else
	{
		iSkill1 = false;
		TerminateThread(USkill1, 0);
	}
}

//Skill3
DWORD SkillDelay3;
wchar_t MySkill3;
bool iSkill3 = false;
void Form3::checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox5->Checked == true)
	{
		iSkill3 = true;
		SkillDelay3 = Convert::ToInt32(this->textBox6->Text);
	    MySkill3 = Convert::ToChar(this->comboBox6->SelectedIndex);
		if (MySkill3 == 0)
		    MySkill3 = 0x41;
		else if (MySkill3 == 1)
			MySkill3 = 0x42;
		else if (MySkill3 == 2)
			MySkill3 = 0x43;
		else if (MySkill3 == 3)
			MySkill3 = 0x44;
		else if (MySkill3 == 4)
			MySkill3 = 0x45;
		else if (MySkill3 == 5)
			MySkill3 = 0x46;
		else if (MySkill3 == 6)
			MySkill3 = 0x47;
		else if (MySkill3 == 7)
			MySkill3 = 0x48;
		else if (MySkill3 == 8)
			MySkill3 = 0x49;
		else if (MySkill3 == 9)
			MySkill3 = 0x4A;
		else if (MySkill3 == 10)
			MySkill3 = 0x4B;
		else if (MySkill3 == 11)
			MySkill3 = 0x4C;
		else if (MySkill3 == 12)
			MySkill3 = 0x4D;
		else if (MySkill3 == 13)
			MySkill3 = 0x4E;
		else if (MySkill3 == 14)
			MySkill3 = 0x4F;
		else if (MySkill3 == 15)
			MySkill3 = 0x50;
		else if (MySkill3 == 16)
			MySkill3 = 0x51;
		else if (MySkill3 == 17)
			MySkill3 = 0x52;
		else if (MySkill3 == 18)
			MySkill3 = 0x53;
		else if (MySkill3 == 19)
			MySkill3 = 0x54;
		else if (MySkill3 == 20)
			MySkill3 = 0x55;
		else if (MySkill3 == 21)
			MySkill3 = 0x56;
		else if (MySkill3 == 22)
			MySkill3 = 0x57;
		else if (MySkill3 == 23)
			MySkill3 = 0x58;
		else if (MySkill3 == 24)
			MySkill3 = 0x59;
		else if (MySkill3 == 25)
			MySkill3 = 0x5A;
		else if (MySkill3 == 26)
			MySkill3 = 0x2D;
		else if (MySkill3 == 27)
			MySkill3 = 0x24;
		else if (MySkill3 == 28)
			MySkill3 = 0x2E;
		else if (MySkill3 == 29)
			MySkill3 = 0x23;
		else if (MySkill3 == 30)
			MySkill3 = 0x21;
		else if (MySkill3 == 31)
			MySkill3 = 0x22;
		else if (MySkill3 == 32)
			MySkill3 = 0x10;
		else if (MySkill3 == 33)
			MySkill3 = 0x11;
		else if (MySkill3 == 34)
			MySkill3 = 0x12;
		NewThread(USkill3);
	}
	else
	{
		iSkill3 = false;
		TerminateThread(USkill3, 0);
	}
}

//Skill4
DWORD SkillDelay4;
wchar_t MySkill4;
bool iSkill4 = false;
void Form3::checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox4->Checked == true)
	{
		iSkill4 = true;
		SkillDelay4 = Convert::ToInt32(this->textBox5->Text);
	    MySkill4 = Convert::ToChar(this->comboBox5->SelectedIndex);
		if (MySkill4 == 0)
		    MySkill4 = 0x41;
		else if (MySkill4 == 1)
			MySkill4 = 0x42;
		else if (MySkill4 == 2)
			MySkill4 = 0x43;
		else if (MySkill4 == 3)
			MySkill4 = 0x44;
		else if (MySkill4 == 4)
			MySkill4 = 0x45;
		else if (MySkill4 == 5)
			MySkill4 = 0x46;
		else if (MySkill4 == 6)
			MySkill4 = 0x47;
		else if (MySkill4 == 7)
			MySkill4 = 0x48;
		else if (MySkill4 == 8)
			MySkill4 = 0x49;
		else if (MySkill4 == 9)
			MySkill4 = 0x4A;
		else if (MySkill4 == 10)
			MySkill4 = 0x4B;
		else if (MySkill4 == 11)
			MySkill4 = 0x4C;
		else if (MySkill4 == 12)
			MySkill4 = 0x4D;
		else if (MySkill4 == 13)
			MySkill4 = 0x4E;
		else if (MySkill4 == 14)
			MySkill4 = 0x4F;
		else if (MySkill4 == 15)
			MySkill4 = 0x50;
		else if (MySkill4 == 16)
			MySkill4 = 0x51;
		else if (MySkill4 == 17)
			MySkill4 = 0x52;
		else if (MySkill4 == 18)
			MySkill4 = 0x53;
		else if (MySkill4 == 19)
			MySkill4 = 0x54;
		else if (MySkill4 == 20)
			MySkill4 = 0x55;
		else if (MySkill4 == 21)
			MySkill4 = 0x56;
		else if (MySkill4 == 22)
			MySkill4 = 0x57;
		else if (MySkill4 == 23)
			MySkill4 = 0x58;
		else if (MySkill4 == 24)
			MySkill4 = 0x59;
		else if (MySkill4 == 25)
			MySkill4 = 0x5A;
		else if (MySkill4 == 26)
			MySkill4 = 0x2D;
		else if (MySkill4 == 27)
			MySkill4 = 0x24;
		else if (MySkill4 == 28)
			MySkill4 = 0x2E;
		else if (MySkill4 == 29)
			MySkill4 = 0x23;
		else if (MySkill4 == 30)
			MySkill4 = 0x21;
		else if (MySkill4 == 31)
			MySkill4 = 0x22;
		else if (MySkill4 == 32)
			MySkill4 = 0x10;
		else if (MySkill4 == 33)
			MySkill4 = 0x11;
		else if (MySkill4 == 34)
			MySkill4 = 0x12;
		NewThread(USkill4);
	}
	else
	{
		iSkill4 = false;
		TerminateThread(USkill4, 0);
	}
}

//AutoLoot
DWORD LootD , ICount;
wchar_t Skill1;
bool NoLoot = true;
void Form3::checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox6->Checked == true)
	{
		NoLoot = false;
		ICount = Convert::ToInt32(textBox7->Text);
		LootD = Convert::ToInt32(textBox8->Text);
		Skill1 = Convert::ToChar(comboBox7->SelectedIndex);
		if (Skill1 == 0)
		    Skill1 = 0x41;
		else if (Skill1 == 1)
			Skill1 = 0x42;
		else if (Skill1 == 2)
			Skill1 = 0x43;
		else if (Skill1 == 3)
			Skill1 = 0x44;
		else if (Skill1 == 4)
			Skill1 = 0x45;
		else if (Skill1 == 5)
			Skill1 = 0x46;
		else if (Skill1 == 6)
			Skill1 = 0x47;
		else if (Skill1 == 7)
			Skill1 = 0x48;
		else if (Skill1 == 8)
			Skill1 = 0x49;
		else if (Skill1 == 9)
			Skill1 = 0x4A;
		else if (Skill1 == 10)
			Skill1 = 0x4B;
		else if (Skill1 == 11)
			Skill1 = 0x4C;
		else if (Skill1 == 12)
			Skill1 = 0x4D;
		else if (Skill1 == 13)
			Skill1 = 0x4E;
		else if (Skill1 == 14)
			Skill1 = 0x4F;
		else if (Skill1 == 15)
			Skill1 = 0x50;
		else if (Skill1 == 16)
			Skill1 = 0x51;
		else if (Skill1 == 17)
			Skill1 = 0x52;
		else if (Skill1 == 18)
			Skill1 = 0x53;
		else if (Skill1 == 19)
			Skill1 = 0x54;
		else if (Skill1 == 20)
			Skill1 = 0x55;
		else if (Skill1 == 21)
			Skill1 = 0x56;
		else if (Skill1 == 22)
			Skill1 = 0x57;
		else if (Skill1 == 23)
			Skill1 = 0x58;
		else if (Skill1 == 24)
			Skill1 = 0x59;
		else if (Skill1 == 25)
			Skill1 = 0x5A;
		else if (Skill1 == 26)
			Skill1 = 0x2D;
		else if (Skill1 == 27)
			Skill1 = 0x24;
		else if (Skill1 == 28)
			Skill1 = 0x2E;
		else if (Skill1 == 29)
			Skill1 = 0x23;
		else if (Skill1 == 30)
			Skill1 = 0x21;
		else if (Skill1 == 31)
			Skill1 = 0x22;
		else if (Skill1 == 32)
			Skill1 = 0x10;
		else if (Skill1 == 33)
			Skill1 = 0x11;
		else if (Skill1 == 34)
			Skill1 = 0x12;
		else if (Skill1 == 35)
			Skill1 = 0x60;
		NewThread(Loot);
	}
	else 
	{
		NoLoot = true;
		TerminateThread(Loot,0);
	}
}

//What happens when Form3 loads
void Form3::Form3_Load(System::Object^  sender, System::EventArgs^  e)
{
	this->comboBox1->SelectedIndex = 0;
	this->comboBox2->SelectedIndex = 2;
	this->comboBox3->SelectedIndex = 33;
	this->comboBox4->SelectedIndex = 34;
	this->comboBox5->SelectedIndex = 29;
	this->comboBox6->SelectedIndex = 32;
	this->comboBox7->SelectedIndex = 35;
}

