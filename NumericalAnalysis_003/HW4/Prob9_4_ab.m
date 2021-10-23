clear;clc;close;

A = [0 -3 7; 1 2 -1; 5 -2 0];
D = det(A);


%compute x1
Acpy = A;
Acpy(:,1) = [4;0;3];
A1 = Acpy;
x1 = det(A1)/D;
%compute x2
Acpy = A;
Acpy(:,2) = [4;0;3];
A2 = Acpy;
x2 = det(A2)/D;
%compute x3
Acpy = A;
Acpy(:,3) = [4;0;3];
A3 = Acpy;
x3 = det(A3)/D;

A1
x1
A2
x2
A3
x3
