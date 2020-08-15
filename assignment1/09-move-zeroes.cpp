#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) 
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            
            for (int j = i + 1; j < n; j++)
                nums[j - 1] = nums[j];
            n--;
            nums[n] = 0;
            i--;
        }
    }
}

int main()
{
    // vector<int> nums{ 0, 0, 1 };
    vector<int> nums{ 0, 1, 0, 3, 12 };
    moveZeroes(nums);
    for (auto e : nums)
        cout << e << " ";
    
    return 0;
}