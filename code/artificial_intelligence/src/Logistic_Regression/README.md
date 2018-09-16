# Logistical Regression

The **logistical regression** algorithm build upon linear regression and is basically a supervised classification algorithm. In a classification problem, the target variable (or output), Y, can take only discrete values for given set of features (or inputs), X.
We can also say that the target variable is categorical. Based on the number of categories, Logistic regression can be classified as:

1. binomial: target variable can have only 2 possible types: 0 or 1 which may represent "win" vs "loss", "pass" vs "fail", "dead" vs "alive", etc.
2. multinomial: target variable can have 3 or more possible types which are not ordered(i.e. types have no quantitative significance) like “disease A” vs “disease B” vs “disease C”.
3. ordinal: it deals with target variables with ordered categories. For example, a test score can be categorized as:“very poor”, “poor”, “good”, “very good”. Here, each category can be given a score like 0, 1, 2, 3.

Here are some points about Logistic regression to ponder upon:
--------------------------------------------------------------

- Does NOT assume a linear relationship between the dependent variable and the independent variables, but it does assume linear relationship between the logit of the explanatory variables and the response.
- Independent variables can be even the power terms or some other nonlinear transformations of the original independent variables.
- The dependent variable does NOT need to be normally distributed, but it typically assumes a distribution from an exponential family (e.g. binomial, Poisson, multinomial, normal,…); binary logistic regression assume binomial distribution of the response.
- The homogeneity of variance does NOT need to be satisfied.
- Errors need to be independent but NOT normally distributed.
- It uses maximum likelihood estimation (MLE) rather than ordinary least squares (OLS) to estimate the parameters, and thus relies on large-sample approximations.


This article is obtained as a reference from [Geeksforgeeks](http://www.geeksforgeeks.org/understanding-logistic-regression/)
