//
// Created by DayWong on 04/10/2018.
//
/*
 * 题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
 */

/*
思路：参考剑指offer
1、首先设置标志位result = false，因为一旦匹配成功result就设为true，
剩下的代码不会执行，如果匹配不成功，默认返回false
2、递归思想，如果根节点相同则递归调用DoesTree1HaveTree2（），
如果根节点不相同，则判断tree1的左子树和tree2是否相同，
再判断右子树和tree2是否相同
3、注意null的条件，HasSubTree中，如果两棵树都不为空才进行判断，
DoesTree1HasTree2中，如果Tree2为空，则说明第二棵树遍历完了，即匹配成功，
tree1为空有两种情况（1）如果tree1为空&&tree2不为空说明不匹配，
（2）如果tree1为空，tree2为空，说明匹配。
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        //if(!pRoot2) return false;
        bool result = false;
        if(pRoot1 && pRoot2)
        {
            if(pRoot1 -> val == pRoot2 -> val)
                result = DoesTree1HasTree2(pRoot1, pRoot2);
            if(!result) result = HasSubtree(pRoot1 -> left, pRoot2);    //如果判断完之后结果不为真，那么再从左右子树来判断
            if(!result) result = HasSubtree(pRoot1 -> right, pRoot2);
        }
        return result;
    }
    bool static DoesTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot2) return true;                                        //如果pRoot2空了，那么真
        if(!pRoot1) return false;                                       //如果pRoot1空了，此时pRoot2不空，那么返回假
        if(pRoot1 -> val != pRoot2 -> val) return false;   //如果中途发现两个节点值不一样，则返回false
        else return DoesTree1HasTree2(pRoot1 -> left, pRoot2 -> left) && DoesTree1HasTree2(pRoot1 -> right, pRoot2 -> right);
    }
};