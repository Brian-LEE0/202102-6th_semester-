
function [J,F] = newFunc(x,func,param)

J = subs(jacobian(func, param),param,x.');
for i = 1:2
    F(i,1) = subs(func(i),param,x.');
end 
end