#include <exception>
#include <iostream>
#include <random>
#include <vector>

#include "maploc.h"

class Map {
  private:
    unsigned int size;

    void randomizeResources(
        unsigned int num_stones, 
        unsigned int num_trees,
        unsigned int num_bushes
    );


  public:
    std::vector<std::vector<char>> grid;

    std::vector<std::pair<int, int>> stones;
    std::vector<std::pair<int, int>> trees;
    std::vector<std::pair<int, int>> bushes;

    Map();
    Map(unsigned int size,
        unsigned int num_stones,
        unsigned int num_trees,
        unsigned int num_bushes);

    void placeTownCenter(int x, int y);

};

std::ostream& operator<<(std::ostream& o, Map const& m);
