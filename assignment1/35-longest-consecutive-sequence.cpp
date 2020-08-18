// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& arr) 
    {
        int n = arr.size();
        unordered_map<int,pair<bool,int>> check;
    for(int i=0;i<n;i++)
    {
        check.insert({arr[i],{false,i}});
    }
    
    int max_len = INT_MIN;			
    int start = INT_MAX;
    
    for(int j=0;j<n;j++)
    {
        int key = arr[j];
        
        if(check[key].first)
            continue;
        else
        {
            check[key].first = true;
            int rc=0;
            int i=1;
            
            while(check.count(key+i) > 0 && !check[key+i].first) //getting right subsequence
            {
                check[key+i].first = true;
                rc++;
                i++; 
            }
            
            i=-1; 
            int lc=0; //sentinel
            while(check.count(key+i) >0 && !check[key+i].first)		//getting left subsequence
            {
                check[key+i].first =true;
                lc++;
                i--;
            }
            
            int star;
            int len;
            
            if(lc !=0)		//defining start
                star = check[key-lc].second;
            else
                star = j;
            
            //defining length
            len = lc + 1 + rc;
            
            //comparing
            if(len > max_len)
            {
                max_len = len;
                start = star;
            }
            else
                if(len == max_len)
                    start = min(start,star);  
        }
    }
    
    return (max_len == INT_MIN?0:max_len);
    }
};