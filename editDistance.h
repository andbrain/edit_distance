#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H
#include <iostream>
#include <algorithm>

namespace ed_classic{
  class editDistance {
  private:
    /* data */
    std::string query;
    std::string data;
    size_t tau;
    int **M;
  public:
    editDistance (std::string query, std::string data, size_t tau);
    ~editDistance ();
    std::string process();
    void initMatrix(int lines, int columns);
    int sigma(const char a, const char b);
  };
}


#endif
