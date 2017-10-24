function [theta] = gradient_descent(x, y, theta, alpha, num_iters)
% Performs gradient descent to learn coefficient theta
%   theta = gradient_descent(x, y, theta, alpha, num_iters) updates theta by
%   taking num_iters gradient steps with learning rate alpha

% Initialize some useful values
m = length(y); % number of training examples
x = [ones(m, 1), x];

for iter = 1:num_iters

theta = theta - alpha / m * ((x * theta - y)' * x)';

end

end
