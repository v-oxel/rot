#include <iostream>
#include <string>
#include <sstream>

#define ALPHABET_ENGLISH_LENGTH 26

const char alphabet_english_upper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
// [65..90]
const char alphabet_english_lower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
// [97..122]

char get_char(int rot, char c)
{
    int ord = c;
    if ((ord >= 65) && (ord <= 90))
    {
        return alphabet_english_upper[(ord - 65 + rot) % ALPHABET_ENGLISH_LENGTH];
    }
    else if ((ord >= 97) && (ord <= 122))
    {
        return alphabet_english_lower[(ord - 97 + rot) % ALPHABET_ENGLISH_LENGTH];
    }
    else
    {
        return c;
    }
}

int main(int argc, char const *argv[])
{
    if ((argc != 1) && (argc != 3))
    {
        std::cout << "Invalid number of parameters \n";
        return -1;
    }

    int rot = 0;
    std::string input;

    if (argc == 1)
    {
        std::cout << "rot >> ";
        std::cin >> rot;
        std::cin.ignore(32767, '\n');
        std::cout << "input >> ";
        getline(std::cin, input);
    }
    else
    {
        std::stringstream ss(argv[1]);
        ss >> rot;
        input = argv[2];
    }

    for (int i = 0; i < input.size(); i++)
        std::cout << get_char(rot, input[i]);
    std::cout << '\n';

    return 0;
}
