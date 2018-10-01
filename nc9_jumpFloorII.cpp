//
// Created by DayWong on 01/10/2018.
//

/*
 * 题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
 求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */
//到达一个点的方法是到达前面所有点的方法之和，
//f(n) = f(n - 1) + f(n - 1)... + f(1)
//f(n - 1) = f(n - 2) + ... + f(1)
//f(n) = 2 * f(n - 1) 只需记录前一个位置
class Solution {
public:
    int jumpFloorII(int number) {
        int ans;
        int temp = 1;//存储跳到前一个台阶的方法数
        if(number == 1) return 1;
        for(int i = 2; i < number + 1; i ++)
        {
            ans = 2 * temp;
            temp = ans;
        }
        return ans;
    }
};