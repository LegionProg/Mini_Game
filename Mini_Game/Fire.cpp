#include "Fire.h"

int PrintFire(int fireSize)
{
	std::cout << "     ";
	for (int i = 0; i < fireSize; i++)
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
}