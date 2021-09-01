#include <iostream>
#include <string>
#include <sstream>

#define ALPHABET_ENGLISH_LENGTH 26

// [65..90]
const char alphabet_english_upper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
// [97..122]
const char alphabet_english_lower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

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

std::string get_output(int rot, std::string input)
{
    std::string result = "";
    for (int i = 0; i < input.size(); i++)
        result += get_char(rot, input[i]);
    return result;
}

int main(int argc, char const *argv[])
{
    switch (argc)
    {
    case 1:
        {
        int rot;
        std::string input;
        std::cout << "rot >> ";
        std::cin >> rot;
        std::cin.ignore(32767, '\n');
        std::cout << "input >> ";
        getline(std::cin, input);
        std::cout << get_output(rot, input) << '\n';
        break;
        }

    case 2:
        {
        for (int i = 0; i < 26; i++)
            std::cout << "ROT" << i << (i < 10 ? "   " : "  ") << get_output(i, argv[1]) << '\n';
        break;
        }

    case 3:
        {
        int rot;
        std::stringstream ss(argv[1]);
        ss >> rot;
        std::cout << get_output(rot, argv[2]) << '\n';
        break;
        }

    default:
        {
        std::cout << "Invalid number of parameters\nUsage: rot [N] [INPUT] to get ROT-N of input\n       rot [INPUT] to get all ROTs of input\n";
        break;
        }
    }

    return 0;
}