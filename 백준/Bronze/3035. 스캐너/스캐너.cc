#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long ll;

int n;
vector<int> v(2);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int r, c, zr, zc;
    char arr[51][51] = { 0, };
    scanf("%d %d %d %d", &r, &c, &zr, &zc);
    for (int i = 0; i < r; i++)
    {
        scanf("%s", arr[i]);
    }
    for (int i = 0; i < r; i++)
    {
        for (int l = 0; l < zr; l++)
        {
            for (int j = 0; j < c; j++)
            {
                for (int k = 0; k < zc; k++)
                {
                    printf("%c", arr[i][j]);
                }
            }
            printf("\n");
        }
    }
}