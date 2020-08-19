#include <iostream>

using namespace std;

class Node
{
    public:
    int val;
    Node* next;

    Node (int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

int length(Node* head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }

    return len;
}

void push_beg(Node*& head, int val)
{
    Node* node = new Node(val);
    node->next = head;
    head = node;
}

void push_end(Node*& head, int val)
{
    if (head == NULL)
    {
        push_beg(head, val);
        return;
    }
    Node* ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    Node* node = new Node(val);
    ptr->next = node;
}

void push_mid(Node*& head, int val, int pos)
{
    if (head == NULL)
    {
        cout << "List is empty, (use push_beg() or push_end())\n";
        return;
    }
    if (pos == 1)
    {
        push_beg(head, val);
        return;
    }
    int len = length(head);
    if (len < pos)
    {
        cout << "Invalid position, length of list = " << len << endl;
        return;
    }

    Node* ptr = head;
    pos -= 2;   // travel to node just before that position
    while (pos)
    {
        ptr = ptr->next;
        pos--;
    }
    Node* node = new Node(val);
    node->next = ptr->next;
    ptr->next = node;
}

void pop_front(Node*& head)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    Node* ptr = head;
    head = head->next;
    delete ptr;
}

void pop_back(Node*& head)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    if (head->next == NULL) // if only one node is present
    {
        pop_front(head);
        return;
    }

    Node* ptr = head;
    while (ptr->next->next != NULL)
        ptr = ptr->next;
    Node* temp = ptr->next;
    ptr->next = NULL;
    delete temp;
}

void pop_mid(Node*& head, int pos)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    if (head->next == NULL && pos == 1) // if only one node is present
    {
        pop_front(head);
        return;
    }

    int len = length(head);
    if (pos > len)
    {
        cout << "Invalid Location" << endl;
        return;
    }
    if (pos == len) // delete last element
    {
        pop_back(head);
        return;
    }
    pos -= 2;
    Node* ptr = head;
    while (pos)
    {
        ptr = ptr->next;
        pos--;
    }
    Node* node_to_delete = ptr->next;
    ptr->next = node_to_delete->next;
    delete node_to_delete;
}

void print(Node* head)
{
    cout << "Printing the linked list\n";
    
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}



int main()
{
    Node* head1 = NULL;
    push_beg(head1, 12);
    push_beg(head1, 15);

    push_end(head1, 25);
    push_mid(head1, 100, 2);


    // delete from front
    print(head1);
    cout << endl;
/*    pop_front(head1);
    print(head1);
    cout << endl;

    // delete from back
    pop_back(head1);
    print(head1);
    cout << endl;
*/
    // delete from mid
    pop_mid(head1, 3);
    print(head1);
    cout << endl;
    
    cout << endl << length(head1);

    return 0;
}