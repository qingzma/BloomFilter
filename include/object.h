#ifndef BF_OBJECT_H
#define BF_OBJECT_H

#include <stddef.h>

namespace bf {
class Object {
private:
  void const *data_ = nullptr;
  size_t size_ = 0;

public:
  Object(void const *data, size_t size) : data_(data), size_(size) {}

  void const *data() const { return data_; }

  size_t size() const { return size_; }
};
} // namespace bf

#endif // BF_OBJECT_H