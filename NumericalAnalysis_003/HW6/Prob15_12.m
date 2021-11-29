clc;close;clear;

x = [1 2 3 4 5]';
y = [2.2 2.8 3.6 4.5 5.5]';
Z = [ones(size(x)) x 1./x];

a = Z\y
p = @(t) a(1)+a(2).*t+a(3)./t;
x1 = 0.2:0.01:7;
y1 = p(x1);
plot(x1,y1);
hold on
scatter(x,y);
hold off

St = sum((y-mean(y)).^2)
Sr = sum((y-Z*a).^2)
r2 = 1 -Sr/St
syx = sqrt(Sr/(length(x)-length(a)))