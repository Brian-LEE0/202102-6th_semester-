clc;close;clear;

fileID= fopen('Hw7_prob2_xyPoint.txt','r');
data= fscanf(fileID,'%f',[2 inf]);
x=data(1,:);
y=data(2,:);

a = GaussNewton2(x,y);