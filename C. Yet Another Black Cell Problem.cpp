#include <iostream>
#include <vector>

using namespace std;

bool check(long long k, const vector<long long>& a, int n, int x) {
    vector<bool> iso(n, false);
    int iso_cnt = 0;
    for (int i = 0; i < n; ++i) {
        bool l = (i > 0 && a[i] - a[i - 1] <= k);
        bool r = (i < n - 1 && a[i + 1] - a[i] <= k);
        if (!l && !r) {
            iso[i] = true;
            iso_cnt++;
        }
    }
    int pairs = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (iso[i] && iso[i + 1] && a[i + 1] - a[i] <= 2 * k) {
            pairs++;
            i++;
        }
    }
    return (iso_cnt - pairs) <= x;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long low = 1, high = 1e9, ans = 1e9;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, a, n, x)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
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