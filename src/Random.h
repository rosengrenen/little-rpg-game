#pragma once

#include <ctime>
#include <random>

class Random
{
public:
	static void init();

	static int getRandomNumber(int min, int max);
};

