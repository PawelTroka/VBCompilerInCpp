#include <Windows.h>
#include "MyApplication.h"

using namespace System;
using namespace System::IO;
using namespace System::Windows;
using namespace System::Windows::Markup;




using namespace std;

[STAThread]
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmd, int nCmd)
{
	Stream^ st = File::OpenRead("MainWindow.xaml");
	Window^ win = (Window^)XamlReader::Load(st, nullptr);
	Application^ app = gcnew MyApplication(win);
	app->Run(win);
}
