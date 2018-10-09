//
// Created by DayWong on 09/10/2018.
//
/*
 * 题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
 则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
 */

class Solution {
public:
    vector<string> Permutation(string str) {
        vector <string> ans;
        PermutationHelp(str, 0, ans);
        return ans;
    }
    void PermutationHelp(string str, int k, vector<string> &ans)
    {
        int length = str.size();
        if(k == length - 1)
            ans.push_back(str);
        unordered_set <char> us;           //记录出现过的字符
        sort(str.begin() + k, str.end());  //按照字典序排序
        for(int i = k; i < length; i ++)
        {
            if(us.find(str[i]) == us.end()) //us中不存在，返回结束迭代器us.end(),只交换没有出现过的字符
            {
                us.insert(str[i]);
                swap(str[i], str[k]);      //函数库调用
                PermutationHelp(str, k + 1, ans);
                swap(str[i], str[k]);
            }
        }
    }
};