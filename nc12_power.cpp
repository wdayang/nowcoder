//
// Created by DayWong on 02/10/2018.
//
/*
 * 题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 */
class Solution {
public:
    double Power(double base, int exponent) {
        //快速幂方法
        //long long p = abs((long long) exponent);
        int p = (exponent >= 0? exponent: -1 * exponent);
        /*int p;
        if(exponent > 0) p = exponent;
        else if(p < 0) p = -1 * exponent;
        else return 1;*/
        double curr = base;
        double ans = 1.;
        if(p == 0) return ans;
        while(p)
        {
            if(p & 1) ans *= curr;
            curr *= curr;
            p >>= 1;
        }
        return exponent > 0? ans: 1/ans;   //最后注意是用exponent不是用p，p是运用的，已经发生了变化
    }
/*
private:
static double Power_usual(double base, int exponent)
{
    double ans = 1.0;
        if(exponent > 0)
        {
            for(int i = 0; i < exponent; i ++) ans *= base;
            return ans;
        }
        else if(exponent < 0)
        {
            for(int i = 0; i < -1 * exponent; i ++) ans *= base;
            ans = 1.0 / ans;
            return ans;
        }
        else          //最后一个必须要是else，不然所有的if都不满足的话就不会有返回值
        {
            if(base == 0) return 9999999;
            else return 1.0;
        }
}*/
};