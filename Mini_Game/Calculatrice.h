#pragma once
#include "Input.h"
class Calculatrice
{
	
private:
	int table[11]{ 0 };
	Input input;
public:
	void PrintMultiplication();
	void Multiplication(int number, int table[11]);
};

