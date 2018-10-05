//
// Created by DayWong on 04/10/2018.
//

/*
 * 题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 */
/*
 * 思想，用左上和右下的坐标定位出一次要旋转打印的数据，一次旋转打印结束后，往对角分别前进和后退一个单位。
    提交代码时，主要的问题出在没有控制好后两个for循环，需要加入条件判断，防止出现单行或者单列的情况。
 */
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector <int> ans;
        if(row == 0 || col == 0) return ans;
        int left = 0, top = 0, right = col - 1, bottom  = row - 1;  //定位四个角的相应位置。
        while(left <= right && top <= bottom)
        {
            //if(left != right)
            for(int i = left; i <= right; i ++) ans.push_back(matrix[top][i]);
            //if(top != bottom)
            for(int i = top + 1; i <= bottom; i ++) ans.push_back(matrix[i][right]);
            if(bottom != top)    //如果出现单行就不执行
                for(int i = right - 1; i >= left; i --) ans.push_back(matrix[bottom][i]);
            if(left != right)    //如果出现单列就不执行
                for(int i = bottom - 1; i > top; i --) ans.push_back(matrix[i][left]);
            left ++, right --, top ++, bottom --;
        }
        return ans;
    }
};