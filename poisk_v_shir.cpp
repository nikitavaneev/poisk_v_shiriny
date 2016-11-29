// poisk_v_shir.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <queue>
#include <cmath>
#include<conio.h>
using namespace std;
const int width = 5, height = 5, inf = 30;
int field[height][width] =
{
	{ inf, inf, inf, inf, 0 },
	{ 0, 0 , 0, inf, 0 },
	{ 0, 0, inf, inf, 0 },
	{ 0, 0, inf, 0, 0 },
	{ 0, 0, inf, inf, inf }
};
int main()
{
	queue<int> pathfinder;
	int x = 0, y = 0;
	int waypointer = 1;
	pathfinder.push(0);
	pathfinder.push(0);
	pathfinder.push(1);
	while (!pathfinder.empty())
	{
		x = pathfinder.front();
		pathfinder.pop();
		y = pathfinder.front();
		pathfinder.pop();
		waypointer = pathfinder.front();
		pathfinder.pop();

		if (x >= width || x < 0 ||
			y >= height || y < 0)
			continue;

		if (field[y][x] == inf)
			field[y][x] = waypointer;
		else
			continue;
		if (x == width - 1 && y == height - 1)
			break;
		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)
			{
				if (abs(i + j) != 1)
					continue;
				pathfinder.push(x + i);
				pathfinder.push(y + j);
				pathfinder.push(waypointer + 1);
			}
		waypointer++;
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			cout << field[i][j] << " ";
		cout << endl;
	}
	_getch();
	return 0;
}