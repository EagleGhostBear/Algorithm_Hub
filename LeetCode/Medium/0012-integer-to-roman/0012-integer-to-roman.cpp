class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        // 1000의 자리
        int n = num / 1000;
        num %= 1000;
        while(n--) ans += 'M';

        // 100의 자리
        n = num / 100;
        num %= 100;
        if(n == 4) ans += "CD";
        else if(n == 9) ans += "CM";
        else{
            if(n >= 5){ans += 'D'; n -= 5;}
            while(n--) ans += 'C';
        }

        // 10의 자리
        n = num / 10;
        num %= 10;
        if(n == 4) ans += "XL";
        else if(n == 9) ans += "XC";
        else{
            if(n >= 5){ans += 'L'; n -= 5;}
            while(n--) ans += 'X';
        }

        // 1의 자리
        n = num;
        if(n == 4) ans += "IV";
        else if(n == 9) ans += "IX";
        else{
            if(n >= 5){ans += 'V'; n -= 5;}
            while(n--) ans += 'I';
        }
        return ans;
    }
};