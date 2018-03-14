#include "TSP.hpp"

/*********************************************************************
*							 constructor
*********************************************************************/
TSP::TSP()
{
	bestDistance = INT_MAX;
	newDistance = 0;

	maxCities = 16000;
	int i, j;

	cities = new City*[maxCities];

	//for (i = 0; i < maxCities; i++) {
	//	cities[i] = new City();
	//}

	dMatrix = new int*[maxCities];
	bestRoute = new int[maxCities];
	newRoute = new int[maxCities];
	tempRoute = new int[maxCities];

	for (i = 0; i < maxCities; i++) {
		dMatrix[i] = new int[maxCities];
	}

	for (i = 0; i < maxCities; i++) {
		for (j = 0; j < maxCities; j++) {
			dMatrix[i][j] = 0;
		}
	}
}

/*********************************************************************
*							 constructor
*********************************************************************/
void TSP::initTSP(const char* fname, int simulations) {

	// set default values
	numCities = 0;

	if (1 == 0) {
		cout << "No input file specified.\n";
	}
	else {
		std::ifstream inFile;
		inFile.open(fname);
		if (!inFile) {
			cout << "Unable to open " << fname << ", program will now exit.\n";
			//return(1);
		};

		int id, x, y;
		inFile >> id;

		while (!inFile.eof()) {
			inFile >> x;
			inFile >> y;
			City * newCity = new City(id, x, y);
			cities[numCities] = newCity;
			numCities++;
			inFile >> id;
		}

		//Close text file
		inFile.close();

		// fill in distance matrix
		for (int i = 0; i < numCities; i++) {
			for (int j = 0; j < numCities; j++) {
				int x, y, edge;
				x = cities[i]->getX() - cities[j]->getX();
				x *= x;
				y = cities[i]->getY() - cities[j]->getY();
				y *= y;
				edge = int(sqrt(x + y + 0.5));
				dMatrix[i][j] = edge;

			}
		}

		cycle(simulations);
	}
}


/*********************************************************************
*							  cycle
*********************************************************************/
void TSP::cycle(int simulations) {
	
	int k = 0;
	int i;

	//set random number seed
	std::srand(unsigned(std::time(0)));

	while (k < simulations) {

		// Generate a new random route
		for (i = 0; i < numCities; i++) {
			newRoute[i] = i;
		}

		std::random_shuffle(&newRoute[0], &newRoute[numCities]);

		// Calculate distance of new route
		calculateNewDistance();

		int x = 1;

		// Apply 2-opt swap until local min is reached
		while (x != 0) {
			x = twoOptSwap();
		}

		updateBestRoute();
		cout << "Local Min " << k << ": " << newDistance << "   Best Distance: " << bestDistance << std::endl;

		k++;
	}
}

/*********************************************************************
*					  calculateNewDistance
*********************************************************************/
void TSP::calculateNewDistance() {

	int i;
	newDistance = 0;

	for (i = 0; i < numCities - 1; i++) {
		newDistance += dMatrix[newRoute[i]][newRoute[i + 1]];
	}

	newDistance += dMatrix[newRoute[numCities - 1]][newRoute[0]];
}


/*********************************************************************
*					     updateBestRoute
*********************************************************************/
void TSP::updateBestRoute() {

	int i;

	if (bestDistance > newDistance) {
		for (i = 0; i < numCities; i++) {
			bestRoute[i] = newRoute[i];
		}

		bestDistance = newDistance;
	}
}


/*********************************************************************
*					       twoOptSwap
*********************************************************************/
int TSP::twoOptSwap() {

	int change;

	for (int i = 0; i < numCities - 2; i++) {

		for (int j = i + 2; j < numCities - 1; j++) {

			change = dMatrix[newRoute[i]][newRoute[j]] + dMatrix[newRoute[i + 1]][newRoute[j + 1]] - dMatrix[newRoute[i]][newRoute[i + 1]] - dMatrix[newRoute[j]][newRoute[j + 1]];

			if (change < 0) {

				//make the swap and reverse order for points in between
				for (int k = 0; k < j - i; k++) {
					tempRoute[k] = newRoute[i + 1 + k];
				}

				for (int k = 0; k < j - i; k++) {
					newRoute[i + k + 1] = tempRoute[j - i - 1 - k];
				}

				newDistance = newDistance + change;

				//print new route
				//cout << newDistance;
				//cout << std::endl;
				return change;
			}
		}
	}

	//no changes made - return 0
	return 0;
}

/*********************************************************************
*					       destructor
*********************************************************************/
TSP::~TSP()
{
	int i;
	for (i = 0; i < maxCities; i++) {
		delete[] dMatrix[i];
	}

	for (i = 0; i < numCities; i++) {
		delete cities[i];
	}
	
	delete[] cities;
	delete[] bestRoute;
	delete[] tempRoute;
	delete[] newRoute;
	delete[] dMatrix;
}
