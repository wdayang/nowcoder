//
// Created by DayWong on 10/10/2018.
//
/*
 * 题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，
 则最小的4个数字是1,2,3,4,。
 */
/*
 * 先对数组进行排序，然后取前k个，但是时间复杂度为nlogn
 */
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        //int length = input.size();
        vector <int> ans;
        if(input.empty() || k > input.size()) return ans;
        sort(input.begin(), input.end());
        for(int i = 0; i < k; i ++)
        {
            ans.push_back(input[i]);
        }
        return ans;
    }
};