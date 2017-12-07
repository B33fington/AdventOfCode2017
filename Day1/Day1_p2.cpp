#include <iostream>
#include <string>

int main()
{
  std::string sequence = "/*sequence*/";
  int solution = 0;
  size_t count = 0, sequenceSize = sequence.size();
  while(count < sequenceSize/2){
    if(sequence[count] == sequence[count + sequenceSize/2])
      solution = solution + 2*((int)sequence[count]-48);
    count++;
  };
  std::cout << solution << std::endl;
}
