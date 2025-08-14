#include "map.h"

constexpr char STONE = 'o';
constexpr char TREE = 'I';
constexpr char BUSH = 'm';

Map::Map() {
  size = 50;

  grid.resize(size);
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      grid.at(i) = std::vector<char>(size, '.');
    }
  }

  placeTownCenter(0, 0);
  randomizeResources(10, 10, 10);
}

void Map::randomizeResources(
    unsigned int num_stones,
    unsigned int num_trees,
    unsigned int num_bushes) {
  std::random_device rd;
  std::mt19937 eng(rd());

  std::uniform_int_distribution<> distr(0, 49);

  for (int i = 0; i < num_stones; ++i) {
    auto p = std::make_pair(distr(eng), distr(eng));

    while (grid.at(p.second).at(p.first) != '.') {
      p = std::make_pair(distr(eng), distr(eng));
    }

    grid.at(p.second).at(p.first) = STONE;
  }

  for (int i = 0; i < num_trees; ++i) {
    auto p = std::make_pair(distr(eng), distr(eng));

    while (grid.at(p.second).at(p.first) != '.') {
      p = std::make_pair(distr(eng), distr(eng));
    }

    grid.at(p.second).at(p.first) = TREE;
  }

  for (int i = 0; i < num_bushes; ++i) {
    auto p = std::make_pair(distr(eng), distr(eng));

    while (grid.at(p.second).at(p.first) != '.') {
      p = std::make_pair(distr(eng), distr(eng));
    }

    grid.at(p.second).at(p.first) = BUSH;
  }
}

void Map::placeTownCenter(int x, int y) {
  // A town center takes up 4 squares incl. its origin, like so:
  //   .....
  //   ..T..
  //   .TtT.
  //   .....

  int normalizedXOrigin = size / 2 + x;
  int normalizedYOrigin = size / 2 + y;

  // basic validations:
  // Since this supports only one orientation, we can't do it if:
  if (normalizedXOrigin <= 0 || normalizedXOrigin >= size-1) {
    std::string msg = "Town Center location " + std::to_string(x) + ", ";
      msg += std::to_string(y) + " is invalid -- too close to edge on X value";
    throw std::runtime_error(msg);
  }
  if (normalizedYOrigin <= 0 || normalizedYOrigin >= size-1) {
    std::string msg = "Town Center location " + std::to_string(x) + ", ";
      msg += std::to_string(y) + " is invalid -- too close to edge on Y value";
    throw std::runtime_error(msg);
  }

  auto& row = grid.at(normalizedYOrigin);
  row.at(normalizedXOrigin - 1) = 'T';
  row.at(normalizedXOrigin) = 't';
  row.at(normalizedXOrigin + 1) = 'T';
  auto& rowAbove = grid.at(normalizedYOrigin - 1);
  rowAbove.at(normalizedXOrigin) = 'T';

}

std::ostream& operator<<(std::ostream& o, Map const& m) {
  for (auto v : m.grid) {
    for (auto c : v) {
      o << c << " ";
    }
    o << "\n";
  }
  return o;
}
