#See https://howtotrainyourrobot.com/machine-learning-svm-the-usefulness-of-kernels/

from __future__ import division
# [row,col] coordinates:
data = [[ 0,0 ], [ 0,1 ], [ 0,2 ], [ 0,3 ],
        [ 1,0 ], [ 1,1 ], [ 1,2 ], [ 1,3 ],
        [ 2,0 ], [ 2,1 ], [ 2,2 ], [ 2,3 ],
        [ 3,0 ], [ 3,1 ], [ 3,2 ], [ 3,3 ],
 ]

#Separating x,y coordinates in nonlinear (circle center, only center positive):
category = [ -1,  -1,  -1, -1,
             -1,   1,   1, -1,
             -1,   1,   1, -1,
             -1,  -1,  -1, -1, ]

import numpy
from sklearn.svm import SVC

clf = SVC(kernel='rbf', C=1)
clf.fit(data, category)

print('accuracy=%f' % clf.score(data, category) )

while True:
	#Try other points
	d = input('vector=')
	calculatedValue = clf.predict(eval(d))
	print(calculatedValue)
