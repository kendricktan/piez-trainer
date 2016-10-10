#include <Windows.h>
#include "Form6.h"
#include "Func.h"
#include <iostream>
#include <string>
using namespace std;
using namespace PiezTrainer;

int TextBox1Length;

//Converts String to Hex
extern void WINAPI msSendPacketA(__in LPCSTR lpPacketStr);
String^ StringToHex(String^ Str)
{
       String^ ReturnString = "";
       for each (char C in Str)
       {
              ReturnString += C.ToString("X"); //if this gives error use ((int)C).ToString("X");
       }
       return ReturnString;
}

//Converts System::String to std::string
void MarshalString ( System::String^ s, std::string& os )
{   
       using namespace System::Runtime::InteropServices;   
       const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();   
       os = chars;   
       Marshal::FreeHGlobal(IntPtr((void*)chars));
}

//Function to send the packet
void SendPacket(String^ dataString)
{
	int Random = rand()%16;	//Gives a random value
	String^ Packet = dataString;
	String^ Packet2 = Packet->Replace(L" ", String::Empty);
	String^ Packet3 = Packet2->Replace(L"*", Random.ToString("X"));//Gives the symbol '*' a random value
	String^ Packet4 = Packet3->Replace(L"L", TextBox1Length.ToString("X2"));
	LPCSTR StringA = (LPCSTR)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Packet4).ToPointer());
	msSendPacketA(StringA);
}

//Modified Sendpacket function to change channel
void SendPacketForCC(String^ dataString)
{
	int Random = rand()%14;
	String^ Packet = dataString;
	String^ Packet2 = Packet->Replace(L" ", String::Empty);
	String^ Packet3 = Packet2->Replace(L"*", Random.ToString("X"));
	LPCSTR StringA = (LPCSTR)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Packet3).ToPointer());
	msSendPacketA(StringA);
}

//Empty event ._____.
int iCheckSkillBinderKey , iCheckSkillBinderSkillId;
void Form6::comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
}

//Empty Event again .___________.
void Form6::comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
}

