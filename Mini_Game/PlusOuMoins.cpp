#include "PlusOuMoins.h"
#include <iostream>
void PlusOuMoins::StartPOM()
{
	std::cout << "Quelle difficulter voulez vous jouez ? " << std::endl << "Facile = 1 " << std::endl << "Normale = 2" << std::endl << "Dificile = 3" << std::endl;
	max = input.Choice(1, 3);
	if (max == 1)
	{
		std::cout << "Tu a choisis Facile petit joueur !! :(" << std::endl;
		max = 50;
		turn = 10;
	}
	else if (max == 2)
	{
		std::cout << "Tu a choisis Normale Sa manque de personaliter tous sa :/" << std::endl;
		max = 100;
		turn = 6;
	}

	else if (max == 3)
	{
		std::cout << "Tu a choisis Difficile t'est sur que tu à le niveau ? XD" << std::endl;
		max = 200;
		turn = 10;
	}
	mystery_Number = input.Generator(max);
}

void PlusOuMoins::GamePOM()
{
	while (true)
	{
		while (true)
		{
			std::cout << "choisit un nombre entre 0 et " << max << std::endl;
			number = input.Choice(0, max);

			if (number == mystery_Number)
			{
				std::cout << "Bien jouer tu a gagner" << std::endl;
				break;
			}
			else if (turn == 0)
			{
				std::cout << "Perdu " << std::endl;
				break;
			}
			else if (number > mystery_Number)
			{
				std::cout << "T'est trop haut" << std::endl;
			}
			else if (number < mystery_Number)
			{
				std::cout << "Trop bas" << std::endl;
			}
			turn--;
		}
		std::cout << "Vous voulez rejouer ? " << std::endl
			<< "Rejouet -> 0" << std::endl
			<< "Quitter -> 1" << std::endl;
		int quit = input.Choice(0, 1);
		if (quit == 1)
			break;
	}
}

void PlusOuMoins::PlayPOM()
{
	StartPOM();
	GamePOM();
}