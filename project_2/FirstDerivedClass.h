
#ifndef ASSIGNMENT_2_EXE2_FIRSTDERIVEDC_H
#define ASSIGNMENT_2_EXE2_FIRSTDERIVEDC_H

#include "ReadFilteredWords.h"

class FirstDerivedClass: public ReadFilteredWords
{
    public:
        FirstDerivedClass(const char *fname): ReadFilteredWords(fname)
        {}

        /**
         * @return - true - if its argument is at lease one UPPERCASE and one lowercase letter
         */
        bool filter(string word);
};

#endif //ASSIGNMENT_2_EXE2_FIRSTDERIVEDC_H
