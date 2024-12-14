#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string tmp;
    string s = "";
    for (int i = 0; i < 2; i++) {
        cin >> tmp;
        if (tmp == "black") {
            s += "0";
        }
        else if (tmp == "brown") {
            s += "1";
        }
        else if (tmp == "red") {
            s += "2";
        }
        else if (tmp == "orange") {
            s += "3";
        }
        else if (tmp == "yellow") {
            s += "4";
        }
        else if (tmp == "green") {
            s += "5";
        }
        else if (tmp == "blue") {
            s += "6";
        }
        else if (tmp == "violet") {
            s += "7";
        }
        else if (tmp == "grey") {
            s += "8";
        }
        else if (tmp == "white") {
            s += "9";
        }
    }

    ll num = stoi(s);
    cin >> tmp;
    if (tmp == "black") {
        num *= 1;
    }
    else if (tmp == "brown") {
        num *= 10;
    }
    else if (tmp == "red") {
        num *= 100;
    }
    else if (tmp == "orange") {
        num *= 1000;
    }
    else if (tmp == "yellow") {
        num *= 10000;
    }
    else if (tmp == "green") {
        num *= 100000;
    }
    else if (tmp == "blue") {
        num *= 1000000;
    }
    else if (tmp == "violet") {
        num *= 10000000;
    }
    else if (tmp == "grey") {
        num *= 100000000;
    }
    else if (tmp == "white") {
        num *= 1000000000;
    }

    cout << num;
}