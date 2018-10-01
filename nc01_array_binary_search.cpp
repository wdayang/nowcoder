//
//dayang_wang 28/09/2018
//

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int length = array[0].size() - 1;// C++ use array.size(), not array.length, length is the same
        for(int i = 0; i < array.size(); i++)
        {
            int start = 0;
            int end = length;
            int mid;
            while(start <= end)
            {
                mid = (start + end) / 2;
                if(array[i][mid] < target)
                {
                    start = mid + 1;
                }
                else if(array[i][mid] > target)
                {
                    end = mid - 1;
                }
                else return true;
            }
        }
        return false;
    }
};