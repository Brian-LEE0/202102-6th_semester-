close;
clc;
clear;

syms x y;
f1 = x^2+y^2-5;
f2 = x^2-y-1;
F = [f1;f2];
a = [x y];
[x,f,ea,iter] = newtmult(@newFunc,[1.5;1.5],0.0001,50,F,a)
fsolve(@fun2,[1.5;1.5])
