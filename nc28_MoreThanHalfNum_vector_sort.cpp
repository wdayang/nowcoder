//
// Created by DayWong on 10/10/2018.
//
/*
 * 题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，
 超过数组长度的一半，因此输出2。如果不存在则输出0。
 */
/*
 * 数组排序后，如果符合条件的数存在，则一定是数组中间那个数。
 * （比如：1，2，2，2，3；或2，2，2，3，4；或2，3，4，4，4等等）
 */
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());
        int length = numbers.size();
        int middle = length/2;
        int times = 0;
        for(int i = 0; i < length; i ++)
        {
            if(numbers[middle] == numbers[i])
                times ++;
        }
        return times > length/2 ? numbers[middle]: 0;
    }
};