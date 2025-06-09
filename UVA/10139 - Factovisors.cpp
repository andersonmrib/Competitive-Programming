/*
   For some reason this code, which is the same of the Steven Halim,
   cannot be accepted in UVA during the date of 11/15/2024,
   but it will run correctly in Kattis and pass in 0.01 seconds.
   Maybe this is just a bug or the code it's not well optimized, but inside this
   link you can check one that is passing with no problem in UVA:
   https://github.com/KHvic/uva-online-judge/blob/master/10139-Factovisors.cpp

   I'll paste the commented code in the bottom of this archive

*/

#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int vp(int p, int n){
  int ans = 0;
  for(int pi=p; pi<=n; pi*=p)
    ans += n/pi;
  return ans;
}

int main(){

  speedBoost;
  int n, m;
  while(cin >> n >> m){
    bool hasSolution;

    if(m == 0){
      cout << m << " does not divide " << n << "!\n";
      continue;
    }

    else if(m <= n){
      cout << m << " divides " << n << "!\n";
      continue;
    }

    unordered_map<int, int> umap;
    int temp = m;
    ll PF = 2;
    while((temp > 1) && (ll)(PF*PF <= m)){
      int frequency = 0;
      while(temp%PF == 0){
        frequency++;
        temp /= PF;
      }
      if(frequency > 0) umap[PF] = frequency;
      PF++;
    }
    if(temp > 1) umap[temp] = 1;

    hasSolution = true;
    for(auto &[p, e] : umap){
      if(vp(p, n) < e){
        hasSolution = false;
        break;
      }
    }
      if(hasSolution) cout << m << " divides " << n << "!\n";
      else            cout << m << " does not divide " << n << "!\n";
  }

  return 0;
}

// ----------------------------------------------------------------------------

/*

#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
const int N = 50000;

void sieve(){
    bitset<N> isPrime;
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for(long long i=2;i<N;i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(long long j=i*i;j<N;j+=i)
                isPrime[j] = false;
        }
    }
}

// exponent of a prime p in n!
int get_powers(int n, int p) {
    int res = 0;
    for(int power=p; power<=n; power*=p)
        res += n/power;
    return res;
}

bool canDivide(int n, int m){
    for(int pidx = 0; pidx <primes.size()
    && primes[pidx]*primes[pidx] <= m; pidx++){
        int cntFactor = 0;
        while(m%primes[pidx] == 0) {
            cntFactor++;
            m /= primes[pidx];
        }
        int cntFactorN = get_powers(n, primes[pidx]);
        if(cntFactorN < cntFactor) return false;
    }
    // not fully factored and m is larger
    if(m != 1 && m > n) return false;
    return true;
}

int main() {
    sieve();
    int n,m;
    while(scanf("%d %d",&n,&m) != EOF){
        if(canDivide(n, m))
            printf("%d divides %d!\n", m, n);
        else
            printf("%d does not divide %d!\n", m, n);
    }
}

*/
