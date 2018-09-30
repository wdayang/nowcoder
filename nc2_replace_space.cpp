//
// Created by dayang_wang on 30/09/2018.
//

class Solution {
public:
    void replaceSpace(char *str,int length) {
        int count = 0;
        for(int i = 0; i < length; i++)    //no need to use str.size(), there is length
        {
            if(str[i] == ' ')
            {
                count ++;     //number of a space
            }
        }
        for(int i = length - 1; i >= 0; i--)      //from back to forth will require less movement than for forth to back
        {
            if(str[i] != ' ')
            {
                str[i + 2 * count] = str[i];
            }
            else
            {
                str[i + 2 * count] = '0';
                str[i + 2 * count -1] = '2';
                str[i + 2 * count - 2] = '%';
                count --;
            }
        }
    }
};