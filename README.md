# cpp_projects

### Project 1
Program opens two given text files; first one with the students’ registration number and their names, the second one has students’ registration number, modules and the marks for it.

E.g. <br/>
*studs.txt*
| Registration No. | Name |
| --- | --- |
| 10101 | Mike Sans |

*marks.txt*
| Registration No. | Module | Mark |
| --- | --- | --- |
| 10101 | Mike Sans | 70 |

The program firstly shows all the students with their registration number along with their names and the marks that they have gotten for the modules.

Then, the user will get prompted to choose two functions:
- First function: asks user to enter the mark, and it prints students with the average mark that is less than or equal to given mark
- Second function: shows user the students who have more than or equal to the mark that the user provided for the specific modules

### Project 2
With a given text file, the program tries to read the file and filter the words in it.

There are 3 filter options:
1.	Word that contain at least one upper-case and at least one lower-case letter
2.	Word containing two or more adjacent digits
3.	Word that contains at least one letter and at least one punctuation

The output of the program include:
- Filtered words occurrence
- Distinct filtered words count
- Top three most frequently occurred words
