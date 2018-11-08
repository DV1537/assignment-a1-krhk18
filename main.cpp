#include <iostream>
#include <fstream>

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char * argv[])     //argc = number of files, argv[] file sent to the program
{
    //Added by help from Andreas. Prints the path to the file sent to the program????
    for(int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }

//Code to read in and sum the numbers in the file. - Entered by Eriks.
/*
    int a = 0;
    int sum = 0;
    
    std::ifstream myReadFile;
    
    myReadFile.open(argv[1]);

    while (myReadFile >> a)
    {
        sum += a;
    }
    myReadFile.close();
        
    std::cout << sum << "\n";
*/

    return 0;
}

