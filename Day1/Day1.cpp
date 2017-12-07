#include <iostream>
#include <string>

int main()
{
  std::string sequence = "/*sequence*/";
  int solution = 0;
  size_t count = 1;
  while(count != sequence.size()){
    if(sequence[count] == sequence[count-1])
      solution += ((int)sequence[count]-48);
    count++;
  };
  if(sequence[sequence.size()-1] == sequence[0])
    solution += ((int)sequence[0]-48);
  std::cout << solution << std::endl;
}
