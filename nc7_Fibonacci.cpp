//
// Created by DayWong on 01/10/2018.
//

/*
 * 题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
 */
//重复计算次数太多了
class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int res = Fibonacci(n - 1) + Fibonacci(n - 2);    //重复计算太多了
        return res;
    }
};

class Solution {
public:
    int Fibonacci(int n) {
        int ans;
        int fib1 = 0; int fib2 = 1;      //只需要记录前两个位置就行了
        if(n == 0 || n == 1) return n;
        for(int i = 2; i < n + 1; i ++)
        {
            ans = fib1 + fib2;
            fib1 = fib2;                 //Fib1和Fib2往后挪动一位
            fib2 = ans;
        }
        return ans;
    }
};