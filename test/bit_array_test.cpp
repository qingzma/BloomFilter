#include "../include/bit_array.h"
#include <chrono>
#include <gtest/gtest.h>
#include <iostream>
TEST(BitPageSizeTest, BasicAssertions) {
  bf::BitArray bitArray(100, true);
  // EXPECT_TRUE(bits.n_bits_per_page);
  // EXPECT_EQ(-1, bits.npos);

  std::cout << "size of bits is" << bitArray.n_bits_per_page << std::endl;
  // std::cout << "position of bits is" << bitArray.npos << std::endl;
};

TEST(BitPageMaskTest, BasicAssertions) {
  bf::BitArray bitArray(100, true);
  // EXPECT_TRUE(bits.n_bits_per_page);
  // EXPECT_EQ(-1, bits.npos);

  bf::BitArray::page_type mask = bitArray.bit_mask(0);
  EXPECT_EQ(mask, 1);
  // std::cout << std::bitset<64>(mask) << std::endl;
  mask = bitArray.bit_mask(1);
  EXPECT_EQ(mask, 2);
  // std::cout << std::bitset<64>(mask) << std::endl;
  mask = bitArray.bit_mask(2);
  EXPECT_EQ(mask, 4);
  // std::cout << std::bitset<64>(mask) << std::endl;
  mask = bitArray.bit_mask(10);
  EXPECT_EQ(mask, 1024);
  // std::cout << std::bitset<64>(mask) << std::endl;
  mask = bitArray.bit_mask(20);
  EXPECT_EQ(mask, 1048576);
  // std::cout << std::bitset<64>(mask) << std::endl;
  mask = bitArray.bit_mask(63);
  // std::cout << std::bitset<64>(mask) << std::endl;
  mask = bitArray.bit_mask(64);
  // std::cout << std::bitset<64>(mask) << std::endl;
};

TEST(BitSetGetTest, BasicAssertions) {
  bf::BitArray bitArray(100, true);
  EXPECT_EQ(2, bitArray.n_pages);
  EXPECT_EQ(0, bitArray.CountOnes());
  // std::cout << std::bitset<64>(bitArray.bits_[0]) << std::endl;
  // std::cout << std::bitset<64>(bitArray.bits_[1]) << std::endl;

  bitArray.Set(0);
  EXPECT_EQ(bitArray.bits_[0], 1);
  EXPECT_EQ(bitArray.bits_[1], 0);
  EXPECT_EQ(1, bitArray.CountOnes());
  // std::cout << std::bitset<64>(bitArray.bits_[0]) << std::endl;
  // std::cout << std::bitset<64>(bitArray.bits_[1]) << std::endl;

  bitArray.Set(1);
  EXPECT_EQ(bitArray.bits_[0], 3);
  EXPECT_EQ(bitArray.bits_[1], 0);
  // std::cout << std::bitset<64>(bitArray.bits_[0]) << std::endl;
  // std::cout << std::bitset<64>(bitArray.bits_[1]) << std::endl;

  bitArray.Set(63);
  EXPECT_EQ(bitArray.bits_[0], bf::BitArray::bit_mask(63) + 3);
  EXPECT_EQ(bitArray.bits_[1], 0);
  // std::cout << std::bitset<64>(bitArray.bits_[0]) << std::endl;
  // std::cout << std::bitset<64>(bitArray.bits_[1]) << std::endl;

  bitArray.Set(64);
  // std::cout << std::bitset<64>(bitArray.bits_[0]) << std::endl;
  // std::cout << std::bitset<64>(bitArray.bits_[1]) << std::endl;
  EXPECT_EQ(bitArray.bits_[0], bf::BitArray::bit_mask(63) + 3);
  EXPECT_EQ(bitArray.bits_[1], 1);

  bitArray.Set(127);
  // std::cout << std::bitset<64>(bitArray.bits_[0]) << std::endl;
  // std::cout << std::bitset<64>(bitArray.bits_[1]) << std::endl;
  EXPECT_EQ(bitArray.bits_[0], bf::BitArray::bit_mask(63) + 3);
  EXPECT_EQ(bitArray.bits_[1], bf::BitArray::bit_mask(63) + 1);

  EXPECT_EQ(5, bitArray.CountOnes());

  // bitArray.Set(128);
  // std::cout << std::bitset<64>(bitArray.bits_[0]) << std::endl;
  // std::cout << std::bitset<64>(bitArray.bits_[1]) << std::endl;

  EXPECT_TRUE(bitArray.Get(0));
  EXPECT_TRUE(bitArray.Get(1));
  EXPECT_TRUE(bitArray.Get(63));
  EXPECT_TRUE(bitArray.Get(64));
  EXPECT_TRUE(bitArray.Get(127));

  EXPECT_FALSE(bitArray.Get(2));
  EXPECT_FALSE(bitArray.Get(3));
  EXPECT_FALSE(bitArray.Get(62));
  EXPECT_FALSE(bitArray.Get(65));
  EXPECT_FALSE(bitArray.Get(126));
};

TEST(benchThroughputTest, BasicAssertions) {
  double cn = 1e8;
  bf::BitArray bitArray(8000, true);
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < cn; i++)
    bitArray.Set(i % 8000);
  auto stop = std::chrono::high_resolution_clock::now();

  auto seconds =
      std::chrono::duration_cast<std::chrono::microseconds>(stop - start)
          .count();
  std::cout << "throuput for Set is " << (1.0 * cn / seconds) * 1e6 / 1e9
            << " G items/second " << std::endl;

  // for getter
  start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < cn; i++)
    bitArray.Get(i % 8000);
  stop = std::chrono::high_resolution_clock::now();
  seconds = std::chrono::duration_cast<std::chrono::microseconds>(stop - start)
                .count();
  std::cout << "throuput for Get is " << (1.0 * cn / seconds) * 1e6 / 1e9
            << " G items/second " << std::endl;
};

TEST(overheadsTest, BasicAssertions) {
  bf::BitArray bitArray(1, true);
  EXPECT_EQ(bitArray.Overheads(), 8);
}