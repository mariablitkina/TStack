#include "MyForm.h"
#include <Windows.h>
#include "..\Project3\TCalculator.h"
using namespace FormCalculator;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}