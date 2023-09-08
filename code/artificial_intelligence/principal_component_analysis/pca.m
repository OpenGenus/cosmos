function [eigenVector,newX,eigenValue] = PrincipalComponentAnalysis(X)
% Part of Cosmos by OpenGenus Foundation
% Input arguments: X input dataset 
% Output arguments: eigenVector,newX,eigenValue

 mu = mean(X);
 Xc =X - repmat(mu, [size(X, 1) 1]);
 C = (Xc' * Xc) / (size(X, 1) -1);
 [eigenVector,eigenValue] = eig(C);
 [eigenValue,order] = sort(diag(eigenValue), 'descend'); 
 eigenVector = eigenVector(:,order);
newX = Xc*eigenVector(:,1:end);
plot(newX(:,1),newX(:,2), 'r+');
Cnew = (newX' * newX) / (size(X, 1) -1);
[Vnew Dnew] = eig(Cnew);
hold on
A =10 * Vnew';
plot([-A(1,1) A(1,1)],[-A(1,2) A(1,2)],'g:');
plot([-A(2,1) A(2,1)],[-A(2,2) A(2,2)],'b:');
title('Transformeddata with 2 eigenvectors');
end
