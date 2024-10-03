# Problem Link:
[PLZLYKME](https://www.codechef.com/problems/PLZLYKME/)

# Description
In a far away dystopian world, the measure of the quality of a person’s life is the numbers of likes he gets for an article about their life. For a person to stay alive, he has to acquire at least L number of likes before D days pass.

People in this world employ various techniques to increase the number of likes. One of the famous ones is to dis-like and re-like their own article once per day. On doing so you can assume that the number of likes for the post increase by a constant factor C.

So if one starts with S likes on Day-1, he would have D2 = S + C * S likes on Day-2, D3 = D2 + D2 * C on Day-3 etc. You are to answer if the person would survive at the end of Day-D or not.