#include <iostream>
#include <string>
#include <vector>

std::string runCaesarCipher(const std::string& inputText, const size_t key, const bool encrypt)
{
  const std::vector<char> alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

  // convert key to value in the range 0 to 25
  const size_t newKey = key % alphabet.size();
  if (encrypt)
    {
      std::cout << "I am encrypting with key " << newKey << std::endl;
    }
  return inputText;
}
