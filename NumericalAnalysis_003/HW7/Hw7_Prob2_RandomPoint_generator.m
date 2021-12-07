a = -0.5;
b = 2.5;

y=@(x) -2.3.*exp(-3.2.*x)+5.3.*exp(-1.7.*x);

count = 1;
r = (b-a).*rand(20,1) + a;
yy = y(r);
xy(1,:) = r;
xy(2,:) = yy;
xy

fileID = fopen('Hw7_prob2_xyPoint.txt','w');
for i = 1:20
    fprintf(fileID,'%4.2f %4.2f\n',xy(1,i),xy(2,i));
end
   