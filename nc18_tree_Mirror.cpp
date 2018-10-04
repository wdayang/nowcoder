//
// Created by DayWong on 04/10/2018.
//
/*
 * 题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
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
    void Mirror(TreeNode *pRoot) {
        if(!pRoot) return;
        if(!pRoot -> left && !pRoot -> right) return; //如果左右子树为空，递归结束
        TreeNode* temp = pRoot -> left;               //交换左右子树
        pRoot -> left = pRoot -> right;
        pRoot -> right = temp;

        if(pRoot -> left) Mirror(pRoot -> left);      //左右子树镜像
        if(pRoot -> right) Mirror(pRoot -> right);
    }
};