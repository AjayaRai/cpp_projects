
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include <set>

#include "FirstDerivedClass.h"
#include "SecondDerivedClass.h"
#include "ThirdDerivedClass.h"

using namespace std;

int main() {
    string fileName;
    string selectDerivedClass;


    cout << "Please enter file name: ";
    cin >> fileName;

    cout << endl;
    cout << "Now, in order to select the first, second or third derived classes, " << endl
        << "ENTER '1', '2' or '3': ";
    cin >> selectDerivedClass;

    // TODO have to change this different computers, as the path to the text file would be different on each devices
    string filePath = "C:\\Users\\raiaj\\Documents\\University of Essex CS 10_7_18\\Year 2\\CE221-C++\\Assignments\\Assignment_2\\ex2testfiles\\";

    fileName = filePath + fileName.c_str();

    ReadFilteredWords *readFilteredWords;
    FirstDerivedClass firstDerivedClass(fileName.c_str());
    SecondDerivedClass secDerivedClass(fileName.c_str());
    ThirdDerivedClass thirdDerivedClass(fileName.c_str());

    // making use of the abstract class and the virtual function "filter"
    string str = selectDerivedClass.c_str();

    if (str.compare("1") == 0)
    {
        readFilteredWords = &firstDerivedClass;
    } else if (str.compare("2") == 0)
    {
        readFilteredWords = &secDerivedClass;
    } else if (str.compare("3") == 0)
    {
        readFilteredWords = &thirdDerivedClass;
    }


    map<string, int> filteredWordsANDoccurrence;
    int totalOccOfFiltWords; // Includes the duplicate words

    string conditionStr = "START";// for making sure that the while loop starts at the beginning

    while (conditionStr != "")
    {
        string filteredWord = readFilteredWords->getNextFilteredWord();
        conditionStr = filteredWord;

        if (conditionStr == "")
        {
            continue;
        } else
        {
            filteredWordsANDoccurrence[filteredWord] += 1;
            totalOccOfFiltWords += 1;
        }
    }
    readFilteredWords->close();

    cout << endl;
    cout << "The total number of occurrence of the filtered words is '" << totalOccOfFiltWords << "'" << endl;
    cout << "Number of distinct filtered words/map entries is '" << filteredWordsANDoccurrence.size() << "'" << endl;


    /**
     * Display three most occurrence words
     *
     * ********************************START*****************************************
     */
    set<int> wordOccSet; // Gets only the occurrence of the words from the "filteredWordsAndoccurrence" and stores it

    map<string, int>::iterator it;
    for (it = filteredWordsANDoccurrence.begin(); it != filteredWordsANDoccurrence.end(); it++)
    {
        wordOccSet.insert(it->second);
    }

    vector<int> wordOccDescendVec; // Collection of the occurrence in descending order
    set<int>::const_iterator itSet = wordOccSet.end();
    // Since list is sorted in default (ascending), loop reverse to get the descending order
    while(itSet != wordOccSet.begin())
    {
        itSet--;
        wordOccDescendVec.push_back(*itSet);
    }

    map<string, int> mostFreqWord;
    map<string, int> secMostFreqWord;
    map<string, int> thirdMostFreqWord;
    /*
     * I know that the below for loop is similar to the above one.
     * However, we need another one here because we can now check the 'wordOccDescendVec'.
     * E.g. 'wordOccDescendVec[0]' will have occurence of a word/s with the highest occurence
     */
    map<string, int>::iterator it_2;
    for (it_2 = filteredWordsANDoccurrence.begin(); it_2 != filteredWordsANDoccurrence.end(); it_2++)
    {
        if (it_2->second == wordOccDescendVec[0])
        {
            mostFreqWord[it_2->first] = it_2->second;
        } else if (it_2->second == wordOccDescendVec[1])
        {
            secMostFreqWord[it_2->first] = it_2->second;
        } else if (it_2->second == wordOccDescendVec[2])
        {
            thirdMostFreqWord[it_2->first] = it_2->second;
        }
    }


    cout << endl << "Most Frequent Occurrence Word/s: " << endl;
    map<string, int>::iterator itMostF;
    for (itMostF = mostFreqWord.begin(); itMostF != mostFreqWord.end(); itMostF++)
    {
        cout << "    Word: '" << itMostF->first << "'. Occurrence count: " << itMostF->second << endl;
    }

    cout << "Second Most Frequent Occurrence Word/s: " << endl;
    map<string, int>::iterator itSecMostF;
    for (itSecMostF = secMostFreqWord.begin(); itSecMostF != secMostFreqWord.end(); itSecMostF++)
    {
        cout << "    Word: '" << itSecMostF->first << "'. Occurrence count: " << itSecMostF->second << endl;
    }

    cout << "Third Most Frequent Occurrence Word/s: " << endl;
    map<string, int>::iterator itThirdMostF;
    int loopCount = 0;
    bool isLoopCouMoreThan10 = false;
    for (itThirdMostF = thirdMostFreqWord.begin(); itThirdMostF != thirdMostFreqWord.end(); itThirdMostF++)
    {
        if (loopCount < 10)
        {
            cout << "    Word: '" << itThirdMostF->first << "'. Occurrence count: " << itThirdMostF->second << endl;
        } else
        {
            isLoopCouMoreThan10 = true;
        }
        loopCount++;
    }
    if (isLoopCouMoreThan10 == true)
    {
        cout << "    and " << (loopCount - 10) << " more words." << endl;
    }
    /**
     * ********************************END*****************************************
     */

    return 0;
}