# Problem Link:
[TAVISUAL](https://www.codechef.com/problems/TAVISUAL/)

# Description
At the end of a busy day, The Chef and his assistants play a game together. The game is not just for fun but also used to decide who will have to clean the kitchen. The Chef is a Game Master, so his concern is how to manage the game but not how to win the game like his assistants do.

The game requires players to find the only ball under one of the N cups after their positions are changed in a special way. At the beginning of the game, The Chef places N cups in a row and put a ball under the C-th cup from the left (the cups are numbered from 1 to N). All players can see the initial position of the ball. Then Chef performs Q flip operations. Each flip operation is defined by two integers L and R such that 1 ≤ L ≤ R ≤ N and consists in reversing the segment [L, R] of cups. Namely, Chef swaps L-th and R-th cups, (L+1)-th and (R−1)-th cups, and so on. After performing all the operations Chef asks his assistants to choose a cup that they think the ball is under it. Who can guess the position of the ball will win the game, and of course, the others will have to clean the kitchen.

The Chef doesn't want to check all the N cups at the end of the game. He notes down the value of C and the pairs (L, R) and asked you, the mastered programmer, to determine the cup that contains the ball.