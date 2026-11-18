#pragma once
#include "Input.h"
class PFC
{
private:
	int choice;
	int botChoice;
	int result = 1;
	int score[3]{ 0 };
	int tableIA[3]{ 0 };
	int randomIA;

	int numberOfManche; // verifier l'hortographe
	Input input;
public:
	void PlayPFC();
	int PFC_IA(int randomIA, int tableIA[3]);
	void PFC_Print_Choice(int choice);
	int PFC_PrintResult(int choice, int botChoice, int* score,int numberOfManche);
};

