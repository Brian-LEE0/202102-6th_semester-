clear;clc;close;

% -q2 - q3 = q1;
% q3 - q4 - q5 = 0;
% q5 - q6 - q7 = 0;
% q3 + 2q4 - 2q2 = 0;
% q5 + 2q6 - 2q4 = 0;
% 3q7 - 2q6 = 0;

A = [10 2 -1;-3 -5 2;1 1 6];
b = [27;-61.5;-21.5];

x = GaussNaive(A,b)