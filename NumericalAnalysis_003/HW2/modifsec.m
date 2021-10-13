function [root,ea,iter]=modifsec(func,xr,delta,es,maxit,varargin)
if nargin<3,error('at least 3 input arguments required'),end
if nargin<4 || isempty(es),es=0.0001;end
if nargin<5 || isempty(maxit),maxit=50;end
iter = 0;
while(1)
    xrold = xr;
    xr = xr - delta*xr*func(xr)/(func(xr+delta*xr)-func(xr));
    iter = iter + 1;
    if xr ~= 0, ea = abs((xr - xrold)/xr) * 100; end
    if ea <= es || iter >= maxit, break, end
end
root = xr;
end