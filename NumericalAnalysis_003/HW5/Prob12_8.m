close;
clc;
clear;

syms x y;
f1 = -x^2+x-y+0.75;
f2 = x^2-5*x*y-y;
F = [f1;f2];
a = [x y];
[x,f,ea,iter] = newtmult(@newFunc,[1.2;1.2],0.0001,50,F,a)
fsolve(@fun,[1.2;1.2])
