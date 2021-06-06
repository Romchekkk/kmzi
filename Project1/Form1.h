#pragma once

#include <msclr/marshal_cppstd.h>
#include "CS.h"
#include "Form2.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxKey;
	protected:

	protected:
	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBoxIV;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBoxAlpha;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBoxI0;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ textBoxLambda;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ textBoxOLS1;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::TextBox^ textBoxOLS2;




	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::TextBox^ textBoxFolder;


	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBoxIV = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBoxAlpha = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBoxI0 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBoxLambda = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBoxOLS1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBoxOLS2 = (gcnew System::Windows::Forms::TextBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->textBoxFolder = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBoxKey
			// 
			this->textBoxKey->Location = System::Drawing::Point(35, 98);
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->ReadOnly = true;
			this->textBoxKey->Size = System::Drawing::Size(322, 20);
			this->textBoxKey->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(424, 96);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Обзор";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(132, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(276, 31);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Турбо шифрование";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(32, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Ключ:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(32, 119);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(190, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Инициализирующий вектор";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(424, 137);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Обзор";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBoxIV
			// 
			this->textBoxIV->Location = System::Drawing::Point(35, 139);
			this->textBoxIV->Name = L"textBoxIV";
			this->textBoxIV->ReadOnly = true;
			this->textBoxIV->Size = System::Drawing::Size(322, 20);
			this->textBoxIV->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(32, 161);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 17);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Альфа:";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(424, 179);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Обзор";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// textBoxAlpha
			// 
			this->textBoxAlpha->Location = System::Drawing::Point(35, 181);
			this->textBoxAlpha->Name = L"textBoxAlpha";
			this->textBoxAlpha->ReadOnly = true;
			this->textBoxAlpha->Size = System::Drawing::Size(322, 20);
			this->textBoxAlpha->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(32, 202);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(23, 17);
			this->label5->TabIndex = 14;
			this->label5->Text = L"i0:";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(424, 220);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Обзор";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// textBoxI0
			// 
			this->textBoxI0->Location = System::Drawing::Point(35, 222);
			this->textBoxI0->Name = L"textBoxI0";
			this->textBoxI0->ReadOnly = true;
			this->textBoxI0->Size = System::Drawing::Size(322, 20);
			this->textBoxI0->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(32, 245);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(183, 17);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Подстановочная матрица:";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(424, 263);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 16;
			this->button5->Text = L"Обзор";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// textBoxLambda
			// 
			this->textBoxLambda->Location = System::Drawing::Point(35, 265);
			this->textBoxLambda->Name = L"textBoxLambda";
			this->textBoxLambda->ReadOnly = true;
			this->textBoxLambda->Size = System::Drawing::Size(322, 20);
			this->textBoxLambda->TabIndex = 15;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(32, 286);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(50, 17);
			this->label7->TabIndex = 20;
			this->label7->Text = L"ОЛК1:";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(424, 304);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 19;
			this->button6->Text = L"Обзор";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// textBoxOLS1
			// 
			this->textBoxOLS1->Location = System::Drawing::Point(35, 306);
			this->textBoxOLS1->Name = L"textBoxOLS1";
			this->textBoxOLS1->ReadOnly = true;
			this->textBoxOLS1->Size = System::Drawing::Size(322, 20);
			this->textBoxOLS1->TabIndex = 18;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(32, 326);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(50, 17);
			this->label8->TabIndex = 23;
			this->label8->Text = L"ОЛК2:";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(424, 344);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 22;
			this->button7->Text = L"Обзор";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// textBoxOLS2
			// 
			this->textBoxOLS2->Location = System::Drawing::Point(35, 346);
			this->textBoxOLS2->Name = L"textBoxOLS2";
			this->textBoxOLS2->ReadOnly = true;
			this->textBoxOLS2->Size = System::Drawing::Size(322, 20);
			this->textBoxOLS2->TabIndex = 21;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(240, 383);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 23);
			this->button9->TabIndex = 27;
			this->button9->Text = L"Далее";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(32, 35);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(107, 17);
			this->label9->TabIndex = 30;
			this->label9->Text = L"Найти в папке:";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(424, 53);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 29;
			this->button8->Text = L"Обзор";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// textBoxFolder
			// 
			this->textBoxFolder->Location = System::Drawing::Point(35, 55);
			this->textBoxFolder->Name = L"textBoxFolder";
			this->textBoxFolder->ReadOnly = true;
			this->textBoxFolder->Size = System::Drawing::Size(322, 20);
			this->textBoxFolder->TabIndex = 28;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 428);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->textBoxFolder);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->textBoxOLS2);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBoxOLS1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBoxLambda);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBoxI0);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBoxAlpha);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBoxIV);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBoxKey);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openDlg = gcnew OpenFileDialog();
		if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
		{
			String^ fileName = openDlg->FileName;
			textBoxKey->Text = fileName;
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openDlg = gcnew OpenFileDialog();
		if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
		{
			String^ fileName = openDlg->FileName;
			textBoxIV->Text = fileName;
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openDlg = gcnew OpenFileDialog();
		if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
		{
			String^ fileName = openDlg->FileName;
			textBoxAlpha->Text = fileName;
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openDlg = gcnew OpenFileDialog();
		if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
		{
			String^ fileName = openDlg->FileName;
			textBoxI0->Text = fileName;
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openDlg = gcnew OpenFileDialog();
		if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
		{
			String^ fileName = openDlg->FileName;
			textBoxLambda->Text = fileName;
		}
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openDlg = gcnew OpenFileDialog();
		if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
		{
			String^ fileName = openDlg->FileName;
			textBoxOLS1->Text = fileName;
		}
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openDlg = gcnew OpenFileDialog();
		if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
		{
			String^ fileName = openDlg->FileName;
			textBoxOLS2->Text = fileName;
		}
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		FolderBrowserDialog^ openDlg = gcnew FolderBrowserDialog();
		if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
		{
			String^ fileName = openDlg->SelectedPath;
			textBoxFolder->Text = fileName;
			textBoxKey->Text = fileName + "\\key.txt";
			textBoxIV->Text = fileName + "\\iv.txt";
			textBoxI0->Text = fileName + "\\i0.txt";
			textBoxAlpha->Text = fileName + "\\alpha.txt";
			textBoxLambda->Text = fileName + "\\lambda.txt";
			textBoxOLS1->Text = fileName + "\\OLS1.txt";
			textBoxOLS2->Text = fileName + "\\OLS2.txt";
		}
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e);
};
}
