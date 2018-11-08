#include <iostream>
#include <fstream>

/*
 * The program reads numbers from a file an prints the ones above average
 * Example: main.exe ./tests/input.in
 */
int main(int argc, const char * argv[])
{
    int size = 1;
    int *numbersPtr = new int[size];
    int count = 0;
    int sum = 0;
    double average = 0;
    std::ifstream inputFile;

    inputFile.open(argv[1]);

    if(!inputFile)      //Checks if read in successfully
        std::cout << "Error opening file." << std::endl;
    else
    {
        while(inputFile >> numbersPtr[count])           //Read in and store
        {
            count++;
            if(count >= size)       //If full: expand
            {
                int *tempPtr = new int[count + 1];  //Create new, bigger
                for(int i = 0; i < count; i++)      //move
                    tempPtr[i] = numbersPtr[i];
                delete []numbersPtr;                //delete old content
                numbersPtr = tempPtr;               //make pointer point to new array
            }
        }

        //Sum elements in array
        for(int i = 0; i < count; i++)
        {
            sum += numbersPtr[i];
        }

        //Average
        average = static_cast<double>(sum) / count;

        //Print above average
        for(int i = 0; i < count; i++)
        {
            if(numbersPtr[i] > average)
                std::cout << numbersPtr[i] << " ";
        }
    }
    return 0;
}

