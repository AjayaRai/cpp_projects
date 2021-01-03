//
// Comment is provided in the "SecondDerivedClass.h" for the overwritten function below
//

#include "SecondDerivedClass.h"

bool SecondDerivedClass::filter(string word)
{
    bool foundAdjacentDig = false;

    for (int i = 0; i < word.length(); i++)
    {
        if (isdigit(word[i]) && isdigit(word[i + 1]))
        {
            foundAdjacentDig = true;
        }
    }

    if (foundAdjacentDig)
    {
        return true;
    }
}