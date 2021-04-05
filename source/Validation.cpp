#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-use-anyofallof"
//
// Author Kinevich T.O. 821703 LOIS lab1
//
#include <string>
#include <iostream>
#include "Validation.h"

const char alphabet[] = {'Q', 'W', 'E','R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J',
                         'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '1', '0'};

enum SYMB
{
    AND = '&',
    OR = '|',
    NEGAT = '!',
    LEFT_BRACE = '(',
    RIGHT_BRACE = ')',
    SPACE = ' '
};

bool checkAndOr(char prev) noexcept;
bool checkNegat(char prev) noexcept;
bool checkLeftBrace(char prev) noexcept;
bool checkRightBrace(char prev) noexcept;
bool checkLetter(char prev) noexcept;
bool swapAndOr(std::string&) noexcept;

bool Validate( std::string& str) noexcept
{
    int left = 0, right = 0;
    char prev = '(';
    if(!swapAndOr(str)){
        return false;
    }

    for (auto ch : str)
    {
        switch (ch)
        {
            case AND:
            case OR:
            {
                if (!checkAndOr(prev))
                    return false;
                break;
            }

            case NEGAT:
            {
                if (!checkNegat(prev))
                    return false;
                break;
            }

            case LEFT_BRACE:
            {
                if (!checkLeftBrace(prev))
                    return false;
                left++;
                break;
            }

            case RIGHT_BRACE:
            {
                if (!checkRightBrace(prev))
                    return false;
                right++;
                break;
            }

            case SPACE:
            {
                ch = prev;
                break;
            }

            default: {
                bool miss_literal = true;
                for (auto temp : alphabet) {
                    if (ch == temp) {
                        if (!checkLetter(prev)) {
                            return false;
                        } else {
                            miss_literal = false;
                        }
                    }
                }
                if (miss_literal)
                {
                    std::cout << "literal not found\n";
                    return false;
                }
                break;
            }
        }

        prev = ch;
    }

    return left == right;
}

bool checkAndOr(char prev) noexcept
{
    if (prev == RIGHT_BRACE)
    {
        return true;
    }
    for (auto ch : alphabet)
    {
        if (ch == prev) return true;
    }
    return false;
}

bool checkNegat(char prev)noexcept
{
    if (prev == AND ||
        prev == OR ||
        prev == LEFT_BRACE)
    {
        return true;// Author Kinevich T.O. 821703
    }
    return false;
}

bool checkLeftBrace(char prev)noexcept
{
    if (prev == AND ||
        prev == OR ||
        prev == LEFT_BRACE)
    {
        return true;
    }
    return false;
}

bool checkRightBrace(char prev)noexcept
{
    if (prev == RIGHT_BRACE)
    {
        return true;
    }
    for (auto ch : alphabet)
    {
        if (ch == prev)
        {
            return true;
        }
    }
    return false;
}

bool checkLetter(char prev) noexcept
{
    if (prev == AND ||
        prev == OR ||
        prev == LEFT_BRACE ||
        prev == NEGAT)
    {
        return true;
    }
    return false;
}

bool swapAndOr(std::string& str) noexcept
{
    for(int i = 0;i < str.size();i++){
        if(str[i] == '&' || str[i] == '|'){
            return false;
        }
        if (str[i] == '/' && str[i + 1] == '\\'){
            str[i] = '&';
            str.erase(str.begin() + i + 1);
            continue;
        }
        if (str[i] == '\\' && str[i + 1] == '/'){
            str[i] = '|';
            str.erase(str.begin() + i + 1);
            continue;
        }
    }
    return true;
}
