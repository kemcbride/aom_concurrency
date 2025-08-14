
#include <chrono>
#include <iostream>
#include <thread>

#include "map.h"

using namespace std;

void print() {
  std::this_thread::sleep_for(std::chrono::seconds{1});
  cout << "Thread ID: " << std::this_thread::get_id() << '\n';
}

void mapUpdates(Map m) {
  while (true) {
    std::this_thread::sleep_for(std::chrono::seconds{3});
    cout << m << endl;
    cout << "-----------" << endl;
  }
}

int main(int argc, char** argv) {
  cout << "Hello world!" << endl;

  cout << std::this_thread::get_id() << endl;
  cout << std::thread::hardware_concurrency() << endl;

  cout << "creatign new jthread with print() fn" << endl;

  auto joinable_thread = std::jthread{print};

  Map m;
  m.placeTownCenter(0,0);

  auto printthread = std::jthread{mapUpdates, m};

  cout << m << endl;

  return 0;
}
