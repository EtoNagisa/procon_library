#include "bits/stdc++.h"
template <int mod, bool isPrime = false>
class Mint {
    using ll = long long;
    bool dirty;
    ll value;

public:
    static std::vector<Mint> fact;
    static std::vector<Mint> rfact;
    constexpr Mint() : value(0), dirty(false){};
    constexpr Mint(ll x) : value(x), dirty(true) {
        value %= mod;
        if (value < 0) value += mod;
    }
    constexpr Mint(const Mint &other)
        : value(other.value), dirty(other.dirty) {}

    ll &get() {
        return value;
    }
    ll get() const {
        return value;
    }

    constexpr Mint pow(ll n) {
        Mint ret(1), tmp(value);
        while (n) {
            if (n & 1) ret *= tmp;
            n >>= 1;
            tmp *= tmp;
        }
        return ret;
    }
    constexpr bool initialized() const {
        return dirty;
    }
    constexpr bool operator==(const Mint &a) const {
        return value == a.value;
    }
    constexpr bool operator!=(const Mint &a) const {
        return value != a.value;
    }
    constexpr Mint &operator=(const Mint &a) {
        value = a.value;
        dirty = true;
        return *this;
    }
    constexpr Mint &operator+=(const Mint &a) {
        if ((value += a.value) >= mod) value -= mod;
        dirty = true;
        return *this;
    }
    constexpr Mint &operator-=(const Mint &a) {
        if ((value += mod - a.value) >= mod) value -= mod;
        dirty = true;
        return *this;
    }
    constexpr Mint &operator*=(const Mint &a) {
        value = value * a.value % mod;
        dirty = true;
        return *this;
    }

    constexpr Mint &operator/=(const Mint &a) {
        initialized = true;
        return *this *= inv(a);
    }
    constexpr Mint operator+(const Mint &a) const {
        return Mint(*this) += a;
    }
    constexpr Mint operator-(const Mint &a) const {
        return Mint(*this) -= a;
    }
    constexpr Mint operator*(const Mint &a) const {
        return Mint(*this) *= a;
    }
    constexpr Mint operator/(const Mint &a) const {
        return Mint(*this) /= a;
    }
    static constexpr void init_comb(int n) {
        fact.resize(n + 1);
        rfact.resize(n + 1);
        fact[0] = 1;
        for (int i = 0; i < n; ++i) {
            fact[i + 1] = fact[i] * (i + 1);
        }
        rfact[n] = inv(fact[n]);
        for (int i = n - 1; i >= 0; --i) {
            rfact[i] = rfact[i + 1] * (i + 1);
        }
    }
    static constexpr Mint comb(int a, int b) {
        if (a < 0 || b < 0 || a >= fact.size() || b >= fact.size() || a < b)
            return Mint(0);
        return fact[a] * rfact[b] * rfact[a - b];
    }
};

template <int mod, bool isPrime>
std::ostream &operator<<(std::ostream &os, const Mint<mod, isPrime> &m) {
    os << m.get();
    return os;
}
template <int mod, bool isPrime>
std::istream &operator>>(std::istream &is, Mint<mod, isPrime> &m) {
    is >> m.get();
    return is;
}

template <int mod>
constexpr Mint<mod, true> inv(const Mint<mod, true> &m) {
    long long a = m.get(), b = mod, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b;
        std::swap(a, b);
        u -= t * v;
        std::swap(u, v);
    }
    return Mint<mod, true>(u);
}

template <int mod, bool isPrime>
constexpr Mint<mod, isPrime> operator+(long long lhs,
                                       const Mint<mod, isPrime> &a) {
    return Mint<mod, isPrime>(lhs + a.get());
}

template <int mod, bool isPrime>
constexpr Mint<mod, isPrime> operator-(long long lhs,
                                       const Mint<mod, isPrime> &a) {
    return Mint<mod, isPrime>(lhs - a.get());
}

template <int mod, bool isPrime>
constexpr Mint<mod, isPrime> operator*(long long lhs,
                                       const Mint<mod, isPrime> &a) {
    return Mint<mod, isPrime>(lhs % mod * a.get());
}

template <int mod>
constexpr Mint<mod, true> operator/(long long lhs, const Mint<mod, true> &a) {
    return Mint<mod, true>(lhs % mod * inv(a));
}
template <int mod, bool isPrime>
std::vector<Mint<mod, isPrime>>
    Mint<mod, isPrime>::fact = std::vector<Mint<mod, isPrime>>();

template <int mod, bool isPrime>
std::vector<Mint<mod, isPrime>>
    Mint<mod, isPrime>::rfact = std::vector<Mint<mod, isPrime>>();

constexpr int default_mod = 1000000007;
using mint = Mint<default_mod, true>;