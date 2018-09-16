/*
** Reimua
** Part of Cosmos by OpenGenus Foundation
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static const int map_size = 9;

/*
** Check a number's existance on a line.
*/

int exist_on_line(char map[map_size][map_size + 2], const int pos_y, const char c)
{
	int i = 0;

	while (i < map_size)
	{
		if (map[pos_y][i++] == c)
			return (1);
	}
	return (0);
}

/*
** Check a number's existance on a column.
*/

int exist_on_column(char map[map_size][map_size + 2], const int pos_x, const char c)
{
	int i = 0;

	while (i < map_size)
	{
		if (map[i++][pos_x] == c)
			return (1);
	}
	return (0);
}

/*
** Check a number's existance on a block.
*/

int exist_on_block(char map[map_size][map_size + 2], const int pos_x, const int pos_y, const char c)
{
	int i = pos_y - (pos_y % 3);
	int j = pos_x - (pos_x % 3);
	int m = i;
	int n = j;

	while (m < i + 3)
	{
		while (n < j + 3)
		{
			if (map[m][n] == c)
				return (1);
			n++;
		}
		m++;
		n = j;
	}
	return (0);
}

/*
** Solve the sudoku by using backtracking.
** 
** The following could be improved by changing
** the order of completion instead of going
** from 0 to map_size².
*/

int resolve_sudoku(char map[map_size][map_size + 2], const int pos)
{
	if (pos == map_size * map_size)
		return (1);

	int pos_x = pos % 9;
	int pos_y = pos / 9;

	if (map[pos_y][pos_x] != '0')
		return (resolve_sudoku(map, pos + 1));

	char c = '1';

	while (c <= map_size + '0')
		{
			if (!exist_on_line(map, pos_y, c) &&
				!exist_on_column(map, pos_x, c) &&
				!exist_on_block(map, pos_x, pos_y, c))
			{
				map[pos_y][pos_x] = c;
				if (resolve_sudoku(map, pos + 1))
					return (1);
			}
			c++;
		}

	map[pos_y][pos_x] = '0';
	return (0);
}

/*
** Read from stdin.
*/

int read_map(char map[map_size][map_size + 2])
{
	int i = 0;

	while (i < map_size)
 	{
 		if (!fgets(map[i], map_size + 2, stdin) ||
 			(int)strlen(map[i]) < map_size)
 			return (1);
 		map[i++][map_size] = '\0';
 	}
 	return (0);
}

int main(void)
{
	int i = 0;
	char map[map_size][map_size + 2];
 
	if (read_map(map))
		return (1); 
 	resolve_sudoku(map, 0);
 	while (i < map_size)
 		printf("%s\n", map[i++]);
    	return (0);
}
