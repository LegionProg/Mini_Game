#include <iostream>

// tous décaler dans des fichier .cpp et .h
int Choice(int min, int max);
int Generator(int max);

void FirPlay();
void PlusOuMoins();
void Multiplication();
void PrintMultiplication();

void Morpion();

int main()
{
	srand(time(NULL));
	int number_Game = 4; // nombre de jeux + 1 pour exit

	while (true)
	{
		std::cout << "Choisiser le jeux" << std::endl
			<< "-> Sapin = 1 " << std::endl
			<< "-> Plus Ou Moins = 2 " << std::endl
			<< "-> Table de multiplication = 3 " << std::endl
			<< "-> Exit = " << number_Game << std::endl;
		int choice = Choice(1, number_Game);


		if (choice == 1)
			FirPlay();
		else if (choice == 2)
			PlusOuMoins();
		else if (choice == 3)
			PrintMultiplication();
		else if (choice == 4)
			Morpion();


		else
			break;
	}

	return 0;
}

int Choice(int min, int max)
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
int Generator(int max)
{

	return rand() % (max + 1);
}

void FirPlay()
{
	{
		// déplacer dans le .h
		unsigned firSize = 0;
		const char firCustomization = '*';
		const unsigned firMinSize = 5;
		const unsigned firMaxSize = 20;

		unsigned logSize = 0;
		const char logCustomization = '|';
		const unsigned logMinSize = 2;
		const unsigned logMaxSize = 12;
		// déplacer ce qui est au dessut dans un .h



		// déplacer dans une fonction ce qui à au dessut
		std::cout << "Please enter the fir size in range [" << firMinSize << "," << firMaxSize << "] : ";
		firSize = Choice(firMinSize, firMaxSize);

		std::cout << "Please enter the log size in range [" << logMinSize << "," << logMaxSize << "] : ";
		logSize = Choice(logMinSize, logMaxSize);;

		std::cout << std::endl;

		int space = 8 * firSize; // de base 4 = 8


		for (int i = 0; i < firSize; i++)
		{
			for (int sp = 0; sp < space; sp++)
			{
				std::cout << " ";
			}
			for (int a = 0; a < i + 1; a++)
			{
				std::cout << firCustomization << firCustomization;
			}
			std::cout << std::endl;
			space = space - 1;
		}
		space = 8 * firSize;
		for (int i = 0; i < logSize; i++)
		{
			for (int sp = 0; sp < space; sp++)
			{
				std::cout << " ";
			}
			std::cout << logCustomization << logCustomization;
			std::cout << std::endl;
		}
	}
}

void PlusOuMoins()
{
	int max;
	int number;
	int turn;
	std::cout << "Quelle difficulter voulez vous jouez ? " << std::endl << "Facile = 1 " << std::endl << "Normale = 2" << std::endl << "Dificile = 3" << std::endl;
	max = Choice(1, 3);
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

	int mystery_Number = Generator(max);

	while (true)
	{
		turn--;
		std::cout << "choisit un nombre entre 0 et" << max << std::endl;
		number = Choice(0, max);

		if (number == mystery_Number)
		{
			std::cout << "Bien jouer tu a gagner" << std::endl;
			break;
		}
		else if (turn == 0)
		{
			std::cout << "Perdut " << std::endl;
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
	const int max_Table = 9;
	char table[max_Table]{'#'};
	int choice;
	while (true)
	{
		int a = 2;
		for (int i = 0; i <= 8; i++)
		{
			std::cout << table;
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
			if (table[choice] != ' ')
			{
				table[choice] = 'x';
				break;
			}
			std::cout << "la place et deja occuper" << std::endl;
		}


		// condition de victoire joueur
		for (int i = 0; i == 6; i = i + 3)
		{
			if (table[i] == 'x' && table[i + 1] == 'x' && table[i + 2] == 'x')
			{
				std::cout << "Bien jouer Gagner !" << std::endl;
				break;
			}
		}
		for (int i = 0; i == 3; i++)
		{
			if (table[i] == 'x' && table[i + 3] == 'x' && table[i + 6] == 'x')
			{
				std::cout << "Bien jouer Gagner !" << std::endl;
				break;
			}
		}
		if ((table[0] == 'x' && table[4] == 'x' && table[8] == 'x') || (table[6] == 'x' && table[4] == 'x' && table[2] == 'x'))
		{
			std::cout << "Bien jouer Gagner !" << std::endl;
			break;
		}
		while (true) // bot stupide (randome
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
				break;
			}
		}

		for (int i = 0; i == 6; i = i + 3)
		{
			if (table[i] == 'o' && table[i + 1] == 'o' && table[i + 2] == 'o')
			{
				std::cout << "Bien jouer Gagner !" << std::endl;
				break;
			}

		}
		for (int i = 0; i == 3; i++)
		{
			if (table[i] == 'o' && table[i+3] == 'o' && table[i + 6] == 'o')
			{
				std::cout << "Bien jouer Gagner !" << std::endl;
				break;
			}
		}
		if ((table[0] == 'o' && table[4] == 'o' && table[8] == 'o') || (table[6] == 'o' && table[4] == 'o' && table[2] == 'o'))
		{
			std::cout << "Bien jouer Gagner !" << std::endl;
			break;
		}


	}

}