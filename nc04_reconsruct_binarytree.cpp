//
// Created by DayWong on 30/09/2018.
//

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int prelength = pre.size();
        if(prelength == 0) return NULL;           //如果没有节点了，就返回NULL
        vector <int> left_pre, left_vin, right_pre, right_vin;

        //找到前序遍历的第一个元素，就是根
        TreeNode* root = new TreeNode(pre[0]);    //注意TreeNode的初始化方法
        int position = -1;                        //记录根节点在中序遍历中的位置
        for(int i = 0; i < prelength; i ++)
        {
            if(vin[i] == pre[0])
            {
                position = i;
                break;
            }
        }

        //将相关节点录入左子树
        for(int i = 0; i < position; i ++)
        {
            left_pre.push_back(pre[i + 1]);       //注意前序第一个为根节点，不能加进去
            left_vin.push_back(vin[i]);
        }

        //将相关节点录入右子树
        for(int i = position + 1; i < prelength; i ++)
        {
            right_pre.push_back(pre[i]);
            right_vin.push_back(vin[i]);
        }

        //左右子树进行递归
        root -> left = reConstructBinaryTree(left_pre, left_vin);
        root -> right = reConstructBinaryTree(right_pre, right_vin);

        return root;
    }
};