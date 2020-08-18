class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        int i = 0, maxi = 0;
        stack<int>st;
        while(i <n)
        {
            if(st.empty() || h[st.top()] <= h[i])
            {
                st.push(i);i++;
            }
            else
            {
                int a = st.top();
                st.pop();
                int j;
                if(st.empty())
                    j = i;
                else 
                    j = i - st.top() - 1;
                maxi = max(maxi, j*h[a]);
            }
        }
        while(!st.empty())
        {
            int a = st.top();
                st.pop();
                int j;
                if(st.empty())
                    j = i;
                else 
                    j = i - st.top() - 1;
                maxi = max(maxi, j*h[a]);
        }
        return maxi;
    }
};