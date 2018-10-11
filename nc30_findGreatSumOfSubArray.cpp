//
// Created by DayWong on 11/10/2018.
//
/*
 * 题目描述
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,
 他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,
当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,
 并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},
 连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，
 你会不会被他忽悠住？(子向量的长度至少是1)
 */
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int cursum = array[0];       //初始值不能设置为0，防止有负数
        int maxsum = array[0];
        int len = array.size();
        for(int i = 1; i < len; i ++)//第一个元素已经初始化了，因此i从1开始
        {
            cursum += array[i];
            if(array[i] > cursum)
                cursum = array[i];   //如果前面计算的结果为负数，那么取消前面的结果
            //不用担心更前一位元素是正数，因为如果是正数的话前一步就已经取消了。
            if(cursum > maxsum)      //记录最大的和
                maxsum = cursum;
        }
        return maxsum;
    }
};