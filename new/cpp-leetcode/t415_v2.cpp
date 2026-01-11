
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1 == "0" && num2 == "0")return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if(num1.size() < num2.size())swap(num1, num2);
        num1 += "0";
        for(int i = 0;i < num2.size();i++){
            int a = num1[i] - '0';
            int b = num2[i] - '0';
            num1[i] = a + b + '0';
        }

        for(int i = 0;i < num1.size();i++){
            num1[i] -= '0';
            if(i < num1.size() - 1)num1[i+1] += num1[i] / 10;
            num1[i] %= 10;
            num1[i] += '0';
        }
        while(num1.back() == '0')num1.pop_back();
        if(num1.size() == 0)return "0";
        reverse(num1.begin(), num1.end());
        return num1;
    }
};
