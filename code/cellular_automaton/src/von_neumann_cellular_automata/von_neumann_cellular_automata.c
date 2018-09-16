#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define WIDTH 20
#define HEIGHT 30

const char* clear = "\e[1;1H\e[2J";

enum states{ 	U,								/*Empty state (__)*/
		S, S0, S00, S000, S01, S1, S10, S11,	//Transition states (??)*/
		C00, C01, C10, C11, 					/*Confluent  states ([])*/
		C_NORTH, C_EAST, C_SOUTH, C_WEST, 		/*Common Transmition states (/\, ->, \/, <-)*/
		S_NORTH, S_EAST, S_SOUTH, S_WEST		/*Special Transition states (/\, ->, \/, <-)*/
	};						

struct cell{
	short state;
	short active; 
};

void 
transmition(struct cell board[][WIDTH], struct cell temp[][WIDTH], int i, int j){
	assert(board[i][j].active <= 1);
	if(board[i][j].active == 1){
		switch(board[i][j].state){
		/*Common States*/
			case C_NORTH:
				if(i > 0 && board[i -1][j].state <= C_WEST){
					if(board[i -1][j].state == U)
						temp[i -1][j].state = S;
					else					
						temp[i -1][j].active++;
				}
				else if(i > 0)
					temp[i -1][j].state = U;
					
				temp[i][j].active--;
				break;
				
			case C_EAST:
				if(j < WIDTH && board[i][j +1].state <= C_WEST){					
					if(board[i][j +1].state == U)
						temp[i][j +1].state = S;
					else
						temp[i][j +1].active++;
				}
				else if(j < WIDTH)
					temp[i][j +1].state = U;
				temp[i][j].active--;
				break;
				
			case C_SOUTH:
				if(i < HEIGHT && board[i +1][j].state <= C_WEST){
					if(board[i +1][j].state == U)
						temp[i +1][j].state = S;
					else					
						temp[i +1][j].active++;
				}
				else if(i < HEIGHT)
					temp[i][j +1].state = U;
				temp[i][j].active--;
				break;
			
			case C_WEST:
				if(j > 0 && board[i][j -1].state <= C_WEST){
					if(board[i][j -1].state == U)
						temp[i][j -1].state = S;
					else					
						temp[i][j -1].active++;
				}
				else if(j > 0)
					temp[i][j -1].state = U;
				temp[i][j].active--;
				break;

		/*Special states*/
			case S_NORTH:
				if(i > 0 && (board[i -1][j].state >= S_NORTH || board[i -1][j].state < C_NORTH)){
					if(board[i -1][j].state == U)
						temp[i -1][j].state = S;
					else if(board[i -1][j].state >= C00 && board[i -1][j].state <= C11)
						temp[i -1][j].state = U;
					else
						temp[i -1][j].active++;
				}
				if(i > 0)
					temp[i -1][j].state = U;
					
				temp[i][j].active--;
				break;
				
			case S_EAST:
				if(j < WIDTH && (board[i][j +1].state >= S_NORTH || board[i][j +1].state < C_NORTH)){
					if(board[i][j +1].state == U)
						temp[i][j +1].state = S;
					else if(board[i][j + 1].state >= C00 && board[i][j +1].state <= C11)
						temp[i][j +1].state = U;
					else					
						temp[i][j +1].active++;
				}
				else if(j < WIDTH)
					temp[i][j +1].state = U;
				temp[i][j].active--;
				break;
				
			case S_SOUTH:
				if(i < HEIGHT && (board[i +1][j].state >= S_NORTH || board[i +1][j].state < C_NORTH)){
					if(board[i +1][j].state == U)
						temp[i +1][j].state = S;
					else if(board[i +1][j].state >= C00 && board[i +1][j].state <= C11)
						temp[i +1][j].state = U;
					else					
						temp[i +1][j].active++;
				}
				else if(i < HEIGHT)
					temp[i][j +1].state = U;
				temp[i][j].active--;
				break;
			
			case S_WEST:
				if(j > 0 && (board[i][j -1].state >= S_NORTH || board[i][j -1].state < C_NORTH)){
					if(board[i][j -1].state == U)
						temp[i][j -1].state = S;
					else if(board[i][j -1].state >= C00 && board[i][j -1].state <= C11)
						temp[i][j -1].state = U;
					else					
						temp[i][j -1].active++;
				}
				else if(j > 0)
					temp[i][j -1].state = U;
				temp[i][j].active--;
				break;
				
		}
	}
}

