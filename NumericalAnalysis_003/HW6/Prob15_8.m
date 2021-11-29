clc;close;clear;

x1 = [0 1 1 2 2 3 3 4 4 ]';
x2 = [0 1 2 1 2 1 2 1 2]';
y = [15.1 17.9 12.7 25.6 20.5 35.1 29.7 45.4 40.2]';
Z = [ones(size(x1)) x1 x2];

a = Z\y
p = @(t,u) a(1)+a(2).*t+a(3).*u;
[X,Y] = meshgrid(1:0.1:10, 1:0.1:10);
Znew = p(X,Y);
surf(X,Y,Znew);

St = sum((y-mean(y)).^2)
Sr = sum((y-Z*a).^2)
r2 = 1 -Sr/St
syx = sqrt(Sr/(length(x1)-length(a)))