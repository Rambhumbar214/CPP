/*. Create a class called LIST with two pure virtual function store() and retrieve(). To store a 
value call store and to retrieve call retrieves function. Derive two classes stack and queue 
from it and override store and retrieve.*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class LIST {
public:
    virtual void store(int value) = 0;
    virtual int retrieve() = 0;
    virtual ~LIST() {}
};

class STACK : public LIST {
private:
    stack<int> s;
public:
    void store(int value) override {
        s.push(value);
    }
    
    int retrieve() override {
        if (s.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int val = s.top();
        s.pop();
        return val;
    }
};

class QUEUE : public LIST {
private:
    queue<int> q;
public:
    void store(int value) override {
        q.push(value);
    }
    
    int retrieve() override {
        if (q.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int val = q.front();
        q.pop();
        return val;
    }
};

int main() {
    LIST* stackList = new STACK();
    LIST* queueList = new QUEUE();
    
    stackList->store(10);
    stackList->store(20);
    stackList->store(30);
    
    queueList->store(100);
    queueList->store(200);
    queueList->store(300);
    
    cout << "Stack retrieve: " << stackList->retrieve() << endl;
    cout << "Stack retrieve: " << stackList->retrieve() << endl;
    cout << "Queue retrieve: " << queueList->retrieve() << endl;
    cout << "Queue retrieve: " << queueList->retrieve() << endl;
    
    delete stackList;
    delete queueList;
    
    return 0;
}

