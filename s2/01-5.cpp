#include <iostream>
#include <string>

enum {
    HEX = 16,
};

int
hex_digit(char hex)
{
    if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    } else if (hex >= '0' && hex <= '9') {
        return hex - '0';
    }
}

int octet_to_dec (std::string hex)
{
    return HEX * hex_digit(hex[0]) + hex_digit(hex[1]);
}

int main()
{

}

