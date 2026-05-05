//Implement Stack using Linked List in C++

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *topNode;
    int count = 0;

public:
    Stack()
    {
        topNode = nullptr;
        count = 0;
    }
    bool isEmpty()
    {

        return topNode == nullptr;
    }
    int Size()
    {

        return count;
    }
    void Push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }
    void Pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty...!\n";
            return;
        }
        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
    }
    int Peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty...!\n";
            return -1;
        }
        return topNode->data;
    }
    void display()
    {
        Node *temp = topNode;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    ~Stack()
    {
        while (!isEmpty())
        {
            Pop();
        }
    }
};

int main()
{

    Stack s1;
    s1.Push(50);
    s1.Push(40);
    s1.Push(40);
    s1.Push(10);
    s1.Push(20);

    s1.display();
    s1.Pop();
    s1.Pop();
    s1.Pop();

    s1.display();
    cout << s1.Peek() << "\n";

    return 0;
}
