/*
** Reimua
** Part of Cosmos by OpenGenus Foundation
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static const int move_nbr = 8;
static const int move_x[] = {2,  2, 1,  1, -2, -2, -1, -1};
static const int move_y[] = {1, -1, 2, -2,  1, -1,  2, -2};

/*
** Check if a case is safe for our dear knight.
** 1 : The position is in the map.
** 2 : We didn't use this position.
*/

int is_safe(char **map, int x, int y, int pos_x, int pos_y)
{
	if (pos_x < 0 || pos_x >= x || pos_y < 0 || pos_y >= y)
		return (0);
	if (map[pos_y][pos_x] != '0')
		return (0);
	return (1);
}

/*
** Order the moveset so we prioritize the case with the less possibility.
*/

void order_moveset(int *move_set, int *combination)
{
	int i = 0;
	int k = 0;
	int j = 0;

	while (i < move_nbr)
	{
		while (j < move_nbr)
		{
			if (combination[j] == k)
			{
				move_set[i++] = j;
				combination[j] = -1;
			}
			j++;
		}
		j = 0;
		k++;
	}
}

/*
** Generate an effective move_set instead of blindly use backtracking.
*/

int *generate_moveset(char **map, int sol[][2], int x, int y, int depth)
{
	int i = 0;
	int j = 0;
	int combination[move_nbr];
	int *move_set = malloc(sizeof(int) * move_nbr);

	if (!move_set)
		return (NULL); 
	memset(combination, '\0', 8 * sizeof(int));
	while (i < move_nbr)
	{
		int pos_x = sol[depth][0] + move_x[i];
		int pos_y =	sol[depth][1] + move_y[i];

		if (is_safe(map, x, y, pos_x, pos_y))
		{
			while (j < move_nbr)
			{
				int new_pos_x = pos_x + move_x[j];
				int new_pos_y = pos_y + move_y[j];

				if (is_safe(map, x, y, new_pos_x, new_pos_y))
					combination[i]++;
				j++;
			}
		}
		j = 0;
		i++;
	}
	order_moveset(move_set, combination);
	return (move_set);
}

/*
** Solve the knight tour recursively.
** 
** The first time i did it, it took a stupid amount of time
** compared to the other on the repositories.
** 
** It was due to the order of the movement in my "move_x" and "move_y" arrays.
** Simply by changing it, I managed to complete a knight tour in less that 1s.
** 
** So, in order to not be "order" dependant, I select my moveset by using the Warnsdorf's rule.
** But now I'm not even sure if backtracking is needed. --(apparently it's not)
*/

int kt_solve(char **map, int sol[][2], int x, int y, int depth)
{
	if (depth == x * y - 1)
		return (1);

	int i = 0;
	int *move_set = generate_moveset(map, sol, x, y, depth);
	map[sol[depth][1]][sol[depth][0]] = 'x';

	if (!move_set)
		return (0);
	while (i < move_nbr)
	{
		int pos_x = sol[depth][0] + move_x[move_set[i]];
		int pos_y =	sol[depth][1] + move_y[move_set[i]];
		
		if (is_safe(map, x, y, pos_x, pos_y))
		{

			sol[depth + 1][0] = pos_x;
			sol[depth + 1][1] = pos_y;
			if (kt_solve(map, sol, x, y, depth + 1))
			{
				free(move_set);
				return (1);
			}
			else
			{
				free(move_set);
				return (0);
			}
		}
		i++;
	}
	free(move_set);
	map[sol[depth][1]][sol[depth][0]] = '0';
	return (0);
}

/*
** Display the solution step by step.
*/

int print_solution(char **map, int sol[][2], int x, int y)
{
	int i = 0;
	int j = 0;
	
	while (i < y)
		memset(map[i++], '.', x);
	while (j < x * y)
	{
		i = 0;
		map[sol[j][1]][sol[j][0]] = 'K';
		printf("\n");
		while (i < y)
			printf("%s\n", map[i++]);
		usleep(500000);
		map[sol[j][1]][sol[j][0]] = 'x';
		j++;
	}
	return (1);
}

/*
** Set up the knight tour.
*/

int knight_tour(int x, int y, int start_x, int start_y)
{
	int i = 0;
	int sol[y * x][2];
	char **map = malloc(sizeof(char*) * y);

	if (!map)
		return (1);
	while (i < y)
	{
		map[i] = malloc(sizeof(char) * (x + 1));
		memset(map[i], '0', x);
		map[i++][x] = '\0';		
	}
	sol[0][0] = start_x,
	sol[0][1] = start_y;
	map[sol[0][1]][sol[0][0]] = 'K';
	if (kt_solve(map, sol, x, y, 0))
		print_solution(map, sol, x, y);
	else
		printf("%s\n", "The knight tour is not possible.\n");
	i = 0;
	while (i < y)
		free(map[i++]);
	free(map);
	return (1);
}

/*
** Check size and start params.
**
*/

int check_input(int x, int y, int start_x, int start_y)
{
	if (start_x >= x || start_x < 0 || start_y >= y || start_y < 0)
	{
		printf("Starting position is out of range.\n");
		return (1);
	}
	if (x > 20 || y > 20) // no one like stack overflox.
	{
		printf("Size can't go above 20");
		return (1);
	}
	return (0);
}	

/*
** Rmq: If i take a long time, it's probably because a knight tour is not possible.
*/

int main(int argc, char **argv)
{
	int size_x;
	int size_y;
	int start_x;
	int start_y;

	if (argc != 5)
	{
		printf("Usage: %s : [size_x] [size_y] [pos_x] [pos_y]\n\n", argv[0]);
		printf("size_x & size_y : Size of the map.\n");
		printf("pos_x  & pos_y  : Knight starting position\n");
		return (1);
	}
	size_x = atoi(argv[1]);
	size_y = atoi(argv[2]);
	start_x = atoi(argv[3]);
	start_y = atoi(argv[4]);
	if (check_input(size_x, size_y, start_x, start_y))
		return (1);
	knight_tour(size_x, size_y, start_x, start_y);
	return (0);
}

