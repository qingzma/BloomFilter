#ifndef BF_BLOOM_FILTER_INTERFACE_H
#define BF_BLOOM_FILTER_INTERFACE_H

#include "hash.h"
#include "object.h"
#include <stddef.h>
#include <stdexcept>

namespace bf {
class BloomFilterInterface {
public:
  BloomFilterInterface(BloomFilterInterface const &) = delete;
  BloomFilterInterface &operator=(BloomFilterInterface const &) = delete;

public:
  BloomFilterInterface() = default;
  BloomFilterInterface(double fp, size_t capacity, size_t seed = 0) {
    throw std::runtime_error("constructor method is not implemented.");
  };
  virtual ~BloomFilterInterface() = default;

  void Insert(Object const &);

  template <typename T> T LookUp(Object const &);

  virtual void Clear() = 0;
};
} // namespace bf

#endif // BF_BLOOM_FILTER_INTERFACE_H