clc;close;clear;

x = [3 4 5 7 8 9 11 12]';
y = [1.6 3.6 4.4 3.4 2.2 2.8 3.8 4.6]';
Z = [ones(size(x)) x x.^2 x.^3];

a = Z\y
p = @(t) a(1)+a(2).*t+a(3).*t.^2+a(4).*t.^3;
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