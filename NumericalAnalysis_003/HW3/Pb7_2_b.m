clear;close;clc;

func = @(x) -x^2 + 8*x -12;

[x,fx,ea,iter,info] = paraInterpol(func,0,2,6,0.0001,3);
fprintf("x = %2.4f fx = %2.4f ea = %2.4f iter = %2.4f\n",x,fx,ea,iter)