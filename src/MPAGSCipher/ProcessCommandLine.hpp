#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

bool processCommandLine(const std::vector<std::string>& args,
			bool& helpRequested,
			bool& versionRequested,
			std::string& inputFile,
			std::string& outputFile,
			std::string& key,
			bool& encrypt);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
