#include <iostream>
#include <fstream>

//Change

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char * argv[])
{
    int size = 1;
    int *numbersPtr = new int[size];
    int count = 0;
    std::ifstream inputFile;

    inputFile.open(argv[1]);

    if(!inputFile)
        std::cout << "Error opening file." << std::endl;
    else
    {
        while(inputFile >> numbersPtr[count])
        {
            count++;
            if(count >= size)
            {
                int *tempPtr = new int[count + 1];
                for(int i = 0; i < count; i++)
                    tempPtr[i] = numbersPtr[i];
                delete []numbersPtr;
                numbersPtr = tempPtr;
            }
        }

        for(int i = 0; i < count; i++)
        {
            std::cout << numbersPtr[i] << std::endl;
        }
    }
    return 0;
}

