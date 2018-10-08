//
// Created by DayWong on 05/10/2018.
//
/*
 * 题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 */
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int length = sequence.size();
        if(!length) return false;
        return Judge(sequence, 0, length - 1);
    }
    bool Judge(vector<int> a, int l, int r)
    {
        if(l >= r) return true;            //此处必须用>=，不能用==不知道为什么
        int i = l;
        while(i < r && a[i] < a[r]) i ++;  //找到右子树第一个元素，而不是左子树的最后一个元素
        for(int j = i; j < r; j ++)        //所有的左子树必须比根小
            if(a[j] < a[r]) return false;
        return Judge(a, l, i - 1) && Judge(a, i, r - 1);
    }
};