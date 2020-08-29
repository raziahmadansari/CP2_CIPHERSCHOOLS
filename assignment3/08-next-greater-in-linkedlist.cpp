// https://leetcode.com/problems/next-greater-node-in-linked-list/


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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        stack<int> Stack;
        
        for (auto ptr = head; ptr != nullptr; ptr = ptr->next)
            result.push_back(ptr->val);
        
        for (int i = result.size() - 1; i >= 0; i--)
        {
            int val = result[i];
            
            while (!Stack.empty() && Stack.top() <= val)
                Stack.pop();
            
            result[i] = Stack.empty() ? 0 : Stack.top();
            Stack.push(val);
        }
        
        return result;
    }
};









