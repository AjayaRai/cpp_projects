//
// To understand what each functions below does,
// please look at the 'Student.h' comments.
//

#include "Student.h"
#include <iostream>


Student::Student(const string& name, int regNo):Person(name)
{
    this->regNo = regNo;
    this->marks; // initialising the map
}

int Student::getRegNo() const
{
    return regNo;
}

void Student::addMark(const string& module, float mark)
{
    marks[module] = mark;
}

float Student::getMark(const string &module) const throw (NoMarkException)
{
    // need the iterator because "marks[module]" is a non-constant
    map<string, float>::const_iterator it = marks.find(module);

    if (it == marks.end())
    {
        cout << "\r";
        throw NoMarkException();
    } else
    {
        return it->second;
    }
}

float Student::getAverageMark() const
{
    map<string, float>::const_iterator it;

    float totalMarks;
    float markCounts=0;

    for (it=marks.begin(); it!=marks.end(); it++)
    {
        totalMarks += it->second;
        markCounts++;
    }

    return totalMarks/markCounts;
}

float Student::getMinimumMark()const
{
    //Starts with max mark+1, but will decrease after the comparison below
    float minMark = 101;

    map<string, float>::const_iterator it;

    for (it=marks.begin(); it!=marks.end(); it++)
    {
        if (it->second < minMark)
        {
            minMark = it->second;
        }
    }

    return minMark;
}

/**
 * Code below is opposite to the above function
 */
float Student::getMaximumMark() const
{
    float maxMark = -1;

    map<string, float>::const_iterator it;

    for (it=marks.begin(); it!=marks.end(); it++)
    {
        if (it->second > maxMark)
        {
            maxMark = it->second;
        }
    }

    return maxMark;
}

bool Student::operator<(const Student &s)
{
    return (regNo < s.regNo);
}

/**
 * If 'marks' map is not empty, it will output all the Marks, e.g. min, mark, avg
 * If empty, it will output 'has no marks'
 */
ostream& operator<<(ostream &str, const Student &s)
{
    try
    {
        if (s.marks.empty())
        {
            throw NoMarkException();
        }

        str << "Name: " << s.name << ", Reg No: " << s.regNo
            << ", Min Mark: " << s.getMinimumMark() << ", Max Mark: " << s.getMaximumMark()
                << ", AVG mark: " << s.getAverageMark() << endl;

        return str;
    } catch(NoMarkException e)
    {
        str << "Name: " << s.name << ", Reg No: " << s.regNo << ", "<< e.message() << endl;
        return  str;
    }
}