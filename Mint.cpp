#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<ll(n);++i)
#define RREP(i,n) for(ll i=ll(n)-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<ll(n);++i)
#define RFOR(i,m,n) for(ll i=ll(n)-1;i>=ll(m);--i)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define DUMP(v) REP(aa, (v).size()) { cout << v[aa]; if (aa != v.size() - 1)cout << " "; else cout << endl; }
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll max(ll a, int b) { return max(a, ll(b)); }
ll max(int a, ll b) { return max(ll(a), b); }
ll min(ll a, int b) { return min(a, ll(b)); }
ll min(int a, ll b) { return min(ll(a), b); }

/*-----------------------------------------------*/
template<unsigned mod>
struct Mint {
private:
	unsigned value;
public:
	unsigned get() const { return value; }
	Mint() :value(0) {}
	Mint(ll x) { if (x<0)value = x% mod + mod; else value = x%mod; }
	Mint<mod>& operator =(const Mint<mod> &a) { value = a.value; return *this; }
	Mint<mod>& operator =(ll a) { if ((a %= mod) < 0)a += mod; value = a;	return *this; }
	Mint<mod>& operator +=(const Mint<mod> &a) { if ((value += a.value) >= mod)value -= mod;	return *this; }
	Mint<mod>& operator +=(ll a) { if ((a %= mod)<0)a += mod; if ((value += a) >= mod)value -= mod; return *this; }
	Mint<mod>& operator -=(const Mint<mod> &a) { if ((value + mod - a.value) >= mod)value -= mod; return *this; }
	Mint<mod>& operator -=(ll a) { a *= -1; return this += a; }
	Mint<mod>& operator *=(const Mint<mod> &a) { value = (unsigned long long)(value)*a.value% mod; return *this; }
	Mint<mod>& operator *=(ll a) { if ((a %= mod)<0)a += mod; value = (unsigned long long)(value)*a%mod; return *this; }
	Mint<mod> operator +(const Mint<mod> &a) const { return Mint<mod>(*this) += a; }
	Mint<mod> operator +(ll a)const { return Mint<mod>(*this) += a; }
	Mint<mod> operator -(const Mint<mod> &a) const { return Mint<mod>(*this) -= a; }
	Mint<mod> operator -(ll a) const { return Mint<mod>(*this) -= a; }
	Mint<mod> operator *(const Mint<mod> a) const { return Mint<mod>(*this) *= a; }
	Mint<mod> operator *(ll a) const { return Mint<mod>(*this) *= a; }
	template<unsigned md> friend ostream& operator <<(ostream &, const Mint<md> &);
	template<unsigned md> friend istream& operator >>(istream &, Mint<md> &);
};
template<unsigned md>ostream& operator <<(ostream &os, const Mint<md> &m) { os << m.value; return os; }
template<unsigned md>istream& operator >>(istream &is, Mint<md> &m) { is >> m.value; return is; }
