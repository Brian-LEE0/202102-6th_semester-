function [x,fx,ea,iter,info]=paraInterpol(f,x1,x2,x3,es,maxit,varargin)
% paraInterpol
% [x,fx,ea,iter]=paraInterpol(f,x1,x2,x3,es,maxit,p1,p2,...):
% uses golden section search to find the minimum of f
% input:
% f = name of function
% xl, xu = lower and upper guesses
% es = desired relative error (default = 0.0001%)
% maxit = maximum allowable iterations (default = 50)
% p1,p2,... = additional parameters used by f
% output:
% x = location of minimum
% fx = minimum function value
% ea = approximate relative error (%)
% iter = number of iterations
if nargin<3,error('at least 3 input arguments required'),end
if nargin<4|isempty(es), es=0.0001;end
if nargin<5|isempty(maxit), maxit=50;end
ea = 1;
iter = 0;
f1 = f(x1,varargin{:}); f2 = f(x2,varargin{:}); f3 = f(x3,varargin{:});
while(1)
 if iter > 1, f4past = f4, end
 x4 = x2 - (1/2)*((x2-x1)^2*(f2-f3)-(x2-x3)^2*(f2-f1))/((x2-x1)*(f2-f3)-(x2-x3)*(f2-f1));
 x = x4;
 f4 = f(x4, varargin{:});
 fx = f4;
 if x4 < x1
     t1 = x4; t2 = x1; t3 = x2;
     x1 = t1; x2 = t2; x3 = t3;
 elseif x1 < x4 & x4 < x2
     t1 = x1; t2 = x4; t3 = x2;
     x1 = t1; x2 = t2; x3 = t3;
 elseif x2 < x4 & x4 < x3
     t1 = x2; t2 = x4; t3 = x3;
     x1 = t1; x2 = t2; x3 = t3;
 elseif x3 < x4
     t1 = x2; t2 = x3; t3 = x4;
     x1 = t1; x2 = t2; x3 = t3;
 end
 f1 = f(x1,varargin{:}); f2 = f(x2,varargin{:}); f3 = f(x3,varargin{:});
 iter=iter+1;
 if iter> 1, ea = abs((f4-f4past)/f4)*100;end;
 f4past = f4;
 info = [x1 f1 x2 f2 x3 f3 x4 f4];
 if ea <= es | iter >= maxit,break,end
end
