import numpy as np



def multiple_feature_linear_regression(xtrain,ytrain):
	b0=0.0
	coef=[]
	for i in range(0,len(xtrain[0])):
		coef.append(0.0)
	coef=np.array(coef)
	alpha=0.01
	for i in range(0,4):
		for j in range(0,len(xtrain)):
			pr=b0
			for k in range(0,len(xtrain[0])):
				pr=pr+coef[k]*xtrain[j][k]

			err=pr-ytrain[j]
			b0=b0-alpha*err
			for k in range(0,len(xtrain[0])):
				coef[k]=coef[k]-alpha*err*xtrain[j][k]


	return b0,coef

def prediction(b0,coef,xtrain):
	return b0+(coef*xtrain)


xtrain=np.array([[1],[2],[4],[3],[5]])
ytrain=np.array([1,3,3,2,5])
xtrain=xtrain*1.0

b0,coef=multiple_feature_linear_regression(xtrain,ytrain)

print("b0 = ",b0,"\ncoef = ",coef)
print("predictions are\n",prediction(b0,coef,xtrain))