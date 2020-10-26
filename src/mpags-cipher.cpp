// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "RunCaesarCipher.hpp"

#include <fstream>


// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> args {argv, argv+argc};
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};
  std::string cipherKey {""};
  bool encrypt {true};

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  processCommandLine(args,
		     helpRequested,
		     versionRequested,
		     inputFile,
		     outputFile,
		     cipherKey,
		     encrypt);


  if (!inputFile.empty())
    {
      std::ifstream in_file {inputFile};
      if (in_file.good())
	{
	  while(in_file >> inputChar)
	    {
	      inputText+=transformChar(inputChar);
	    }
	}
    }
  else
    {
      while(std::cin >> inputChar)
	{
	  inputText+=transformChar(inputChar);
	}
    }

  /// Run Caesar Cipher here
  size_t key {0};
  if (!cipherKey.empty())
    {
      key = std::stoul(cipherKey);
      runCaesarCipher(inputText, key, encrypt);
    }




  if (!outputFile.empty())
    {
      std::ofstream out_file {outputFile};
      if (out_file.good())
	{
	  out_file << inputText << std::endl;
	}
    }
  else
    {
      std::cout << inputText << std::endl;
    }

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}
