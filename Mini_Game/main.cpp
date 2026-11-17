#include <iostream>
#include "Fire.h"
#include "PlusOuMoins.h"
// tous décaler dans des fichier .cpp et .h

//void Multiplication();
void PrintMultiplication();

int PFC_IA(int randomIA, int tableIA[3]);
int PFC_PrintResult(int choice, int botChoice, int score[3], int numberOfManche);
void PFC_Print_Choice(int choice);
void PFC();

void Morpion();

int main()
{
	srand(time(NULL));
	int number_Game = 6; // nombre de jeux + 1 pour exit
	Fire fire;
	PlusOuMoins pom;
	while (true)
	{
		std::cout << "Choisiser le jeux" << std::endl
			<< "-> Sapin = 1 " << std::endl // maintenir le sapin existant
			<< "-> Plus Ou Moins = 2 " << std::endl
			<< "-> Table de multiplication = 3 " << std::endl
			<< "-> Pierre Papier Ciseau = 4 " << std::endl
			<< "-> Morpion = 5 " << std::endl
			<< "-> Exit = " << number_Game << std::endl;
		int choice = Choice(1, number_Game);


		if (choice == 1)
			fire.FirPlay();
		else if (choice == 2)
			pom.PlayPOM();
		else if (choice == 3)
			PrintMultiplication();
		else if (choice == 4)
			PFC();
		else if (choice == 5)
			Morpion();

		else
			break;
		//system("cls");
	}

	return 0;
}

void Multiplication(int number, int table[11])
{
	for (int i = 0; i <= 10; i++)
	{
		table[i] = i * number;
	}
}

void PrintMultiplication()
{
	std::cout << "Entrer un nombre de 0 a 10" << std::endl;
	int number = Choice(0, 9);
	int table[11]{ 0 };
	Multiplication(number, table);
	std::cout << "Voici la table de " << number << std::endl;
	for (int i = 0; i <= 10; i++)
	{
		std::cout << "-> " << table[i] << std::endl;
	}
}

void Morpion()
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
			choice = Choice(0, 8);
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
			end = Choice(0,1);
			if (end == 1)
			break;
		}
		while (true) // bot stupide (random)
		{
			choice = Generator(max_Table);
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
			end = Choice(0, 1);
			if (end == 1)
				break;
		}
	}
}






void PFC()
{
	{
		int choice;
		int botChoice;
		int result = 1;
		int numberOfManche; // verifier l'hortographe
		std::cout << ">Bienvenu dans le jeux du pierre feuille ciseau" << std::endl;

		int score[3]{ 0 };
		int tableIA[3]{ 0 };
		int randomIA;

		std::cout << "Choisissez le nombre de manche -> ";
		numberOfManche = Choice(1, 10);
		while (true)
		{
			randomIA = Generator(100);
			botChoice = PFC_IA(randomIA, tableIA);
			std::cout << "Choisissez " << std::endl
				<< "Pierre = 0" << std::endl
				<< "Feuille = 1" << std::endl
				<< "Ciseau = 2" << std::endl;

			choice = Choice(0, 2);
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

	}
}

int PFC_IA(int randomIA, int tableIA[3])
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
		botChoice = Generator(3);
		//cout << endl << "RN" << endl;
	}
	return botChoice;
}
void PFC_Print_Choice(int choice)
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
int PFC_PrintResult(int choice, int botChoice, int score[3], int numberOfManche)
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

