clear;close;clc;

f = @(x) sin(x)+sin(2/3*x);
[x,fx,ea,iter] = goldmin(f,2,20);
fprintf("x = %2.4f fx = %2.4f ea = %2.4f iter = %d\n",x,fx,ea,iter)
