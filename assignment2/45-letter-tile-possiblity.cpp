// https://leetcode.com/problems/letter-tile-possibilities/


class Solution {
public:
    void helper(string tiles, int &result, int begin) 
    {
        result++;
        for(int i=begin;i<tiles.size();i++) 
        {
            if(i!=begin && tiles[i]==tiles[begin])  
                continue;
            swap(tiles[i],tiles[begin]);
            helper(tiles,result,begin+1);
        }
        return;
    }
    
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        int result=-1;
        helper(tiles,result,0);
    
        return result;
    }
};