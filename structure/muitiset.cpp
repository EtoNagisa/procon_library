#include "bits/stdc++.h"

template <typename Kty> struct _const_iterator {
private:
  using _map = std::map<Kty, size_t>;
  using _iterator = typename _map::const_iterator;
  _iterator _it;
  size_t cnt;

public:
  _const_iterator() : cnt(0) {}
  _const_iterator(_iterator it) : _it(it), cnt(0) {}
  _const_iterator(const _const_iterator &) = default;
  _const_iterator(_const_iterator &&) = default;
  _const_iterator &operator=(const _const_iterator &) = default;
  _const_iterator &operator=(_const_iterator &&) = default;

  using iterator_category = typename _iterator::iterator_category;
  using value_type = Kty;
  using difference_type = std::ptrdiff_t;
  using pointer = const value_type *;
  using reference = const value_type &;

  reference operator*() const {
    return _it->first;
  }

  pointer operator->() const {
    return &_it->first;
  }

private:
  void increment() {
    ++cnt;
    if (cnt == (*_it).second) {
      ++_it;
      cnt = 0;
    }
  }

  void decrement() {
    if (cnt > 0) {
      --cnt;
    } else {
      --_it;
      cnt = (*_it).second - 1;
    }
  }

public:
  _const_iterator &operator++() {
    increment();
    return *this;
  }

  _const_iterator operator++(int) {
    _const_iterator tmp = *this;
    increment();
    return tmp;
  }

  _const_iterator &operator--() {
    decrement();
    return *this;
  }

  _const_iterator operator--(int) {
    _const_iterator tmp = *this;
    decrement();
    return tmp;
  }

  bool operator==(const _const_iterator &rhs) const {
    return this->_it == rhs._it;
  }

  bool operator!=(const _const_iterator &rhs) const {
    return !(*this == rhs);
  }
};
template <typename Kt, class Ct = std::less<Kt>> class muitiset {
public:
  using key_type = Kt;
  using compare_type = Ct;

private:
  using _map = std::map<key_type, size_t, compare_type>;
  _map _count;

public:
  using const_iterator = _const_iterator<key_type>;
  using const_reverse_iterator =
      std::reverse_iterator<_const_iterator<key_type>>;

  const_iterator begin() const {
    return const_iterator(_count.begin());
  }

  const_iterator end() const {
    return const_iterator(_count.end());
  }

  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(end());
  }

  const_reverse_iterator rend() const {
    return const_reverse_iterator(begin());
  }

  size_t count(const key_type &val) const noexcept {
    auto itr = _count.find(val);
    itr = _count.end() ? 0 : itr->second;
  }

  void insert(const key_type &val) noexcept {
    _count[val]++;
  }

  void erase(const key_type &val) noexcept {
    if (_count.count(val) == 1) {
      if (--_count[val] == 0) {
        _count.erase(val);
      }
    }
  }

  void clear() noexcept {
    _count.clear();
  }

  size_t size() const noexcept {
    return _count.size();
  }

  const_iterator lower_bound(const key_type &val) const {
    return const_iterator(_count.lower_bound(val));
  }

  const_iterator upper_bound(const key_type &val) const {
    return const_iterator(_count.upper_bound(val));
  }

  const_reverse_iterator rlower_bound(const key_type &val) const {
    return const_reverse_iterator(upper_bound(val));
  }

  const_reverse_iterator rupper_bound(const key_type &val) const {
    return const_reverse_iterator(lower_bound(val));
  }

  const_iterator max_element() const {
    if (_count.empty()) {
      return end();
    }
    auto tmp = _count.end();
    tmp--;
    return const_iterator(tmp);
  }

  const_iterator min_element() const {
    if (_count.empty()) {
      return end();
    }
    return begin();
  }
};