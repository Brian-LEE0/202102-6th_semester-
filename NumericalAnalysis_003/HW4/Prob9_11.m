clear;clc;close;

A = [15 17 19;0.3 0.4 0.55;1 1.2 1.5];
b = [3890; 95; 282];

x = GaussNaive(A,b);
fprintf("Component 1 : %0.0f개\n",x(1));
fprintf("Component 2 : %0.0f개\n",x(2));
fprintf("Component 3 : %0.0f개\n",x(3));