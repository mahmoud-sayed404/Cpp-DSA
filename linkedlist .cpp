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
class SLL
{
private:
    Node *head, *tail;
    int size;

public:
    SLL()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    bool isEmpty()
    {

        return head == nullptr;
    }

    int Size()
    {
        return size;
    }
    void insertAtBegin(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {

            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {

            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void insertAtMiddle(int pos, int val)
    {
        if (pos < 0 || pos > size)
        {
            cout << "Invalid Index...!\n";
            return;
        }
        if (pos == 0)
        {
            insertAtBegin(val);
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; i++)
        {

            temp = temp->next;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == nullptr)
            tail = newNode;
        size++;
    }
    int deleteAtBegin()
    {
        if (isEmpty())
        {
            cout << "LinkedList is Empty...!\n";
            return -1;
        }
        int val = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr)
            tail = nullptr;
        size--;
        return val;
    }
    int deleteAtEnd()
    {

        if (isEmpty())
        {
            cout << "LinkedList is Empty...!\n";
            return -1;
        }
        int val = tail->data;

        if (head == tail)
        {

            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {

                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        size--;
        return val;
    }
    bool deleteValue(int val)
    {
        if (isEmpty())
        {
            cout << "LinkedList is Empty...!\n";
            return false;
        }
        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
            if (head == nullptr)
                tail = nullptr;
            return true;
        }
        Node *prev = head;
        Node *curr = head->next;
        while (curr != nullptr && curr->data != val)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr)
        {

            return false;
        }
        prev->next = curr->next;
        if (curr == tail)
            tail = prev;
        delete curr;
        size--;
        return true;
    }
    bool search(int val)
    {
        Node *ptr = head;
        while (ptr != nullptr)
        {
            if (ptr->data == val)
            {
                cout << "Found this element = " << val << "\n";
                return true;
            }
            ptr = ptr->next;
        }
        cout << "Not Found...!\n";
        return false;
    }

    void Display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main()
{
    SLL l1;
    l1.insertAtBegin(5);
    l1.insertAtBegin(6);
    l1.insertAtBegin(7);
    l1.insertAtBegin(8);
    l1.Display();

    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.insertAtEnd(4);
    l1.insertAtEnd(5);
    l1.Display();

    cout << "Deleted value at end: " << l1.deleteAtEnd() << "\n";
    l1.Display();

    if (l1.deleteValue(100))
        cout << "Deleted successfully\n";
    else
        cout << "Value not found\n";

    l1.Display();

    l1.search(3);
    l1.search(100);

    return 0;
}