// https://leetcode.com/problems/last-stone-weight/

/*
 *HINT - USE HEAP DATA STRUCTURE
 *
 */

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(begin(stones), end(stones)); // initialize the heap
        
        while (pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a > b)
                pq.push(a - b);
        }
        return pq.empty() ? 0 : pq.top();
    }
};