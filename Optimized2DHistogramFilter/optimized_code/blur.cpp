#include "headers/blur.h"


using namespace std;

vector < vector <float> > blur(vector < vector < float> >& grid, float blurring) {

	static float center = 1.0 - blurring;
	static float corner = blurring / 12.0;
	static float adjacent = blurring / 6.0;

	static vector<vector<float>> window = {
		{corner, adjacent, corner},
		{adjacent, center, adjacent},
		{corner, adjacent, corner}};

	int height = grid.size();
	int width = grid[0].size();

	vector<float> row(width, 0);
	vector<vector<float>> newGrid(height, row);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			float grid_val = grid[i][j];
			for (int dx = -1; dx < 2; dx++)
			{
				for (int dy = -1; dy < 2; dy++)
				{
					float coefficient = window[dx + 1][dy + 1];
					int new_i = (((i + dy) % height) + height) % height;
					int new_j = (((j + dx) % width) + width) % width;
					newGrid[new_i][new_j] += coefficient * grid_val;
				}
			}
		}
	}

	return newGrid;
}
