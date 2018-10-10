//
// Created by DayWong on 10/10/2018.
//
/*
 * 题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
 */

/*
 * 思路：如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。
在遍历数组时保存两个值：一是数组中一个数字，一是次数。遍历下一个数字时，
 若它与之前保存的数字相同，则次数加1，否则次数减1；若次数为0，则保存下一个数字，并将次数置为1。
 遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。
 */
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int temp = numbers[0];
        int flag = 1;
        int length = numbers.size();
        for(int i = 1; i < length; i ++)   //如果这个数存在的话，那么就是temp
        {
            if(numbers[i] == temp)
            {
                flag ++;
            }
            else
            {
                flag --;
                if(flag == 0)
                {
                    temp = numbers[i];
                    flag = 1;
                }
            }
        }

        int times = 0;
        for(int i = 0; i < length; i ++)      //如果这个数不存在也会有temp，因此需要验证temp是否满足条件
        {
            if(numbers[i] == temp) times ++;
        }
        return times > length/2 ? temp: 0;
    }
};