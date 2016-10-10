#include <Windows.h>
#include "Form1.h"
#include "SplashScreen.h"
#include "Main.h"
#include "Botting.h"
#include "Func.h"
#include "Pointers.h"
#include <urlmon.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#pragma comment(lib, "urlmon.lib")
using namespace PiezTrainer;
using namespace System::IO;
using namespace std;
[STAThreadAttribute]

//To Show the GUI
int Main( )
{
    Application::EnableVisualStyles( );
    Application::SetCompatibleTextRenderingDefault(false); 
    Application::Run(gcnew SplashScreen());
    return 0;
}

//Changes all the Form's opacity to 80%
void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e)
{
	wForm2->Opacity = 0.8;
	wForm3->Opacity = 0.8;
	wForm4->Opacity = 0.8;
	wForm5->Opacity = 0.8;
	wForm6->Opacity = 0.8;
	wCCForm->Opacity = 0.8;
}

//Timer which grabs all the in-game info
extern int MouseX , MouseY , Breath , AttackCount , MapID , PeopleCount , HP , MP , ItemX , ItemY , MobCount , ItemCount , Channel ;
extern double Exp;
double CurExp , BarCurExp;
void Form1::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	CurExp = Math::Round(Exp, 2);
	BarCurExp = Math::Round(Exp, 0);
	double ExpBarLength = (BarCurExp / 100) * 106;
	this->pictureBox6->Size = System::Drawing::Size((int)ExpBarLength, 10);
	this->label13->Text = MapID.ToString();
	this->label14->Text = MouseX.ToString() + "," + MouseY.ToString();
	this->label15->Text = ItemX.ToString() + "," + ItemY.ToString();
	this->label16->Text = PeopleCount.ToString();
	this->label17->Text = AttackCount.ToString();
	this->label18->Text = ItemCount.ToString();
	this->label19->Text = MobCount.ToString();
	this->label20->Text = CurExp.ToString() + "%";
	this->label21->Text = MP.ToString();
	this->label22->Text = HP.ToString();
	this->label28->Text = Channel.ToString();
	Sleep(1);
}

void Form1::label13_Click(System::Object^  sender, System::EventArgs^  e)
{
}

//Picture downloader < currently not working :\ >
void Form1::label13_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	int ipy = 0;
	if(this->label13->Text != "0")
	{
		String^ linkURL = "http://www.mapletip.com/images/new-maps/" + GetMapId().ToString() + ".png";
		LPCSTR variableURL = (LPCTSTR)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(linkURL).ToPointer());
		LPCSTR rPic = (LPCTSTR)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi("rPic" + ipy + ".png").ToPointer());
		URLDownloadToFile(NULL, variableURL, rPic, 0, 0);
		this->pictureBox1->Image = Image::FromFile("rPic" + ipy + ".png");
		remove(rPic);
		ipy++;
	}
	else
	{
		String^ linkURL = "http://s9.postimage.org/tqrhpwjzv/Piez_Character.png";
		LPCSTR variableURL = (LPCTSTR)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(linkURL).ToPointer());
		LPCSTR rPic = (LPCTSTR)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi("rPic" + ipy + ".png").ToPointer());
		
		URLDownloadToFile(NULL, variableURL, rPic, 0, 0);
		this->pictureBox1->Image = Image::FromFile("rPic" + ipy + ".png");
		remove(rPic);
		ipy++;
	}
}

