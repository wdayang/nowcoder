//
// Created by DayWong on 02/10/2018.
//
/*
题目描述
        输入一个链表，反转链表后，输出新链表的表头。
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
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead) return NULL;
        //head为当前节点，如果当前节点为空的话，那就什么也不做，直接返回null；
        ListNode* pre = NULL;
        ListNode* proceed = NULL;
        //当前节点是head，pre为当前节点的前一节点，proceed为当前节点的下一节点
        //需要pre和proceed的目的是让当前节点从pre->head->proceed1->proceed2变成pre<-head proceed1->proceed2
        //即pre让节点可以反转所指方向，但反转之后如果不用proceed节点保存proceed1节点的话，此单链表就此断开了
        //所以需要用到pre和proceed两个节点
        //1->2->3->4->5
        //1<-2<-3 4->5
        while(pHead)
        {
            //做循环，如果当前节点不为空的话，始终执行此循环，此循环的目的就是让当前节点从指向proceed到指向pre
            //如此就可以做到反转链表的效果
            //先用proceed保存head的下一个节点的信息，保证单链表不会因为失去head节点的原proceed节点而就此断裂
            proceed = pHead -> next;
            //保存完proceed，就可以让head从指向proceed变成指向pre了，代码如下
            pHead -> next = pre;
            //head指向pre后，就继续依次反转下一个节点
            //让pre，head，proceed依次向后移动一个节点，继续下一次的指针反转
            pre = pHead;
            pHead = proceed;
        }
        //如果head为null的时候，pre就为最后一个节点了，但是链表已经反转完毕，pre就是反转后链表的第一个节点
        //直接输出pre就是我们想要得到的反转后的链表
        return pre;
    }
};