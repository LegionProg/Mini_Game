#include "Input.h"
#include <iostream>

int Input::Choice(int min, int max)
{
	int choice;
	while (true)
	{
		std::cin >> choice;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Entrez un nombre valide : \n";
		}
		else if (choice < min || choice > max)
		{
			std::cout << "Recommencer Joueur ! " << std::endl;
		}
		else
		{
			return choice;
		}
	}
}

int Input::Generator(int max)
{
	return rand() % (max + 1);
}