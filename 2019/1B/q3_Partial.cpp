//Codechef: mohilllll Codeforces: mohilkhare Google: mohilkhare17
//headers
#include <bits/stdc++.h>
#include <assert.h>
//shorts
#define ll long long int
#define vll vector<long long int>
#define vvll vector<vector<long long int>
#define sll stack<long long int>
#define pb push_back
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
//program specific shorts (if any)
//
//namespaces
using namespace std;

/*

for testcase 1: we can make n(n+1)/2 pairs for n is v small i.e. n <= 100
for testcase 2: dunno yet

*/

int main() {
    fastIO;
    ll t; cin >> t;
    for(ll q = 0; q < t; q++) {
        ll n, k; cin >> n >> k;
        ll c[n], d[n];
        for(ll i = 0; i < n; i++) cin >> c[i];
        for(ll i = 0; i < n; i++) cin >> d[i];
        // n^2 soln
        ll finalAns = 0;
        for(ll i = 0; i < n; i++) {
            ll maxc = c[i], maxd = d[i];
            for(ll j = i; j < n; j++) {
                maxc = max(maxc, c[j]);
                maxd = max(maxd, d[j]);
                if(abs(maxc - maxd) <= k)
                    finalAns++;
            }
        }
        cout << "Case #" << q+1 << ": " << finalAns << endl;
    }
    return 0;
}