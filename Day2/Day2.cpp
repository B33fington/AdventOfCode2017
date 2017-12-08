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
  int solution = 0;
  for(int row = 0; row < inputMatrix.size(); ++row) {
    int high, low;
    high = low = inputMatrix[row][0];
    for(int column = 1; column < inputMatrix[row].size(); ++column) {
      high = (high < inputMatrix[row][column]) ? inputMatrix[row][column] : high;
      low = (low > inputMatrix[row][column]) ? inputMatrix[row][column] : low;
    }
    solution += (high - low);
  }
  std::cout << solution << std::endl;
}
