#ifndef BF_BITS_H
#define BF_BITS_H

#include <bitset>
#include <cassert>
#include <limits>
#include <memory.h>
#include <stddef.h>
#include <string>
#include <vector>

namespace bf {
class BitArray {
public:
  typedef size_t page_type;
  typedef size_t size_type;
  static page_type constexpr n_bits_per_page =
      std::numeric_limits<page_type>::digits;
  // static size_type constexpr npos = static_cast<size_type>(-1);

public:
  page_type *bits_;
  size_type n_bits_;
  size_type n_pages;

public:
  BitArray(size_type size, bool value);

  ~BitArray();

  void Set(size_type i);

  bool Get(size_type i) const;

  size_type CountOnes() const;

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

public:
  static size_type constexpr page_index(size_type i) {
    return i / n_bits_per_page;
  }

  /**
   * @brief get the bit index within a page
   *
   * @param i the index of the input
   * @return uint8_t constexpr the location of the input within the bit array.
   */
  static uint8_t constexpr bit_index(size_type i) {
    return static_cast<uint8_t>(i % n_bits_per_page);
  }

  // /**
  //  * @brief
  //  *
  //  * @param bits
  //  * @return size_type constexpr
  //  */
  // static size_type constexpr n_pages(size_type bits) {

  //   return bit_index(bits) == 0 ? page_index(bits) : page_index(bits) + 1;
  // }

  static page_type constexpr bit_mask(size_type i) {
    return page_type(1) << bit_index(i);
  }
};

} // namespace bf

#endif // BF_BITS_H