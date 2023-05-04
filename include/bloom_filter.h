#ifndef BF_BLOOM_FILTER_H
#define BF_BLOOM_FILTER_H

namespace bf {
class BloomFilterInterface {
public:
  BloomFilterInterface(BloomFilterInterface const &) = delete;
  BloomFilterInterface &operator=(BloomFilterInterface const &) = delete;

public:
  BloomFilterInterface() = default;
  virtual ~BloomFilterInterface() = default;

  template <typename T> void Insert(T const &);
};
} // namespace bf

#endif // BF_BLOOM_FILTER_H