//
// Created by DayWong on 03/10/2018.
//
/*
 * 题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 */
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge2(ListNode* pHead1, ListNode* pHead2)   //普通方法
    {
        ListNode* newHead; //记录新表头
        ListNode* temp; //作为新表头的移动指针
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        //取新的头指针
        if(pHead1 -> val <= pHead2 -> val)
        {
            newHead = pHead1;
            pHead1 = pHead1 -> next;
        }
        else
        {
            newHead = pHead2;
            pHead2 = pHead2 -> next;
        }
        temp = newHead;
        //开始合并，小的添加到新表，并且指针后移一位，新表指针也后移一位
        while(pHead1 && pHead2)
        {
            if(pHead1 -> val <= pHead2 -> val)
            {
                temp -> next = pHead1;        //添加到新表
                pHead1 = pHead1 -> next;      //旧表后移一位
                temp = temp -> next;          //新表指针后移一位
            }
            else
            {
                temp -> next = pHead2;
                pHead2 = pHead2 -> next;
                temp = temp -> next;
            }
        }
        if(!pHead1) temp -> next = pHead2;
        else temp -> next = pHead1;
        return newHead;
    }
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)     //递归方法
    {
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        else{
            while(pHead1 && pHead2)
            {
                if(pHead1 -> val <= pHead2 -> val)
                {
                    pHead1 -> next = Merge(pHead1 -> next, pHead2);
                    return pHead1;
                }
                else
                {
                    pHead2 -> next = Merge(pHead1, pHead2 -> next);
                    return pHead2;
                }
            }
            return pHead1;     //最后一行没有用，但是不加上编译无法通过，编译器觉得可能没有返回值
        }
    }
};
