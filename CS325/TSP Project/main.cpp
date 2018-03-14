/***************************************************************
* Date: 03/14/18
* Description: TSP Program using 2-OPT ALL Method
* ***********************************************************/

#include "TSP.hpp"

int main() {

	TSP* problem = new TSP();
	problem->initTSP("tsp_example_2.txt", 10);
	delete problem;

	return 0;
}
