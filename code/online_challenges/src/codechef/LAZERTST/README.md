# Problem Link

[EGGFREE](https://www.codechef.com/MARCH20A/problems/LAZERTST)

# Description
### This is an interactive problem.

When Vivek was creating the problem LAZER, he realised that it can be used to create a different, interactive problem. Can you solve this problem too?

Let's frame this problem formally. You are given integers N, M, K and Q. Consider a random sequence A1,A2,…,AN, where each element is generated independently and uniformly randomly between 1 and M (inclusive). As described in the problem statement of LAZER, we create line segments between pairs of points (i,Ai) and (i+1,Ai+1) for each valid i.

The height of a line segment connecting points (x1,y1) and (x2,y2) is defined as |y1−y2|. You are given Q queries. In each query, you are given integers L and R; you should consider the line segments such that the x-coordinates of their endpoints lie between L and R inclusive, and you should find the maximum of heights of these segments.

Your task is to answer these queries. However, the sequence A is hidden and you may only ask at most K questions (of a different type from the queries you should answer). In each of your questions:

You should choose integers x1, x2 and y, where 1≤x1<x2≤N and 1≤y≤109.
Consider a laser beam fired horizontally to the right from the point (x1,y), which stops at the point (x2,y) and does not propagate further.
This beam collides with zero or more of the line segments described above. The beam is considered to collide with a line segment if it intersects or touches this segment, except when the left endpoint of this segment is (x2,y) or its right endpoint is (x1,y).
The answer to this question is the maximum of heights of the segments with which it collides or the information that it does not collide with any segments