clear;close;clc;

f = @(x) sin(x)+sin(2/3*x);
[xmin, fval] = fminbid(f,2,20)