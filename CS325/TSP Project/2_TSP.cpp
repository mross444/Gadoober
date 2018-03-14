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
		const char *inputFile = "test-input-4.txt";
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
	Point p1, p2, p3, p4;

	for (int i = 0; i < numCities - 2; i++) {

		for (int j = i + 2; j < numCities - 1; j++) {

			p1.x = cities[newRoute[i]]->getX();
			p2.x = cities[newRoute[i+1]]->getX();
			p3.x = cities[newRoute[j]]->getX();
			p4.x = cities[newRoute[j+1]]->getX();

			p1.y = cities[newRoute[i]]->getY();
			p2.y = cities[newRoute[i + 1]]->getY();
			p3.y = cities[newRoute[j]]->getY();
			p4.y = cities[newRoute[j + 1]]->getY();

			if (doIntersect(p1, p2, p3, p4)) {

				//make the swap and reverse order for points in between
				for (int k = 0; k < j - i; k++) {
					tempRoute[k] = newRoute[i + 1 + k];
				}

				for (int k = 0; k < j - i; k++) {
					newRoute[i + k + 1] = tempRoute[j - i - 1 - k];
				}


				calculateNewDistance();

				return 1;
			}

			//change = dMatrix[newRoute[i]][newRoute[j]] + dMatrix[newRoute[i + 1]][newRoute[j + 1]] - dMatrix[newRoute[i]][newRoute[i + 1]] - dMatrix[newRoute[j]][newRoute[j + 1]];

			//if (change < 0) {

			//	//make the swap and reverse order for points in between
			//	for (int k = 0; k < j - i; k++) {
			//		tempRoute[k] = newRoute[i + 1 + k];
			//	}

			//	for (int k = 0; k < j - i; k++) {
			//		newRoute[i + k + 1] = tempRoute[j - i - 1 - k];
			//	}


			//	newDistance = newDistance + change;

			//	//return 

			//	//print new route
			//	cout << newDistance;
			//	cout << std::endl;
			//	return change;
		}

	}

	//no changes made - return
	return 0;


}


// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
	if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
		q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
		return true;

	return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
	// See https://www.geeksforgeeks.org/orientation-3-ordered-points/
	// for details of below formula.
	int val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;  // colinear

	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
	// Find the four orientations needed for general and
	// special cases
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	// General case
	if (o1 != o2 && o3 != o4)
		return true;

	// Special Cases
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;

	// p1, q1 and q2 are colinear and q2 lies on segment p1q1
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;

	return false; // Doesn't fall in any of the above cases
}