//
// Created by DayWong on 07/10/2018.
//

/*
 * 题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
 返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 */
/*思路：
 *  1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
    2、遍历链表，A1->random = A->random->next;
    3、将链表拆分成原链表和复制后的链表
 */
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        NodeClone(pHead);
        SetRandom(pHead);
        return Seperate(pHead);
        //return res;
    }
    void NodeClone(RandomListNode* Head)             // 复制节点
    {
        RandomListNode* pHead = Head;                //必须新建一个遍历变量，Head不能变
        while(pHead)
        {
            RandomListNode* pClone = new RandomListNode(pHead -> label);
            pClone -> next = pHead -> next;
            pHead -> next = pClone;
            pHead = pClone -> next;                  //此处不是pHead，需要跳过pClone
        }
    }
    void SetRandom(RandomListNode* Head)             //复制random指针
    {
        RandomListNode* pHead = Head;
        while(pHead)
        {
            RandomListNode* pClone = pHead -> next;  //必须放到while循环里，每一个pHead都需要一个新的pClone
            if(pHead -> random)
                pClone -> random = pHead -> random -> next;
            pHead = pClone -> next;                  //此处是pClone -> next
        }
    }
    RandomListNode* Seperate(RandomListNode* Head)   //拆分链表
    {
        RandomListNode* pHead = Head;
        RandomListNode* res = pHead -> next;
        //RandomListNode* pClone = res;
        while(pHead)
        {
            RandomListNode* pClone = pHead -> next;
            pHead -> next = pClone -> next;
            pHead = pHead -> next;                   //此处遍历用pHead -> next，因为pClone已经移除
            if(pHead)
            {
                pClone -> next = pHead -> next;
            }
        }
        return res;
    }
};