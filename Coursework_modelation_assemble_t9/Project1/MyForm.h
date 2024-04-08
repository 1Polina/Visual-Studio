#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include "Header.h"
#include <sstream>

using namespace std;

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using System::Text::RegularExpressions::Regex;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::TextBox^ textBoxWords;

	private: System::Windows::Forms::TextBox^ textBox1;
		   System::String^ textResult;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ d;


	private: System::Windows::Forms::Button^ del;
	private: System::Windows::Forms::Button^ clear;
	private: System::Windows::Forms::Button^ space;
	private: System::Windows::Forms::Button^ one;
	private: System::Windows::Forms::Button^ two;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::Button^ button28;
	private: System::Windows::Forms::Button^ button20;


	private: System::Windows::Forms::Button^ button31;
	private: System::Windows::Forms::Button^ button32;
	private: System::Windows::Forms::Button^ button33;
	private: System::Windows::Forms::Button^ button34;
	private: System::Windows::Forms::Button^ button35;
	private: System::Windows::Forms::Button^ button36;
	private: System::Windows::Forms::Button^ button37;

		   /* Void buttonAddWords_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   string words = msclr::interop::marshal_as<string>(textBoxWords->Text);
			   BinaryTree tree;
			   addWordsToBinaryTree(tree, words);
			   tree.writeToDisk();
			   textBoxWords->Text = "";
		   }*/
	private: System::Windows::Forms::Button^ ch;
	private: System::Windows::Forms::Button^ txt;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Button^ chas;
	private: System::Windows::Forms::Button^ txxt;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBoxWords = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->d = (gcnew System::Windows::Forms::Button());
			this->del = (gcnew System::Windows::Forms::Button());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->space = (gcnew System::Windows::Forms::Button());
			this->one = (gcnew System::Windows::Forms::Button());
			this->two = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->button37 = (gcnew System::Windows::Forms::Button());
			this->ch = (gcnew System::Windows::Forms::Button());
			this->txt = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->chas = (gcnew System::Windows::Forms::Button());
			this->txxt = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBoxWords
			// 
			this->textBoxWords->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxWords->Location = System::Drawing::Point(0, 383);
			this->textBoxWords->Multiline = true;
			this->textBoxWords->Name = L"textBoxWords";
			this->textBoxWords->Size = System::Drawing::Size(372, 37);
			this->textBoxWords->TabIndex = 1;
			this->textBoxWords->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxWords_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->textBox1->Location = System::Drawing::Point(119, 426);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(140, 26);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->textBox2->Location = System::Drawing::Point(0, 426);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(110, 26);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->textBox3->Location = System::Drawing::Point(265, 426);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(107, 26);
			this->textBox3->TabIndex = 5;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::MenuBar;
			this->textBox4->Location = System::Drawing::Point(208, 12);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox4->Size = System::Drawing::Size(191, 318);
			this->textBox4->TabIndex = 6;
			// 
			// d
			// 
			this->d->BackColor = System::Drawing::Color::Lavender;
			this->d->Location = System::Drawing::Point(-1, 602);
			this->d->Name = L"d";
			this->d->Size = System::Drawing::Size(46, 48);
			this->d->TabIndex = 7;
			this->d->Text = L"dic";
			this->d->UseVisualStyleBackColor = false;
			this->d->Click += gcnew System::EventHandler(this, &MyForm::d_Click);
			// 
			// del
			// 
			this->del->BackColor = System::Drawing::Color::Lavender;
			this->del->Location = System::Drawing::Point(338, 602);
			this->del->Name = L"del";
			this->del->Size = System::Drawing::Size(66, 48);
			this->del->TabIndex = 10;
			this->del->Text = L"delete";
			this->del->UseVisualStyleBackColor = false;
			this->del->Click += gcnew System::EventHandler(this, &MyForm::del_Click);
			// 
			// clear
			// 
			this->clear->BackColor = System::Drawing::Color::LightSteelBlue;
			this->clear->Location = System::Drawing::Point(315, 656);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(89, 33);
			this->clear->TabIndex = 11;
			this->clear->Text = L"clear";
			this->clear->UseVisualStyleBackColor = false;
			this->clear->Click += gcnew System::EventHandler(this, &MyForm::clear_Click);
			// 
			// space
			// 
			this->space->BackColor = System::Drawing::Color::Azure;
			this->space->Location = System::Drawing::Point(98, 656);
			this->space->Name = L"space";
			this->space->Size = System::Drawing::Size(211, 33);
			this->space->TabIndex = 12;
			this->space->Text = L"space";
			this->space->UseVisualStyleBackColor = false;
			this->space->Click += gcnew System::EventHandler(this, &MyForm::space_Click);
			// 
			// one
			// 
			this->one->BackColor = System::Drawing::Color::Silver;
			this->one->Location = System::Drawing::Point(-1, 458);
			this->one->Name = L"one";
			this->one->Size = System::Drawing::Size(45, 30);
			this->one->TabIndex = 13;
			this->one->Text = L"1";
			this->one->UseVisualStyleBackColor = false;
			this->one->Click += gcnew System::EventHandler(this, &MyForm::one_Click);
			// 
			// two
			// 
			this->two->BackColor = System::Drawing::Color::Silver;
			this->two->Location = System::Drawing::Point(39, 458);
			this->two->Name = L"two";
			this->two->Size = System::Drawing::Size(45, 30);
			this->two->TabIndex = 14;
			this->two->Text = L"2";
			this->two->UseVisualStyleBackColor = false;
			this->two->Click += gcnew System::EventHandler(this, &MyForm::two_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Silver;
			this->button1->Location = System::Drawing::Point(79, 458);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(45, 30);
			this->button1->TabIndex = 15;
			this->button1->Text = L"3";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Silver;
			this->button2->Location = System::Drawing::Point(119, 458);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(45, 30);
			this->button2->TabIndex = 16;
			this->button2->Text = L"4";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Silver;
			this->button3->Location = System::Drawing::Point(159, 458);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(45, 30);
			this->button3->TabIndex = 17;
			this->button3->Text = L"5";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Silver;
			this->button4->Location = System::Drawing::Point(199, 458);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(45, 30);
			this->button4->TabIndex = 18;
			this->button4->Text = L"6";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Silver;
			this->button5->Location = System::Drawing::Point(239, 458);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(45, 30);
			this->button5->TabIndex = 19;
			this->button5->Text = L"7";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Silver;
			this->button6->Location = System::Drawing::Point(279, 458);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(45, 30);
			this->button6->TabIndex = 20;
			this->button6->Text = L"8";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::Silver;
			this->button7->Location = System::Drawing::Point(319, 458);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(45, 30);
			this->button7->TabIndex = 21;
			this->button7->Text = L"9";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::Silver;
			this->button8->Location = System::Drawing::Point(359, 458);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(44, 30);
			this->button8->TabIndex = 22;
			this->button8->Text = L"0";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::Silver;
			this->button9->Location = System::Drawing::Point(0, 494);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(45, 48);
			this->button9->TabIndex = 23;
			this->button9->Text = L"q";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::LightSteelBlue;
			this->button10->Location = System::Drawing::Point(0, 656);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(92, 35);
			this->button10->TabIndex = 24;
			this->button10->Text = L"clear dic";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::Silver;
			this->button11->Location = System::Drawing::Point(39, 494);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(45, 48);
			this->button11->TabIndex = 25;
			this->button11->Text = L"w";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::Silver;
			this->button12->Location = System::Drawing::Point(79, 494);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(45, 48);
			this->button12->TabIndex = 26;
			this->button12->Text = L"e";
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::Silver;
			this->button13->Location = System::Drawing::Point(119, 494);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(45, 48);
			this->button13->TabIndex = 27;
			this->button13->Text = L"r";
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::Color::Silver;
			this->button14->Location = System::Drawing::Point(159, 494);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(45, 48);
			this->button14->TabIndex = 28;
			this->button14->Text = L"t";
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::Color::Silver;
			this->button15->Location = System::Drawing::Point(199, 494);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(45, 48);
			this->button15->TabIndex = 29;
			this->button15->Text = L"y";
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button16
			// 
			this->button16->BackColor = System::Drawing::Color::Silver;
			this->button16->Location = System::Drawing::Point(239, 494);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(45, 48);
			this->button16->TabIndex = 30;
			this->button16->Text = L"u";
			this->button16->UseVisualStyleBackColor = false;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button17
			// 
			this->button17->BackColor = System::Drawing::Color::Silver;
			this->button17->Location = System::Drawing::Point(279, 494);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(45, 48);
			this->button17->TabIndex = 31;
			this->button17->Text = L"i";
			this->button17->UseVisualStyleBackColor = false;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// button18
			// 
			this->button18->BackColor = System::Drawing::Color::Silver;
			this->button18->Location = System::Drawing::Point(319, 494);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(45, 48);
			this->button18->TabIndex = 32;
			this->button18->Text = L"o";
			this->button18->UseVisualStyleBackColor = false;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// button19
			// 
			this->button19->BackColor = System::Drawing::Color::Silver;
			this->button19->Location = System::Drawing::Point(359, 494);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(45, 48);
			this->button19->TabIndex = 33;
			this->button19->Text = L"p";
			this->button19->UseVisualStyleBackColor = false;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			// 
			// button21
			// 
			this->button21->BackColor = System::Drawing::Color::Silver;
			this->button21->Location = System::Drawing::Point(298, 548);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(45, 48);
			this->button21->TabIndex = 42;
			this->button21->Text = L"k";
			this->button21->UseVisualStyleBackColor = false;
			this->button21->Click += gcnew System::EventHandler(this, &MyForm::button21_Click);
			// 
			// button22
			// 
			this->button22->BackColor = System::Drawing::Color::Silver;
			this->button22->Location = System::Drawing::Point(258, 548);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(45, 48);
			this->button22->TabIndex = 41;
			this->button22->Text = L"j";
			this->button22->UseVisualStyleBackColor = false;
			this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
			// 
			// button23
			// 
			this->button23->BackColor = System::Drawing::Color::Silver;
			this->button23->Location = System::Drawing::Point(218, 548);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(45, 48);
			this->button23->TabIndex = 40;
			this->button23->Text = L"h";
			this->button23->UseVisualStyleBackColor = false;
			this->button23->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
			// 
			// button24
			// 
			this->button24->BackColor = System::Drawing::Color::Silver;
			this->button24->Location = System::Drawing::Point(178, 548);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(45, 48);
			this->button24->TabIndex = 39;
			this->button24->Text = L"g";
			this->button24->UseVisualStyleBackColor = false;
			this->button24->Click += gcnew System::EventHandler(this, &MyForm::button24_Click);
			// 
			// button25
			// 
			this->button25->BackColor = System::Drawing::Color::Silver;
			this->button25->Location = System::Drawing::Point(138, 548);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(45, 48);
			this->button25->TabIndex = 38;
			this->button25->Text = L"f";
			this->button25->UseVisualStyleBackColor = false;
			this->button25->Click += gcnew System::EventHandler(this, &MyForm::button25_Click);
			// 
			// button26
			// 
			this->button26->BackColor = System::Drawing::Color::Silver;
			this->button26->Location = System::Drawing::Point(98, 548);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(45, 48);
			this->button26->TabIndex = 37;
			this->button26->Text = L"d";
			this->button26->UseVisualStyleBackColor = false;
			this->button26->Click += gcnew System::EventHandler(this, &MyForm::button26_Click);
			// 
			// button27
			// 
			this->button27->BackColor = System::Drawing::Color::Silver;
			this->button27->Location = System::Drawing::Point(58, 548);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(45, 48);
			this->button27->TabIndex = 36;
			this->button27->Text = L"s";
			this->button27->UseVisualStyleBackColor = false;
			this->button27->Click += gcnew System::EventHandler(this, &MyForm::button27_Click);
			// 
			// button28
			// 
			this->button28->BackColor = System::Drawing::Color::Silver;
			this->button28->Location = System::Drawing::Point(18, 548);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(45, 48);
			this->button28->TabIndex = 35;
			this->button28->Text = L"a";
			this->button28->UseVisualStyleBackColor = false;
			this->button28->Click += gcnew System::EventHandler(this, &MyForm::button28_Click);
			// 
			// button20
			// 
			this->button20->BackColor = System::Drawing::Color::Silver;
			this->button20->Location = System::Drawing::Point(338, 548);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(45, 48);
			this->button20->TabIndex = 43;
			this->button20->Text = L"l";
			this->button20->UseVisualStyleBackColor = false;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
			// 
			// button31
			// 
			this->button31->BackColor = System::Drawing::Color::Silver;
			this->button31->Location = System::Drawing::Point(288, 602);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(45, 48);
			this->button31->TabIndex = 50;
			this->button31->Text = L"m";
			this->button31->UseVisualStyleBackColor = false;
			this->button31->Click += gcnew System::EventHandler(this, &MyForm::button31_Click);
			// 
			// button32
			// 
			this->button32->BackColor = System::Drawing::Color::Silver;
			this->button32->Location = System::Drawing::Point(248, 602);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(45, 48);
			this->button32->TabIndex = 49;
			this->button32->Text = L"n";
			this->button32->UseVisualStyleBackColor = false;
			this->button32->Click += gcnew System::EventHandler(this, &MyForm::button32_Click);
			// 
			// button33
			// 
			this->button33->BackColor = System::Drawing::Color::Silver;
			this->button33->Location = System::Drawing::Point(208, 602);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(45, 48);
			this->button33->TabIndex = 48;
			this->button33->Text = L"b";
			this->button33->UseVisualStyleBackColor = false;
			this->button33->Click += gcnew System::EventHandler(this, &MyForm::button33_Click);
			// 
			// button34
			// 
			this->button34->BackColor = System::Drawing::Color::Silver;
			this->button34->Location = System::Drawing::Point(168, 602);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(45, 48);
			this->button34->TabIndex = 47;
			this->button34->Text = L"v";
			this->button34->UseVisualStyleBackColor = false;
			this->button34->Click += gcnew System::EventHandler(this, &MyForm::button34_Click);
			// 
			// button35
			// 
			this->button35->BackColor = System::Drawing::Color::Silver;
			this->button35->Location = System::Drawing::Point(128, 602);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(45, 48);
			this->button35->TabIndex = 46;
			this->button35->Text = L"c";
			this->button35->UseVisualStyleBackColor = false;
			this->button35->Click += gcnew System::EventHandler(this, &MyForm::button35_Click);
			// 
			// button36
			// 
			this->button36->BackColor = System::Drawing::Color::Silver;
			this->button36->Location = System::Drawing::Point(88, 602);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(45, 48);
			this->button36->TabIndex = 45;
			this->button36->Text = L"x";
			this->button36->UseVisualStyleBackColor = false;
			this->button36->Click += gcnew System::EventHandler(this, &MyForm::button36_Click);
			// 
			// button37
			// 
			this->button37->BackColor = System::Drawing::Color::Silver;
			this->button37->Location = System::Drawing::Point(48, 602);
			this->button37->Name = L"button37";
			this->button37->Size = System::Drawing::Size(45, 48);
			this->button37->TabIndex = 44;
			this->button37->Text = L"z";
			this->button37->UseVisualStyleBackColor = false;
			this->button37->Click += gcnew System::EventHandler(this, &MyForm::button37_Click);
			// 
			// ch
			// 
			this->ch->BackColor = System::Drawing::Color::Thistle;
			this->ch->Location = System::Drawing::Point(378, 383);
			this->ch->Name = L"ch";
			this->ch->Size = System::Drawing::Size(33, 75);
			this->ch->TabIndex = 51;
			this->ch->Text = L"add";
			this->ch->UseVisualStyleBackColor = false;
			this->ch->Click += gcnew System::EventHandler(this, &MyForm::ch_Click);
			// 
			// txt
			// 
			this->txt->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->txt->ForeColor = System::Drawing::SystemColors::MenuText;
			this->txt->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"txt.Image")));
			this->txt->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->txt->Location = System::Drawing::Point(342, 336);
			this->txt->Name = L"txt";
			this->txt->Size = System::Drawing::Size(57, 41);
			this->txt->TabIndex = 52;
			this->txt->Text = L"chastota";
			this->txt->UseVisualStyleBackColor = false;
			this->txt->Click += gcnew System::EventHandler(this, &MyForm::txt_Click);
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::SystemColors::MenuBar;
			this->textBox5->Location = System::Drawing::Point(12, 12);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox5->Size = System::Drawing::Size(192, 318);
			this->textBox5->TabIndex = 53;
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::SystemColors::Window;
			this->textBox6->Location = System::Drawing::Point(3, 351);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(110, 26);
			this->textBox6->TabIndex = 54;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox6_TextChanged);
			// 
			// chas
			// 
			this->chas->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->chas->ForeColor = System::Drawing::SystemColors::MenuText;
			this->chas->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"chas.Image")));
			this->chas->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->chas->Location = System::Drawing::Point(189, 336);
			this->chas->Name = L"chas";
			this->chas->Size = System::Drawing::Size(141, 41);
			this->chas->TabIndex = 55;
			this->chas->Text = L"chastota txt file";
			this->chas->UseVisualStyleBackColor = false;
			this->chas->Click += gcnew System::EventHandler(this, &MyForm::chas_Click_1);
			// 
			// txxt
			// 
			this->txxt->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->txxt->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"txxt.BackgroundImage")));
			this->txxt->ForeColor = System::Drawing::SystemColors::MenuText;
			this->txxt->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"txxt.Image")));
			this->txxt->Location = System::Drawing::Point(119, 336);
			this->txxt->Name = L"txxt";
			this->txxt->Size = System::Drawing::Size(64, 41);
			this->txxt->TabIndex = 56;
			this->txxt->Text = L"txt file";
			this->txxt->UseVisualStyleBackColor = false;
			this->txxt->Click += gcnew System::EventHandler(this, &MyForm::txxt_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(411, 734);
			this->Controls->Add(this->txxt);
			this->Controls->Add(this->chas);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->txt);
			this->Controls->Add(this->ch);
			this->Controls->Add(this->button31);
			this->Controls->Add(this->button32);
			this->Controls->Add(this->button33);
			this->Controls->Add(this->button34);
			this->Controls->Add(this->button35);
			this->Controls->Add(this->button36);
			this->Controls->Add(this->button37);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button22);
			this->Controls->Add(this->button23);
			this->Controls->Add(this->button24);
			this->Controls->Add(this->button25);
			this->Controls->Add(this->button26);
			this->Controls->Add(this->button27);
			this->Controls->Add(this->button28);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->two);
			this->Controls->Add(this->one);
			this->Controls->Add(this->space);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->del);
			this->Controls->Add(this->d);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBoxWords);
			this->Controls->Add(this->textBox4);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(433, 790);
			this->MinimumSize = System::Drawing::Size(433, 790);
			this->Name = L"MyForm";
			this->Text = L"T9";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void buttonAddWords_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
		   bool HasRussianLetters(String^ input)
		   {
			   try {
				   Regex^ regex = gcnew Regex("[а-яА-Я]");
				   if (regex->IsMatch(input))
				   {
					   textBoxWords->Text = " ";
					   throw erException("Обнаружены русские буквы!");
				   }
			   }
			   catch (exception& ex)
			   {
				   String^ message = "нельзя вводить русские буквы!";
				   MessageBox::Show(message, "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   }
			   catch (erException& ex)
			   {
				   String^ message = "нельзя вводить русские буквы!";
				   MessageBox::Show(message, "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   }
		   }

	private: System::Void textBoxWords_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		string words = msclr::interop::marshal_as<string>(textBoxWords->Text);
		String^ input = textBoxWords->Text;
		try {
			System::Windows::Forms::TextBox^ textBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
			if (textBox->Text->Length > 15) {
				textBox->Text = textBox->Text->Substring(0, 15); // Обрезаем текст до 15 символов
				throw erException("Input exceeds the character limit of 15!");
			}
		}
		catch (erException& ex) {
			String^ message = "нельзя вводить больше 15 символов!";
			MessageBox::Show(message, "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (exception& ex) {
			String^ message = "нельзя вводить больше 15 символов!";
			MessageBox::Show(message, "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}


		bool hasRussianLetters = HasRussianLetters(input);

		// Открываем файл и сравниваем каждое слово с textBoxWord
		ifstream file("words.txt");
		ifstream file2("words2.txt");
		ifstream file3("words3.txt");
		if (file.is_open())
		{
			string word;
			while (getline(file, word))
			{
				// Вычисляем расстояние Левенштейна между словами
				int distance = LevenshteinDistance(words, word);

				// Выводим слово, если расстояние меньше или равно заданному порогу
				if (distance <= 2) {
					System::String^ textResult = msclr::interop::marshal_as<System::String^>(word);
					textBox1->Text = textResult;
				}
			}

			while (getline(file2, word))
			{
				// Вычисляем расстояние Левенштейна между словами
				int distance = LevenshteinDistance(words, word);

				// Выводим слово, если расстояние меньше или равно заданному порогу
				if (distance <= 2) {
					System::String^ textResult = msclr::interop::marshal_as<System::String^>(word);
					textBox2->Text = textResult;
				}
			}
			while (getline(file3, word))
			{
				// Вычисляем расстояние Левенштейна между словами
				int distance = LevenshteinDistance(words, word);

				// Выводим слово, если расстояние меньше или равно заданному порогу
				if (distance <= 2) {
					System::String^ textResult = msclr::interop::marshal_as<System::String^>(word);
					textBox3->Text = textResult;
				}
			}

			file.close();
			file2.close();
			file3.close();
		}
		else
		{
			cout << "Ошибка открытия файла" << endl;
		}
		if (words == "") {
			textBox1->Text = "";
			textBox2->Text = "";
			textBox3->Text = "";
		}
	}

private: System::Void d_Click(System::Object^ sender, System::EventArgs^ e) { //выводим содержимое файла в textBox
	BinaryTree tree;
	readFileToBinaryTree(tree); // read words from file and convert to binary tree
	string words = msclr::interop::marshal_as<string>(textBoxWords->Text);
	addWordsToBinaryTree(tree, words); // add new words to binary tree
	tree.writeToDisk();
	textBoxWords->Text = "";
	string filename = "words.txt";
	LoadFileContentsToTextBox(textBox4, filename);
}

private: System::Void del_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ text = textBoxWords->Text;

    // Проверяем, что текст не пустой
		if (!String::IsNullOrEmpty(text))
		{
			 text = text->Substring(0, text->Length - 1);
			 textBoxWords->Text = text;
		}
}

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	const string filename = "word_frequencies.txt";
	LoadWordFrequencies(frequencyMap, filename);
}
private: System::Void ch_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox4->Clear();
	string word = msclr::interop::marshal_as<string>(textBoxWords->Text);
	frequencyMap[word]++;

	wordQueue = priority_queue<WordFrequency>(); // Очищаем очередь перед каждым заполнением

	for (const auto& pair : frequencyMap) {
		wordQueue.push(WordFrequency(pair.first, pair.second));
	}
	while (!wordQueue.empty()) {
		WordFrequency wf = wordQueue.top();
		wordQueue.pop();
		System::String^ wordFrequency = gcnew System::String(wf.word.c_str()) + " - " + wf.frequency.ToString() + " раз" + Environment::NewLine;
		textBox4->AppendText(wordFrequency);
	}

	const string filename = "word_frequencies.txt";
	SaveWordFrequencies(frequencyMap, filename);
	ifstream inputFile("word_frequencies.txt");
	ofstream outputFile("words.txt");

	char c;
	while (inputFile.get(c)) {
		if (!isdigit(c)) {
			outputFile << c;
		}
	}


	inputFile.close();
	outputFile.close();
}

private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	const string filename = "word_frequencies.txt";
	SaveWordFrequencies(frequencyMap, filename);
}

private: System::Void txt_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox4->Clear();

	// Получаем текст из textBox
	System::String^ text = textBox5->Text;

	// Преобразуем текст в строку C++
	string cppText = msclr::interop::marshal_as<string>(text);

	// Вызываем функцию для расчета частоты слов
	frequencyMap = CalculateWordFrequency(cppText); // удалено объявление frequencyMap

	priority_queue<WordFrequency> wordQueue;

	// Заполняем очередь с приоритетом
	for (const auto& pair : frequencyMap) {
		wordQueue.push(WordFrequency(pair.first, pair.second));
	}

	// Отображаем результаты в textBox4
	while (!wordQueue.empty()) {
		WordFrequency wf = wordQueue.top();
		wordQueue.pop();
		System::String^ wordFrequency = gcnew System::String(wf.word.c_str()) + " - " + wf.frequency.ToString() + " раз" + Environment::NewLine;
		textBox4->AppendText(wordFrequency);
	}

	const string filename = "text.txt";
	SaveWordFrequencies(frequencyMap, filename);
	ifstream inputFile("text.txt");
	ofstream outputFile("words.txt");

	char c;
	while (inputFile.get(c)) {
		if (!isdigit(c)) {
			outputFile << c;
		}
	}


	inputFile.close();
	outputFile.close();
}

	   unordered_map<string, int> CalculateWordFrequency(const string& text) {
		   unordered_map<string, int> tempFrequencyMap; // создаем временный контейнер

		   istringstream iss(text);
		   string word;

		   while (iss >> word) {
			   tempFrequencyMap[word]++;
		   }

		   // Обновляем значения в основной frequencyMap, чтобы сохранить предыдущие значения
		   for (const auto& pair : tempFrequencyMap) {
			   frequencyMap[pair.first] += pair.second;
		   }

		   return frequencyMap;
	   }

	   void readSelectedFile(const string& filename) {
		   ifstream file(filename);
		   if (file.is_open()) {
			   string line;
			   string fileContent;
			   while (getline(file, line)) {
				   fileContent += line + '\n';
			   }
			   file.close();
			   System::String^ textResult = msclr::interop::marshal_as<System::String^>(fileContent);
			   textBox5->Text = textResult;
		   }
	   }

private: System::Void chas_Click_1(System::Object^ sender, System::EventArgs^ e) {
	textBox4->Clear();

	String^ text = textBox5->Text;
	string cppText = msclr::interop::marshal_as<string>(text);

	// Очищаем frequencyMap перед каждым заполнением
	frequencyMap.clear();

	// Разделяем текст на отдельные слова и увеличиваем частоту каждого слова
	istringstream iss(cppText);
	string word;
	while (iss >> word) {
		frequencyMap[word]++;
	}

	// Обновляем очередь с приоритетом
	wordQueue = priority_queue<WordFrequency>(); // Очищаем очередь перед каждым заполнением
	for (const auto& pair : frequencyMap) {
		wordQueue.push(WordFrequency(pair.first, pair.second));
	}

	// Отображаем результаты в textBox4
	while (!wordQueue.empty()) {
		WordFrequency wf = wordQueue.top();
		wordQueue.pop();
		String^ wordFrequency = gcnew System::String(wf.word.c_str()) + " - " + wf.frequency.ToString() + " раз" + Environment::NewLine;
		textBox4->AppendText(wordFrequency);
	}

	const string filename = "word_frequencies.txt";
	SaveWordFrequencies(frequencyMap, filename);

	ifstream inputFile("word_frequencies.txt");
	ofstream outputFile("words.txt");
	char c;
	while (inputFile.get(c)) {
		if (!std::isdigit(c)) {
			outputFile << c;
		}
	}

	inputFile.close();
	outputFile.close();
}
private: System::Void txxt_Click(System::Object^ sender, System::EventArgs^ e) {
	string word = msclr::interop::marshal_as<string>(textBox6->Text);
	readSelectedFile(word);
}
private: System::Void a_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "a";
}
private: System::Void b_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "b";
}
private: System::Void clear_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Clear();
}
private: System::Void space_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += " ";
}
private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "p";
}
private: System::Void button37_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "z";
}
private: System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "m";
}
private: System::Void button32_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "n";
}
private: System::Void button33_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "b";
}
private: System::Void button34_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "v";
}
private: System::Void button35_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "c";
}
private: System::Void button36_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "x";
}
private: System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox4->Text = "";
}
private: System::Void one_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "1";
}
private: System::Void two_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "2";
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "3";
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "4";
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "5";
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "6";
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "7";
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "8";
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "9";
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "0";
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "q";
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "w";
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "e";
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "r";
}
private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "t";
}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "y";
}
private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "u";
}
private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "i";
}
private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "o";
}
private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "a";
}
private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "s";
}
private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "d";
}
private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "f";
}
private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "g";
}
private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "h";
}
private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "j";
}
private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "k";
}
private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxWords->Text += "l";
}
};
}