//Save Button , i like individual savings . Although they cause more work , but they load faster :P
void Form1::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Save file in what file and as what name
	String^ KamiVacMobCountString = "C:\\PiezTrainer\\Settings\\KamiMobCount.txt";
	String^ OffMapPeopleCountString = "C:\\PiezTrainer\\Settings\\OffMapPeopleCountCount.txt";
	String^ AOffMapDelayString = "C:\\PiezTrainer\\Settings\\AOffMapDelay.txt";
	String^ AOffMapAttackString = "C:\\PiezTrainer\\Settings\\AOffMapAttack.txt";
	String^ MorphIDString = "C:\\PiezTrainer\\Settings\\MorphID.txt";

	String^ AttackTypeString = "C:\\PiezTrainer\\Settings\\AttackTypeString.txt";
	String^ AttackKeyString = "C:\\PiezTrainer\\Settings\\AttackKeyString.txt";
	String^ AttackMobCountString = "C:\\PiezTrainer\\Settings\\AttackMobCountString.txt";
	String^ AttackDelayString = "C:\\PiezTrainer\\Settings\\AttackDelayString.txt";

	String^ Skill1KeyString = "C:\\PiezTrainer\\Settings\\Skill1KeyString.txt";
	String^ Skill1DelayString = "C:\\PiezTrainer\\Settings\\Skill1DelayString.txt";

	String^ Skill2KeyString = "C:\\PiezTrainer\\Settings\\Skill2KeyString.txt";
	String^ Skill2DelayString = "C:\\PiezTrainer\\Settings\\Skill2DelayString.txt";

	String^ Skill3KeyString = "C:\\PiezTrainer\\Settings\\Skill3KeyString.txt";
	String^ Skill3DelayString = "C:\\PiezTrainer\\Settings\\Skill3DelayString.txt";

	String^ Skill4KeyString = "C:\\PiezTrainer\\Settings\\Skill4KeyString.txt";
	String^ Skill4DelayString = "C:\\PiezTrainer\\Settings\\Skill4DelayString.txt";

	String^ LootKeyString = "C:\\PiezTrainer\\Settings\\LootKeyString.txt";
	String^ LootItemString = "C:\\PiezTrainer\\Settings\\LootItemString.txt";
	String^ LootDelayString = "C:\\PiezTrainer\\Settings\\LootDelayString.txt";

	String^ HpKeyString = "C:\\PiezTrainer\\Settings\\HpKeyString.txt";
	String^ HpCountString = "C:\\PiezTrainer\\Settings\\HpCountString.txt";

	String^ MpKeyString = "C:\\PiezTrainer\\Settings\\MpKeyString.txt";
	String^ MpCountString = "C:\\PiezTrainer\\Settings\\MpCountString.txt";

	String^ PvPKeyString = "C:\\PiezTrainer\\Settings\\PvPKeyString.txt";
	String^ PacketTextString = "C:\\PiezTrainer\\Settings\\PacketTextString.txt";

	String^ CCPeopleString = "C:\\PiezTrainer\\Settings\\CCPeopleString.txt";
	String^ CCAttackString = "C:\\PiezTrainer\\Settings\\CCAttackString.txt";
	String^ CCDelayString = "C:\\PiezTrainer\\Settings\\CCDelayString.txt";
	String^ CCTypeString = "C:\\PiezTrainer\\Settings\\CCTypeString.txt";

	StreamWriter^ SaveList1 = gcnew StreamWriter(KamiVacMobCountString);
	StreamWriter^ SaveList2 = gcnew StreamWriter(OffMapPeopleCountString);
	StreamWriter^ SaveList3 = gcnew StreamWriter(AOffMapDelayString);
	StreamWriter^ SaveList4 = gcnew StreamWriter(AOffMapAttackString);
	StreamWriter^ SaveList5 = gcnew StreamWriter(MorphIDString);

	StreamWriter^ SaveList6 = gcnew StreamWriter(AttackTypeString);
	StreamWriter^ SaveList7 = gcnew StreamWriter(AttackKeyString);
	StreamWriter^ SaveList8 = gcnew StreamWriter(AttackMobCountString);
	StreamWriter^ SaveList9 = gcnew StreamWriter(AttackDelayString);

	StreamWriter^ SaveList10 = gcnew StreamWriter(Skill1KeyString);
	StreamWriter^ SaveList11 = gcnew StreamWriter(Skill1DelayString);

	StreamWriter^ SaveList12 = gcnew StreamWriter(Skill2KeyString);
	StreamWriter^ SaveList13 = gcnew StreamWriter(Skill2DelayString);

	StreamWriter^ SaveList14 = gcnew StreamWriter(Skill3KeyString);
	StreamWriter^ SaveList15 = gcnew StreamWriter(Skill3DelayString);

	StreamWriter^ SaveList16 = gcnew StreamWriter(Skill4KeyString);
	StreamWriter^ SaveList17 = gcnew StreamWriter(Skill4DelayString);

	StreamWriter^ SaveList18 = gcnew StreamWriter(LootKeyString);
	StreamWriter^ SaveList19 = gcnew StreamWriter(LootItemString);
	StreamWriter^ SaveList20 = gcnew StreamWriter(LootDelayString);

	StreamWriter^ SaveList21 = gcnew StreamWriter(HpKeyString);
	StreamWriter^ SaveList22 = gcnew StreamWriter(HpCountString);

	StreamWriter^ SaveList23 = gcnew StreamWriter(MpKeyString);
	StreamWriter^ SaveList24 = gcnew StreamWriter(MpCountString);

	StreamWriter^ SaveList25 = gcnew StreamWriter(PvPKeyString);
	StreamWriter^ SaveList26 = gcnew StreamWriter(PacketTextString);

	StreamWriter^ SaveList27 = gcnew StreamWriter(CCPeopleString);
	StreamWriter^ SaveList28 = gcnew StreamWriter(CCAttackString);
	StreamWriter^ SaveList29 = gcnew StreamWriter(CCDelayString);
	StreamWriter^ SaveList30 = gcnew StreamWriter(CCTypeString);

	//Writes down the string properties of the textbox / comboBox in all the forms

	String^ KamiVacMobCount = wForm2->textBox1->Text;
	String^ OffMapPeopleCount = wForm2->textBox3->Text;
	String^ AOffMapDelay = wForm2->textBox7->Text;
	String^ AOffMapAttack = wForm2->textBox6->Text;
	String^ MorphIDs = wForm2->textBox8->Text;

	String^ AttackType = wForm3->comboBox1->SelectedIndex.ToString();
	String^ AttackKey = wForm3->comboBox2->SelectedIndex.ToString();
	String^ AttackMobCount = wForm3->textBox1->Text;
	String^ AttackDelay = wForm3->textBox2->Text;

	String^ Skill1Key = wForm3->comboBox3->SelectedIndex.ToString();
	String^ Skill1Delay = wForm3->textBox3->Text;

	String^ Skill2Key = wForm3->comboBox4->SelectedIndex.ToString();
	String^ Skill2Delay = wForm3->textBox4->Text;

	String^ Skill3Key = wForm3->comboBox6->SelectedIndex.ToString();
	String^ Skill3Delay = wForm3->textBox6->Text;

	String^ Skill4Key = wForm3->comboBox5->SelectedIndex.ToString();
	String^ Skill4Delay = wForm3->textBox5->Text;

	String^ LootKey = wForm3->comboBox7->SelectedIndex.ToString();
	String^ LootItem = wForm3->textBox7->Text;
	String^ LootDelay = wForm3->textBox8->Text;

	String^ HpKey = wForm4->comboBox1->SelectedIndex.ToString();
	String^ HpCount = wForm4->textBox1->Text;

	String^ MpKey = wForm4->comboBox2->SelectedIndex.ToString();
	String^ MpCount = wForm4->textBox2->Text;

	String^ PvPKey = wForm6->comboBox3->SelectedIndex.ToString();
	String^ PacketText = wForm6->textBox1->Text;

	String^ CCPeople = wCCForm->textBox1->Text;
	String^ CCAttack = wCCForm->textBox2->Text;
	String^ CCDelay = wCCForm->textBox4->Text;
	String^ CCType = wCCForm->comboBox1->SelectedIndex.ToString();

	SaveList1->WriteLine(KamiVacMobCount);
	SaveList2->WriteLine(OffMapPeopleCount);
	SaveList3->WriteLine(AOffMapDelay);
	SaveList4->WriteLine(AOffMapAttack);
	SaveList5->WriteLine(MorphIDs);

	SaveList6->WriteLine(AttackType);
	SaveList7->WriteLine(AttackKey);
	SaveList8->WriteLine(AttackMobCount);
	SaveList9->WriteLine(AttackDelay);

	SaveList10->WriteLine(Skill1Key);
	SaveList11->WriteLine(Skill1Delay);

	SaveList12->WriteLine(Skill2Key);
	SaveList13->WriteLine(Skill2Delay);

	SaveList14->WriteLine(Skill3Key);
	SaveList15->WriteLine(Skill4Delay);

	SaveList16->WriteLine(Skill4Key);
	SaveList17->WriteLine(Skill4Delay);

	SaveList18->WriteLine(LootKey);
	SaveList19->WriteLine(LootItem);
	SaveList20->WriteLine(LootDelay);

	SaveList21->WriteLine(HpKey);
	SaveList22->WriteLine(HpCount);

	SaveList23->WriteLine(MpKey);
	SaveList24->WriteLine(MpCount);

	SaveList25->WriteLine(PvPKey);
	SaveList26->WriteLine(PacketText);

	SaveList27->WriteLine(CCPeople);
	SaveList28->WriteLine(CCAttack);
	SaveList29->WriteLine(CCDelay);
	SaveList30->WriteLine(CCType);

	//Closes the SaveList

	SaveList1->Close(); 
	SaveList2->Close(); 
	SaveList3->Close(); 
	SaveList4->Close(); 
	SaveList5->Close(); 
	SaveList6->Close(); 
	SaveList7->Close(); 
	SaveList8->Close(); 
	SaveList9->Close(); 
	SaveList10->Close(); 
	SaveList11->Close(); 
	SaveList12->Close(); 
	SaveList13->Close(); 
	SaveList14->Close(); 
	SaveList15->Close(); 
	SaveList16->Close(); 
	SaveList17->Close(); 
	SaveList18->Close(); 
	SaveList19->Close(); 
	SaveList20->Close();
	SaveList21->Close(); 
	SaveList22->Close(); 
	SaveList23->Close(); 
	SaveList24->Close(); 
	SaveList25->Close(); 
	SaveList26->Close(); 
	SaveList27->Close();
	SaveList28->Close();
	SaveList29->Close();
	SaveList30->Close();
}

