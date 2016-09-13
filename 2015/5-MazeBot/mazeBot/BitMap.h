#pragma once
#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <cassert>
#include <bitset>
#include <string>

struct Coordinate {
  int x;
  int y;
};

class BitMap {
public:
  std::bitset<1600>::reference operator()(int x, int y);

  std::bitset<1600>::reference operator()(Coordinate c);

  std::string to_string();

private:
  std::bitset<1600> data;
  static constexpr int MAX_X = 40;
  static constexpr int MAX_Y = 40;

  static constexpr int indexForCoordinates(int x, int y);
};
