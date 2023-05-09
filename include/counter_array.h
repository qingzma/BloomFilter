#ifndef BF_COUNTER_ARRAY_H
#define BF_COUNTER_ARRAY_H

#include <cassert>
#include <initializer_list>
#include <limits>
#include <memory.h>

#include "types.h"
#include <algorithm>
#include <string>

namespace bf {
template <class T> class CounterArray {
public:
  static page_type constexpr n_bits_per_page = std::numeric_limits<T>::digits;
  // static size_type constexpr npos = static_cast<size_type>(-1);

public:
  T *array_;
  size_type n_;

public:
  CounterArray(size_type size) : n_(size) {
    array_ = new T[size];
    std::fill_n(array_, size, 0);
  };

  ~CounterArray() { delete[] array_; };

  void Add(T val, size_type i) noexcept {
    assert(i < n_);
    array_[i] += val;
  };

  void Adds(T val, std::initializer_list<size_type> list) noexcept {
    for (auto i : list) {
      Add(val, i);
    };
  }

  T Get(size_type i) const noexcept { return array_[i]; };

  T GetMin(std::initializer_list<size_type> list) const noexcept {
    T res = std::numeric_limits<T>::max();
    for (auto elem : list) {
      res = std::min(res, Get(elem));
    }
    return res;
  };

  size_type CountNonZeros() const noexcept {
    size_type cnt = 0;
    for (auto &item : array_) {
      if (item)
        cnt++;
    }
    return cnt;
  };

  /**
   * @brief get the size of this bitmap
   *
   * @return size_type size in bytes.
   */
  size_type Overheads() const { return sizeof(*array_) * n_; };

public:
  /**
   * @brief currently, only display the first page
   *
   * @return std::string
   */
  std::string To_string() const {
    std::string res = "[";
    for (int i = 0; i < std::min((size_type)50, n_); i++) {
      res += (std::to_string(array_[i]) + ", ");
    }
    res.pop_back();
    res += "]";
    return res;
  };

  // void Clear() noexcept;
};

} // namespace bf

#endif // BF_COUNTER_ARRAY_H