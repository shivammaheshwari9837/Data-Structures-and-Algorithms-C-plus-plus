/*

Ques:- Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Concept:- 1)Here we will use the formula :-      a/b = e^(ln(a))/e^(ln(b)) = e^(ln(a)-ln(b))

Time - O(log n)
Space  - O(1)

*/

int divide(int dividend, int divisor) {
        
        if(dividend == 0)
            return 0;
        
        double a = log(fabs(dividend));
        double b = log(fabs(divisor));
        
        long long res = double(exp(a-b));
        
        if((dividend < 0)^(divisor < 0)) //if signs of both dividend and divisor are different
            res = -res;
        
        if(res > INT_MAX) //if answer overflows
            return INT_MAX;
        
        return res;
        
    }
