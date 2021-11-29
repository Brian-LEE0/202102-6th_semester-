clc;close;clear;

x = [0.5 1 2 3 4 5 6 7 9]';
y = [6 4.4 3.2 2.7 2 1.9 1.7 1.4 1.1]';
Z = [exp(-1.5.*x) exp(-0.3.*x) exp(-0.05.*x)];

a = Z\y
p = @(t) a(1).*exp(-1.5.*t)+a(2).*exp(-0.3.*t)+a(3).*exp(-0.05.*t);
x1 = 0:0.01:15;
y1 = p(x1);
plot(x1,y1);
hold on
scatter(x,y);
hold off

St = sum((y-mean(y)).^2)
Sr = sum((y-Z*a).^2)
r2 = 1 -Sr/St
syx = sqrt(Sr/(length(x)-length(a)))