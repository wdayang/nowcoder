//
// Created by DayWong on 10/10/2018.
//
/*
 * 题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
 */
//思路，运用partition函数
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ans;
        int len = input.size();
        if(len == 0 || k > len || k <= 0) return ans;
        int begin = 0, end = len - 1;
        int index = Partition(input, begin, end);
        while(index != k - 1)    //直到index = k - 1的时候退出，这时候得到正确的index
        {
            if(index > k - 1)    //当index太大的时候，那么前k小的元素必然在index之前，此时对index前面的元素进行partition
            {
                end = index - 1;
                index = Partition(input, begin, end);
            }
            else                 //当index小与k - 1时，那么index的元素是要求的子集，对元素后面的元素进行partition
            {
                begin = index + 1;
                index = Partition(input, begin, end);
            }
        }
        for(int j = 0; j < k; j ++)
        {
            ans.push_back(input[j]);
        }
        return ans;
    }
    int Partition(vector<int> &input, int begin, int end)   //重点
    {
        int pivot = input[begin];    //以第一个元素为分割点
        int position = begin;        //记录比分割点小的元素的最大的位置
        for(int i = begin + 1; i < end + 1; i ++)
            if(input[i] < pivot)     //当元素比分割点小的时候，将其与position后面一个位置进行交换，同时position+1
                swap(input[i], input[++ position]);
        swap(input[position], input[begin]);  //最后将position的元素与分割点交换。
        return position;             //返回当前input[begin]的坐标position,左边的小，右边的大
    }
};