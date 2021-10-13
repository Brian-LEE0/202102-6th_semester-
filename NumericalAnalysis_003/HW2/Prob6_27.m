
close;
clear;
clc;

y = @(x) exp(-0.5*x)*(4-x)-2;
dy = @(x) (x-6)*exp(-0.5*x)/2;
fprintf("----------------------------\n");
fprintf("(a) 2\n");
[root,ea,iter]=newtraph(y,dy,2);
fprintf("root = %f   ea = %f   iter = %d\n",root,ea,iter);
fprintf("(a) is convergence\n\n");
fprintf("----------------------------\n");
fprintf("(b) 6\n");
[root,ea,iter]=newtraph(y,dy,6);
fprintf("root = %f   ea = %f   iter = %d\n",root,ea,iter);
fprintf("(b) is divergence\n\n");
fprintf("----------------------------\n");
fprintf("(c) 8\n");
[root,ea,iter]=newtraph(y,dy,8);
fprintf("root = %f   ea = %f   iter = %d\n",root,ea,iter);
fprintf("(c) is divergence\n\n");

