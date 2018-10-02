//
// Created by DayWong on 02/10/2018.
//
/*
 * 输入一个链表，输出该链表中倒数第k个结点。
 */

/*
 * 最佳代码：Java代码，通过校验。代码思路如下：两个指针，先让第一个指针和第二个指针都指向头结点，
 * 然后再让第一个指正走(k-1)步，到达第k个节点。然后两个指针同时往后移动，当第一个结点到达末尾的时候，
 * 第二个结点所在位置就是倒数第k个节点了。。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        auto p1 = pListHead;
        auto p2 = pListHead;
        for(int i = 0; i < k; i ++)
        {
            if(p2)
                p2 = p2 -> next;
            else return nullptr;    //如果k的输入比链表本身长的话就返回nullptr
        }
        while(p2)
        {
            p2 = p2 -> next;
            p1 = p1 -> next;
        }
        return p1;
    }
};

/*
vector <double> temp;
        ListNode* p = pListHead;
        while(p -> next != NULL)
        {
            temp.push_back(p -> val);
        }
        int length = temp.size();
        for(int i = 0; i < length - k + 1; i ++)
        {
            p = p -> next;
        }
        return p;
*/