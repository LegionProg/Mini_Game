#pragma once
#include "Input.h"
class Fire
{
private:
		unsigned firSize = 0;
		const char firCustomization = '*';
		const unsigned firMinSize = 5;
		const unsigned firMaxSize = 20;

		unsigned logSize = 0;
		const char logCustomization = '|';
		const unsigned logMinSize = 2;
		const unsigned logMaxSize = 12;

		Input input;
public:
	void PrintFire();
	void FirPlay();
	void FirCustomization();
};

