#include <string>
#include <cctype>

std::string transformChar(const char in_char)
{
  /* Function which takes an input character, applies the cipher,
     then adds it to the inputText defined earlier */
  std::string newChar {""};

  if (std::isalpha(in_char)) {
    newChar += std::toupper(in_char);
  }

    // Transliterate digits to English words
  switch (in_char) {
  case '0':
    newChar += "ZERO";
    break;
  case '1':
    newChar += "ONE";
    break;
  case '2':
    newChar += "TWO";
    break;
  case '3':
    newChar += "THREE";
    break;
  case '4':
    newChar += "FOUR";
    break;
  case '5':
    newChar += "FIVE";
    break;
  case '6':
    newChar += "SIX";
    break;
  case '7':
    newChar += "SEVEN";
    break;
  case '8':
    newChar += "EIGHT";
    break;
  case '9':
    newChar += "NINE";
    break;
  }

    // If the character isn't alphabetic or numeric, DONT add it.
    // Our ciphers can only operate on alphabetic characters.
    return newChar;
  }
