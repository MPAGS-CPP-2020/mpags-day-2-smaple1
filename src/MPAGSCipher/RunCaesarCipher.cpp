#include <iostream>
#include <string>
#include <vector>

std::string runCaesarCipher(const std::string& inputText, const size_t key, const bool encrypt)
{
  const std::vector<char> alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

  std::string outputText {""};
  char newChar {'x'};

  // convert key to value in the range 0 to 25
  const size_t newKey = key % alphabet.size();
  for ( const auto& origChar : inputText )
    {
      for (size_t i{0}; i< alphabet.size(); ++i)
	{
	  if (origChar == alphabet[i])
	    {
	      if (encrypt)
		{
	      newChar = alphabet[(i+newKey) % alphabet.size()];
		}
	      else
		{
		  newChar = alphabet[(i-newKey+alphabet.size()) % alphabet.size()];
		}
	    }
	}
      outputText+=newChar;
    }
  return outputText;
}
