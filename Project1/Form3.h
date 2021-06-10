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
	private: System::Windows::Forms::TextBox^ textBoxMessageNumber;

	private: System::Windows::Forms::Label^ label5;


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
			this->textBoxMessageNumber = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(26, 106);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(192, 17);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Зашифрование сообщение:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(418, 124);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Обзор";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form3::button1_Click);
			// 
			// textBoxMessage
			// 
			this->textBoxMessage->Location = System::Drawing::Point(29, 126);
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
			this->label1->Size = System::Drawing::Size(282, 31);
			this->label1->TabIndex = 9;
			this->label1->Text = L"CS расшифрование";
			this->label1->Click += gcnew System::EventHandler(this, &Form3::label1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(26, 177);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(186, 17);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Ассоциированные данные:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(418, 195);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Обзор";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form3::button2_Click);
			// 
			// textBoxAssociatedData
			// 
			this->textBoxAssociatedData->Location = System::Drawing::Point(29, 197);
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
			this->label4->Location = System::Drawing::Point(26, 248);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(188, 17);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Куда поместить результат:";
			// 
			// button3
			// 
			this->button3->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button3->Location = System::Drawing::Point(418, 266);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Обзор";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form3::button3_Click);
			// 
			// textBoxOutputFile
			// 
			this->textBoxOutputFile->Location = System::Drawing::Point(29, 268);
			this->textBoxOutputFile->Name = L"textBoxOutputFile";
			this->textBoxOutputFile->ReadOnly = true;
			this->textBoxOutputFile->Size = System::Drawing::Size(322, 20);
			this->textBoxOutputFile->TabIndex = 13;
			// 
			// button4
			// 
			this->button4->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button4->Location = System::Drawing::Point(217, 393);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(95, 23);
			this->button4->TabIndex = 16;
			this->button4->Text = L"Зашифровать";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form3::button4_Click);
			// 
			// textBoxMessageNumber
			// 
			this->textBoxMessageNumber->Location = System::Drawing::Point(167, 318);
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
			this->label5->Location = System::Drawing::Point(28, 318);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(133, 17);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Номер сообщения:";
			// 
			// Form3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 428);
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
			this->Load += gcnew System::EventHandler(this, &Form3::Form3_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		vector<vector<unsigned char>> result = _cipher->cipher(marshal_as<string>(textBoxMessage->Text), marshal_as<string>(textBoxAssociatedData->Text));
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
		outputFile << "\n}\nЗашифрованное сообщение\n{";
		for (size_t j = 1; j < result.size(); j++) {
			for (size_t k = 0; k < result[j].size(); k++) {
				outputMessageFile.put(result[j][k]);
				outputFile.put(result[j][k]);
			}
		}
		outputFile << "\n}\n\n";
		textBoxMessageNumber->Text = marshal_as<String^>(_cipher->getMessageNumber());
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
};
}
