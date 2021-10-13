close;
clear;
clc;

f1 = @(x) -12-21.*x+18.*x.^2-2.75.*x.^3;
fprintf("----------------------------\n");
fprintf("(b) bisect \n");
[root, fx, ea, iter] = bisect(f1, -1, 0, 1);
fprintf("root = %f   fx = %f ea = %f   iter = %d\n",root,fx,ea,iter);

fprintf("----------------------------\n");
fprintf("(c) falsepos \n");
[root, fx, ea, iter] = falsepos(f1, -1, 0, 1);
fprintf("root = %f   fx = %f ea = %f   iter = %d\n",root,fx,ea,iter);

