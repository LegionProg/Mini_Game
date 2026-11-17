#pragma once
#include "Input.h"
class PlusOuMoins
{
private:
	int max;
	int number;
	int turn = 10;

	int mystery_Number;

	Input input;
public:

	int StartPOM();
	void GamePOM();
	void PlayPOM();
};

