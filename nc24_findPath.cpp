//
// Created by DayWong on 06/10/2018.
//
/*
 * 题目描述
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
 (注意: 在返回值的list中，数组长度大的数组靠前)
 */
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector <vector <int>> ans;       //每一个节点都是一个路径向量
    vector <int> path;               //每一个工作路径
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root) dfsFind(root, expectNumber);
        return ans;
    }
    void dfsFind(TreeNode* root, int expectNumber)     //需要递归的话则引入一个新的函数
    {
        if(!root) return;
        path.push_back(root -> val); //记录一次路径
        if((!root -> left && !root -> right) && root -> val == expectNumber)
            ans.push_back(path);     //如果是树节点，并且节点之和等于expectNumber，那么将路径放入ans的一个节点
        else
        {
            dfsFind(root -> left, expectNumber - root -> val);
            dfsFind(root -> right, expectNumber - root -> val);
        }
        path.pop_back();             //当前节点遍历过后，不管有没有成功，弹出该节点，尝试下一个节点。
    }
};