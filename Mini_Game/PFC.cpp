#include "PFC.h"
#include <iostream>

void PFC::PlayPFC()
{
	while (true)
	{		
		std::cout << ">Bienvenu dans le jeux du pierre feuille ciseau" << std::endl;
		std::cout << "Choisissez le nombre de manche -> ";
		numberOfManche = input.Choice(1, 10);
		while (true)
		{
			randomIA = input.Generator(100);
			botChoice = PFC_IA(randomIA, tableIA);
			std::cout << "Choisissez " << std::endl
				<< "Pierre = 0" << std::endl
				<< "Feuille = 1" << std::endl
				<< "Ciseau = 2" << std::endl;

			choice = input.Choice(0, 2);
			std::cout << "Humain joue -> ";
			PFC_Print_Choice(choice);

			tableIA[choice] = tableIA[choice] + 1;

			std::cout << "Machine joue -> ";
			PFC_Print_Choice(botChoice);
			result = PFC_PrintResult(choice, botChoice, score, numberOfManche);
			if (result == 0)
			{
				break;
			}
		}
		std::cout << "Vous voulez rejouer ? " << std::endl
			<< "Rejouet -> 0" << std::endl
			<< "Quitter -> 1" << std::endl;
		int quit = input.Choice(0, 1);
		if (quit == 1)
			break;
	}
}

int PFC::PFC_IA(int randomIA, int tableIA[3])
{
	int botChoice;
	if (randomIA <= 70)
	{
		//cout << endl << "IA" << endl;
		if (tableIA[0] > tableIA[1] && tableIA[0] > tableIA[2])
			botChoice = 1;
		else if (tableIA[1] > tableIA[2])
			botChoice = 2;
		else
			botChoice = 0;
	}
	else
	{
		botChoice = input.Generator(3);
		//cout << endl << "RN" << endl;
	}
	return botChoice;
}
void PFC::PFC_Print_Choice(int choice)
{

	if (choice == 0)
	{
		std::cout << "Pierre" << std::endl;
	}
	else if (choice == 1)
	{
		std::cout << "Feuille" << std::endl;
	}
	else if (choice == 2)
	{
		std::cout << "Ciseau" << std::endl;
	}

}
int PFC::PFC_PrintResult(int choice, int botChoice, int score[3], int numberOfManche)
{
	// Proto ->
	if (choice == botChoice)
	{
		std::cout << std::endl << "egaliter" << std::endl;
		score[2] = score[2] + 1;
	}
	else if (choice == 0) // caillou
	{
		if (botChoice == 1) // feuille
		{
			std::cout << std::endl << "perdu " << std::endl;
			score[1] = score[1] + 1;
		}
		else
		{
			std::cout << std::endl << "Victoir " << std::endl;
			score[0] = score[0] + 1;

		}
	}
	else if (choice - 1 == botChoice)
	{
		std::cout << std::endl << "Victoire " << std::endl;
		score[0] = score[0] + 1;
	}
	else if (choice == botChoice + 1)
	{
		std::cout << std::endl << "perdu " << std::endl;
		score[1] = score[1] + 1;
	}

	/// <- Proto

	std::cout << std::endl << "Voici les score Humain -> " << score[0]
		<< " | score Machine -> " << score[1]
		<< " | manche nul -> " << score[2] << std::endl;

	if (score[0] == numberOfManche)
	{
		std::cout << "tu a gagner cette fois si " << std::endl;
		return 0;
	}
	else if (score[1] == numberOfManche)
	{
		std::cout << "tu a perdu " << std::endl;
		return 0;
	}
}