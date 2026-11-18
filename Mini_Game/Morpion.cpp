#include "Morpion.h"
#include <iostream>
void Morpion::PlayMorpion()
{
	int end = 0;
	const int max_Table = 9;
	char table[max_Table]{ ' ', ' ',' ',' ', ' ',' ', ' ', ' ',' ' };
	int choice;
	while (true)
	{
		int a = 2;
		for (int i = 0; i <= 8; i++)
		{
			std::cout << table[i];
			if (i != a && i != 9)
				std::cout << " | ";
			if (i == a)
			{
				std::cout << std::endl;
				a = a + 3;
			}

		}

		while (true) // joueur qui joue
		{
			choice = input.Choice(0, 8);
			if (table[choice] == ' ')
			{
				table[choice] = 'x';
				break;
			}
			std::cout << "la place et deja occuper" << std::endl;
		}


		// condition de victoire joueur
		for (int i = 0; i <= 6; i = i + 3)
		{
			if (table[i] == 'x' && table[i + 1] == 'x' && table[i + 2] == 'x')
			{
				std::cout << "Bien jouer Gagner !" << std::endl;
				end = 1;
				break;
			}
		}
		for (int i = 0; i <= 3; i++)
		{
			if (table[i] == 'x' && table[i + 3] == 'x' && table[i + 6] == 'x')
			{
				std::cout << "Bien jouer Gagner !" << std::endl;
				end = 1;
				break;
			}
		}
		if ((table[0] == 'x' && table[4] == 'x' && table[8] == 'x') || (table[6] == 'x' && table[4] == 'x' && table[2] == 'x'))
		{
			std::cout << "Bien jouer Gagner !" << std::endl;
			end = 1;
		}
		if (end != 0)
		{
			std::cout << "La parti et finis la relancer ? " << std::endl
				<< "Oui = 0" << std::endl
				<< "Non = 1" << std::endl;
			end = input.Choice(0, 1);
			if (end == 1)
				break;
		}
		while (true) // bot stupide (random)
		{
			choice = input.Generator(max_Table);
			if (table[choice] == ' ')
			{
				table[choice] = 'o';
				break;
			}

		}
		for (int i = 0; i == 8; i++)
		{
			if (table[i] == ' ' && table[i + 1] == ' ' && table[i + 2] == ' ')
			{
				std::cout << " Egaliter " << std::endl;
				end = 1;
				break;
			}
		}

		for (int i = 0; i == 6; i = i + 3) // vertical
		{
			if (table[i] == 'o' && table[i + 1] == 'o' && table[i + 2] == 'o')
			{
				std::cout << "Perdu !" << std::endl;
				end = 1;
				break;
			}

		}
		for (int i = 0; i == 3; i++) // horizontal
		{
			if (table[i] == 'o' && table[i + 3] == 'o' && table[i + 6] == 'o')
			{
				std::cout << "Perdu !" << std::endl;
				end = 1;
				break;
			}
		}
		if ((table[0] == 'o' && table[4] == 'o' && table[8] == 'o') || (table[6] == 'o' && table[4] == 'o' && table[2] == 'o'))
		{
			std::cout << "Perdu !" << std::endl;
			end = 1;
		}
		if (end != 0)
		{
			std::cout << "La parti et finis la relancer ? " << std::endl
				<< "Oui = 0" << std::endl
				<< "Non = 1" << std::endl;
			end = input.Choice(0, 1);
			if (end == 1)
				break;
		}
	}
}