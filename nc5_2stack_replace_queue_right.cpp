//
// Created by DayWong on 30/09/2018.
//

class Solution
{
public:
    void push(int node) {                       //stack1负责进栈
        stack1.push(node);
    }

    int pop() {
        int val;
        if(stack2.empty())                      //当stack2为空时从stack1中逆序传送到stack2，然后从stack2出栈
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        val = stack2.top();                     //当stack2不为空时，直接从stack2出栈
        stack2.pop();
        return val;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};