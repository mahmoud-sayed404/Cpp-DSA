#include <iostream>
using namespace std;
class Stack
{
private:
    int top, Capacity;
    int *arr;

    void Resize()
    {
        Capacity *= 2;
        int *temp = new int[Capacity];

        for (int i = 0; i <= top; i++)
        {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
    }

public:
    Stack(int maxSize)
    {
        Capacity = maxSize;
        top = -1;
        arr = new int[Capacity];
    }

    bool isFull()
    {
        return top == Capacity - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    int Size()
    {
        return top + 1;
    }

    void Push(int val)
    {
        if (isFull())
        {
            Resize();
        }
        arr[++top] = val;
    }

    int Pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty..!\n";
            return -1;
        }
        return arr[top--];
    }

    int Peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty..!\n";
            return -1;
        }
        return arr[top];
    }

    void Clear()
    {
        top = -1;
    }

    void Display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return;
        }

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack s(3);

    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Push(40);

    s.Display();

    cout << "Pop: " << s.Pop() << "\n";
    cout << "Top: " << s.Peek() << "\n";

    s.Display();

    return 0;
}
