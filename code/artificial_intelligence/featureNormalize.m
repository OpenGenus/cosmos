function [X_norm, mu, sigma] = featureNormalize(X)

X_norm = X;
mu = zeros(1, size(X, 2));
sigma = zeros(1, size(X, 2));



mu=mean(X);
sigma=std(X);
X_norm=(X_norm-mu)./sigma;




end
