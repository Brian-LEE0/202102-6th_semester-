close;
clear;
clc;

x = linspace(0,4);
y = @(x) x.^3-6.*(x.^2)+11.*x - 6.1;
y1 = y(x);
plot(x,y1);
grid;

% f'(x) = 3x^2 -12x+11
% using newtraph

y_diff = @(x) 3.*(x.^2) - 12.*x + 11;
fprintf("----------------------------\n");
fprintf("(b) Using the Newton-Raphson method\n");
[root,ea,iter]=newtraph(y,y_diff,3.5,0.01,3);
fprintf("root = %2.4f   ea = %2.4f   iter = %d\n",root,ea,iter);
fprintf("----------------------------\n");
fprintf("(c) Using the secant method\n");
[root,ea,iter]=secant(y,2.5,3.5,0.01,3);
fprintf("root = %2.4f   ea = %2.4f   iter = %d\n",root,ea,iter);
fprintf("----------------------------\n");
fprintf("(d) Using the modified secant method \n");
[root,ea,iter]=modifsec(y,3.5,0.01,0.01,3);
fprintf("root = %2.4f   ea = %2.4f   iter = %d\n",root,ea,iter);
fprintf("----------------------------\n");
fprintf("(e) Determine all the roots with MATLABn");
a = [1 -6 11 -6.1];
roots(a)
