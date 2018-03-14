#ifndef TSP_HPP
#define TSP_HPP

#include "City.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <limits.h>
#include <fstream>
#include <algorithm>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using std::cout;

class TSP {
protected:
	City** cities;
	int numCities;
	int** dMatrix;
	int* bestRoute;
	int* newRoute;
	int* tempRoute;
	int bestDistance;
	int newDistance;
	int maxCities;


public:
	TSP();
	void initTSP(const char*, int);
	void cycle(int);
	void calculateNewDistance();
	void updateBestRoute();
	int twoOptSwap();
	~TSP();
};

#endif