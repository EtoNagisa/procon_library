#include "bits/stdc++.h"
template<int mod, bool isPrime = false >
class  Mint {
	using ll = long long;
	ll value;
public:
	constexpr Mint() : value(0) {};
	constexpr Mint(ll x) : value(x) {
		value %= mod;
		if (value < 0)value += mod;
	}
	constexpr Mint(const Mint &other) : value(other.value) {}

	ll get() const { return value; }

	constexpr Mint pow(ll n) {
		Mint ret(1), tmp(value);
		while (n) {
			if (n & 1)ret *= tmp;
			n >>= 1;
			tmp *= tmp;
		}
		return ret;
	}
	constexpr bool operator == (const Mint &a) const {
		return value == a.value;
	}
	constexpr Mint& operator =(const Mint &a) {
		value = a.value;
		return *this;
	}
	constexpr Mint& operator +=(const Mint &a) {
		if ((value += a.value) >= mod)value -= mod;
		return *this;
	}
	constexpr Mint& operator -=(const Mint &a) {
		if ((value += mod - a.value) >= mod)value -= mod;
		return *this;
	}
	constexpr Mint& operator *=(const Mint &a) {
		value = value * a.value% mod;
		return *this;
	}

	constexpr Mint& operator /=(const Mint &a) {
		return *this *= inv(a);
	}
	constexpr Mint operator +(const Mint &a) const {
		return Mint(*this) += a;
	}
	constexpr Mint operator -(const Mint &a) const {
		return Mint(*this) -= a;
	}
	constexpr Mint operator *(const Mint &a) const {
		return Mint(*this) *= a;
	}
	constexpr Mint operator /(const Mint &a) const {
		return Mint(*this) /= a;
	}
};
template<int mod, bool isPrime> std::ostream& operator << (std::ostream &os, const Mint<mod, isPrime>& m) { os << m.get(); return os; }
template<int mod, bool isPrime> std::istream& operator >> (std::istream &is, Mint<mod, isPrime>& m) { is >> m.get();  return is; }

template<int mod>
constexpr Mint<mod, true> inv(const Mint<mod, true> &m) {
	long long a = m.get(), b = mod, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; std::swap(a, b);
		u -= t * v; std::swap(u, v);
	}
	return Mint<mod, true>(u);
}

template<int mod, bool isPrime>
constexpr Mint<mod, isPrime> operator +(long long lhs, const Mint<mod, isPrime> &a) {
	return Mint<mod, isPrime>(lhs + a.get());
}

template<int mod, bool isPrime>
constexpr Mint<mod, isPrime> operator -(long long lhs, const Mint<mod, isPrime> &a) {
	return Mint<mod, isPrime>(lhs - a.get());
}

template<int mod, bool isPrime>
constexpr Mint<mod, isPrime> operator *(long long lhs, const Mint<mod, isPrime> &a) {
	return Mint<mod, isPrime>(lhs%mod * a.get());
}

constexpr int default_mod = 1000000007;
using mint = Mint<default_mod, true>;
