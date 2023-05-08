#include "../include/bit_array.h"

bf::BitArray::BitArray(size_type size, bool value) {
  n_pages = bit_index(size) == 0 ? page_index(size) : page_index(size) + 1;
  n_bits_ = n_pages * n_bits_per_page;
  bits_ = new page_type[n_pages];
  // set the array to zero
  memset(bits_, 0, n_pages * sizeof(*bits_));
}

bf::BitArray::~BitArray() { delete[] bits_; }

bool bf::BitArray::Get(size_type i) const {
  assert(i < n_bits_);
  return bits_[page_index(i)] & bit_mask(i);
}

void bf::BitArray::Set(size_type i) {
  assert(i < n_bits_);
  bits_[page_index(i)] |= bit_mask(i);
}

bf::BitArray::size_type bf::BitArray::CountOnes() const {
  size_type cnt = 0;
  for (int i = 0; i < n_pages; i++)
    cnt += std::bitset<n_bits_per_page>(bits_[i]).count();
  return cnt;
};

bf::BitArray::size_type bf::BitArray::Overheads() const {
  return sizeof(*bits_) * n_pages;
}