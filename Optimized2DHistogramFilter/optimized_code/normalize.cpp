#include <numeric>
#include "headers/normalize.h"

using namespace std;

vector< vector<float> > normalize(vector< vector <float> > & grid) {

	float sum = 0;
	for (int i = 0; i < grid.size(); i++)
	{
		sum = accumulate(grid[i].begin(), grid[i].end(), sum);
	}
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			grid[i][j] = grid[i][j] / sum;
		}
	}

	return grid;
}
