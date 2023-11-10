# Minimum Rests Skipped to Reach on Time

## Description

You have to travel to your office in `reachTime` time by travelling on `n` roads given as array `dist` where `dist[i]` is the length of ith road. You have a constant speed `Speed`. After you travel road `i`, you must rest and wait for the next integer hour before you can begin traveling on the next road.

For example, if traveling a road takes 1.4 hours, you must wait until the 2 hour mark before traveling the next road. If traveling a road takes exactly 2 hours, you do not need to wait.

However, you are allowed to skip some rests to be able to arrive on time, meaning you do not need to wait for the next integer hour. Note that this means you may finish traveling future roads at different hour marks.

Return the **minimum** number of skips required to arrive at the office on time, or -1 if it is impossible. 

## Thought Process

Let's number the roads and stops starting from 0. So the stop after road 0 is stop 0 and so on.
Thinking in terms of subproblems and recurrence is a good start. Try answering yourself before revealing the collapsed hints.  

<details>
  <summary>What's the Subproblem in terms of roads and skips?</summary>
  What is the minimum time which it takes to cover the i roads using j skips.
</details>

<details>
  <summary>What's the recurrence relation?</summary>
  
  <p>There are two ways to cover i roads using j skips.
    <ol>
		  <li>	You cover i-1 roads using j skips and don't skip at the i-1 th ie. between roads i-1 and i stop. </li>
		  <li>  You cover i roads using j-1 skips and skip after the ith stop. So you use j-1+1 skip. </li>
    </ol>
  </p>
	Now, you just need to think about the edge cases like how you would cover i roads without any skip?
</details>

## Solution

Create a 2D DP table of n rows and n columns where dp[i][j] stores the minimum time to cover till(including) road i using j skips.

To find the answer, we iterate over all columns (times taken) for road n-1. The skip count corresponding to the first time which is lesser than 
reachTime is the answer.



