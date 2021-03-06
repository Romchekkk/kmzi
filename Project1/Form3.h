#pragma once

#include <msclr/marshal_cppstd.h>
#include "Form1.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// ?????? ??? Form3
	/// </summary>
	public ref class Form3 : public System::Windows::Forms::Form
	{
	private: CS* _cipher;
	public:
		Form3(CS cipher)
		{
			InitializeComponent();
			_cipher = new CS(cipher);
		}

	protected:
		/// <summary>
		/// ?????????? ??? ???????????? ???????.
		/// </summary>
		~Form3()
		{
			if (components)
			{
				delete components;
			}
			Application::Exit();
		}

	private: System::Windows::Forms::Label^ label2;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBoxMessage;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBoxAssociatedData;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBoxOutputFile;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBoxMessageNumber;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ textBoxCalcKeyWrite;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ textBoxCDWrite;

	private: System::Windows::Forms::Label^ label10;


	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ labelCondition;


	private:
		/// <summary>
		/// ???????????? ?????????? ????????????.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ????????? ????? ??? ????????? ???????????? ? ?? ????????? 
		/// ?????????? ????? ?????? ? ??????? ????????? ????.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBoxMessage = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBoxAssociatedData = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBoxOutputFile = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBoxMessageNumber = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBoxCalcKeyWrite = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBoxCDWrite = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->labelCondition = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(26, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 17);
			this->label2->TabIndex = 8;
			this->label2->Text = L"?????????:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(418, 84);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"?????";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form3::button1_Click);
			// 
			// textBoxMessage
			// 
			this->textBoxMessage->Location = System::Drawing::Point(29, 86);
			this->textBoxMessage->Name = L"textBoxMessage";
			this->textBoxMessage->ReadOnly = true;
			this->textBoxMessage->Size = System::Drawing::Size(322, 20);
			this->textBoxMessage->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(145, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(235, 31);
			this->label1->TabIndex = 9;
			this->label1->Text = L"CS ??????????";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(26, 107);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(186, 17);
			this->label3->TabIndex = 12;
			this->label3->Text = L"??????????????? ??????:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(418, 125);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"?????";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form3::button2_Click);
			// 
			// textBoxAssociatedData
			// 
			this->textBoxAssociatedData->Location = System::Drawing::Point(29, 127);
			this->textBoxAssociatedData->Name = L"textBoxAssociatedData";
			this->textBoxAssociatedData->ReadOnly = true;
			this->textBoxAssociatedData->Size = System::Drawing::Size(322, 20);
			this->textBoxAssociatedData->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(26, 149);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(179, 17);
			this->label4->TabIndex = 15;
			this->label4->Text = L"???? ???????? ?????????:";
			// 
			// button3
			// 
			this->button3->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button3->Location = System::Drawing::Point(418, 167);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 14;
			this->button3->Text = L"?????";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form3::button3_Click);
			// 
			// textBoxOutputFile
			// 
			this->textBoxOutputFile->Location = System::Drawing::Point(29, 169);
			this->textBoxOutputFile->Name = L"textBoxOutputFile";
			this->textBoxOutputFile->ReadOnly = true;
			this->textBoxOutputFile->Size = System::Drawing::Size(322, 20);
			this->textBoxOutputFile->TabIndex = 13;
			// 
			// button4
			// 
			this->button4->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button4->Location = System::Drawing::Point(212, 435);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(95, 23);
			this->button4->TabIndex = 16;
			this->button4->Text = L"????????????";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form3::button4_Click);
			// 
			// textBoxMessageNumber
			// 
			this->textBoxMessageNumber->Location = System::Drawing::Point(165, 336);
			this->textBoxMessageNumber->Name = L"textBoxMessageNumber";
			this->textBoxMessageNumber->ReadOnly = true;
			this->textBoxMessageNumber->Size = System::Drawing::Size(43, 20);
			this->textBoxMessageNumber->TabIndex = 17;
			this->textBoxMessageNumber->Text = L"1";
			this->textBoxMessageNumber->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label5->Location = System::Drawing::Point(26, 336);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(133, 17);
			this->label5->TabIndex = 18;
			this->label5->Text = L"????? ?????????:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(26, 191);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(233, 17);
			this->label6->TabIndex = 21;
			this->label6->Text = L"???? ???????? ??????????? ????";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(418, 230);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 20;
			this->button5->Text = L"?????";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form3::button5_Click);
			// 
			// textBoxCalcKeyWrite
			// 
			this->textBoxCalcKeyWrite->Location = System::Drawing::Point(29, 232);
			this->textBoxCalcKeyWrite->Name = L"textBoxCalcKeyWrite";
			this->textBoxCalcKeyWrite->ReadOnly = true;
			this->textBoxCalcKeyWrite->Size = System::Drawing::Size(322, 20);
			this->textBoxCalcKeyWrite->TabIndex = 19;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(26, 210);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(264, 17);
			this->label7->TabIndex = 22;
			this->label7->Text = L"(???????? ??????, ???? ?? ?????????):";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(26, 274);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(264, 17);
			this->label8->TabIndex = 26;
			this->label8->Text = L"(???????? ??????, ???? ?? ?????????):";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(26, 255);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(115, 17);
			this->label9->TabIndex = 25;
			this->label9->Text = L"???? ???????? c";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(418, 294);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 24;
			this->button6->Text = L"?????";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form3::button6_Click);
			// 
			// textBoxCDWrite
			// 
			this->textBoxCDWrite->Location = System::Drawing::Point(29, 296);
			this->textBoxCDWrite->Name = L"textBoxCDWrite";
			this->textBoxCDWrite->ReadOnly = true;
			this->textBoxCDWrite->Size = System::Drawing::Size(322, 20);
			this->textBoxCDWrite->TabIndex = 23;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->label10->Location = System::Drawing::Point(135, 263);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(7, 9);
			this->label10->TabIndex = 27;
			this->label10->Text = L"i";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(374, 230);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(22, 23);
			this->button7->TabIndex = 30;
			this->button7->Text = L"X";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form3::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(374, 294);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(22, 23);
			this->button8->TabIndex = 31;
			this->button8->Text = L"X";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form3::button8_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(29, 395);
			this->progressBar1->Margin = System::Windows::Forms::Padding(2);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(464, 19);
			this->progressBar1->TabIndex = 32;
			// 
			// labelCondition
			// 
			this->labelCondition->AutoSize = true;
			this->labelCondition->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->labelCondition->Location = System::Drawing::Point(26, 369);
			this->labelCondition->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelCondition->Name = L"labelCondition";
			this->labelCondition->Size = System::Drawing::Size(158, 17);
			this->labelCondition->TabIndex = 33;
			this->labelCondition->Text = L"???????? ??????????";
			// 
			// Form3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 469);
			this->Controls->Add(this->labelCondition);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBoxCDWrite);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBoxCalcKeyWrite);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBoxMessageNumber);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBoxOutputFile);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBoxAssociatedData);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBoxMessage);
			this->Name = L"Form3";
			this->Text = L"Form3";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	progressBar1->Value = 0;
	//labelCondition->Text = "???????? ??????????";
	labelCondition->Text = "???????? ????????????";
	string message = marshal_as<string>(textBoxMessage->Text);
	if (message == "" || message == "????????? ??? ????") {
		textBoxMessage->Text = "????????? ??? ????";
		return;
	}

	string ass = marshal_as<string>(textBoxAssociatedData->Text);
	if (ass == "" || ass == "????????? ??? ????") {
		textBoxAssociatedData->Text = "????????? ??? ????";
		return;
	}
	string output = marshal_as<string>(textBoxOutputFile->Text);
	if (output == "" || output == "????????? ??? ????") {
		textBoxOutputFile->Text = "????????? ??? ????";
		return;
	}
	progressBar1->Value = 25;
	bool imitResult = _cipher->checkImitationInsert(marshal_as<string>(textBoxMessage->Text), marshal_as<string>(textBoxAssociatedData->Text), marshal_as<string>(textBoxCalcKeyWrite->Text));
	if (imitResult == false) {
		labelCondition->Text = "???????????? ?? ?????? ????????! ?????? ??????????!";
	}
	else {
		string message = _cipher->decipher(marshal_as<string>(textBoxMessage->Text), marshal_as<string>(textBoxAssociatedData->Text), marshal_as<string>(textBoxCDWrite->Text));
		progressBar1->Value = 80;
		labelCondition->Text = "?????? ?????????????? ??????";

		ofstream outputFile;
		outputFile.open(marshal_as<string>(textBoxOutputFile->Text), std::ios::app);

		
		outputFile << message;

		labelCondition->Text = "?????? ????????? ???????";
		progressBar1->Value = 100;
		textBoxMessageNumber->Text = marshal_as<String^>(_cipher->getMessageNumber());
	}

}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openDlg = gcnew OpenFileDialog();
	if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
	{
		String^ fileName = openDlg->FileName;
		textBoxMessage->Text = fileName;
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openDlg = gcnew OpenFileDialog();
	if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
	{
		String^ fileName = openDlg->FileName;
		textBoxAssociatedData->Text = fileName;
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openDlg = gcnew OpenFileDialog();
	if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
	{
		String^ fileName = openDlg->FileName;
		textBoxOutputFile->Text = fileName;
	}
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openDlg = gcnew OpenFileDialog();
	if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
	{
		String^ fileName = openDlg->FileName;
		textBoxCalcKeyWrite->Text = fileName;
	}
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openDlg = gcnew OpenFileDialog();
	if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
	{
		String^ fileName = openDlg->FileName;
		textBoxCDWrite->Text = fileName;
	}
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxCalcKeyWrite->Text = "";
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxCDWrite->Text = "";
}
};
}
