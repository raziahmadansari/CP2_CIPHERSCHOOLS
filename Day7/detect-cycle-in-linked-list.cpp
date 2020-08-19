#include <iostream>
#include <windows.h>

using namespace std;

class Node
{
    public:
    int val;
    Node* next;

    Node(int val = 0)
    {
        this->val = val;
        this->next = nullptr;
    }
};

void insert(Node*& head, int val)
{
    Node* node = new Node(val);
    node->next = head;
    head = node;
}

bool cycle(Node* slow)
{
    if (slow == nullptr || slow->next == nullptr)
        return false;
    
    Node* fast = slow->next;
    while (fast)
    {
        if (slow == fast)
            return true;
        if (fast->next == nullptr) // reached the end of linked list
            break;
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}

void create_cycle(Node*& head, int from, int to)
{
    Node* ptr_from = head;
    Node* ptr_to = head;

    from -= 1;
    while (from)
    {
        ptr_from = ptr_from->next;
        from--;
    }
    to -= 1;
    while (to)
    {
        ptr_to = ptr_to->next;
        to--;
    }
    ptr_to->next = ptr_from; // joined the two nodes
}

void print(Node* head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
        Sleep(1000);
    }
}

int main()
{
    Node* head = nullptr;
    for (int i = 5; i >= 1; i--)
        insert(head, i * 10);
    
    print(head);

    create_cycle(head, 1, 4);
    if (cycle(head))
        cout << "\ncycle present" << endl;
    else
        cout << "\ncycle not present" << endl;
    
    print(head);

    return 0;
}