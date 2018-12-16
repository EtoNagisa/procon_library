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

////////////////////////////////////////////////

class lct_node {
	lct_node *l, *r, *p;
	bool rev;

	int pos() {
		if (p && p->l == this)return -1;
		if (p&& p->r == this)return 1;
		return 0;
	}

	void eval() {
		if (pos())p->eval();
		if (rev) {
			swap(l, r);
			if (l)l->rev ^= true;
			if (r)r->rev ^= true;
			rev = false;
		}
	}

	void rotate() {
		lct_node *par = p, *tmp;
		if (p->l == this) {
			tmp = r;
			r = par;
			par->l = tmp;
		}
		else {
			tmp = l;
			l = par;
			par->r = tmp;
		}
		if (tmp)tmp->p = par;
		p = par->p;
		par->p = this;
		if (p&&p->l == par) p->l = this;
		if (p&&p->r == par) p->r = this;
	}

	void splay() {
		eval();
		while (pos()) {
			int st = pos()*(p->pos());
			if (!st)rotate();
			else if (st == 1)p->rotate(),rotate();
			else rotate(), rotate();
		}
	}

public :
	lct_node() :l(nullptr), r(nullptr), p(nullptr), rev(false) {}
	
	void expose() {
		for (lct_node *x = this, *y = nullptr; x; y = x, x = x->p)x->splay(), x->r = y;
		splay();
	}

	void link(lct_node *x) {
		x->expose();
		expose();
	}

};
