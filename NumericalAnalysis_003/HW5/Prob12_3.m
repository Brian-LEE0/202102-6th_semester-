close;
clc;
clear;

A = [10 2 -1;-3 -6 2; 1 1 5];
b = [27;-61.5;-21.5];

x = GaussSeidel(A,b,5);
fprintf("x1 = %2.4f\nx2 = %2.4f\nx3 = %2.4f\n",x(1), x(2), x(3));