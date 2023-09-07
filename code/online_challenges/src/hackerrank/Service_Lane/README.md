# Problem Link:
[Service Lane](https://www.hackerrank.com/challenges/service-lane/problem)

# Description
Calvin is driving his favorite vehicle on the 101 freeway. He notices that the check engine light of his vehicle is on, and he wants to service it immediately to avoid any risks. Luckily, a service lane runs parallel to the highway. The service lane varies in width along its length.

Paradise Highway

You will be given an array of widths at points along the road (indices), then a list of the indices of entry and exit points. Considering each entry and exit point pair, calculate the maximum size vehicle that can travel that segment of the service lane safely.

For example, there are n = 4 measurements yielding width = [2, 3, 2, 1]. If our entry index, i = 1 and our exit, j = 2, there are two segment widths of 2 and 3 respectively. The widest vehicle that can fit through both is 2. If i = 2 and j = 4, our widths are [3, 2, 1] which limits vehicle width to 1.