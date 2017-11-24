#include<random>
#include<iostream>
#include<limits>
#include<fstream>

int main()
{
  std::ofstream myFile;
  myFile.open("arrInt_100000.txt");
  int imax = std::numeric_limits<int>::max();
  std::cout<<imax<<"\n";
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(-imax,imax); // distribution in range [1, 6]
  int i = 0;
  for (i = 0; i < 100000; i++){
    myFile << dist6(rng)<<",";
  }
  myFile << dist6(rng) << "\n";
  myFile.close();
  return 0;
}
