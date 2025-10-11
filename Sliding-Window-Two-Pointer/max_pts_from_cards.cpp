#include <bits/stdc++.h>

using namespace std;

int maxScore(vector<int>& cards, int k) {
    int n = cards.size();
    int total_pts = 0;
    int remove_pts = 0;

    for (int card : cards) total_pts += card;

    if (k == n) return total_pts;

    int window_size = n - k;

    for (int i = 0; i < window_size; i++) remove_pts += cards[i];

    int min_remove = remove_pts;

    for (int i = window_size; i < n; i++) {
        remove_pts = remove_pts + cards[i] - cards[i - window_size];
        min_remove = min(min_remove, remove_pts);
    }

    return total_pts - min_remove;
}

int main() {
    vector<int> cards = {1,2,3,4,5,6,1};
    int k = 3;

    cout << maxScore(cards, k) << endl;

    return 0;
}