#include "GameManager.h"
#include <iostream>
void GameManager::PlayGame()
{
	
	while (true)
	{
		std::cout << "Choisiser le jeux" << std::endl
			<< "-> Sapin = 1 " << std::endl // maintenir le sapin existant
			<< "-> Plus Ou Moins = 2 " << std::endl
			<< "-> Table de multiplication = 3 " << std::endl
			<< "-> Pierre Papier Ciseau = 4 " << std::endl
			<< "-> Morpion = 5 " << std::endl
			<< "-> Exit = " << number_Game << std::endl;
		int choice = input.Choice(1, number_Game);


		if (choice == 1)
			fire.FirPlay();
		else if (choice == 2)
			pom.PlayPOM();
		else if (choice == 3)
			calc.PrintMultiplication();
		else if (choice == 4)
			pfc.PlayPFC();
		else if (choice == 5)
			morpion.PlayMorpion();

		else
			break;
		//system("cls");
	}
}