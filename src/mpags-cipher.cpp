// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"








// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> args {argv, argv+argc};
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  processCommandLine(args,
		     helpRequested,
		     versionRequested,
		     inputFile,
		     outputFile);

  while(std::cin >> inputChar)
    {
      inputText+=transformChar(inputChar);
    }
  std::cout << inputText << std::endl;
  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}