void Form1::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	string STRING;

	ifstream LoadList1;
	ifstream LoadList2;
	ifstream LoadList3;
	ifstream LoadList4;
	ifstream LoadList5;
	ifstream LoadList6;
	ifstream LoadList7;
	ifstream LoadList8;
	ifstream LoadList9;
	ifstream LoadList10;
	ifstream LoadList11;
	ifstream LoadList12;
	ifstream LoadList13;
	ifstream LoadList14;
	ifstream LoadList15;
	ifstream LoadList16;
	ifstream LoadList17;
	ifstream LoadList18;
	ifstream LoadList19;
	ifstream LoadList20;
	ifstream LoadList21;
	ifstream LoadList22;
	ifstream LoadList23;
	ifstream LoadList24;
	ifstream LoadList25;
	ifstream LoadList26;
	ifstream LoadList27;
	ifstream LoadList28;
	ifstream LoadList29;
	ifstream LoadList30;

	//Loads the text file

	LoadList1.open("C:\\PiezTrainer\\Settings\\KamiMobCount.txt");
	LoadList2.open("C:\\PiezTrainer\\Settings\\OffMapPeopleCountCount.txt");
	LoadList3.open("C:\\PiezTrainer\\Settings\\AOffMapDelay.txt");
	LoadList4.open("C:\\PiezTrainer\\Settings\\AOffMapAttack.txt");
	LoadList5.open("C:\\PiezTrainer\\Settings\\MorphID.txt");

	LoadList6.open("C:\\PiezTrainer\\Settings\\AttackTypeString.txt");
	LoadList7.open("C:\\PiezTrainer\\Settings\\AttackKeyString.txt");
	LoadList8.open("C:\\PiezTrainer\\Settings\\AttackMobCountString.txt");
	LoadList9.open("C:\\PiezTrainer\\Settings\\AttackDelayString.txt");

	LoadList10.open("C:\\PiezTrainer\\Settings\\Skill1KeyString.txt");
	LoadList11.open("C:\\PiezTrainer\\Settings\\Skill1DelayString.txt");

	LoadList12.open("C:\\PiezTrainer\\Settings\\Skill2KeyString.txt");
	LoadList13.open("C:\\PiezTrainer\\Settings\\Skill2DelayString.txt");

	LoadList14.open("C:\\PiezTrainer\\Settings\\Skill3KeyString.txt");
	LoadList15.open("C:\\PiezTrainer\\Settings\\Skill3DelayString.txt");

	LoadList16.open("C:\\PiezTrainer\\Settings\\Skill4KeyString.txt");
	LoadList17.open("C:\\PiezTrainer\\Settings\\Skill4DelayString.txt");

	LoadList18.open("C:\\PiezTrainer\\Settings\\LootKeyString.txt");
	LoadList19.open("C:\\PiezTrainer\\Settings\\LootItemString.txt");
	LoadList20.open("C:\\PiezTrainer\\Settings\\LootDelayString.txt");

	LoadList21.open("C:\\PiezTrainer\\Settings\\HpKeyString.txt");
	LoadList22.open("C:\\PiezTrainer\\Settings\\HpCountString.txt");

	LoadList23.open("C:\\PiezTrainer\\Settings\\MpKeyString.txt");
	LoadList24.open("C:\\PiezTrainer\\Settings\\MpKeyString.txt");

	LoadList25.open("C:\\PiezTrainer\\Settings\\PvPKeyString.txt");
	LoadList26.open("C:\\PiezTrainer\\Settings\\PacketTextString.txt");

	LoadList27.open("C:\\PiezTrainer\\Settings\\CCPeopleString.txt");
	LoadList28.open("C:\\PiezTrainer\\Settings\\CCAttackString.txt");
	LoadList29.open("C:\\PiezTrainer\\Settings\\CCDelayString.txt");
	LoadList30.open("C:\\PiezTrainer\\Settings\\CCTypeString.txt");

	//If it doesn't obtain either one of the textfile
	if(!LoadList1 || !LoadList2 || !LoadList3 || !LoadList4 || !LoadList5 || !LoadList6 || !LoadList7 || !LoadList8 || !LoadList9 || !LoadList10 || !LoadList11 || !LoadList12 || !LoadList13 || !LoadList14 || !LoadList15 || !LoadList16 || !LoadList17 || !LoadList18 || !LoadList19 || !LoadList20 || !LoadList21 || !LoadList22 || !LoadList23 || !LoadList24 || !LoadList25 || !LoadList26 || !LoadList27 || !LoadList28 || !LoadList29 || !LoadList30 )
	{
		//Shows a MessageBox
		MessageBoxA(NULL, "There is no saved Settings", "Cannot Find File", MB_OK | MB_SETFOREGROUND);
	}
	else
	{
		//If it able to read the textfile
		if(getline(LoadList1, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm2->textBox1->Text = sSettings; 
		}
		if(getline(LoadList2, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm2->textBox3->Text = sSettings; 
		}
		if(getline(LoadList3, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm2->textBox7->Text = sSettings; 
		}
		if(getline(LoadList4, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm2->textBox6->Text = sSettings; 
		}
		if(getline(LoadList5, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm2->textBox8->Text = sSettings; 
		}
		if(getline(LoadList6, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm3->comboBox1->SelectedIndex = Convert::ToInt32(sSettings); 
		}
		if(getline(LoadList7, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm3->comboBox2->SelectedIndex = Convert::ToInt32(sSettings); 
		}
		if(getline(LoadList8, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm3->textBox1->Text = sSettings; 
		}
		if(getline(LoadList9, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm3->textBox2->Text = sSettings; 
		}
		if(getline(LoadList10, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm3->comboBox3->SelectedIndex = Convert::ToInt32(sSettings); 
		}
		if(getline(LoadList11, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm3->textBox3->Text = sSettings; 
		}
		if(getline(LoadList12, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm3->comboBox4->SelectedIndex = Convert::ToInt32(sSettings); 
		}
		if(getline(LoadList13, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm3->textBox4->Text = sSettings; 
		}
		if(getline(LoadList14, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm3->comboBox6->SelectedIndex = Convert::ToInt32(sSettings); 
		}
		if(getline(LoadList15, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm3->textBox6->Text = sSettings; 
		}
		if(getline(LoadList16, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm3->comboBox5->SelectedIndex = Convert::ToInt32(sSettings); 
		}
		if(getline(LoadList17, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm3->textBox5->Text = sSettings; 
		}
		if(getline(LoadList18, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm3->comboBox7->SelectedIndex = Convert::ToInt32(sSettings); 
		}
		if(getline(LoadList19, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm3->textBox7->Text = sSettings; 
		}
		if(getline(LoadList20, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm3->textBox8->Text = sSettings; 
		}
		if(getline(LoadList21, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm4->comboBox1->SelectedIndex = Convert::ToInt32(sSettings);
		}
		if(getline(LoadList22, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm4->textBox1->Text = sSettings; 
		}
		if(getline(LoadList23, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm4->comboBox2->SelectedIndex = Convert::ToInt32(sSettings);
		}
		if(getline(LoadList24, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm4->textBox2->Text = sSettings; 
		}
		if(getline(LoadList25, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm6->comboBox3->SelectedIndex = Convert::ToInt32(sSettings);
		}
		if(getline(LoadList26, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wForm6->textBox1->Text = sSettings; 
		}
		if(getline(LoadList27, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wCCForm->textBox1->Text = sSettings; 
		}
		if(getline(LoadList28, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wCCForm->textBox2->Text = sSettings; 
		}
		if(getline(LoadList29, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wCCForm->textBox4->Text = sSettings; 
		}
		if(getline(LoadList30, STRING))
		{
			char *cString(convertStringToChar(STRING));
	    	String ^sSettings = gcnew String(cString);
	    	wCCForm->comboBox1->SelectedIndex = Convert::ToInt32(sSettings);
		}
	}

	LoadList1.close(); 
	LoadList2.close(); 
	LoadList3.close(); 
	LoadList4.close(); 
	LoadList5.close();
	LoadList6.close(); 
	LoadList7.close(); 
	LoadList8.close(); 
	LoadList9.close(); 
	LoadList10.close(); 
	LoadList11.close(); 
	LoadList12.close(); 
	LoadList13.close(); 
	LoadList14.close(); 
	LoadList15.close(); 
	LoadList16.close(); 
	LoadList17.close(); 
	LoadList18.close(); 
	LoadList19.close(); 
	LoadList20.close(); 
	LoadList21.close(); 
	LoadList22.close(); 
	LoadList23.close(); 
	LoadList24.close(); 
	LoadList25.close(); 
	LoadList26.close(); 
	LoadList27.close(); 
	LoadList28.close(); 
	LoadList29.close(); 
	LoadList30.close(); 
}

//Shows Maplestory
void Form1::button4_Click(System::Object^  sender, System::EventArgs^  e)
{
	HWND hwnd = FindWindow("MapleStoryClass", 0);
    ShowWindow(hwnd, SW_SHOW);
}

//Hides Maplestory
void Form1::button3_Click(System::Object^  sender, System::EventArgs^  e)
{
	HWND hwnd = FindWindow("MapleStoryClass", 0);
	ShowWindow(hwnd, SW_HIDE);
}

//All Form->Topmost = false
void Form1::button6_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->TopMost = false;
	wForm2->TopMost = false;
	wForm3->TopMost = false;
	wForm4->TopMost = false;
	wForm5->TopMost = false;
	wForm6->TopMost = false;
	wCCForm->TopMost = false;
	button5->Visible = true;
	button6->Visible = false;
}

//All Form->Topmost = true
void Form1::button5_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->TopMost = true;
	wForm2->TopMost = true;
	wForm3->TopMost = true;
	wForm4->TopMost = true;
	wForm5->TopMost = true;
	wForm6->TopMost = true;
	wCCForm->TopMost = true;
	button5->Visible = false;
	button6->Visible = true;
}

//Show Botting Form (Form3)
void Form1::button7_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(wForm3->Visible == false)
	{
		wForm3->Visible = true;
	}
	else
	{
		 wForm3->Visible = false;
	}
}

//Show Auto-Pot Form (Form4)
void Form1::button8_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(wForm4->Visible == false)
	{
		wForm4->Visible = true;
	}
	else
	{
		wForm4->Visible = false;
	}
}

//Show Hacks Form (Form2)
void Form1::button9_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(wForm2->Visible == false)
	{
		wForm2->Visible = true;
	}
	 else
	{
		wForm2->Visible = false;
	}
}

//Show Change Log Form (Form5)
void Form1::button10_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(wForm5->Visible == false)
	{
		wForm5->Visible = true;
	}
	 else
	{
		wForm5->Visible = false;
	}
}

//Shows Exploit Form (Form6)
void Form1::button11_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(wForm6->Visible == false)
	{
		wForm6->Visible = true;
	}
	 else
	{
		wForm6->Visible = false;
	}
}

//Shows CC Form (CCForm)
void Form1::button12_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (wCCForm->Visible == false)
	{
		wCCForm->Visible = true;
	}
	else
	{
		wCCForm->Visible = false;
	}
}

//Changes the opacity of all the Forms via a trackbar
void Form1::trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	this->Opacity = trackBar1->Value * 0.01;
	wForm2->Opacity = trackBar1->Value * 0.01;
	wForm3->Opacity = trackBar1->Value * 0.01;
	wForm4->Opacity = trackBar1->Value * 0.01;
	wForm5->Opacity = trackBar1->Value * 0.01;
	wForm6->Opacity = trackBar1->Value * 0.01;
	wCCForm->Opacity = trackBar1->Value * 0.01;
}
