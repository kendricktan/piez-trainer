#pragma once

namespace PiezTrainer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form3
	/// </summary>
	public ref class Form3 : public System::Windows::Forms::Form
	{
	public:
		Form3(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form3()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::GroupBox^  groupBox3;
	protected: 
	public: System::Windows::Forms::TextBox^  textBox8;
	public: System::Windows::Forms::Label^  label15;
	public: System::Windows::Forms::TextBox^  textBox7;
	public: System::Windows::Forms::Label^  label14;
	public: System::Windows::Forms::ComboBox^  comboBox7;
	public: System::Windows::Forms::Label^  label13;

	protected: 






	public: System::Windows::Forms::CheckBox^  checkBox6;
	public: System::Windows::Forms::GroupBox^  groupBox2;
	public: System::Windows::Forms::TextBox^  textBox5;
	public: System::Windows::Forms::Label^  label9;
	public: System::Windows::Forms::ComboBox^  comboBox5;
	public: System::Windows::Forms::Label^  label10;
	public: System::Windows::Forms::CheckBox^  checkBox4;
	public: System::Windows::Forms::TextBox^  textBox6;
	public: System::Windows::Forms::Label^  label11;
	public: System::Windows::Forms::ComboBox^  comboBox6;
	public: System::Windows::Forms::Label^  label12;
	public: System::Windows::Forms::CheckBox^  checkBox5;
	public: System::Windows::Forms::TextBox^  textBox4;
	public: System::Windows::Forms::Label^  label7;
	public: System::Windows::Forms::ComboBox^  comboBox4;
	public: System::Windows::Forms::Label^  label8;
	public: System::Windows::Forms::CheckBox^  checkBox3;
	public: System::Windows::Forms::TextBox^  textBox3;
	public: System::Windows::Forms::Label^  label6;
	public: System::Windows::Forms::ComboBox^  comboBox3;
	public: System::Windows::Forms::Label^  label5;
	public: System::Windows::Forms::CheckBox^  checkBox2;
	public: System::Windows::Forms::GroupBox^  groupBox1;
	public: System::Windows::Forms::TextBox^  textBox2;
	public: System::Windows::Forms::Label^  label4;
	public: System::Windows::Forms::TextBox^  textBox1;
	public: System::Windows::Forms::Label^  label3;
	public: System::Windows::Forms::ComboBox^  comboBox2;
	public: System::Windows::Forms::Label^  label2;
	public: System::Windows::Forms::Label^  label1;
	private: 






























	public: System::Windows::Forms::ComboBox^  comboBox1;
	private: 

	public: System::Windows::Forms::CheckBox^  checkBox1;
	private: 


	protected: 







































	private:
		protected:
			void Form3::checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
			void Form3::groupBox2_Enter(System::Object^  sender, System::EventArgs^  e);
			void Form3::checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
			void Form3::checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
			void Form3::checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
			void Form3::checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
			void Form3::checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
			void Form3::Form3_Load(System::Object^  sender, System::EventArgs^  e);
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form3::typeid));
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->comboBox7 = (gcnew System::Windows::Forms::ComboBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox8);
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Controls->Add(this->textBox7);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->comboBox7);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->checkBox6);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox3->ForeColor = System::Drawing::Color::White;
			this->groupBox3->Location = System::Drawing::Point(12, 364);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(285, 99);
			this->groupBox3->TabIndex = 9;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Loot";
			// 
			// textBox8
			// 
			this->textBox8->BackColor = System::Drawing::Color::Black;
			this->textBox8->ForeColor = System::Drawing::Color::White;
			this->textBox8->Location = System::Drawing::Point(203, 66);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(71, 21);
			this->textBox8->TabIndex = 28;
			this->textBox8->Text = L"100";
			this->textBox8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(153, 69);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(44, 15);
			this->label15->TabIndex = 27;
			this->label15->Text = L"Delay :";
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::Color::Black;
			this->textBox7->ForeColor = System::Drawing::Color::White;
			this->textBox7->Location = System::Drawing::Point(203, 39);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(71, 21);
			this->textBox7->TabIndex = 26;
			this->textBox7->Text = L"1";
			this->textBox7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(144, 42);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(53, 15);
			this->label14->TabIndex = 7;
			this->label14->Text = L"Item(s) :";
			// 
			// comboBox7
			// 
			this->comboBox7->BackColor = System::Drawing::Color::Black;
			this->comboBox7->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox7->ForeColor = System::Drawing::Color::White;
			this->comboBox7->FormattingEnabled = true;
			this->comboBox7->Items->AddRange(gcnew cli::array< System::Object^  >(36) {L" A", L" B", L" C", L" D", L" E", L" F", L" G", 
				L" H", L" I", L" J", L" K", L" L", L" M", L" N", L" O", L" P", L" Q", L" R", L" S", L" T", L" U", L" V", L" W", L" X", L" Y", 
				L" Z", L" Insert", L" Home", L" Del", L" End", L" Pg_Up", L" Pg_Down", L" Shift", L" Ctrl", L" Alt", L" NumPad 0"});
			this->comboBox7->Location = System::Drawing::Point(48, 39);
			this->comboBox7->Name = L"comboBox7";
			this->comboBox7->Size = System::Drawing::Size(90, 23);
			this->comboBox7->TabIndex = 6;
			this->comboBox7->Text = L" NumPad 0";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 42);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(35, 15);
			this->label13->TabIndex = 5;
			this->label13->Text = L"Key :";
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(6, 20);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(51, 19);
			this->checkBox6->TabIndex = 0;
			this->checkBox6->Text = L"Loot";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &Form3::checkBox6_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox5);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->comboBox5);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->checkBox4);
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->comboBox6);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->checkBox5);
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->comboBox4);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->checkBox3);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->comboBox3);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->checkBox2);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox2->ForeColor = System::Drawing::Color::White;
			this->groupBox2->Location = System::Drawing::Point(12, 124);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(285, 234);
			this->groupBox2->TabIndex = 8;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Skills";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &Form3::groupBox2_Enter);
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::Black;
			this->textBox5->ForeColor = System::Drawing::Color::White;
			this->textBox5->Location = System::Drawing::Point(203, 195);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(71, 21);
			this->textBox5->TabIndex = 25;
			this->textBox5->Text = L"100000";
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(153, 198);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(44, 15);
			this->label9->TabIndex = 24;
			this->label9->Text = L"Delay :";
			// 
			// comboBox5
			// 
			this->comboBox5->BackColor = System::Drawing::Color::Black;
			this->comboBox5->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox5->ForeColor = System::Drawing::Color::White;
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(35) {L" A", L" B", L" C", L" D", L" E", L" F", L" G", 
				L" H", L" I", L" J", L" K", L" L", L" M", L" N", L" O", L" P", L" Q", L" R", L" S", L" T", L" U", L" V", L" W", L" X", L" Y", 
				L" Z", L" Insert", L" Home", L" Del", L" End", L" Pg_Up", L" Pg_Down", L" Shift", L" Ctrl", L" Alt"});
			this->comboBox5->Location = System::Drawing::Point(47, 195);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(91, 23);
			this->comboBox5->TabIndex = 23;
			this->comboBox5->Text = L" End";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 198);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(35, 15);
			this->label10->TabIndex = 22;
			this->label10->Text = L"Key :";
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(6, 173);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(62, 19);
			this->checkBox4->TabIndex = 21;
			this->checkBox4->Text = L"Skill 4";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &Form3::checkBox4_CheckedChanged);
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::Black;
			this->textBox6->ForeColor = System::Drawing::Color::White;
			this->textBox6->Location = System::Drawing::Point(203, 144);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(71, 21);
			this->textBox6->TabIndex = 20;
			this->textBox6->Text = L"75000";
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(153, 147);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(44, 15);
			this->label11->TabIndex = 19;
			this->label11->Text = L"Delay :";
			// 
			// comboBox6
			// 
			this->comboBox6->BackColor = System::Drawing::Color::Black;
			this->comboBox6->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox6->ForeColor = System::Drawing::Color::White;
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(35) {L" A", L" B", L" C", L" D", L" E", L" F", L" G", 
				L" H", L" I", L" J", L" K", L" L", L" M", L" N", L" O", L" P", L" Q", L" R", L" S", L" T", L" U", L" V", L" W", L" X", L" Y", 
				L" Z", L" Insert", L" Home", L" Del", L" End", L" Pg_Up", L" Pg_Down", L" Shift", L" Ctrl", L" Alt"});
			this->comboBox6->Location = System::Drawing::Point(47, 144);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(91, 23);
			this->comboBox6->TabIndex = 18;
			this->comboBox6->Text = L" Shift";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(6, 147);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(35, 15);
			this->label12->TabIndex = 17;
			this->label12->Text = L"Key :";
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(6, 122);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(62, 19);
			this->checkBox5->TabIndex = 16;
			this->checkBox5->Text = L"Skill 3";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &Form3::checkBox5_CheckedChanged);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::Black;
			this->textBox4->ForeColor = System::Drawing::Color::White;
			this->textBox4->Location = System::Drawing::Point(203, 93);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(71, 21);
			this->textBox4->TabIndex = 15;
			this->textBox4->Text = L"50000";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(153, 96);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(44, 15);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Delay :";
			// 
			// comboBox4
			// 
			this->comboBox4->BackColor = System::Drawing::Color::Black;
			this->comboBox4->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox4->ForeColor = System::Drawing::Color::White;
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(35) {L" A", L" B", L" C", L" D", L" E", L" F", L" G", 
				L" H", L" I", L" J", L" K", L" L", L" M", L" N", L" O", L" P", L" Q", L" R", L" S", L" T", L" U", L" V", L" W", L" X", L" Y", 
				L" Z", L" Insert", L" Home", L" Del", L" End", L" Pg_Up", L" Pg_Down", L" Shift", L" Ctrl", L" Alt"});
			this->comboBox4->Location = System::Drawing::Point(47, 93);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(91, 23);
			this->comboBox4->TabIndex = 13;
			this->comboBox4->Text = L" Alt";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 96);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 15);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Key :";
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(6, 71);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(62, 19);
			this->checkBox3->TabIndex = 11;
			this->checkBox3->Text = L"Skill 2";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Form3::checkBox3_CheckedChanged);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::Black;
			this->textBox3->ForeColor = System::Drawing::Color::White;
			this->textBox3->Location = System::Drawing::Point(203, 42);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(71, 21);
			this->textBox3->TabIndex = 10;
			this->textBox3->Text = L"25000";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(153, 45);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(44, 15);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Delay :";
			// 
			// comboBox3
			// 
			this->comboBox3->BackColor = System::Drawing::Color::Black;
			this->comboBox3->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox3->ForeColor = System::Drawing::Color::White;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(35) {L" A", L" B", L" C", L" D", L" E", L" F", L" G", 
				L" H", L" I", L" J", L" K", L" L", L" M", L" N", L" O", L" P", L" Q", L" R", L" S", L" T", L" U", L" V", L" W", L" X", L" Y", 
				L" Z", L" Insert", L" Home", L" Del", L" End", L" Pg_Up", L" Pg_Down", L" Shift", L" Ctrl", L" Alt"});
			this->comboBox3->Location = System::Drawing::Point(47, 42);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(91, 23);
			this->comboBox3->TabIndex = 5;
			this->comboBox3->Text = L" Ctrl";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 45);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 15);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Key :";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(6, 20);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(62, 19);
			this->checkBox2->TabIndex = 0;
			this->checkBox2->Text = L"Skill 1";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Form3::checkBox2_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->comboBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(285, 106);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Attack ";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::Black;
			this->textBox2->ForeColor = System::Drawing::Color::White;
			this->textBox2->Location = System::Drawing::Point(203, 70);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(71, 21);
			this->textBox2->TabIndex = 8;
			this->textBox2->Text = L"1500";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(153, 73);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 15);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Delay :";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Black;
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(203, 42);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(71, 21);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"1";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(144, 48);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 15);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Mob(s) :";
			// 
			// comboBox2
			// 
			this->comboBox2->BackColor = System::Drawing::Color::Black;
			this->comboBox2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox2->ForeColor = System::Drawing::Color::White;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(35) {L" A", L" B", L" C", L" D", L" E", L" F", L" G", 
				L" H", L" I", L" J", L" K", L" L", L" M", L" N", L" O", L" P", L" Q", L" R", L" S", L" T", L" U", L" V", L" W", L" X", L" Y", 
				L" Z", L" Insert", L" Home", L" Del", L" End", L" Pg_Up", L" Pg_Down", L" Shift", L" Ctrl", L" Alt"});
			this->comboBox2->Location = System::Drawing::Point(48, 70);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(90, 23);
			this->comboBox2->TabIndex = 4;
			this->comboBox2->Text = L" C";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 15);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Key :";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 15);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Type :";
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::Color::Black;
			this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox1->ForeColor = System::Drawing::Color::White;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L" Normal", L" Double", L" Triple", L" Charged"});
			this->comboBox1->Location = System::Drawing::Point(48, 42);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(90, 23);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->Text = L" Normal";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(6, 20);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(65, 19);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Attack ";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form3::checkBox1_CheckedChanged);
			// 
			// Form3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(317, 479);
			this->ControlBox = false;
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form3";
			this->Text = L"Attack / Skills";
			this->Load += gcnew System::EventHandler(this, &Form3::Form3_Load);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	
};
}
