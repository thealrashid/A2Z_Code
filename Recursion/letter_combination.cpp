#include <bits/stdc++.h>

using namespace std;

void backtrack(string digits, int index, unordered_map<char, string> &phone_map, string current, vector<string> &result) {
    if (index == digits.size()) {
        result.push_back(current);
        return;
    }

    char digit = digits[index];
    string letters = phone_map[digit];

    for (char letter : letters) {
        current.push_back(letter);
        backtrack(digits, index + 1, phone_map, current, result);
        current.pop_back();
    }
}

vector<string> letter_combination(string digits) {
    vector<string> result;
    
    if (digits.empty()) return result;
    
    unordered_map<char, string> phone_map = {
        {'2' , "abc"},
        {'3' , "def"},
        {'4' , "ghi"},
        {'5' , "jkl"},
        {'6' , "mno"},
        {'7' , "pqrs"},
        {'8' , "tuv"},
        {'9' , "wxyz"}
    };
    
    backtrack(digits, 0, phone_map, "", result);

    return result;
}

int main() {
    string digits = "23";

    vector<string> result = letter_combination(digits);

    for (auto itr : result) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}