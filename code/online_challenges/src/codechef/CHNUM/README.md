# Problem Link

[CHNUM](https://www.codechef.com/MARCH19B/problems/CHNUM)

# Description

Recently, Chef hosted a strange competition at the Byteland annual fair. There were N participants in the competition (numbered 1 through N); at the end of the competition, their scores were A1,A2,…,AN. Since it was a strange competition, negative scores were allowed too.

The total score of the competition is calculated as follows:

Divide the participants into one or more non-empty groups (subsets); 

if there are K groups, let's denote them by G1,G2,…,GK. Each participant should be a member of exactly one group.

Sum up the scores of participants in each individual group. For each valid i, let's denote the sum of scores of participants in group i by Xi. 

The total score of the competition is the sum of squares of these summed up scores, i.e. X1^2 + X2^2+…+XK^2.

Chef wants to choose the groups in such a way that the total score is maximum possible. Since there may be many ways to form the groups that lead to the maximum total score, Chef wants to know just the size of the largest group and the size of the smallest group which could be formed while still maximising the total score. These sizes are independent - formally, they are the maximum and minimum size sof a group such that there is a way to form groups which maximises the total score and contains a group with size s.
