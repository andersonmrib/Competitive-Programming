#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {

    int n;
    while(cin >> n, n) {
        vector<int> vec;

        for(int i = 0; i < n; i++) {
            int num; cin >> num;
            vec.push_back(num);
        }

        long long demand = 0, ans = 0;
        for(auto x : vec) {
            demand += x;
            ans += labs(demand);
        }
        cout << ans << endl;
    }

    return 0;
}
