 stack<int> s;
    stack<int> m;
 
MinStack::MinStack() {
    while(s.size())
    s.pop();
    while(m.size())
    m.pop();
}
 
void MinStack::push(int x) {
    s.push(x);
    
    if(m.size()==0) m.push(x);
    else
    {
        if(x<=m.top())
        m.push(x);
        else
        m.push(m.top());
    }
    
}
 
void MinStack::pop() {
    if(s.size())
    {
        s.pop();
        m.pop();
    }
}
 
int MinStack::top() {
    if(s.size())
    return s.top();
    else
    return -1;
}
 
int MinStack::getMin() {
    if(m.size())
    return m.top();
    else
    return -1;
}
 
