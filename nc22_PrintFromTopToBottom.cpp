//
// Created by DayWong on 05/10/2018.
//
/*
 * 题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector <int> ans;
        queue <TreeNode*> que;  //队列存储的是一个个节点
        TreeNode* temp;         //用来获取当前节点
        if(!root) return ans;   //存储answer的向量
        que.push(root);
        while(!que.empty())
        {
            temp = que.front();  //获取队列第一个值
            que.pop();
            ans.push_back(temp -> val); //存到结果向量中
            if(temp -> left) que.push(temp -> left);   //将左右节点放到队列中
            if(temp -> right) que.push(temp -> right);
            //que.pop();
        }
        return ans;
    }
};