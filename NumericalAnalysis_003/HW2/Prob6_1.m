close;
clear;
clc;

x0 = 0.5; % guess
x1 = sin(sqrt(x0));
count = 1;
ea = abs((x1-x0)/x1)*100;
es = ea*0.001/100;
fprintf("no%d : x1 = %2.5f, ea = %2.5f\n",count, x1, ea);
count = count + 1;
while ea > es

    x0 = x1;

    x1 = sin(sqrt(x1));

    ea = abs((x1-x0)/x1)*100;
    
    fprintf("no%d : x1 = %2.5f, ea = %2.5f\n",count, x1, ea);
    count = count + 1;
end