#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> lis;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (lis.empty() || lis.back() < num) lis.push_back(num);
        else {
            int left = 0, right = lis.size() - 1;
            int mid = 0;
            while (left <= right) {
                mid = (left + right) / 2;
                if (lis[mid] == num) break;
                else if (lis[mid] < num) left = mid + 1;
                else right = mid - 1;
            }
            if (lis[mid] < num) lis[mid + 1] = num;
            else lis[mid] = num;
        }
    }
    cout << lis.size();
}