
using namespace std;
#include "Student.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <list>

/**
 * Displays Students' name, min mark, max mark and their average,
 * CONDITION: Display the ones who have avg mark <= second parameter.
 * Output sorted by the registration number
 */
void firstFunction(vector<Student> vecContainStudObjs, float inputMark)
{
    list<Student> listContainVecEle; // Copy the parameter one elements to the list for sorting
    vector<Student>::iterator vecIt;

    // for copying
    for (vecIt=vecContainStudObjs.begin(); vecIt!=vecContainStudObjs.end(); vecIt++)
    {
        listContainVecEle.push_back(*vecIt);
    }

    listContainVecEle.sort();
    list<Student>::iterator listIt;

    bool studFound = false;

    // for displaying
    for (listIt=listContainVecEle.begin(); listIt!=listContainVecEle.end(); listIt++)
    {
        if (listIt->getAverageMark() <= inputMark)
        {
            studFound = true;
            cout << *listIt;
        }
    }

    if (!studFound)
    {
        cout << "No students are found, who have AVG marks that is <= " << inputMark << endl;
    }
}

/**
 * Displays name and mark for the given module of each student
 * CONDITION: Students who have marks >= third parameter
 */
void secondFunction(vector<Student> vecContainStudObjs, string inModuCode, float inputMark)
{
    bool studFound = false;

    for (int i = 0; i < vecContainStudObjs.size(); i++)
    {
        try
        {
            if (vecContainStudObjs[i].getMark(inModuCode) >= inputMark)
            {
                studFound = true;
                cout << "Name: " << vecContainStudObjs[i].getName() << ", Marks: " << vecContainStudObjs[i].getMark(inModuCode) << endl;
            }
        } catch (NoMarkException e)
        {
            continue;
        }
    }

    if (!studFound)
    {
        cout << "For the Module: " << inModuCode << ", no students are found who have marks >= " << inputMark << endl;
    }
}

