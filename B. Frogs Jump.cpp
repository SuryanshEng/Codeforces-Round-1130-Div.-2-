#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    int total_frogs = 0;
    vector<int> c(n), type(n);

    for (int i = 0; i < n; ++i) {
        int t = (s1[i] == 'f');
        int b = (s2[i] == 'f');
        c[i] = t + b;
        total_frogs += c[i];
        type[i] = t + 2 * b;
    }

    auto get_max = [&](int mode) {
        vector<int> dp(2, -1e9);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> next_dp(2, -1e9);
            for (int lx = 0; lx <= 1; ++lx) {
                if (dp[lx] < 0) continue;
                for (int cx = 0; cx <= 1; ++cx) {
                    if (i == n - 1 && cx != 0) continue;
                    int H = lx + cx;
                    if (H > c[i]) continue;

                    int cost = 0;
                    if (type[i] == 1) {
                        cost = (mode == 1) ? (H == 0 ? 2 : 1) : (H == 0 ? 0 : 1);
                    } else if (type[i] == 2) {
                        cost = (mode == 1) ? (H == 0 ? 0 : 1) : (H == 0 ? 2 : 1);
                    } else {
                        cost = (H == 1) ? 3 : 2;
                    }

                    next_dp[cx] = max(next_dp[cx], dp[lx] + cost);
                }
            }
            dp = move(next_dp);
        }
        return dp[0];
    };

    int m1 = get_max(1);
    int m2 = get_max(2);
    int limit = total_frogs - (total_frogs % 2);
    int max_kept = min({m1, m2, limit});

    cout << total_frogs - max_kept << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}