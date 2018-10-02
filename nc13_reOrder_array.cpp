//
// Created by DayWong on 02/10/2018.
//
/*
 * 题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
 所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变
 */

/* 解题思路
 * 1.要想保证原有次序，则只能顺次移动或相邻交换。
 * 2.i从左向右遍历，找到第一个偶数。
 * 3.j从i+1开始向后找，直到找到第一个奇数。
 * 4.将[i,...,j-1]的元素整体后移一位，最后将找到的奇数放入i位置，然后i++。
 */

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int length = array.size();
        int temp;                                        //用来记录需要移动的数据
        for(int i = 0; i < length; i ++)
        {
            for(int j = i + 1; j < length; j ++)
            {
                if(!(array[i] & 1) && (array[j] & 1))    //i是第一个偶数（只需要记录第一个偶数）
                {                                        //j是第一个奇数
                    temp = array[j];
                    for(int k = j - 1; k >= i; k --)     //将第一个奇数存起来，将从i到j-1的数据往后挪动一位
                    {                                    //将存起来的奇数放到i位置上
                        array[k + 1] = array[k];
                    }
                    array[i] = temp;
                }
            }
        }
    }
};