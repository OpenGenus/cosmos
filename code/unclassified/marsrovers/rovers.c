//Since rovers can only walk over the plateau, any movement that exceeds the plateau is discarded

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (void) {
	char move[500]; //string with the instructions
	int xmax, ymax; //upper-right corner coordinates
	int x0, y0; //rover position variables
	char dir0; //rover facing direction
	int count;

	scanf("%d %d", &xmax, &ymax); //gets the upper-right coordinates of the plateau

	scanf("%d", &x0); //gets the first x0 to check condition of the program to run
	while(x0!=-1) { //the stop condition is that x0 is -1

		scanf("%d %c", &y0, &dir0); //gets starting position and facing direction
		
		getchar(); //cleans keyboard buffer
		scanf("%[^\n]", move); //gets the movement string

		for(count=0;move[count]!='\0';count++) {
			switch(move[count]) { 
				case 'R' : //In case rover turns to the right
					switch(dir0) {
						case 'N' :
							dir0='E';
							break;
						case 'E':
							dir0='S';
							break;
						case 'S' :
							dir0='W';
							break;
						case 'W':
							dir0='N';
							break;
					}
					break;
				case 'L' : //In case rover turns to the left
					switch(dir0) {
						case 'N' :
							dir0='W';
							break;
						case 'E':
							dir0='N';
							break;
						case 'S' :
							dir0='E';
							break;
						case 'W':
							dir0='S';
							break;
					}
					break;
				case 'M' : //In case rover moves foward
					switch(dir0) {
						case 'N' :
							if(y0+1<=ymax) y0++;
							break;
						case 'E' :
							if(x0+1<=xmax) x0++;
							break;
						case 'S' :
							if(y0-1>=0) y0--;
							break;
						case 'W' :
							if(x0-1>=0) x0--;
							break;
					}
					break;
			}
		}
		
		printf("%d %d %c\n", x0, y0, dir0); //outputs each test case
		
		scanf("%d", &x0); //gets the next x0 to proceed or not with the tests, if its -1, no more tests occur
	}

	return 0;
} //end of main
