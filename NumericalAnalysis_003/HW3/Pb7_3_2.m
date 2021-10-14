clear;close;clc;

f = @(x) 6+10*x+9*x^2+16*x^3;

[x,fx,ea,iter] = bisect(f,-1,0);
fprintf("x = %2.4f fx = %e ea = %2.4f iter = %d\n",x,fx,ea,iter)