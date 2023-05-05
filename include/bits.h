#ifndef BF_BITS_H
#define BF_BITS_H

#include <limits>
#include <stddef.h>

namespace bf {
class Bits {
private:
  typedef size_t page_type;
  typedef size_t size_type;
  static page_type constexpr n_bits_per_page =
      std::numeric_limits<page_type>::digits;
  static size_type constexpr npos = static_cast<size_type>(-1);
};

} // namespace bf

#endif // BF_BITS_H