void 
confluent(struct cell board[][WIDTH], struct cell temp[][WIDTH], int i, int j){
	int aux[4];		/*Neighborhood vector [up, left, down, right]*/
	int in = 0, out = 0;

	aux[0] =  (i > 0 && board[i -1][j].state == C_SOUTH && ++in) - 
				(i > 0 && (board[i -1][j].state == C_NORTH || board[i -1][j].state == S_NORTH) && ++out); 
	aux[1] = (j > 0 && board[i][j -1].state == C_EAST  && ++in) -
				(j > 0 && (board[i][j -1].state == C_WEST || board[i][j -1].state == S_WEST)&& ++out);
	aux[2] = (i < HEIGHT && board[i +1][j].state == C_NORTH && ++in) - 
				(i < HEIGHT && (board[i +1][j].state == C_SOUTH || board[i +1][j].state == S_SOUTH) && ++out);
	aux[3] = (j < WIDTH && board[i][j +1].state == C_WEST && ++in) - 
				(j < WIDTH && (board[i][j +1].state == C_EAST || board[i][j +1].state == S_EAST) && ++out);
	
	switch(board[i][j].state){
		case C00:
			if(temp[i][j].active >= in)
				temp[i][j].state = C01;
			temp[i][j].active = 0;
			break;

		case C01:
			if(out > 0){			/*Transfering data for neighborhood*/
				if(aux[0] == -1)	temp[i -1][j].active++;
				if(aux[1] == -1)	temp[i][j -1].active++;
				if(aux[2] == -1)	temp[i +1][j].active++;
				if(aux[3] == -1)	temp[i][j +1].active++;
				
			}
			if(temp[i][j].active >= in)
				temp[i][j].state = C11;
			else
				temp[i][j].state = C10;
			temp[i][j].active = 0;
			break;

		case C10:
			if(temp[i][j].active >= in)
				temp[i][j].state = C01;
			else
				temp[i][j].state = C00;
			temp[i][j].active = 0;
			break;

		case C11:
			if(out > 0){
				if(aux[0] == -1)	temp[i -1][j].active++;
				if(aux[1] == -1)	temp[i][j -1].active++;
				if(aux[2] == -1)	temp[i +1][j].active++;
				if(aux[3] == -1)	temp[i][j +1].active++;
				
			}
			if(temp[i][j].active >= in)
				temp[i][j].state = C11;
			else 
				temp[i][j].state = C10;
			temp[i][j].active = 0;
			break;
	}
}

void 
transition(struct cell board[][WIDTH], struct cell temp[][WIDTH], int i, int j){
	
	switch(board[i][j].state){
		case S:
			if(temp[i][j].active == 1)
				temp[i][j].state = S1;
			else
				temp[i][j].state = S0;
			temp[i][j].active--;
			break;

		case S0:
			if(temp[i][j].active == 1)
				temp[i][j].state = S01;
			else
				temp[i][j].state = S00;
			temp[i][j].active--;
			break;

		case S00:
			if(temp[i][j].active == 1)
				temp[i][j].state = C_WEST;
			else
				temp[i][j].state = S000;
			temp[i][j].active--;
			break;

		case S000:
			if(temp[i][j].active == 1)
				temp[i][j].state = C_NORTH;
			else
				temp[i][j].state = C_EAST;
			temp[i][j].active--;
			break;

		case S01:
			if(temp[i][j].active == 1)
				temp[i][j].state = S_EAST;
			else
				temp[i][j].state = C_SOUTH;
			temp[i][j].active--;
			break;

		case S1:
			if(temp[i][j].active == 1)
				temp[i][j].state = S11;
			else
				temp[i][j].state = S10;
			temp[i][j].active--;
			break;

		case S10:
			if(temp[i][j].active == 1)
				temp[i][j].state = S_WEST;
			else
				temp[i][j].state = S_NORTH;
			temp[i][j].active--;
			break;

		case S11:
			if(temp[i][j].active == 1)
				temp[i][j].state = C00;
			else
				temp[i][j].state = S_SOUTH;
			temp[i][j].active--;
			break;

	}
}

