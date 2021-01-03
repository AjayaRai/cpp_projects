//
// To understand what the function below does, please look at the 'ReadFilteredWords.h'
//
#include "ReadFilteredWords.h"

string ReadFilteredWords::getNextFilteredWord()
{
    /*
     * Please, do not remove the boolean below.
     * If you remove it, then you will see one extra word in the end,
     * which is not accurate to the file you inputted.
     */
    bool boolean;
    string nextWord;

    while (isNextWord())
    {
        boolean = false;
        nextWord = getNextWord();

        if (filter(nextWord))
        {
            return nextWord;
        }
    }

    if (boolean == false)
    {
    return "";
    }
};