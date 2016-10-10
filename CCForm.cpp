#include "CCForm.h"
#include <Windows.h>
#include "Main.h"
#include "Botting.h"
#include "Func.h"
using namespace PiezTrainer;

//Extract the CC Functions
extern void SendPacketForCC(String^ dataString);

//Added a check to see whether the user CC's
bool iCheckForCC = false;

//Auto CC People
bool eCCPeopleCount , eCCAttackCount = false;
int iCCPeopleCount = 1; 
int iCCAttackCount = 99;
void AutoPeopleCC()
{
   while(eCCPeopleCount)
   {
        if(GetPeopleCount() >= iCCPeopleCount)
        {
			iCheckForCC = true;//Enables the CC check
	        Sleep(500);
            SendPacketForCC("24 00 0* ** ** ** **");
        }
        Sleep(1000);
   }
}

//Auto CC Attack
void AutoAttackCC()
{
   while(eCCAttackCount)
   {
        if(GetAttackCount() > iCCAttackCount)
        {
			iCheckForCC = true;//Enables the CC check
	        Sleep(500);
            SendPacketForCC("24 00 0* ** ** ** **");
        }
        Sleep(1000);
   }
}


//Timed CC
bool bCCTTimeDelay = false;
int iCCTimeDelay = 300;
int iSecorMin = 60000;
void AutoTimedCC()
{
   while(bCCTTimeDelay)
   {
	    Sleep(iCCTimeDelay * iSecorMin);
		iCheckForCC = true;//Enables the CC check
	    Sleep(500);
        SendPacketForCC("24 00 0* ** ** ** **");
   }
}

//Manual CC Channel 1 ~ 20
void CCForm::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 00 ** ** ** **");
}
	
void CCForm::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 01 ** ** ** **");
}

void CCForm::button3_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 02 ** ** ** **");
}

void CCForm::button4_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 03 ** ** ** **");
}

void CCForm::button5_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 04 ** ** ** **");
}

void CCForm::button10_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 05 ** ** ** **");
}

void CCForm::button9_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 06 ** ** ** **");
}

void CCForm::button8_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 07 ** ** ** **");
}

void CCForm::button7_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 08 ** ** ** **");
}

void CCForm::button6_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 09 ** ** ** **");
}

void CCForm::button15_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 0A ** ** ** **");
}

void CCForm::button14_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 0B ** ** ** **");
}

void CCForm::button13_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 0C ** ** ** **");
}

void CCForm::button12_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 0D ** ** ** **");
}

void CCForm::button11_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 0E ** ** ** **");
}

void CCForm::button20_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 0F ** ** ** **");
}

void CCForm::button19_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 10 ** ** ** **");
}

void CCForm::button18_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 11 ** ** ** **");
}

void CCForm::button17_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 12 ** ** ** **");
}

void CCForm::button16_Click(System::Object^  sender, System::EventArgs^  e)
{
	iCheckForCC = true;
	Sleep(500);
	SendPacketForCC("24 00 13 ** ** ** **");
}

//Auto CC checkBox
void CCForm::checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox1->Checked == true)
	{
		if(this->radioButton1->Checked == true)
		{		     
			eCCAttackCount = false;
			eCCPeopleCount = true;
			NewThread(AutoPeopleCC);
		}
		if(this->radioButton2->Checked == true)
		{		     
			eCCPeopleCount = false;
			eCCAttackCount = true;
			NewThread(AutoAttackCC);
		}
	}
	else
	{
		eCCPeopleCount = false;
		eCCAttackCount = false;
		TerminateThread(AutoAttackCC,0);
		TerminateThread(AutoPeopleCC,0);
	}
}

//Empty Timer ._.
void CCForm::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
}

//People Count
void CCForm::textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->textBox1->Text->Length != NULL)
	{
		iCCPeopleCount = Convert::ToInt32(textBox1->Text);
	}
}

//CC People count radioButton
void CCForm::radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->radioButton1->Checked == true && this->checkBox1->Checked == true)
	{
		eCCAttackCount = false;
		eCCPeopleCount = true;
		TerminateThread(AutoAttackCC,0);
		NewThread(AutoPeopleCC);
	}
}

//Attack Count for CC
void CCForm::textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->textBox2->Text->Length != NULL)
	{
		iCCAttackCount = Convert::ToInt32(textBox2->Text);
	}
}

//CC Attack Count for Attack
void CCForm::radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->radioButton2->Checked == true && this->checkBox1->Checked == true)
	{
		eCCPeopleCount = false;
		eCCAttackCount = true;
		TerminateThread(AutoPeopleCC,0);
		NewThread(AutoAttackCC);
	}
}


//Timed CC
void CCForm::checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox2->Checked == true)
	{
		bCCTTimeDelay = true;
		NewThread(AutoTimedCC);
	}
	else
	{
		bCCTTimeDelay = false;
		TerminateThread(AutoTimedCC,0);
	}
}

//Timed CC Delay
void CCForm::textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->textBox4->Text->Length != NULL)
	{
		iCCTimeDelay = Convert::ToInt32(textBox4->Text);
	}
}

//Determines if you chose Mins or Secs
void CCForm::comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->comboBox1->SelectedIndex == 0)
	{
		iSecorMin = 1000;
	}
	else if(this->comboBox1->SelectedIndex == 1)
	{
		iSecorMin = 60000;
	}
}

// Another Empty Timer ._.
void CCForm::timer2_Tick(System::Object^  sender, System::EventArgs^  e)
{
}

//20 Channels
void CCForm::radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->radioButton3->Checked == true)
	{
		if(this->button16->Enabled == false && this->button17->Enabled == false && this->button18->Enabled == false && this->button19->Enabled == false && this->button20->Enabled == false)
		{
			this->button16->Enabled = true;
			this->button17->Enabled = true;
			this->button18->Enabled = true;
			this->button19->Enabled = true;
			this->button20->Enabled = true;
		}
	}
}

//15 Channels
void CCForm::radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->radioButton4->Checked == true)
	{
		{
			this->button16->Enabled = false;
			this->button17->Enabled = false;
			this->button18->Enabled = false;
			this->button19->Enabled = false;
			this->button20->Enabled = false;
		}
	}
}

//CCForm Loads
void CCForm::CCForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	this->radioButton1->Checked = true;
	this->comboBox1->SelectedIndex = 1;
	this->textBox1->Text = "1";
	this->textBox2->Text = "99";
	this->textBox4->Text = "3";
}

void CCForm::groupBox1_Enter(System::Object^  sender, System::EventArgs^  e)
{
}