void 
update(struct cell board[][WIDTH], struct cell temp[][WIDTH]){
	int i, j;

	for(i = 0; i < HEIGHT; i++){
		for(j = 0; j < WIDTH; j++){
			
			temp[i][j].active = temp[i][j].active > 0;
			board[i][j].state = temp[i][j].state;
			board[i][j].active = temp[i][j].active;
		}
	}

	for(i = 0; i < HEIGHT; i++){
			for(j = 0; j < WIDTH; j++){
				if(board[i][j].state >= C_NORTH)	/*Transmition states*/
					transmition(board, temp, i, j);
			}
	}

	for(i = 0; i < HEIGHT; i++){
			for(j = 0; j < WIDTH; j++){
				
				if(board[i][j].state == U)				/*Empty state*/
					continue;

				else if(board[i][j].state < C00) 		/*Transition states*/
					transition(board, temp, i, j);

				else if(board[i][j].state < C_NORTH) 	/*Confluent states*/
					confluent(board, temp, i, j);
				
			}
		}

	
}

void print_board(struct cell board[][WIDTH]){
	int i, j;
	for(i = 0; i < HEIGHT; i++){
		for(j = 0; j < WIDTH; j++){
			if(board[i][j].active == 1)
				printf("++");
			else if(board[i][j].state == U )
				printf("__");
			else if(board[i][j].state < C00)
				printf("??");
			else if(board[i][j].state < C_NORTH)
				printf("<>");
			else{ 
				if((board[i][j].state - C_NORTH) % 4 == 0)
					printf("/\\");
				else if((board[i][j].state - C_NORTH) % 4 == 1)
					printf("->");
				else if((board[i][j].state - C_NORTH) % 4 == 2)
					printf("\\/");
				else if((board[i][j].state - C_NORTH) % 4 == 3)
					printf("<-");
			}
			printf(".");
		}
		printf("\n");
	}
}

void clear_board(struct cell board[][WIDTH], struct cell temp[][WIDTH]){
	int i, j;	
	for(i = 0; i < HEIGHT; i++){
		for(j = 0; j < WIDTH; j++){
			board[i][j].state = U;
			board[i][j].active = 0;
			temp[i][j].state = U;
			temp[i][j].active = 0;
		}
	}
}

void initial_board(struct cell board[][WIDTH], struct cell temp[][WIDTH]){
	int i;
	/*Create loop*/
	for(i = 5; i <= 10; i++){
		board[5][i].state = C_EAST;
		board[10][i].state = C_WEST;
		board[i][5].state = C_NORTH;
		board[i][10].state = C_SOUTH;

		temp[5][i].state = C_EAST;
		temp[10][i].state = C_WEST;
		temp[i][5].state = C_NORTH;
		temp[i][10].state = C_SOUTH;

	}
	board[5][5].state = C_EAST;
	board[5][10].state = C_SOUTH;
	board[10][10].state = C_WEST;
	board[10][5].state = C_NORTH;
	temp[5][5].state = C_EAST;
	temp[5][10].state = C00;
	temp[5][11].state = S_EAST;
	temp[10][10].state = C_WEST;
	temp[10][5].state = C_NORTH;
	
	/*initial condition*/
	temp[10][5].active = 1;
	temp[10][7].active = 1;
	temp[10][8].active = 1; 
}

int main(){
	struct cell board[HEIGHT][WIDTH];
	struct cell temp[HEIGHT][WIDTH];
	
	clear_board(board, temp);
	initial_board(board, temp);	

	do{
		
		/*Update boards*/
		update(board, temp);
		print_board(board);		

		getchar();
		printf("%s", clear);
	}while(1);
}
