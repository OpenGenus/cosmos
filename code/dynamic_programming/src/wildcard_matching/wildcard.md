# Wildcard Matching

Learn more: [Wildcard Pattern Matching (Dynamic Programming)](https://iq.opengenus.org/wildcard-pattern-matching-dp/)

## Description

You have a string `s` of length `m` and a pattern `p` of length `n`. With wildcard matching enabled ie. character `?` in `p` can replace 1 character of `s` and a `*` 
in `p` can replace any number of characters of `s` including 0 character, find if `s` is equivalent to `p`.

Return **true** if `s` is equivalent to `p` else **false**.

## Thought Process

Let's follow 1-based indexing and denote s[i,j] as the substring of s from ith to jth character including both. Same for p. So for example, if s is "abcde", then 
s[2,4] is the substring "bcd".      

<details> 
  <summary>What's the problem in terms of s, p, m, and n?</summary>
  </br>
  Return true when s[1:m] is equivalent to p[1:n].
  
</details>

<details> 
  <summary>What's the Subproblem in terms of s and p?</summary>
  </br>
  <ol>
    <li>For an index i and an index j, we want to find if s[1:i] is equivalent to p[1:j].</li>
    <li>Note that a subproblem can be formulated from the end of strings as well but then you'll need to fill the DP table from bottom to top.</li>
  </ol>

</details>

<details> 
  <summary>Solution</summary>
  </br>
  <ol>
  <li>We iterate over all i from 1 to m. For each i, we iterate over all j from 1 to n. At each point, we check if s[1:i] is equivalent to p[1:j] and fill true
  or false in the cell dp[i][j] of the dp table. Recording this will help in finding answers to further i and j which we'll see in the recurrence relation.</li>
  <li>The final answer is dp[m][n].</li>
  </ol>
</details>

<details>
  <summary>What's the recurrence relation?</summary>
  </br>
  <ol>
  <li>If the jth character of p is the same as ith character of s, then s[1:i]=p[1:j] if s[1:i-1]=p[1:j-1] ie. dp[i][j]=dp[i-1][j-1]. Also, when jth character 
   of p is ?, it will consume the ith character of s. Hence same for it.</li>

  <li>If the jth character of p is '*', then it can consume 0 characters ie. s[1:i]=p[1:j-1] or several characters ie. dp[i][j]=dp[i][j-1] || dp[i-1][j].</li>
  </ol>
</details>

<details>
  <summary>What's the time complexity?</summary>
  </br>
  Since we need to lookup atmost two adjacent cells to fill any cell in the dp table, filling a cell is an O(1) process. And we need to fill m*n such cells.
  Thus the complexity is O(mn).
  
</details>
<details>
  <summary>What's next?</summary>
  </br>
  <ol>
  <li>Think about the subproblem that each cell of the DP table handles and come up with the edge cases.</li> 
  <li>What changes when you consider 0-based indexing for strings? </li>
  </ol>
  
</details>

