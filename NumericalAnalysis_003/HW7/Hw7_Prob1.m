clc;close;clear;

fileID= fopen('gaussnewton_testdata.txt','r');
data= fscanf(fileID,'%f',[2 inf]);
x=data(1,:);
y=data(2,:);

a = GaussNewton(x,y);