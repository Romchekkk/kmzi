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
    if (key == "" || key == "Заполните это поле") {
        textBoxKey->Text = "Заполните это поле";
        return;
    }
    string iv = marshal_as<string>(textBoxIV->Text);
    if (iv == "" || iv == "Заполните это поле") {
        textBoxIV->Text = "Заполните это поле";
        return;
    }
    string alpha = marshal_as<string>(textBoxAlpha->Text);
    if (alpha == "" || alpha == "Заполните это поле") {
        textBoxAlpha->Text = "Заполните это поле";
        return;
    }
    string i0 = marshal_as<string>(textBoxI0->Text);
    if (i0 == "" || i0 == "Заполните это поле") {
        textBoxI0->Text = "Заполните это поле";
        return;
    }
    string lambda = marshal_as<string>(textBoxLambda->Text);
    if (lambda == "" || lambda == "Заполните это поле") {
        textBoxLambda->Text = "Заполните это поле";
        return;
    }
    string OLS1 = marshal_as<string>(textBoxOLS1->Text);
    if (OLS1 == "" || OLS1 == "Заполните это поле") {
        textBoxOLS1->Text = "Заполните это поле";
        return;
    }
    string OLS2 = marshal_as<string>(textBoxOLS2->Text);
    if (OLS2 == "" || OLS2 == "Заполните это поле") {
        textBoxOLS2->Text = "Заполните это поле";
        return;
    }
    bool encrypt = radioButton1->Checked ? true : false;
    try {
        CS cipher(key, iv, alpha, i0, lambda, OLS1, OLS2);
        if (encrypt) {
            Form2^ newForm = gcnew Form2(cipher);
            this->Hide();
            newForm->Show();
        }
        else {
            Form3^ newForm = gcnew Form3(cipher);
            this->Hide();
            newForm->Show();
        }
    }
    catch (...) {

    }

}
