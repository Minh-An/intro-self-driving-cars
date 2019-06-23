 #include "headers/initialize_beliefs.h"

using namespace std;

// OPTIMIZATION: pass large variables by reference
vector< vector <float> > initialize_beliefs(vector< vector <char> > grid) {
  	float prob_per_cell = 1.0 / ( (float) grid.size() * grid[0].size()) ;
	vector<float> newRow(grid[0].size(), prob_per_cell);
	vector< vector <float> > newGrid(grid.size(), newRow);
	return newGrid;
}