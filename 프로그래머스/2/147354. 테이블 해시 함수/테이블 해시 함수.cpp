#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct compare{
    int col;
    compare(int c) : col(c) {}
    
    bool operator()(vector<int> left, vector<int> right){
        if(left[col - 1] < right[col - 1]) return true;
        if(left[col - 1] > right[col - 1]) return false;
        
        if(left[0] > right[0]) return true;
        if(left[0] < right[0]) return false;
        return false;
    }
};

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    sort(data.begin(), data.end(), compare(col));
    for(int i=row_begin; i<=row_end; i++){
        int tmp = 0;
        for(int j=0; j<data[0].size(); j++) tmp += (data[i-1][j] % i);
        answer ^= tmp;
    }
    return answer;
}