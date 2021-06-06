#include "Form1.h"

using namespace System;
using namespace System::Windows::Forms;



[STAThread]
void main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Project1::Form1 form; //WinFormsTest - имя вашего проекта
    Application::Run(% form);
}

System::Void Project1::Form1::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
    string key = marshal_as<string>(textBoxKey->Text);
    string iv = marshal_as<string>(textBoxIV->Text);
    string alpha = marshal_as<string>(textBoxAlpha->Text);
    string i0 = marshal_as<string>(textBoxI0->Text);
    string lambda = marshal_as<string>(textBoxLambda->Text);
    string OLS1 = marshal_as<string>(textBoxOLS1->Text);
    string OLS2 = marshal_as<string>(textBoxOLS2->Text);
    CS cipher(key, iv, alpha, i0, lambda, OLS1, OLS2);
    Form2^ newForm = gcnew Form2(cipher);
    this->Hide();
    newForm->Show();
}
