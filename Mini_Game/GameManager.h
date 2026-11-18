#pragma once
#include "Input.h"
#include "Fire.h"
#include "PlusOuMoins.h"
#include "Calculatrice.h"
#include "PFC.h"
#include "Morpion.h"

class GameManager
{
private:

	int number_Game = 7; // nombre de jeux + 1 pour exit
	Input input;
	Fire fire;
	PlusOuMoins pom;
	Calculatrice calc;
	PFC pfc;
	Morpion morpion;

public:
	void PlayGame();
};

