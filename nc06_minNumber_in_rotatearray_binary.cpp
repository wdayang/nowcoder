//
// Created by DayWong on 01/10/2018.
//


/*
 * 注意这里有个坑：如果待查询的范围最后只剩两个数，那么mid 一定会指向下标靠前的数字
比如 array = [4,6]
array[low] = 4 ;array[mid] = 4 ; array[high] = 6 ;
如果high = mid - 1，就会产生错误， 因此high = mid
但情形(1)中low = mid + 1就不会错误
 */
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int start = 0;
        int end = rotateArray.size() - 1;
        int mid;
        while(start < end)
        {
            mid = start + (end - start) / 2;
            if(rotateArray[mid] > rotateArray[end]) start = mid + 1;    //这里是mid + 1，end总是比start大，所以加一没有关系
            else if(rotateArray[mid] < rotateArray[end]) end = mid;     //这里是mid，因为如果是mid - 1最后只剩下两个数会报错
            else end -= 1;
        }
        return rotateArray[start];
    }
};