//Aran Skill Key Binder
void Form6::button6_Click(System::Object^  sender, System::EventArgs^  e)
{
	String^ iSkillBinderKey;
	String^ iSkillBinderSkillId;
	iCheckSkillBinderSkillId = Convert::ToInt32(this->comboBox1->SelectedIndex);
	iCheckSkillBinderKey = Convert::ToInt32(this->comboBox2->SelectedIndex);
	    if (iCheckSkillBinderKey == 0)
		    iSkillBinderKey = "1E";
		else if (iCheckSkillBinderKey == 1)
			iSkillBinderKey = "30";
		else if (iCheckSkillBinderKey == 2)
			iSkillBinderKey = "2E";
		else if (iCheckSkillBinderKey == 3)
			iSkillBinderKey = "20";
		else if (iCheckSkillBinderKey == 4)
			iSkillBinderKey = "12";
		else if (iCheckSkillBinderKey == 5)
			iSkillBinderKey = "21";
		else if (iCheckSkillBinderKey == 6)
			iSkillBinderKey = "22";
		else if (iCheckSkillBinderKey == 7)
			iSkillBinderKey = "23";
		else if (iCheckSkillBinderKey == 8)
			iSkillBinderKey = "17";
		else if (iCheckSkillBinderKey == 9)
			iSkillBinderKey = "24";
		else if (iCheckSkillBinderKey == 10)
			iSkillBinderKey = "25";
		else if (iCheckSkillBinderKey == 11)
			iSkillBinderKey = "26";
		else if (iCheckSkillBinderKey == 12)
			iSkillBinderKey = "32";
		else if (iCheckSkillBinderKey == 13)
			iSkillBinderKey = "31";
		else if (iCheckSkillBinderKey == 14)
			iSkillBinderKey = "18";
		else if (iCheckSkillBinderKey == 15)
			iSkillBinderKey = "19";
		else if (iCheckSkillBinderKey == 16)
			iSkillBinderKey = "10";
		else if (iCheckSkillBinderKey == 17)
			iSkillBinderKey = "13";
		else if (iCheckSkillBinderKey == 18)
			iSkillBinderKey = "1F";
		else if (iCheckSkillBinderKey == 19)
			iSkillBinderKey = "14";
		else if (iCheckSkillBinderKey == 20)
			iSkillBinderKey = "16";
		else if (iCheckSkillBinderKey == 21)
			iSkillBinderKey = "2F";
		else if (iCheckSkillBinderKey == 22)
			iSkillBinderKey = "11";
		else if (iCheckSkillBinderKey == 23)
			iSkillBinderKey = "2D";
		else if (iCheckSkillBinderKey == 24)
			iSkillBinderKey = "15";
		else if (iCheckSkillBinderKey == 25)
			iSkillBinderKey = "2C";
		else if (iCheckSkillBinderKey == 26)
			iSkillBinderKey = "02";
		else if (iCheckSkillBinderKey == 27)
			iSkillBinderKey = "03";
		else if (iCheckSkillBinderKey == 28)
			iSkillBinderKey = "04";
		else if (iCheckSkillBinderKey == 29)
			iSkillBinderKey = "05";
		else if (iCheckSkillBinderKey == 30)
			iSkillBinderKey = "06";
		else if (iCheckSkillBinderKey == 31)
			iSkillBinderKey = "07";
		else if (iCheckSkillBinderKey == 32)
			iSkillBinderKey = "08";
		else if (iCheckSkillBinderKey == 33)
			iSkillBinderKey = "09";
		else if (iCheckSkillBinderKey == 34)
			iSkillBinderKey = "0A";
		else if (iCheckSkillBinderKey == 35)
			iSkillBinderKey = "0B";
		else if (iCheckSkillBinderKey == 36)
			iSkillBinderKey = "2A";
		else if (iCheckSkillBinderKey == 37)
			iSkillBinderKey = "1D";
		else if (iCheckSkillBinderKey == 38)
			iSkillBinderKey = "38";
		else if (iCheckSkillBinderKey == 39)
			iSkillBinderKey = "39";
		else if (iCheckSkillBinderKey == 40)
			iSkillBinderKey = "3B";
		else if (iCheckSkillBinderKey == 41)
			iSkillBinderKey = "3C";
		else if (iCheckSkillBinderKey == 42)
			iSkillBinderKey = "3D";
		else if (iCheckSkillBinderKey == 43)
			iSkillBinderKey = "3E";
		else if (iCheckSkillBinderKey == 44)
			iSkillBinderKey = "3F";
		else if (iCheckSkillBinderKey == 45)
			iSkillBinderKey = "40";
		else if (iCheckSkillBinderKey == 46)
			iSkillBinderKey = "41";
		else if (iCheckSkillBinderKey == 47)
			iSkillBinderKey = "42";
		else if (iCheckSkillBinderKey == 48)
			iSkillBinderKey = "43";
		else if (iCheckSkillBinderKey == 49)
			iSkillBinderKey = "44";
		else if (iCheckSkillBinderKey == 50)
			iSkillBinderKey = "57";
		else if (iCheckSkillBinderKey == 51)
			iSkillBinderKey = "58";
		else if (iCheckSkillBinderKey == 52)
			iSkillBinderKey = "52";
		else if (iCheckSkillBinderKey == 53)
			iSkillBinderKey = "47";
		else if (iCheckSkillBinderKey == 54)
			iSkillBinderKey = "49";
		else if (iCheckSkillBinderKey == 55)
			iSkillBinderKey = "51";
		else if (iCheckSkillBinderKey == 56)
			iSkillBinderKey = "53";
		else if (iCheckSkillBinderKey == 57)
			iSkillBinderKey = "4F";
	    if (iCheckSkillBinderSkillId == 0)
		    iSkillBinderSkillId = "42 6F 40 01";
		else if (iCheckSkillBinderSkillId == 1)
			iSkillBinderSkillId = "E1 F5 41 01";
		else if (iCheckSkillBinderSkillId == 2)
			iSkillBinderSkillId = "05 44 42 01";
		else if (iCheckSkillBinderSkillId == 3)
			iSkillBinderSkillId = "E2 F5 41 01";
		else if (iCheckSkillBinderSkillId == 4)
			iSkillBinderSkillId = "F3 1C 42 01";
		else if (iCheckSkillBinderSkillId == 5)
			iSkillBinderSkillId = "F6 1C 42 01";
		else if (iCheckSkillBinderSkillId == 6)
			iSkillBinderSkillId = "44 6F 40 01";
		else if (iCheckSkillBinderSkillId == 7)
			iSkillBinderSkillId = "E5 F5 41 01";
		else if (iCheckSkillBinderSkillId == 8)
			iSkillBinderSkillId = "E7 F5 41 01";
		else if (iCheckSkillBinderSkillId == 9)
			iSkillBinderSkillId = "FB 1C 42 01";
		else if (iCheckSkillBinderSkillId == 10)
			iSkillBinderSkillId = "06 44 42 01";
		else if (iCheckSkillBinderSkillId == 11)
			iSkillBinderSkillId = "07 44 42 01";
	SendPacket("B2 00 00 00 00 00 02 00 00 00 " + iSkillBinderKey + " 00 00 00 01 " + iSkillBinderSkillId +" 30 00 00 00 00 29 73 40 01");
}