int main()
{
    /*
     * Since we are opening two separate text files,
     * there are txtFile_1 and txtFile_2;
     * fileName_1 and fileName_2
     */
    ifstream txtFile_1;
    string fileName_1;

    cout << "Enter the file name: ";
    cin >> fileName_1;

    // TODO: before you run the code, you might need to change the file path relative to where you have saved the text file of "Students" and "Marks"
    string filePath = "C:\\Users\\raiaj\\CLionProjects\\testProject\\";

    txtFile_1.open(filePath + fileName_1.c_str());

    cout << fileName_1 + "\n";

    if (txtFile_1.fail())
    {
        cout << "Sorry file couldn't be Found/Opened." << endl;
        exit(EXIT_SUCCESS);
    }


   /**
    * Read the file, then using it's data create new objects of Students,
    * and then add to the vector "vecContainStudObj"
    *
    * ******************* START ***************************
    */
    string file_1_Line;
    string file_1_word;
    vector<string> vecContainRegnoANDName; // basically, it contains each line in turn
    string fullName;
    vector<Student> vecContainStudObjs;

    while (!txtFile_1.eof())
    {
        getline(txtFile_1, file_1_Line);

        /*
         * PLEASE don't remove the if statement below.
         * If you do, the program will try to read the last line which is empty, then fail.
         * However, you can make it work by removing the last line in the text.
         */
        if (file_1_Line.length() == 0)
        {
            break;
        }

        //Split sentence into words
        for (int i=0; i<file_1_Line.length(); i++)
        {
            if (file_1_Line[i] == ' ')
            {
                vecContainRegnoANDName.push_back(file_1_word);
                file_1_word = "";
            } else
            {
                if (isalnum(file_1_Line[i]))
                {
                    file_1_word += file_1_Line[i];
                }
            }
        }
        vecContainRegnoANDName.push_back(file_1_word);
        file_1_word = "";

        // Since the sentence is split, the first-name and last-name is also split,
        // so we join it.
        fullName = (vecContainRegnoANDName[1] + " " + vecContainRegnoANDName[2]);

        vecContainStudObjs.push_back(Student(fullName,
                stoi(vecContainRegnoANDName[0])));

        fullName = "";
        vecContainRegnoANDName.clear();
    }
    /**
     * ******************* END ***************************
     */
    txtFile_1.close();


    ifstream txtFile_2;
    string fileName_2;

    cout << "Enter the SECOND file name: ";
    cin >> fileName_2;

    txtFile_2.open(filePath + fileName_2.c_str());

    if (txtFile_2.fail())
    {
        cout << "Sorry file couldn't be Found/Opened." << endl;
        exit(EXIT_SUCCESS);
    }


    /**
     * Reads the txtFile_2, and add marks to the each Student Object appropriately by matching the Registration No.
     *
     * **************************************START*********************************************
     */
    string file_2_line;
    string file_2_word;
    vector<string> vecContainRegModMar; // Contains the line in each turn
    vector<Student>::iterator studObjIt;
    bool hasRegInStudObjs = false;
    set<string> moduleSet; // stores all the module code read from "file_2"; no duplicates

    while (!txtFile_2.eof())
    {
        getline(txtFile_2, file_2_line);

        /*
         * Again,
         * PLEASE don't remove the if statement below.
         * If you do, the program will try to read the last line which is empty, then fail.
         * However, you can make it work by removing the last line in the text.
         */
        if (file_2_line.length() == 0)
        {
            break;
        }
        //Split sentence into words
        for (int i=0; i<file_2_line.length(); i++)
        {
            if (file_2_line[i] == ' ') {
                vecContainRegModMar.push_back(file_2_word);
                file_2_word = "";
            } else
            {
                if (file_2_line[i] == '.' || isalnum(file_2_line[i]))
                {
                    file_2_word += file_2_line[i];
                }
            }
        }
        vecContainRegModMar.push_back(file_2_word);
        file_2_word = "";

        // addMark to the student Object, if regNo matches
        for (studObjIt=vecContainStudObjs.begin(); studObjIt!=vecContainStudObjs.end(); studObjIt++)
        {
            if (stoi(vecContainRegModMar[0]) == studObjIt->getRegNo())
            {
                hasRegInStudObjs = true;
                studObjIt->addMark(vecContainRegModMar[1], stof(vecContainRegModMar[2]));
            }
        }

        moduleSet.insert(vecContainRegModMar[1]);

        if (hasRegInStudObjs == false)
        {
            cout << "WARNING: Cannot find regNo '" << (vecContainRegModMar[0]) <<
                 "' in the student object collection"
                 << endl;
        }
        hasRegInStudObjs = false;

        vecContainRegModMar.clear();
    }
    /**
     * **************************************END*********************************************
     */
    txtFile_2.close();


    set<string>::iterator modSetIt;

    // Shows all the details of the students
    printf("\n");
    for (int i=0; i < vecContainStudObjs.size(); i++)
    {
        printf("RegNo: %d, Name: %s\n", vecContainStudObjs[i].getRegNo(), vecContainStudObjs[i].getName().c_str());

        for (modSetIt = moduleSet.begin(); modSetIt != moduleSet.end(); modSetIt++)
        {
            try
            {
                printf("    Module: %s, Marks: %3.1f\n", modSetIt->c_str(), vecContainStudObjs[i].getMark(*modSetIt));
            } catch (NoMarkException e)
            {
                printf("    No mark for %s\n", modSetIt->c_str());
            }
        }
        printf("\n");
    }


    vector<Student>:: iterator allStudsIt;

    cout << "**Showing all the students, including the ones who have NO MARKS**" << endl;
    for (allStudsIt=vecContainStudObjs.begin(); allStudsIt!=vecContainStudObjs.end(); allStudsIt++)
    {
        cout << *allStudsIt;
    }
    cout << endl;


    string userEnter;
    float inputMark;
    string inModuCode;
    bool stopLoop = false;

    while (!stopLoop)
    {
        cout << "Please enter 'f' for testing the first function, 's' for second function or 'q' for quitting: ";
        cin >> userEnter;

        if (userEnter == "f")
        {
            cout << "Enter mark; for finding the students with AVG mark <= given mark: ";
            cin >> inputMark;

            firstFunction(vecContainStudObjs, inputMark);
            cout << endl;
        } else if (userEnter == "s")
        {
            cout << "Enter module name: ";
            cin >> inModuCode;

            cout << "Enter mark; for finding the students with the given module name who have marks >= given mark: ";
            cin >> inputMark;

            secondFunction(vecContainStudObjs, inModuCode, inputMark);
            cout << endl;
        } else if (userEnter == "q")
        {
            stopLoop = true;
        }
    }

    return 0;
}