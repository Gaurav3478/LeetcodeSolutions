class MyStack {
private:
    queue<int> q, q2;
public:
    MyStack() {
    }
    void push(int x) {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++) {
            q2.push(q.front());
            q.pop();
        }
        for(int i=0; i<s; i++) {
            q.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int n = q.front();
        q.pop();
        return n;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};