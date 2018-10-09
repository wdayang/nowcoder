//
// Created by DayWong on 09/10/2018.
//
/*
题目描述:
        输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
        要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* root = pRootOfTree;
        if(!root) return NULL;
        if(!root -> left && !root -> right) return root;
        TreeNode* left = Convert(root -> left); //返回左边链表第一个节点，递归的时候不需要判断，因为进入递归后会进行判断
        TreeNode* p = left;

        while(p && p -> right)                  //找到左链表最后一个节点，p以及p -> right不为空
            p = p -> right;
        if(left)
        {
            p -> right = root;                  //将左链表最后一个节点与root相互连接起来
            root -> left = p;
        }
        TreeNode* right = Convert(root -> right);//找到右子树的第一个节点
        if(right)
        {
            right -> left = root;
            root -> right = right;              //将右链表第一个节点链接到root
        }
        return left != NULL? left: root;
    }
};