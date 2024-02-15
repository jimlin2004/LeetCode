#include <stack>
using namespace std;

class MinStack 
{
private:
    stack<int> dataStack;
    stack<int> minStack;
public:
    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        this->dataStack.push(val);
        if (this->minStack.empty())
            this->minStack.push(val);
        else
        {
            int topMin = this->minStack.top();
            if (topMin > val)
            {
                this->minStack.push(val);
            }
            else
                this->minStack.push(topMin);
        }
    }
    
    void pop() 
    {
        this->dataStack.pop();
        this->minStack.pop();
    }
    
    int top() 
    {
        return this->dataStack.top();
    }
    
    int getMin() 
    {
        return this->minStack.top();
    }
};