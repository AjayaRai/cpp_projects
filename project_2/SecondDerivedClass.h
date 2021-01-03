
#ifndef ASSIGNMENT_2_EXE2_SECDERIVEDC_H
#define ASSIGNMENT_2_EXE2_SECDERIVEDC_H

#include "ReadFilteredWords.h"

class SecondDerivedClass: public ReadFilteredWords
{
    public:
        SecondDerivedClass(const char *fname): ReadFilteredWords(fname)
        {}

        /**
         * @return - true - if its argument contains two or more adjacent digits
         */
        bool filter(string word);
};

#endif //ASSIGNMENT_2_EXE2_SECDERIVEDC_H
