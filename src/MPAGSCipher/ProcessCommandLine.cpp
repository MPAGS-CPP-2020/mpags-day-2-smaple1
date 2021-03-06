#include <iostream>
#include <string>
#include <cctype>
#include <vector>

// Add a typedef that assigns another name for the given type for clarity
typedef std::vector<std::string>::size_type size_type;


bool processCommandLine(const std::vector<std::string>& args,
			bool& helpRequested,
			bool& versionRequested,
			std::string& inputFile,
			std::string& outputFile,
			std::string& cipherKey,
			bool& encrypt)
  
{
  
  const size_type nCmdLineArgs {args.size()};

  // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it
  for (size_type i {1}; i < nCmdLineArgs; ++i) {

    if (args[i] == "-h" || args[i] == "--help") {
      helpRequested = true;
    }
    else if (args[i] == "--version") {
      versionRequested = true;
    }
    else if (args[i] == "-i") {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      if (i == nCmdLineArgs-1) {
	std::cerr << "[error] -i requires a filename argument" << std::endl;
	// exit main with non-zero return to indicate failure
	return 1;
      }
      else {
	// Got filename, so assign value and advance past it
	inputFile = args[i+1];
	++i;
      }
    }
    else if (args[i] == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nCmdLineArgs-1) {
	std::cerr << "[error] -o requires a filename argument" << std::endl;
	// exit main with non-zero return to indicate failure
	return 1;
      }
      else {
	// Got filename, so assign value and advance past it
	outputFile = args[i+1];
	++i;
      }
    }
    else if (args[i] == "-k" || args[i] == "--key") {
      if (i == nCmdLineArgs-1) {
	std::cerr << "[error] key requires an integer argument" << std::endl;
	return 1;
      }
      else {
	cipherKey = args[i+1];
	++i;
      }
    }
    else if (args[i] == "--encrypt") {
      encrypt = true;
    }
    else if (args[i] == "--decrypt") {
      encrypt = false;
    }
    else {
      // Have an unknown flag to output error message and return non-zero
      // exit status to indicate failure
      std::cerr << "[error] unknown argument '" << args[i] << "'\n";
      return 1;
    }
  }
  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    return 0;
  }

  return 0;
}
