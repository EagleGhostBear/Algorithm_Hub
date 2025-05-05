#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ans;
vector<vector<int>> datas;

struct compare_code{
    bool operator()(vector<int> left, vector<int> right){
        return left[0] < right[0];
    }
};

struct compare_date{
    bool operator()(vector<int> left, vector<int> right){
        return left[1] < right[1];
    }
};

struct compare_maximum{
    bool operator()(vector<int> left, vector<int> right){
        return left[2] < right[2];
    }
};

struct compare_remain{
    bool operator()(vector<int> left, vector<int> right){
        return left[3] < right[3];
    }
};

void solve(int type, int val_ext){
    for(int i=0; i<datas.size(); i++){
        if(datas[i][type] < val_ext) ans.push_back(datas[i]);
    }
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    datas = data;
    if(ext == "code") solve(0, val_ext);
    else if(ext == "date") solve(1, val_ext);
    else if(ext == "maximum") solve(2, val_ext);
    else if(ext == "remain") solve(3, val_ext);
    
    if(sort_by == "code") sort(ans.begin(), ans.end(), compare_code());
    else if(sort_by == "date") sort(ans.begin(), ans.end(), compare_date());
    else if(sort_by == "maximum") sort(ans.begin(), ans.end(), compare_maximum());
    else if(sort_by == "remain") sort(ans.begin(), ans.end(), compare_remain());
    
    return ans;
}