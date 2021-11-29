close;
clc;
clear;

A = [3 8;7 -1];
b = [11;5];

x = GaussSeidel(A,b,0.01,3);
fprintf("x1 = %2.4f\nx2 = %2.4f\n",x(1), x(2));