#ifndef BF_BLOOM_FILTER_INTERFACE_H
#define BF_BLOOM_FILTER_INTERFACE_H

#include "hash.h"
#include <stddef.h>

namespace bf {
class BloomFilterInterface {
public:
  BloomFilterInterface(BloomFilterInterface const &) = delete;
  BloomFilterInterface &operator=(BloomFilterInterface const &) = delete;

public:
  BloomFilterInterface() = default;
  BloomFilterInterface(double fp, size_t capacity, size_t seed = 0);
  virtual ~BloomFilterInterface() = default;

  template <typename T> void Insert(T const &);

  template <typename T, typename R> R LookUp(T const &);

  virtual void clear() = 0;
};
} // namespace bf

#endif // BF_BLOOM_FILTER_INTERFACE_H