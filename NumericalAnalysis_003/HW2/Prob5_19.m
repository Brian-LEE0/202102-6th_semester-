close;
clear;
clc;

e0 = 8.9e-12;
F = 1.25;
q = 2e-5;
Q = 2e-5;
a = 0.85;

x1 = linspace(0,2);
y = @(x) F - 1/(4*pi*e0)*q*Q.*x./((x.^2+a^2).^(3/2)); 


[root,fx,ea,iter]=bisect(y,0.1,0.4)

y = y(x1);
plot(x1,y);
grid on