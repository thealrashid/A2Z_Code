#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int p = 31;
const int M = 1e9 + 9;

// Compute polynomial hash of a string
ll compute_hash(const string &s) {
    ll hash = 0;
    ll p_pow = 1;
    for (char c : s) {
        hash = (hash + (c - 'a' + 1) * p_pow) % M;
        p_pow = (p_pow * p) % M;
    }
    return hash;
}

// Rabin-Karp pattern matching
vector<int> rabin_karp(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    ll pattern_hash = compute_hash(pattern);

    vector<ll> prefix_hash(n + 1, 0), power(n + 1, 1);

    // Precompute powers of p
    for (int i = 1; i <= n; i++)
        power[i] = (power[i - 1] * p) % M;

    // Compute prefix hashes of text
    for (int i = 0; i < n; i++) {
        prefix_hash[i + 1] = (prefix_hash[i] + (text[i] - 'a' + 1) * power[i]) % M;
    }

    vector<int> result;

    for (int i = 0; i + m <= n; i++) {
        ll current_hash = (prefix_hash[i + m] - prefix_hash[i] + M) % M;
        ll expected_hash = (pattern_hash * power[i]) % M;
        if (current_hash == expected_hash) {
            // Optional: verify actual substring
            if (text.substr(i, m) == pattern)
                result.push_back(i);  // match at index i
        }
    }

    return result;
}

int main() {
    string text = "cdabcdab";
    string pattern = "abcd";

    vector<int> matches = rabin_karp(text, pattern);

    for (int idx : matches)
        cout << "Match at index: " << idx << "\n";

    return 0;
}
