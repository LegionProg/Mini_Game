#include <iostream>

// tous décaler dans des fichier .cpp et .h
int Choice(int min, int max);
int Generator(int max);

void FirPlay();
void PlusOuMoins();


int main()
{
	srand(time(NULL));
	int number_Game = 2; // nombre de jeux + 1 pour exit

	while (true)
	{
		std::cout << "Choisiser le jeux\n 1 = Sapin\n 2 = EXIT" << std::endl;
		int choice = Choice(0, number_Game);


		if (choice == 1)
			FirPlay();
		else
			break;
	}

	return 0;
}

int Choice(int min, int max)
{
	int choice;
	std::cin >> choice;
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

