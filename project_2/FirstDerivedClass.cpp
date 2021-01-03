//
// Comment is provided in the "FirstDerivedClass.h" for the overwritten function below
//

#include "FirstDerivedClass.h"

bool FirstDerivedClass::filter(string word)
{
    bool wordHasUpperCase = false;
    bool wordHasLowerCase = false;

    for (int i=0; i < word.length(); i++)
    {
        if (isupper(word[i]))
        {
            wordHasUpperCase = true;
        } else if (islower(word[i]))
        {
            wordHasLowerCase = true;
        }
    }

    if (wordHasUpperCase && wordHasLowerCase)
    {
        return true;
    }
}