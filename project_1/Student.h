
#ifndef _STUDENT_H_
#define _STUDENT_H_

using namespace std;
#include "Person.h"
#include <string>
#include <map>
#include <stdexcept>

class NoMarkException: public exception
{
    public:

        /**
         * Can be called within 'try' block if NoMarkException is thrown
         */
        const char *message()
        {
            return "'has no marks'";
        }

};

class Student: public Person
{
    public:
        // constructor should initialise name and registration number using arguments
        // and initialise marks map to be empty
        Student(const string &name, int regNo);

        // method to return registration number
        int getRegNo() const;

        // method to add the mark to the map
        // if a mark for the module is already present it should be overwritten
        void addMark(const string& module, float mark);

        // method to retrieve the mark for a module
        // should throw NoMarkException if student has no mark for that module
        float getMark(const string &module) const throw (NoMarkException);

        /**
         * With a given student, adds all the marks and divides by the number of mark(s)
         * @return - average mark of a student
         */
        float getAverageMark() const;

        /**
         * @return - Minimum mark of a given student
         */
        float getMinimumMark() const;

        /**
         * @return - Maximum mark of a given student
         */
        float getMaximumMark() const;

        /**
         * Compares the registration Numbers to sort the list of Student Object
         * Sorted by registration number
         */
        bool operator<(const Student &s);

    private:
        int regNo;
        map<string, float> marks;  // keys are modules, values are marks in range 0.0 to 100.0

        // friend function to output details of student to stream
        // should output name, regno, and minimum, maximum and average marks on a single line
        // if the student has no marks "has no marks" should be output instead of the marks
        friend ostream& operator<<(ostream &str, const Student &s);

};

#endif
