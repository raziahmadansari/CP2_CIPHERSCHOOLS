#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node* next;

    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

struct LinkedList
{
    Node* head;
    LinkedList()
    {
        this->head = NULL;
    }

    // adding node to linked list
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;

        delete temp;
    }

    void print()
    {
        Node* ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->val;
            if (ptr->next)
                cout << " -> ";
            ptr = ptr->next;
        }
        cout << endl;
        delete ptr;
    }

    void reverse()
    {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;  // reversing
            prev = curr;
            curr = next;
        }
        head = prev;

        delete curr;
        delete prev;
        delete next;
    }
};

int main()
{
    LinkedList ll;
    for (int i = 1; i <= 5; i++)
        ll.push(i * 10);
    
    cout << "Original linked list : ";
    ll.print();

    cout << "After reversing : ";
    ll.reverse();
    ll.print();

    return 0;
}