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
  CounterArray(size_type size);

  ~CounterArray();

  void Add(T val, size_type i) noexcept;

  void Adds(T val, std::initializer_list<size_type> list) noexcept;

  T Get(size_type i) const noexcept;

  T GetMin(std::initializer_list<size_type> list) const noexcept;

  size_type CountNonZeros() const noexcept;

  /**
   * @brief get the size of this bitmap
   *
   * @return size_type size in bytes.
   */
  size_type Overheads() const;

public:
  /**
   * @brief currently, only display the first page
   *
   * @return std::string
   */
  std::string To_string() const;

  // void Clear() noexcept;
};

} // namespace bf

#endif // BF_COUNTER_ARRAY_H