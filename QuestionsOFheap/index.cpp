#include<iostream>
#include<cmath>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<string>
#include<map>
#include<list>
#include<queue>
#include<unordered_map>
#include<set>
#include<stack>
#include<cstring>
#include<numeric>
#include<climits>
#include<bitset>
#include<iomanip>

#define f(n) for(int i=0;i<n;i++)
#define fr(i,a,b) for(int i=a;i<=b;i+=1)
#define ceil(a,b) (a+b-1)/b
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define sum(x) accumulate(x.begin(),x.end(),0ll)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define strend string::npos
#define mod 1000000007
#define MAXN 100005
#define maxn 1000009
#define inf (int)1e9
#define infll (ll)1e18
#define PRECISION 6
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pi "3.14159265358979323846264338327"

namespace io
{
    template<class, class = void>
    struct is_iterable : std::false_type {};
    template<class T>
    struct is_iterable<T,std::__void_t<decltype(std::declval<T>().begin()),decltype(std::declval<T>().end())>> : std::true_type {};
    template<> struct is_iterable<std::string> : std::false_type {};
    template<> struct is_iterable<const std::string> : std::false_type {};
    template<class A, class B>
    std::ostream& operator<<(std::ostream& os, const std::pair<A,B>& p){return os << '(' << p.first << ", " << p.second << ')';}
    template<class K, class V,class Comp, class Alloc>std::ostream& operator<<(std::ostream& os,const std::map<K,V,Comp,Alloc>& m){
        os << '{';bool first = true;
        for (const auto& [k, v] : m){
            if (!first) os << ", ";
            first = false;
            os << k << ": " << v;
        }return os << '}';
    }
    template<class Container,std::enable_if_t<is_iterable<Container>::value, int> = 0>
    std::ostream& operator<<(std::ostream& os, const Container& c){
        os << '{';
        bool first = true;
        for (const auto& elem : c){
            if (!first) os << ", ";
            first = false;
            os << elem;
        }
        return os << '}';
    }
}

using namespace std;
using namespace io;

// Sieve of Eratosthenes to count primes up to n
ll primes_up_to_n(ll n){
    if(n <= 2) return 0;
    vector<bool> v(n, true);
    v[0] = v[1] = false;
    for(ll i = 2; i * i < n; i++){
        if(v[i]){
            for(ll j = i * i; j < n; j += i)
                v[j] = false;
        }
    }
    ll cnt = 0;
    for(int i = 0; i < n; i++) if(v[i]) cnt++;
    return cnt;
}

bool isprime(ll x){
    if(x<=1)return false;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}

// Modular exponentiation
ll modpow(ll x,ll n){
    ll res = 1;
    x %= mod;
    while(n > 0){
        if(n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

// Prime factorization
vll prime_factors(ll n){
    vll factors;
    for(ll i = 2; i * i <= n; i++){
        while(n % i == 0){
            factors.pb(i);
            n /= i;
        }
    }
    if(n > 1) factors.pb(n);
    return factors;
}

// Solve ax + by = c
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

bool solve_linear_diophantine(long long a, long long b, long long c, long long &x0, long long &y0, long long &g) {
    g = extended_gcd(a, b, x0, y0);
    if (c % g != 0) return false;
    x0 *= (c / g);
    y0 *= (c / g);
    return true;
}

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    fr(i,1,n-2){
        if(s[i-1]=='1' && s[i+1]=='1'){
            if(s[i]=='0')s[i]='1';

        }
    }
    ll mx=0;
    f(n){
        if(s[i]=='1')mx++;

    }
    fr(i,1,n-2){
        if(s[i-1]=='1' && s[i+1]=='1'){
            if(s[i]=='1')s[i]='0';

        }
    }

    ll mn=0;
    f(n){
        if(s[i]=='1')mn++;

    }
    cout<<mn<<" "<<mx;

}

int main(){
    fast;
    cout<<setprecision(PRECISION);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}