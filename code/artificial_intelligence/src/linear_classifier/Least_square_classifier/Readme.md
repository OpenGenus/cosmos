# Least Square Linear Classifier

The idea of using least squares to create a linear classifier is to define a linear function:

## Explanation

We have some data that we separate into training and validation sets that we know what groups they should be in. For data in an n-dimensional space (say, the data is defined by n coordinates, or in even simpler terms, has n features), we need to find hyperplanes of dimension n-1 that will SPLIT the space in half, where everything on one side is in one group, and everything on the other side of the hyperplane is in another (Intuitively, for our purposes, you can see 2D Euclidean space can be separated into two parts by a line, which is a 1 dimensional object, and a 3D euclidean space can be split by a plane, which is a 2D object).

So how do we find said hyperplane to divide up our space? The simplest way, and probably the most common way is to employ least-squares just because it’s easy for a first-shot attempt at classification and linear regression.

## Algorithm

Here the linear function taken is:

```
f(x) = wx
```

and we want to adjust w so that f(x) is close to 1 for data points of one class and close to -1 for the other class. The adjustment of w is done by minimizing for each data point the squared distance between f(x) and either 1 or -1, depending on its class.


---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
