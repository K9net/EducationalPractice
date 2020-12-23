#include "MyForm1.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
inline void Main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	praktika::MyForm1 form;
	Application::Run(% form);
}
