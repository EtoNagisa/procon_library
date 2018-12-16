#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<n;++i)
#define RREP(i,n) for(ll i=n-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<n;++i)
#define RFOR(i,m,n) for(ll i=n-1;i>=m;--i)
#define ALL(v) (v).begin(),(v).end()
#define PB(a) push_back(a)
#define UNIQUE(v) v.erase(unique(ALL(V),v.end()));
#define DUMP(v) REP(i, (v).size()) { cout << v[i]; if (i != v.size() - 1)cout << " "; else cout << endl; }
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

using namespace std;
//////////////////////////////////////
typedef long double ld;
typedef complex<ld> Point;
const ld  pi = acos(-1);


struct Line {
	Point a, b;
};

struct Lseg {
	Point a, b;
};

struct Circle {
	Point p;
	ld r;
};
bool eq(ld a, ld b) {
	return abs(a - b) < EPS;
}

ld dot(Point a, Point b) {
	return real(conj(a)*b);
}

ld cross(Point a, Point b) {
	return imag(conj(a)*b);
}

ld norm(Point a) {
	return dot(a, a);
}

int ccw(Point a, Point b, Point c){
	b -= a; c -= a;
	if (cross(b, c) > EPS) return 1; //a,b,c: anticlockwise
	if (cross(b, c) < -EPS) return -1;//a,b,c: clockwise
	if (dot(b, c) < 0) return 2; //c,a,b:liner
	if (norm(b) < norm(c)) return -2;// a,b,c: liner
	return 0;// a,c,b:liner
}

bool crossed(Line l, Line m) {
	return !eq(cross(l.b-l.a,m.a-m.b), 0);
}

bool crossed(Line l, Lseg s) {
	return cross(l.b - l.a, l.a - s.a)*cross(l.b - l.a, l.a - s.b) < EPS;
}

bool crossed(Lseg s, Lseg t) {
	return ccw(s.a, s.b, t.a)*ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a)*ccw(t.a, t.b, s.b) <= 0;
}
