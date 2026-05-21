#include <iostream>
using namespace std;
class Queue
{
private:
    int Front, Capacity, Size, Rear;
    int *arr;

public:
    Queue(int max_size)
    {
        Capacity = max_size;
        arr = new int[Capacity];
        Size = Front = 0;
        Rear = -1;
    }
    bool IsEmpty()
    {

        return Size == 0;
    }
    bool IsFully()
    {

        return Size == Capacity;
    }
    int length()
    {
        return Size;
    }

    void Clear()
    {
        Size = Front = 0;
        Rear = -1;
    }
    void EnQueue(int val)
    {
        if (IsFully())
        {
            cout << "Queue Is Fully\n";
            return;
        }
        Rear = (Rear + 1) % Capacity;
        arr[Rear] = val;
        Size++;
    }
    int Dequeue()
    {
        if (IsEmpty())
        {
            cout << "Queue Is Empty\n";
            return -1;
        }
        int Deval = arr[Front];
        Front = (Front + 1) % Capacity;
        Size--;
        return Deval;
    }
    int Top()
    {
        if (IsEmpty())
        {
            cout << "Queue Is Empty\n";
            return -1;
        }
        return arr[Front];
    }

    void display()
    {
        int i = Front;
        for (int count = 0; count < Size; count++)
        {
            cout << arr[i] << " ";
            i = (i + 1) % Capacity;
        }
        cout << "\n";
    }
    ~Queue()
    {
        delete[] arr;
    }
};
int main()
{
    Queue q1(5);
    q1.EnQueue(1);
    q1.EnQueue(2);
    q1.EnQueue(3);
    q1.EnQueue(4);
    q1.EnQueue(5);
    q1.display();
    q1.Dequeue();
    q1.display();
    cout << q1.Top() << "\n";

    return 0;
}