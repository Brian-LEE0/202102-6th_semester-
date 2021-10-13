close;
clear;
clc;

cal(9.81,95,9,46,0.2,0.5);


function cal(g,m,t,v,xl,xu)
    f1 = @(c) sqrt(g*m/c)*tanh(sqrt(g*c/m)*t)-v;
    count = 0;
    fprintf("xl     f(xl)      xu     f(xu)     xr     f(xr)     E\n");
    while 1
        rl = f1(xl);
        ru = f1(xu);
        if (rl*ru) > 0
            fprintf("Cannot Calculate");
            break;
        else
            xr = (xl+xu)/2;
            rr = f1(xr);
            
            
            if count>0
                E = abs((xrpast - xr)/xr) * 100;
                fprintf("%5.4f  %8.6f  %5.4f  %8.6f  %5.4f  %8.6f  %8.6f%%\n", xl, rl, xu, ru, xr, rr, E);
                if(E < 5)
                    break;
                end
            else
                fprintf("%5.4f  %8.6f  %5.4f  %8.6f  %5.4f  %8.6f  -\n", xl, rl, xu, ru, xr, rr);
                
            end
            
            if rr > 0
                if rl > 0
                    xl = xr;
                else
                    xu = xr;
                end
            else
                if rl > 0
                    xu = xr;
                else
                    xl = xr;
                end
            end
            xrpast = xr;
            count = count + 1;
            
            if (count > 10)
                break;
            end
            
        end
            
        
    end
    
end


