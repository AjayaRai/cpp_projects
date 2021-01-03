
#ifndef ASSIGNMENT_2_EXE2_THIRDDERIVEDC_H
#define ASSIGNMENT_2_EXE2_THIRDDERIVEDC_H

#include "ReadFilteredWords.h"

class ThirdDerivedClass: public ReadFilteredWords
{
    public:
        ThirdDerivedClass(const char *fname): ReadFilteredWords(fname)
        {}

        /**
         * @return - true - if its argument has at lease one letter and one punctuation
         */
        bool filter(string word);
};

#endif //ASSIGNMENT_2_EXE2_THIRDDERIVEDC_H
