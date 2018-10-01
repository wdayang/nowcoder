//
// Created by DayWong on 01/10/2018.
//

/*
 * 题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
 */

//跟上一题斐波那契那数列类似
class Solution {
public:
    int jumpFloor(int number) {
        int res;
        int forward1 = 1; int forward2 = 2;
        if(number == 1 || number == 2) return number;
        for(int i = 3; i < number + 1; i ++)
        {
            res = forward1 + forward2;
            forward1 = forward2;
            forward2 = res;
        }
        return res;
    }
};