#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ans = 0, row, col, end_floor;
vector<vector<int>> v;

int solution(int n, int w, int num) {
    v.resize(n/w + 1, vector<int>(w));
    
    for(int i=1; i<=n;){
        int floor = i / w;
        if(!(i % w)) floor--;
        if(floor%2){ // 역방향
            for(int j=w-1; j>-1; j--){
                v[floor][j] = i;
                if(i == num) row = floor, col = j;
                if(i == n) end_floor = floor;
                i++;
            }
        }
        else{ // 정방향
            for(int j=0; j<w; j++){
                v[floor][j] = i;
                if(i == num) row = floor, col = j;
                if(i == n) end_floor = floor;
                i++;
            }
        }
    }
    
    for(int i=row; i<=end_floor; i++){
        if(v[i][col] <= n) ans++;
    }
    return ans;
}