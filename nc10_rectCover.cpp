//
// Created by DayWong on 01/10/2018.
//
/*
 * 题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 */
//还是斐波那契数列
class Solution {
public:
    int rectCover(int number) {
        int ans;
        int fib1 = 1; int fib2 = 2;
        if(number == 1 || number == 2) return number;
        for(int i = 3; i < number + 1; i ++)
        {
            ans = fib1 + fib2;
            fib1 = fib2;
            fib2 = ans;
        }
        return ans;
    }
};