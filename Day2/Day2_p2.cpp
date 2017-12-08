#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::vector<int>> getMatrixFromTextfile()
{
  std::vector<std::vector<int>> inputMatrix;
  std::vector<int> inputRow;
  std::string input;
  std::ifstream inputFile ("input.txt");
  if(inputFile.is_open())
  {
    while(getline (inputFile, input))
    {
      inputRow.clear();
      std::stringstream stream(input);
      int n;
      while(stream >> n)
      {
        inputRow.push_back(n);
      }
      inputMatrix.push_back(inputRow);
    }
    inputFile.close();
  }
  return inputMatrix;
}

int main()
{
  std::vector<std::vector<int>> inputMatrix = getMatrixFromTextfile();
  std::cout << "inputMatrix.size: " << inputMatrix.size() << std::endl;
  int solution = 0;
  for(size_t x = 0; x < inputMatrix.size(); x++) {
    std::cout << "inputMatrix.size: " << inputMatrix[x].size() << std::endl;
    std::cout << "X: " << x << std::endl;
    for(size_t y = 0; y < inputMatrix[x].size(); y++) {
      std::cout << "Y: " << y << std::endl;
      for(size_t y2 = 0; y2 < inputMatrix[x].size(); y2++) {
        std::cout << "Y2: " << y2 << std::endl;
        if(inputMatrix[x][y]%inputMatrix[x][y2]==0 && inputMatrix[x][y]!=inputMatrix[x][y2]) {
          std::cout << "We're adding to the solution" << std::endl;
          solution += inputMatrix[x][y]/inputMatrix[x][y2];
        }
      }
    }
  }
  std::cout << "Solution is: " << solution << std::endl;
}
