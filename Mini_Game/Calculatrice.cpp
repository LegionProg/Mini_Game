#include "Calculatrice.h"
#include <iostream>

void Calculatrice::PrintMultiplication()
{
	while (true)
	{
		std::cout << "Entrer un nombre de 0 a 10" << std::endl;
		int number = input.Choice(0, 9);
		Multiplication(number, table);
		std::cout << "Voici la table de " << number << std::endl;
		for (int i = 0; i <= 10; i++)
		{
			std::cout << "-> " << table[i] << std::endl;
		}
		std::cout << "Vous voulez rejouer ? " << std::endl
			<< "Rejouet -> 0" << std::endl
			<< "Quitter -> 1" << std::endl;
		int quit = input.Choice(0, 1);
		if (quit == 1)
			break;
	}
}
void Calculatrice::Multiplication(int number, int table[11])
{
	for (int i = 0; i <= 10; i++)
	{
		table[i] = i * number;
	}
}