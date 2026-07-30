class Solution {
public:
    int gcd(int a, int b){
        while(b){
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return gcd(nums.front(), nums.back());
    }
};