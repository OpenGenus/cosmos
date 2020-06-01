# Problem Link

[HILLJUMP](https://www.codechef.com/AUG17/status/HILLJUMP)

# Description
Chef is going to organize a hill jumping competition and he is going to be one of the judges in it. In this competition there are N hills in a row, and the initial height of i-th hill is Ai. Participants are required to demonstrate their jumping skills by doing what the judges tell them.

Judges will give each participant a card which has two numbers, i and k, which means that the participant should start at the i-th hill and jump k times, where one jump should be from the current hill to the nearest hill to the right which is strictly higher (in height) than the current one. If there is no such hill or its distance (i.e. difference between their indices) is more than 100 then the participant should remain in his current hill.

Please help Chef by creating a program to use it during the competitions. It should read the initial heights of the hill and should support two kinds of operations:

Type 1: Given a two numbers: i and k, your program should output the index of the hill the participant is expected to finish if he starts from the i-th hill (as explained above).

Type 2: Given three numbers: L, R, X, the heights of all the hills between L and R, both end points inclusive, should be increased by X (if X is negative then their height is decreased).