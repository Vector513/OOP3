#include "application.h"
#include "Windows.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	Application application;
	Polynom polynom;
	application.exec(polynom);

	return 0;
}