clear;close;clc;

Tair = 293;
rw = 6e-3;
q = 75;
k = 0.17;
h = 12;

T = @(ri) Tair+q/(2*pi)/k*log((rw+ri)/rw)+1/(h*(rw+ri));
[xmin, fval]=fminbnd(T,0,1e-3)