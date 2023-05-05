#ifndef BF_BLOOM_FILTER_H
#define BF_BLOOM_FILTER_H

#include "bloom_filter_interface.h"

namespace bf {
class BloomFilter : public BloomFilterInterface {
public:
  BloomFilter(double fp, size_t capacity, size_t seed = 0);

  void Insert(Object const &);
};
} // namespace bf

#endif // BF_BLOOM_FILTER_H