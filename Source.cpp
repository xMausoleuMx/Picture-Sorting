#include "container.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PictureSorting::container container;
	Application::Run(%container);
}

