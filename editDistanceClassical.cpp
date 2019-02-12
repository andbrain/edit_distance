#include "editDistance.h"

ed_classic::editDistance::editDistance(std::string query, std::string data, size_t tau)
{
  std::cout << "Creating.." << '\n';
  this->query = query;
  this->data = data;
  this->tau = tau;
  initMatrix(query.length()+1, data.length()+1);

  std::cout << "edit distance method.." << '\n';
}

ed_classic::editDistance::~editDistance()
{
  std::cout << "Deleting edit distance method.." << '\n';

  for (size_t i = 0; i < this->query.length(); ++i)
    delete [] this->M[i];
  delete [] this->M;
}

std::string ed_classic::editDistance::process()
{
  std::cout << "Query: " << this->query << '\n';
  std::cout << "Data: " << this->data << '\n';

  int lowerBound = -tau;
  int higherBound = tau;

  for(size_t i=0; i < this->query.length() + 1; i++)
  // for(size_t i=0; i < 2; i++)
  {
    for(size_t j=0; j < this->data.length() + 1; j++)
    {
      if(i == 0)
      {
        // if(j <= tau)
          M[i][j] = j;
      }
      else if(j == 0)
      {
        // if(i <= tau)
          M[i][j] = i;
      }
      else
      {
        // int k = j-i;

        // if((k >= lowerBound) && (k <= higherBound))
        // {
          M[i][j] = std::min({M[i-1][j-1] + sigma(this->query[i-1], this->data[j-1]), M[i-1][j] + 1, M[i][j-1] + 1});
        // }

      }
      std::cout << M[i][j] << " ";

    }
    std::cout << '\n';
  }

  return "Returned distance";
}

void ed_classic::editDistance::initMatrix(int lines, int columns)
{

  this->M = new int*[lines];

  for(int i=0; i < lines ; i++)
  {
    M[i] = new int[columns];
  }

  std::cout << "Matrix create with " << lines << " x " << columns << '\n';
}

int ed_classic::editDistance::sigma(const char a, const char b)
{
  if(a == b)
    return 0;

  return 1;
}
