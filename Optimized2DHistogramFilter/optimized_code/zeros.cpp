#include "headers/zeros.h"

using namespace std;

vector < vector <float> > zeros(int height, int width) {  
	// OPTIMIZATION: Reserve space in memory for vectors
	vector <float> newRow(width, 0);
	vector < vector <float> > newGrid(height, newRow);
	return newGrid;
}