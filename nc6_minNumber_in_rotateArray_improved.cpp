//
// Created by DayWong on 01/10/2018.
//

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int length = rotateArray.size();
        int min = 99999999;
        if(length == 0) return 0;
        for(int i = 0; i < length; i ++)
        {
            if(rotateArray[i] > rotateArray[i + 1])
            {
                return rotateArray[i + 1];      //如果发现后面的元素比前面的小，那么她肯定是最小的元素
            }
        }
        return rotateArray[0];
    }
};