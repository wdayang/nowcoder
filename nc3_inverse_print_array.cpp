//
// Created by DayWong on 30/09/2018.
//

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector <int> result;
        stack <int> temp;
        ListNode* p = head;
        while(p != NULL)
        {
            temp.push(p -> val);    //进栈
            p = p -> next;
        }
        int length = temp.size();
        for(int i = 0; i < length; i++)
        {
            result.push_back(temp.top());  //将栈的最上方元素放置到向量的首位
            temp.pop();    //出栈
        }
        return result;
    }
};