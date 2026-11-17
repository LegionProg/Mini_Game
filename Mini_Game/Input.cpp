#include "Input.h"
#include <iostream>

int Input::Choice(int min, int max)
{
	int choice;
	while (true)
	{
		std::cin >> choice;
		if (choice >= min && choice <= max)
			break;
		std::cout << "Vous avez mal saisie recomancer et cette fois si correctement !!!" << std::endl;
	}


	return choice;
}

int Input::Generator(int max)
{
	return rand() % (max + 1);
}