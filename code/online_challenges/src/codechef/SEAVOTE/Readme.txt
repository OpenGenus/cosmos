# Problem Link:
[SEAVOTE](https://www.codechef.com/problems/SEAVOTE)

# Description
Sereja conducted a voting about N of his opinions. Ai percent of people voted for opinion number i. This statistics is called valid if sum of all Ai is equal to 100.

Now let us define rounding up of a statistics A.

If Ai is not an integer, it will be rounded up to next integer.
Otherwise it will be left as it is.
e.g. 4.1 became 5, 4.9 became 5 but 6 will still be 6.
Now let us consider a statistics B of size N in which each of Bi is an integer. Now he wants to know whether there exists some valid statistic A of size N (may contain real numbers) such that after rounding it up, it becomes same as B?

Input
First line of input contain integer T - number of test cases.
For each test, case first line contains integer N - number of opinions.
Next line contains N integers B1, B2, ..., BN as defined in the problem.
Output
For each test case, output YES or NO denoting the answer of the problem, i.e. if there exists some statistics A which could be rounded to make it B, print YES otherwise NO.
Constraints
1 ≤ T ≤ 50
1 ≤ N ≤ 10000
0 ≤ Bi ≤ 1000
Sub tasks
Subtask #1: N ≤ 100 (50 points)
Subtask #2: original (50 points)
Example
Input:
3
3
30 30 30
4
25 25 25 25
2
50 51
Output:
NO
YES
YES
Explanation
In test case 1, There can not be any A which could be rounded up to get B. Hence answer is NO.
In test case 2, In this case A = {25, 25, 25, 25}. After rounding we get {25, 25, 25, 25} which is equal to B. Hence answer is YES.
In test case 3, A = {49.5, 50.5}. After rounding up we get {50, 51} which is equal to B. Hence answer is YES.