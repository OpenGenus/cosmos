
// Part of cosmos repository
// Implementing alpha beta prruning in java
import java.io.*;
import java.util.*;
class AlphaBetaPruningJava {

static int MAXIMUM = 1000;
static int MINIMUM = -1000;

static int minimaxAlphaBeta(int values[],
                int depth,               //Minimax function
                int node,
				Boolean maxPlayer,
				int alpha,
				int beta)
{
    //We know the depth here , hence a constant value. Otherwise it can be found out.(logn)
	if (depth == 3)
		return values[node];

	if (maxPlayer==true)
	{
		int ans = MINIMUM;
		for (int i = 0; i < 2; i++)
		{
			int currValue = minimaxAlphaBeta(values,depth + 1, node * 2 + i,
							false, alpha, beta);
			ans = Math.max(ans, currValue);
			alpha = Math.max(alpha, ans);

			// Alpha Beta Pruning
			if (beta <= alpha)
				break;
		}
		return ans;
	}
	else
	{
		int ans = MAXIMUM;
		for (int i = 0; i < 2; i++)
		{
			
			int currValue = minimaxAlphaBeta(values,depth + 1, node * 2 + i,true, alpha, beta);
			ans = Math.min(ans, currValue);
			beta = Math.min(beta, ans);

			if (beta <= alpha)
				break;
		}
		return ans;
	}
}
	public static void main (String[] args)
	{
		int values[] = {13, 8, 24, -5, 23, 15, -14, -20};
		System.out.println(minimaxAlphaBeta(values,0,0, true, MINIMUM, MAXIMUM));
	}
}


