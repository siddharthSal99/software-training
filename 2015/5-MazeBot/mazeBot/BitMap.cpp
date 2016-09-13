#include "BitMap.h"

using namespace std;

bitset<1600>::reference BitMap::operator()(int x, int y) {
  assert(x < MAX_X && x >= 0);
  assert(y < MAX_Y && y >= 0);
  return data[indexForCoordinates(x,y)];
}

bitset<1600>::reference BitMap::operator()(Coordinate c) {
  assert(c.x < MAX_X && c.x >= 0);
  assert(c.y < MAX_Y && c.y >= 0);
  return data[indexForCoordinates(c.x,c.y)];
}

string BitMap::to_string() {
  string s = data.to_string<char,char_traits<char>,allocator<char>>();
  for(int i = BitMap::MAX_X; i < (BitMap::MAX_Y+1) * BitMap::MAX_X; i+=BitMap::MAX_X+2) {
      s.insert(i, "\r\n");
  }
  return s;
}

constexpr int BitMap::indexForCoordinates(int x, int y) {
  return ( y * MAX_X ) + x;
}
