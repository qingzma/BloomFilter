#include "../include/counter_array.h"

namespace bf {
template <class T> CounterArray<T>::CounterArray(size_type size) : n_(size) {
  array_ = new T[size];
  std::fill_n(array_, size, 0);
};

template <class T> CounterArray<T>::~CounterArray() { delete[] array_; }

template <class T> T CounterArray<T>::Get(size_type i) const noexcept {
  return array_[i];
}

template <class T>
T CounterArray<T>::GetMin(
    std::initializer_list<size_type> list) const noexcept {
  T res = std::numeric_limits<T>::max();
  for (auto elem : list) {
    res = std::min(res, Get(elem));
  }
  return res;
}

template <class T> void CounterArray<T>::Add(T val, size_type i) noexcept {
  array_[i] += val;
}

template <class T>
void CounterArray<T>::Adds(T val,
                           std::initializer_list<size_type> list) noexcept {
  for (auto i : list) {
    Add(val, i);
  }
}

template <class T> size_type CounterArray<T>::CountNonZeros() const noexcept {
  size_type cnt = 0;
  for (auto &item : array_) {
    if (item)
      cnt++;
  }
  return cnt;
}

template <class T> size_type CounterArray<T>::Overheads() const {
  return sizeof(*array_) * n_;
}

template <class T> std::string CounterArray<T>::To_string() const {
  std::string res = "[";
  for (int i = 0; i < std::min((size_type)50, sizeof(*array_)); i++) {
    res += (std::to_string(array_[i]) + ", ");
  }
  res.pop_back();
  res += "]";
  return res;
}

} // namespace bf
// void TemporaryFunction() { bf::CounterArray<int> TempObj(1); }
