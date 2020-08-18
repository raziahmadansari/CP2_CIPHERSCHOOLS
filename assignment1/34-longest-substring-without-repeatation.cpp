// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        //for checking all 256 characters visited or not.
        vector<bool>vis(256, false);
		//deque to check repeated charater. 
		//we pop queue from front until repeated character is not found.
        deque<int>q;
		
        int i = 0, ans = 0;
		//Loop over string 
        while(i < s.size())
        {
			// if character is not yet considered take it, increase the
			// answer and put the index into queue.
            if(!vis[s[i]])
            {
                vis[s[i]] = true;
                q.push_back(i);
                ans++;
                i++;
            }
			//Find the repeating character
			// To do this pop the queue from front and make them unvisited
			//decrease the ans as size is decreasing
            else
            {
                while(vis[s[i]])
                {
                    vis[s[q.front()]] = false;
                    ans--;
                    q.pop_front();
                }
                q.push_back(i);
                vis[s[i]] = true;
                ans++;
                i++;
                
            }
			//Always store maximum value in maxi
            maxi = max(ans, maxi);
        }
       return maxi;
    }
};