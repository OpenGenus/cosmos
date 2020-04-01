Problem code:GIFTSRC Problem Statement: Today is Chef's birthday and he is looking forward to his gift. As usual, the gift is hidden and Chef has to follow a sequence of N instructions to reach it.

Initially, Chef is standing in the cell (0,0) of a two-dimensional grid. The sequence of instructions is given as a string S. If we denote Chef's current cell by (x,y), each character of S corresponds to an instruction as follows:

'L' means to go left, i.e. to the cell (x−1,y) 'R' means to go right, i.e. to the cell (x+1,y) 'U' means to go up, i.e. to the cell (x,y+1) 'D' means to go down, i.e. to the cell (x,y−1) In addition, Chef should never perform multiple consecutive moves along the same axis of the grid. If there are multiple consecutive instructions to move along the same axis (left/right or up/down), he should perform only the first of these moves.

Find the cell (xg,yg) which contains the hidden gift.