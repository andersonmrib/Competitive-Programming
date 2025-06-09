#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {

    int n, d;
    while ((cin >> n >> d) && (n != 0 && d != 0)) {
        string number, prize;
        int removedDigits = 0, prizeLen = 0;
        cin >> number;

        for(auto c : number) {
            if (prize.empty()) {
                prizeLen++;
                prize.push_back(c);
            } else {
                while (!prize.empty()) {
                    if (removedDigits >= d) break;
                    if (prize.back() < c) {
                        removedDigits++;
                        prizeLen--;
                        prize.pop_back();
                    } else break;
                }
                if (n - d > prizeLen) {
                    prizeLen++;
                    prize.push_back(c);
                }
            }
        }
        cout << prize << endl;
    }

    return 0;
}
