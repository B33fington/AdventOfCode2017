#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::vector<int>> parseFile()
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
  std::vector<std::vector<int>> inputMatrix = parseFile();
  return 0;
}
