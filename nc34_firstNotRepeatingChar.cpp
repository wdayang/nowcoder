//
// Created by DayWong on 19/10/2018.
//
/*
 * 题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
 并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
 */
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> mp;     //使用map<char, int>，每一个字符作为key
        for(int i = 0; i < str.size(); i++)
        {
            mp[str[i]] ++;     //不需要初始化，当key不存在时map自动创建，值为0
        }
        for(int i = 0; i < str.size(); i ++)
        {
            if(mp[str[i]] == 1)//遍历找到出现一次的字符，虽然map会排序，但是是按照str字符顺序进行检索的，所以找到的是第一个出现一次的字符
                return i;
        }
        return -1;
    }
};