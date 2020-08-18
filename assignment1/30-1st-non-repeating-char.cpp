#include <iostream>
#include <queue>
#include <string>
#include <climits>

using namespace std;

void firstNonRepeating(string& str)
{
    queue<char> q; 
    int charCount[26] = { 0 }; 
  
    // traverse whole stream 
    for (int i = 0; str[i]; i++)
    { 
        q.push(str[i]); 
 
        charCount[str[i] - 'a']++; 
   
        while (!q.empty())
        { 
            if (charCount[q.front() - 'a'] > 1) 
                q.pop(); 
            else { 
                cout << q.front() << " "; 
                break; 
            } 
        } 
  
        if (q.empty()) 
            cout << -1 << " "; 
    }
}

int main()
{
    string str = "aabc";
    firstNonRepeating(str);

    return 0;
}