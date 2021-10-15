clear;close;clc;

f = @(x) sin(x)+sin(2/3*x);
x = linspace(2,20);
y = f(x);
plot(x,y);
grid on;