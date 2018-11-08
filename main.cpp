#include <iostream>
#include <fstream>
#include <iomanip>

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char * argv[])
{
    const int SIZE = 3;
    int *numPtr = new int[SIZE];
    int sum = 0;
    int count = 0;
    double average = 0;
    std::ifstream inputFile;

    inputFile.open(argv[1]);

    //Read in to dynamically allocated array
    if(!inputFile)
        std::cout << "Error opening data file" << std::endl;
    else
    {
        while(inputFile >> numPtr[count] && count < SIZE)
        {
            count++;
        }

        //Print array
        for(int i = 0; i < SIZE; i++)
        {
            std::cout << numPtr[i] << std::endl;
        }

        inputFile.close();
    }

    return 0;
}

