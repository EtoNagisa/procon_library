#include "bits/stdc++.h"

template <typename Kt, class Ct = std::less<Kt>> class muitiset {
public:
  using value_type = Kt;
  using compare_type = Ct;

private:
  using _map = std::map<value_type, size_t, compare_type>;
  _map _count;

  struct _const_iterator {
  private:
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
    using value_type = muitiset::value_type;
    using difference_type = std::ptrdiff_t;
    using pointer = const muitiset::value_type *;
    using reference = const muitiset::value_type &;

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

public:
  using const_iterator = _const_iterator;
  using const_reverse_iterator = std::reverse_iterator<_const_iterator>;

  const_iterator begin() const {
    return _const_iterator(_count.begin());
  }

  const_iterator end() const {
    return _const_iterator(_count.end());
  }

  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(end());
  }

  const_reverse_iterator rend() const {
    return const_reverse_iterator(begin());
  }

  size_t count(const value_type &val) const noexcept {
    _count.count(val) == 1 ? _count[val] : 0;
  }

  void insert(const value_type &val) noexcept {
    _count[val]++;
  }

  void erase(const value_type &val) noexcept {
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
  
  bool empty() const noexcept {
    return _count.empty();
  }

  const_iterator lower_bound(const value_type &val) const {
    return _const_iterator(_count.lower_bound(val));
  }

  const_iterator upper_bound(const value_type &val) const {
    return _const_iterator(_count.upper_bound(val));
  }

  const_reverse_iterator rlower_bound(const value_type &val) const {
    return const_reverse_iterator(upper_bound(val));
  }

  const_reverse_iterator rupper_bound(const value_type &val) const {
    return const_reverse_iterator(lower_bound(val));
  }

  const_iterator max_element() const {
    if (_count.empty()) {
      return end();
    }
    auto tmp = _count.end();
    tmp--;
    return _const_iterator(tmp);
  }

  const_iterator min_element() const {
    if (_count.empty()) {
      return end();
    }
    return begin();
  }
};