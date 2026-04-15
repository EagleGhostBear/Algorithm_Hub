class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int sz = words.size() / 2;
        for(int i=0; i<=sz; i++){
            string left = (startIndex - i < 0 ? words[startIndex - i + words.size()] : words[startIndex - i]);
            string right = (startIndex + i >= words.size() ? words[startIndex + i - words.size()] : words[startIndex + i]);
            if(left == target || right == target) return i;
        }
        return -1;
    }
};