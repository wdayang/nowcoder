//
// Created by DayWong on 04/10/2018.
//
/*
 * 题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
 */
/*
 * 进栈：进stack1，如果stack2为空或者比stack2.top()小，那么入栈stack2
 * 出栈：出stack1，如果stack1.top() == stack2.top() ，即stack2.top()是最小元素，那么stack2出栈
 */
class Solution {
public:
    stack <int> stack1, stack2; //stack1主栈，stack2辅助栈，最小元素在上面
    void push(int value) {
        stack1.push(value);
        if(stack2.empty())
            stack2.push(value);
        else if(value < stack2.top())
            stack2.push(value);
        return;
    }
    void pop() {
        if(stack1.top() == stack2.top())   //必须先要比较再stack1出栈
            stack2.pop();
        stack1.pop();
        return;
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return stack2.top();
    }
};