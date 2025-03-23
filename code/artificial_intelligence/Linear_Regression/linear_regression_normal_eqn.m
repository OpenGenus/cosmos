function [theta] = normal_equation(x, y, theta)
% Calculates linear regression coefficients using Normal Equation
% An analytical solution to linear regression

theta = inv(x' * x) * x' * y;

end
