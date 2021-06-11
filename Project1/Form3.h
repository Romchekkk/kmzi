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
	/// Сводка для Form3
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
		/// Освободить все используемые ресурсы.
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
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ labelCondition;





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
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->labelCondition = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(35, 130);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(244, 20);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Зашифрованое сообщение:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(557, 153);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Обзор";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form3::button1_Click);
			// 
			// textBoxMessage
			// 
			this->textBoxMessage->Location = System::Drawing::Point(39, 155);
			this->textBoxMessage->Margin = System::Windows::Forms::Padding(4);
			this->textBoxMessage->Name = L"textBoxMessage";
			this->textBoxMessage->ReadOnly = true;
			this->textBoxMessage->Size = System::Drawing::Size(428, 22);
			this->textBoxMessage->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(172, 11);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(351, 39);
			this->label1->TabIndex = 9;
			this->label1->Text = L"CS расшифрование";
			this->label1->Click += gcnew System::EventHandler(this, &Form3::label1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(35, 218);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(235, 20);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Ассоциированные данные:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(557, 240);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 28);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Обзор";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form3::button2_Click);
			// 
			// textBoxAssociatedData
			// 
			this->textBoxAssociatedData->Location = System::Drawing::Point(39, 242);
			this->textBoxAssociatedData->Margin = System::Windows::Forms::Padding(4);
			this->textBoxAssociatedData->Name = L"textBoxAssociatedData";
			this->textBoxAssociatedData->ReadOnly = true;
			this->textBoxAssociatedData->Size = System::Drawing::Size(428, 22);
			this->textBoxAssociatedData->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(35, 305);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(243, 20);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Куда поместить результат:";
			// 
			// button3
			// 
			this->button3->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button3->Location = System::Drawing::Point(557, 327);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 28);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Обзор";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form3::button3_Click);
			// 
			// textBoxOutputFile
			// 
			this->textBoxOutputFile->Location = System::Drawing::Point(39, 330);
			this->textBoxOutputFile->Margin = System::Windows::Forms::Padding(4);
			this->textBoxOutputFile->Name = L"textBoxOutputFile";
			this->textBoxOutputFile->ReadOnly = true;
			this->textBoxOutputFile->Size = System::Drawing::Size(428, 22);
			this->textBoxOutputFile->TabIndex = 13;
			// 
			// button4
			// 
			this->button4->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button4->Location = System::Drawing::Point(289, 484);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(127, 28);
			this->button4->TabIndex = 16;
			this->button4->Text = L"Расшифровать";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form3::button4_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(39, 408);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(618, 23);
			this->progressBar1->TabIndex = 17;
			this->progressBar1->Click += gcnew System::EventHandler(this, &Form3::progressBar1_Click);
			// 
			// labelCondition
			// 
			this->labelCondition->AutoSize = true;
			this->labelCondition->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->labelCondition->Location = System::Drawing::Point(36, 379);
			this->labelCondition->Name = L"labelCondition";
			this->labelCondition->Size = System::Drawing::Size(203, 20);
			this->labelCondition->TabIndex = 18;
			this->labelCondition->Text = L"Прогресс шифрования";
			// 
			// Form3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(712, 527);
			this->Controls->Add(this->labelCondition);
			this->Controls->Add(this->progressBar1);
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
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form3";
			this->Text = L"Form3";
			this->Load += gcnew System::EventHandler(this, &Form3::Form3_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		labelCondition->Text = "Идет шифрование";
		progressBar1->Value = 0;
		string message = marshal_as<string>(textBoxMessage->Text);
		if (message == "" || message == "Заполните это поле") {
			textBoxMessage->Text = "Заполните это поле";
			return;
		}

		string ass = marshal_as<string>(textBoxAssociatedData->Text);
		if (ass == "" || ass == "Заполните это поле") {
			textBoxAssociatedData->Text = "Заполните это поле";
			return;
		}
		string output = marshal_as<string>(textBoxOutputFile->Text);
		if (output == "" || output == "Заполните это поле") {
			textBoxOutputFile->Text = "Заполните это поле";
			return;
		}
		progressBar1->Value = 25;
		vector<vector<unsigned char>> result = _cipher->cipher(marshal_as<string>(textBoxMessage->Text), marshal_as<string>(textBoxAssociatedData->Text));
		progressBar1->Value = 60;
		ofstream outputFile;
		outputFile.open(marshal_as<string>(textBoxOutputFile->Text), std::ios::app);
		ofstream outputMessageFile;
		outputMessageFile.open("test.bin", std::ios_base::out | std::ios_base::binary);
		if (!outputFile) {
			exit(1);
		}
		outputFile << "Ассоциированные данные\n{\n";
		size_t i = 0;
		while (result[0][i]) {
			outputFile.put(result[0][i]);
			i++;
		}
		progressBar1->Value = 80;
		outputFile << "\n}\nЗашифрованное сообщение\n{";
		for (size_t j = 1; j < result.size(); j++) {
			for (size_t k = 0; k < result[j].size(); k++) {
				outputMessageFile.put(result[j][k]);
				outputFile.put(result[j][k]);
			}
		}
		outputFile << "\n}\n\n";
		progressBar1->Value = 100;
		labelCondition->Text = "Работа завершена успешно";
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
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Form3_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
