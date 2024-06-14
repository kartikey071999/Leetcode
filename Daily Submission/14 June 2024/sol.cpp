class Solution {
public:
    int minIncrementForUnique(vector<int>& n) 
    {
        sort(n.begin(), n.end());
        unordered_map<int,int> m;
        int o = n[0]-1, k = 0;
        for(int i : n)
        {
            if(i <= o)
            {
                k+=((o+1)-i);
                ++o;
            }
            else
            {
                o = i;
            }
        }
        return k;
    }
};