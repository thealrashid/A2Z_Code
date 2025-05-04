#include <iostream>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

void array_input(vector<int>& arr, int n) {
    for( int i = 0; i < n; i++) cin >> arr[i];
}

void array_print(vector<int> arr, int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int max_profit(vector<int> prices, int n) {
    int buy = -1, sell = -1, profit = 0, min_price = INT_MAX, profit_max = 0;

    for (int i = 0; i < n; i++) {
        if(prices[i] < min_price) min_price = prices[i];
        profit = prices[i] - min_price;
        if (profit > profit_max) profit_max = profit;
    }
    return profit_max;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    if (n <= 0) {
        cout << "Enter valid size." << endl;
        return -1;
    }
    vector<int> prices(n);
    array_input(prices, n);
    array_print(prices, n);

    cout << "Max profit: " << max_profit(prices, n) << endl;

    return 0;
}