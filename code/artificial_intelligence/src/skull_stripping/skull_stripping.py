# SKULL STRIPPING IN PYTHON USING THE CONCEPT OF CONNECTED COMPONENTS

import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt 
from skimage import io 

import sys
sys.setrecursionlimit(10000000)

def dfs(x, y, data, skull):
	nxt = [(x+1, y), (x-1, y), (x, y+1), (x, y-1)]
	for (dx,dy) in nxt:
		if dx >= 0 and dy >= 0 and dx < data.shape[0] and dy < data.shape[1] and data[dx, dy] > 0 and vis[dx][dy] == False:
			vis[dx][dy] = True
			skull[x, y] = data[x,y]
			dfs(dx, dy, data, skull)

data = io.imread('skull.jpeg', gray=True)
data = data.astype('int')
data = data[:,:,0]

vis = [[False] * data.shape[1] for _ in range(data.shape[0])]

skull = None
max_count = 0

for i in range(data.shape[0]):
	for j in range(data.shape[1]):
		if data[i, j] > 40 and vis[i][j] == False:
			temp_skull = np.zeros(data.shape)
			stck = [[i, j]]
			current_count = 0
			while stck:
				x, y = stck[-1]
				temp_skull[x,y] = data[x,y]
				current_count += 1
				stck.pop()
				nxt = [(x+1, y), (x-1, y), (x, y+1), (x, y-1)]
				for (dx,dy) in nxt:
					if dx >= 0 and dy >= 0 and dx < data.shape[0] and dy < data.shape[1] and data[dx, dy] > 40 and vis[dx][	dy] == False:
						vis[dx][dy] = True
						stck.append((dx, dy))
			if current_count > max_count:
				max_count = current_count
				skull = temp_skull

plt.imshow(skull, cmap='gray')
plt.show()



