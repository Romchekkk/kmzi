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