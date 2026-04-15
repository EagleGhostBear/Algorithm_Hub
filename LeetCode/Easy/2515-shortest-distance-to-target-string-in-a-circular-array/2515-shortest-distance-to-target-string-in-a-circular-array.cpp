class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int sz = words.size() / 2;
        for(int i=0; i<=sz; i++){
            int left = (startIndex - i < 0 ? startIndex - i + words.size() : startIndex - i);
            int right = (startIndex + i >= words.size() ? startIndex + i - words.size() : startIndex + i);
            if(words[left] == target || words[right] == target) return i;
        }
        return -1;
    }
};