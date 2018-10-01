//
// Created by DayWong on 30/09/2018.
//

//该算法中始终保持一个栈为空，然后另一个栈保证随时可以出栈，但是如果有两个元素相继进栈的话就会出现问题，
//因为第一次进栈以后栈里元素的顺序已经反转，再次进栈的话就再次反转了，结果就错了，这是一个错误的程序

class Solution
{
public:
    void push(int node) {
        int length1 = stack1.size();
        int length2 = stack2.size();
        if(length1 == 0)
        {
            stack1.push(node);
            while(!stack2.empty())//确保stack2没有空
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        else
        {
            stack2.push(node);
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }

    int pop() {
        int length1 = stack1.size();
        int val = -1;
        if(length1 == 0)
        {
            val = stack2.top();
            stack2.pop();
        }
        else
        {
            val = stack1.top();
            stack1.pop();
        }
        return val;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};