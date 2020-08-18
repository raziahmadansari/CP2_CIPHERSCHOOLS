// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<double>s; 
    priority_queue<double,vector<double>,greater<double>>g;
    int c;
    double ans;
    MedianFinder() {
        c=0;
        ans=0;
      
    }
    
    void addNum(int num) {
        num=(double)num;
        
        if(s.size()>g.size())
        {
            if(num<ans)
            {
                g.push(s.top());
                s.pop();
                s.push(num);
            }
            else
                g.push(num);
            ans=(s.top()+g.top())/2.0;
        }
        else if(g.size()>s.size())
        {
            if(num>ans)
            {
                s.push(g.top());
                g.pop();
                g.push(num);
            }
            else
                s.push(num);
            ans=(s.top()+g.top())/2.0;
        }
        else
        {
            if(num<ans)
            {
                s.push(num);
                ans=s.top();
            }
            else
            {
                g.push(num);
                ans=g.top();
            }
        }
        
    }
    
    double findMedian() {
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */