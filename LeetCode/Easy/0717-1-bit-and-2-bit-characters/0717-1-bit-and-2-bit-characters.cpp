class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        vector<int> v;
        for(int i=0; i<bits.size(); i++){
            if(bits[i] == 1){
                v.push_back(2);
                i++;
            }
            else v.push_back(1);
        }
        if(v.back() == 1) return true;
        return false;
    }
};