//Packet Sender's textbox 
void Form6::textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	TextBox1Length = this->textBox1->Text->Length;
}

//Packet Sender
void Form6::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	SendPacket(this->textBox1->Text);
}

//Mushy Reset
void Form6::button5_Click(System::Object^  sender, System::EventArgs^  e)
{
	SendPacket("A3 00 0B 01");
}

//Teleport To Perion
void Form6::button4_Click(System::Object^  sender, System::EventArgs^  e)
{
	timer1->Enabled = true;
}

//Tele To Perion Spam
void Form6::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	if(timer1->Enabled == true)
	{
		int iSpamToPerion = 60;
	for (iSpamToPerion=0; iSpamToPerion<60; iSpamToPerion++)
	{
		SendPacket("A3 00 00 04 00 00");
		Sleep(1);
	}
	timer1->Enabled = false;
	}
}
//Free Omok
void Form6::button7_Click(System::Object^  sender, System::EventArgs^  e)
{
	SendPacket("A3 00 00 01 0F 00 50 69 65 7A 20 49 73 20 41 77 65 73 6F 6D 65 00 04");
}

//Free Card Game
void Form6::button8_Click(System::Object^  sender, System::EventArgs^  e)
{
	SendPacket("A3 00 00 02 0F 00 50 69 65 7A 20 49 73 20 41 77 65 73 6F 6D 65 00 00");
}

//PvP No Delay
void Form6::checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(this->checkBox1->Checked == true)
	{
		this->timer2->Enabled = true;
	}
	else if(this->checkBox1->Checked == false)
	{
		this->timer2->Enabled = false;
	}
}

void Form6::comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
}
	
//PvP No Delay
void Form6::timer2_Tick(System::Object^  sender, System::EventArgs^  e)
{
		if(this->comboBox3->SelectedIndex == 0)
		{
			if(GetAsyncKeyState(0x43))
			{
				SendPacket("35 00 61 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00");
				SendPacket("35 00 61 00 00 00 01 00 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00");
				Sleep(75);
			}
		}
		if(this->comboBox3->SelectedIndex == 1)
		{
			if(GetAsyncKeyState(VK_SHIFT))
			{
				SendPacket("35 00 61 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00");
				SendPacket("35 00 61 00 00 00 01 00 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00");
				Sleep(75);
			}
		}
		if(this->comboBox3->SelectedIndex == 2)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{
				SendPacket("35 00 61 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00");
				SendPacket("35 00 61 00 00 00 01 00 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00");
				Sleep(75);
			}
		}
		if(this->comboBox3->SelectedIndex == 3)
		{
			if(GetAsyncKeyState(VK_MENU))
			{
				SendPacket("35 00 61 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00");
				SendPacket("35 00 61 00 00 00 01 00 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00");
				Sleep(75);
			}
		}
}

void Form6::Form6_Load(System::Object^  sender, System::EventArgs^  e)
{
	this->comboBox1->SelectedIndex = 0;
	this->comboBox2->SelectedIndex = 0;
	this->comboBox3->SelectedIndex = 0;
}