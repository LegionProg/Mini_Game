#include "Fire.h"
#include <iostream>

void Fire::FirCustomization()
{
	std::cout << "Please enter the fir size in range [" << firMinSize << "," << firMaxSize << "] : ";
	firSize = input.Choice(firMinSize, firMaxSize);

	std::cout << "Please enter the log size in range [" << logMinSize << "," << logMaxSize << "] : ";
	logSize = input.Choice(logMinSize, logMaxSize);

	std::cout << std::endl;
}

void Fire::PrintFire()
{
	int space = 8 * firSize; // de base 4 = 8
	int quit;

	for (int i = 1; i <= firSize; i++)
	{
		for (int sp = 0; sp < space; sp++)
		{
			std::cout << " ";
		}
		for (int a = 0; a < i; a++)
		{
			std::cout << firCustomization << firCustomization;
		}
		std::cout << std::endl;
		space = space - 1;
	}
	space = 8 * firSize;
	for (int i = 1; i <= logSize; i++)
	{
		for (int sp = 0; sp < space; sp++)
		{
			std::cout << " ";
		}
		std::cout << logCustomization << logCustomization;
		std::cout << std::endl;
	}
	std::cout << "Vous voulez rejouer ? " << std::endl 
		<< "Rejouet -> 1" << std::endl 
		<< "Quitter -> 1" << std::endl;
	quit = input.Choice(0, 1);
}

void Fire::FirPlay()
{
	FirCustomization();
	PrintFire();
}