clear;close;clc;

x = linspace(-0.5,1.5);y=linspace(-1,1);
[X,Y] = meshgrid(x,y);
Z=4*X-2*Y-X.^2-2*X.^4+2*X.*Y-3*Y.^2;
subplot(1,2,1);
cs=contour(X,Y,Z);clabel(cs);
xlabel('x_1');ylabel('x_2');
title('(a) Contour plot');grid;
subplot(1,2,2);
cs=surfc(X,Y,Z);
zmin=floor(min(Z));
zmax=ceil(max(Z));
xlabel('x_1');ylabel('x_2');zlabel('f(x_1,x_2)');
title('(b) Mesh plot');

f = @(x) -(4*x(1) - 2*x(2) - x(1)^2 - 2*x(1)^4 + 2*x(1)*x(2) - 3*x(2)^2);
[xmax, fval] = fminsearch(f,[0.5,-0.2]);
fprintf("xmax=(%2.4f, %2.4f), fval=%2.4f\n",xmax,-fval);
