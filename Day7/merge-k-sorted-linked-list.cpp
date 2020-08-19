#include <iostream>
#include <vector>

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

void push_back(Node*& head, int val)
{
    if (head == nullptr)
    {
        insert(head, val);
        return;
    }
    Node* ptr = head;
    while (ptr->next != nullptr)
        ptr = ptr->next;
    
    Node* node = new Node(val);
    ptr->next = node;
}

Node* mergeSortedList(Node* one, Node* two)
{
    Node* newList = nullptr;

    while (one && two)
    {
        if (one->val < two->val)
        {
            push_back(newList, one->val);
            one = one->next;
            continue;
        }
        if (two->val < one->val)
        {
            push_back(newList, two->val);
            two = two->next;
            continue;
        }
        // else both values are equal
        push_back(newList, one->val);
        push_back(newList, two->val);
        one = one->next;
        two = two->next;
    }

    while (one) // if list one still contains some element then add them directly
    {
        push_back(newList, one->val);
        one = one->next;
    }

    while (two)
    {
        push_back(newList, two->val);
        two = two->next;
    }

    return newList;
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
    }
    cout << endl;
    return;
}

Node* mergeKsortedList(vector<Node*>& head)
{
    Node* node = nullptr;
    int n = head.size();

    for (int i = 0; i < n; i++)
        node = mergeSortedList(node, head[i]);

    return node;
}

int main()
{
    Node* head1 = nullptr;
    insert(head1, 50); insert(head1, 25), insert(head1, 10);

    Node* head2 = nullptr;
    insert(head2, 52); insert(head2, 48); insert(head2, 27); insert(head2, 14); insert(head2, 10);

    Node* head3 = nullptr;
    insert(head3, 100); insert(head3, 35), insert(head3, 15);

    vector<Node*> mergeKsorted;
    mergeKsorted.push_back(head1);
    mergeKsorted.push_back(head2);
    mergeKsorted.push_back(head3);

    print(head1);
    print(head2);
    print(head3);
    cout << "Linked lists merged\n";
    Node* newList = mergeKsortedList(mergeKsorted);
    print(newList);

    /*print(head1);
    print(head2);

    Node* newList = mergeSortedList(head1, head2);
    cout << "Merged\n";
    print(newList);*/

    return 0;
}