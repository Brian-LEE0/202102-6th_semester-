function a = GaussNewton(x,y)
tol = 0.0001; % tolerance 
a = [-3,-1.5,-2,6];% initial value
iter_max = 50; % max iteration
n = length(x); % number of data point
disp('ietration a0 a1 da0 da1');
for iter = 1:iter_max
    a0 = a(1);
    a1 = a(2);
    a2 = a(3);
    a3 = a(4);
    for i = 1:n 
        f(i) = a2.*exp(a0.*x(i))+a3.*exp(a1.*x(i));
        j(i,1) = a2.*x(i).*exp(a0.*x(i))+a3.*exp(a1.*x(i));
        j(i,2) = a2.*exp(a0.*x(i))+a3.*x(i).*exp(a1.*x(i));
        j(i,3) = exp(a0.*x(i))+a3.*exp(a1.*x(i));
        j(i,4) = a2.*exp(a0.*x(i))+exp(a1.*x(i));
        d(i) = y(i) - f(i);
    end
    da = (j'*j)\(j'*d');
    a = a + da';
    out = [iter a da'];
    disp(out)
    if(abs(da(1))<tol && abs(da(2))<tol)
        disp("Gauss-Newton method has converged");
        break
    end
end
x1 = min(x);
x2 = max(x);
xx = linspace(x1,x2,100);
yy = a2.*exp(a0.*xx)+a3.*exp(a1.*xx);
plot(xx,yy,x,y,'ro');
fprintf("\n---------------\nx1:%4.2f || x2:%4.2f || x3:%4.2f || x4:%4.2f\n---------------\n",a0,a1,a2,a3);
