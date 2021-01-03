//
// Comment is provided in the "ThirdDerivedClass.h" for the overwritten function below
//

#include "ThirdDerivedClass.h"

bool ThirdDerivedClass::filter(string word)
{
    bool wordHasLetter = false;
    bool wordHasPunct = false;

    for (int i = 0; i < word.length(); i++) {
        if (isalpha(word[i])) {
            wordHasLetter = true;
        } else if (ispunct(word[i])) {
            wordHasPunct = true;
        }
    }

    if (wordHasLetter && wordHasPunct) {
        return true;
    }
}