// https://leetcode.com/problems/merge-k-sorted-lists/


/*
 *
 * TIME LIMIT EXCEEDED
 * 
 * /

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void insert(ListNode*& head, int val)
    {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
    }
    
    void push_back(ListNode*& head, int val)
    {
        if (head == nullptr)
        {
            insert(head, val);
            return;
        }
        ListNode* ptr = head;
        while (ptr->next != nullptr)
            ptr = ptr->next;
    
        ListNode* node = new ListNode(val);
        ptr->next = node;
    }
    
    ListNode* mergeSortedList(ListNode* one, ListNode* two)
    {
        ListNode* newList = nullptr;

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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* node = nullptr;
        int n = lists.size();

        for (int i = 0; i < n; i++)
            node = mergeSortedList(node, lists[i]);

        return node;
    }
};


/*
 *
 * METHOD 2
 * 
 * /

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        int size = lists.size();
        
        ListNode* result = nullptr;
        if (size == 0)
            return result;
        
        for (int i = 0 ; i < size; i++)
        {
            ListNode* temp = lists[i];
            while (temp)
            {
                v.push_back(temp->val);
                temp = temp->next;
            }
        }
        
        if (v.size() == 0)
            return result;
        
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        
        for (int i = 0; i < v.size(); i++)
        {
            ListNode* node = new ListNode(v[i]);
            node->next = result;
            result = node;
        }

        return result;
    }
};