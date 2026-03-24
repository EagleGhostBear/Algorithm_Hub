class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       unordered_map<int,int> um;
	   for(auto n : nums) um[n]++;
	   for(auto n : um) if(n.second == 1) return n.first;
	   return -1;
    }
};