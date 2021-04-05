//
// Author Kinevich T.O. 821703 LOIS lab1
//

#include <string>
#include <iostream>
#include <set>
#include "DNF.h"
#include "Validation.h"

bool CheckDNF(std::string& str) noexcept
{
    if (!Validate(str))
    {
        std::cout << "Validation Failed\n";
        return false;
    }
    if(str.empty()){
        return false;
    }


    std::set<int> conjunction;
    std::set<int> disjunction;

    int left_count = 0, right_count = 0;

    for (auto i : str)
    {
        if (i == '(')
        {
            left_count++;
        }
        if (i == ')')
        {
            right_count++;
        }
        if (i == '&')
        {
            conjunction.insert(left_count - right_count);
        }
        if (i == '|')
        {
            disjunction.insert(left_count - right_count);
        }
    }
    if(left_count < 1 && str.length() > 1){
        return false;
    }
    bool good_disjunction = disjunction.size() <= 1;
    bool good_conjunction = conjunction.size() == 1 && *conjunction.cbegin() > *disjunction.cbegin();
    good_conjunction = good_conjunction ? good_conjunction : conjunction.empty();
    if(disjunction.size() == 1 && conjunction.size() == 0){
        return true;
    }
    if(disjunction.size() == 0 && conjunction.size() == 1){
        return true;
    }
    if (good_conjunction && good_disjunction)
    {
        return true;
    }
    return false;
}
