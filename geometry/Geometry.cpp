#include "bits/stdc++.h"

//The MIT License (MIT)
//
//Copyright (c) 2015 asi1024
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.


//////////////////////////////////////
using ld = long double;
using Point = std::complex<ld>;
const ld  pi = std::acos(-1);
constexpr ld eps = 1e-9;

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
	return std::abs(a - b) < eps;
}

ld dot(Point a, Point b) {
	return std::real(std::conj(a) * b);
}

ld cross(Point a, Point b) {
	return std::imag(std::conj(a) * b);
}

ld norm(Point a) {
	return dot(a, a);
}

int ccw(Point a, Point b, Point c) {
	b -= a; c -= a;
	if (cross(b, c) > eps) return 1; //a,b,c: anticlockwise
	if (cross(b, c) < -eps) return -1;//a,b,c: clockwise
	if (dot(b, c) < 0) return 2; //c,a,b:liner
	if (norm(b) < norm(c)) return -2;// a,b,c: liner
	return 0;// a,c,b:liner
}

bool isis_ll(Line l, Line m) {
	return !eq(cross(l.b - l.a, m.a - m.b), 0);
}

bool isis_ls(Line l, Lseg s) {
	return cross(l.b - l.a, l.a - s.a) * cross(l.b - l.a, l.a - s.b) < eps;
}

bool isis_ss(Lseg s, Lseg t) {
	return ccw(s.a, s.b, t.a)* ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

bool isis_lp(Line l, Point p) {
	return std::abs(cross(l.b - p, l.a - p)) < eps;
}

bool isis_sp(Lseg s, Point p) {
	return eq(abs(s.a - p) + abs(s.b - p), abs(s.b - s.a));
}

Point proj(Line l, Point p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}

Point proj(Lseg l, Point p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}

Point is_ll(Line s, Line t) {
	Point sv = s.b - s.a, tv = t.b - t.a;
	assert(cross(sv, tv) != 0);
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}

ld dist_lp(Line l, Point p) {
	return abs(p - proj(l, p));
}

ld dist_ll(Line l, Line m) {
	return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}

ld dist_ls(Line l, Lseg s) {
	return isis_ls(l, s) ? 0 : std::min(dist_lp(l, s.a), dist_lp(l, s.b));
}

ld dist_sp(Lseg s, Point p) {
	Point r = proj(s, p);
	return isis_sp(s, r) ? abs(r - p) : std::min(std::abs(s.a - p), std::abs(s.b - p));
}

ld dist_ss(Lseg s, Lseg t) {
	if (isis_ss(s, t))return 0;
	return std::min({ dist_sp(s,t.a),dist_sp(s,t.b),dist_sp(t,s.a),dist_sp(t,s.b) });
}