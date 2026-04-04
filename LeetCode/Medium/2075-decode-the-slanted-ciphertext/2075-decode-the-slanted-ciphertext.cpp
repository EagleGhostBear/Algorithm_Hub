class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string ans = "";
        vector<vector<char>> v(rows, vector<char>(encodedText.size() / rows));
        for(int i=0; i<encodedText.size(); i++){
            int row = i / v[0].size();
            int col = i % v[0].size();
            v[row][col] = encodedText[i];
        }
        int cnt = 0;
        for(int i=0; i<v[0].size(); i++){
            int row = 0, col = i;
            while(row < v.size() && col < v[0].size()){
                if(v[row][col] == ' ') cnt++;
                else{
                    while(cnt){
                        ans += ' ';
                        cnt--;
                    }
                    ans += v[row][col];
                }
                row++, col++;
            }
        }
        return ans;
    }
};