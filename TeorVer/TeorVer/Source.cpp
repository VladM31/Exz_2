#include <GL/glut.h>
#include <stdio.h>
#include <stdint.h>
#include "System.h"

int main(int argc, char** argv) {

	System::SetAxis(-1.0f, 6.0f, -1.0f, 1.0f, 0.1f);

	System::InitGraphicSys(600, 600, "Teorver", argc, argv);

	int selector = 0;

	printf(SEPARATOR ART SEPARATOR);
	printf("1. Start \n");
	printf(SEPARATOR);
	scanf_s("%d", &selector);
	MessageBox(NULL, L"PRESS TAB FOR NEXT GRAPHIC", L"Postavte 100 pogaluista", MB_ICONINFORMATION);
	MessageBox(NULL, L"Funciya Ravnomernogo Raspredeleniya", L"Postavte 100 pogaluista", MB_ICONINFORMATION);
	System::CreateGraphicWindow();
	System::StartGraphics();


}