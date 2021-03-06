#include <iostream>
#include <fstream>
#include <cmath>

/*
 * The program reads numbers from a file an prints the ones above average
 * Example: main.exe ./tests/input.in
 */
int main(int argc, const char * argv[])
{
    double test = 0.0;
    int size = 1;
    double *numbersPtr = new double[size];
    int count = 0;
    double sum = 0;
    double average = 0;
    std::ifstream inputFile;

    inputFile.open(argv[1]);

    if(!inputFile)      //Checks if read in successfully
    {
        std::cout << "Error opening file.\n" << std::endl;
    }
    else
    {
        while(inputFile >> numbersPtr[count])           //Read in and store
        {           
            count++;
            if(count >= size)       //If full: expand
            {
                size += 1;
                double *tempPtr = new double[size];  //Create new, bigger
                for(int i = 0; i < size - 1; i++)      //move
                {
                    tempPtr[i] = numbersPtr[i];
                }
                delete []numbersPtr;                //delete old content
                numbersPtr = tempPtr;               //make pointer point to new array
                tempPtr = nullptr;
            }
        }
        if(count == 0 || !inputFile.eof())
        {
            std::cout << "File is empty or contains non-numerical values\n";
        }
        else
        {        
            //Sum elements in array
            for(int i = 0; i < size; i++)
            {
                sum += numbersPtr[i];
            }

            //Average
            average = sum / count;

            //Print above average
            for(int i = 0; i < size; i++)
            {
                if(numbersPtr[i] > average)
                {
                    numbersPtr[i] = round(numbersPtr[i] * 1000) / 1000;     //Three decimal digits
                    std::cout << numbersPtr[i] << " ";
                }
            }
        }
    }
 
    delete []numbersPtr;
    numbersPtr = nullptr;
 
    return 0;
}