#include "TSP.hpp"

/*********************************************************************
*							 constructor
*********************************************************************/
TSP::TSP() 
{
	bestDistance = INT_MAX;
	newDistance = 0;

	int max = 16000;
	int i, j;

	cities = new City*[max];

	for (i = 0; i < max; i++) {
		cities[i] = new City();
	}
	

	dMatrix = new int*[max];
	bestRoute = new int[max];
	newRoute = new int[max];
	tempRoute = new int[max];

	for (i = 0; i < max; i++) {
		dMatrix[i] = new int[max];
	}


	for (i = 0; i < max; i++) {
		for (j = 0; j < max; j++) {
			dMatrix[i][j] = 0;
		}
	}


}

/*********************************************************************
*							 constructor
*********************************************************************/
void TSP::initTSP(std::string fname) {
	
	// set default values
	numCities = 0;
	
	// initialize cities from file
	int citiesMax = 16000;

	if (1 == 0) {
		cout << "No input file specified.\n";
	}
	else {
		const char *inputFile = "test-input-6.txt";
		std::ifstream inFile;
		inFile.open(inputFile);
		if (!inFile) {
			cout << "Unable to open " << inputFile << ", program will now exit.\n";
			//return(1);
		};


		int id, x, y;
		inFile >> id;
		//Loop through text file to get all cities
		while (!inFile.eof()) {
			inFile >> x;
			inFile >> y;
			City * newCity = new City(id, x, y);
			cities[numCities] = newCity;
			//cout << std::endl;
			//cout << id << " " << x << " " << y;
			numCities++;
			inFile >> id;
		}

		//Close text file
		inFile.close();

		//cout << std::endl << std::endl;

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
				//cout << edge << " ";
			}
		/*	cout << std::endl;*/
		}

		cycle(3);

	}
}


/*********************************************************************
*							  cycle
*********************************************************************/
void TSP::cycle(int minutes) {

	//start clock, declare time parameter
	int n = 5;
	int k = 0;
	int i;

	//set random number seed
	std::srand(unsigned(std::time(0)));

	while (k < n) {

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

	newDistance = 0;

	int i;

	for (i = 0; i < numCities-1; i++) {

		newDistance += dMatrix[newRoute[i]][newRoute[i + 1]];

	}

	newDistance += dMatrix[newRoute[numCities - 1]][newRoute[0]];

}


/*********************************************************************
*					     updateBestRoute
*********************************************************************/
void TSP::updateBestRoute() {

	if (bestDistance > newDistance) {

		int i;

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

				//return 

				//print new route
				cout << newDistance;
				cout << std::endl;
				return change;
			}

		}

	}

	//no changes made - return
	return 0;


}


