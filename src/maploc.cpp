#include "maploc.h"

MapLocation::MapLocation(int a, int b) : c('.'), x(a), y(b) {};

MapLocation::MapLocation(char t, int a, int b) : c(t), x(a), y(b) {};

std::pair<int, int> MapLocation::getCoords() {
  return std::make_pair(x, y);
}

char MapLocation::getChar() {
  return c;
}

std::ostream& operator<<(std::ostream& o, MapLocation& m) {
  return o << m.getChar();
}

MapResource::MapResource(char t, int a, int b, unsigned int c) : 
  MapLocation(t, a, b), total(c) {
  current = 0;
};

unsigned int MapResource::getTotal() {
  return total;
}

unsigned int MapResource::getCurrent() {
  return current;
}
