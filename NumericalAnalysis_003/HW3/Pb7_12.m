clear;close;clc;

f = @(x) -0.8.*x.^4+2.2.*x.^2+0.6;
[x,fx,ea,iter] = goldmax(f,0.7,1.4,10);
fprintf("x = %2.4f fx = %2.4f ea = %2.4f iter = %d\n",x,fx,ea,iter)
