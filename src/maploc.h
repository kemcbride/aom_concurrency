#include <iostream>

class MapLocation {
  private:
    char c;
    int x;
    int y;


  public:
    MapLocation() = delete;
    MapLocation(int, int);
    MapLocation(char, int, int);

    std::pair<int, int> getCoords();
    char getChar();
};


class MapResource : MapLocation {
  private:
    // Potentially only for subclass "resource"
    unsigned int total;
    unsigned int current;

  public:
    MapResource() = delete;
    MapResource(char, int, int, unsigned int);

    unsigned int getTotal();
    unsigned int getCurrent();
    void decCurrent(unsigned int);
};
