#include <iostream>
#include <fstream>

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char * argv[])
{
    int num = 0;
    int sum = 0;
    int count = 0;
    double average = 0;
    std::ifstream inputFile;

    inputFile.open(argv[1]);

    while(inputFile >> num)
    {
        sum += num;
        count++;   
    }

    inputFile.close();

    average = static_cast<double>(sum) / count;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Elements: " << count << std::endl;
    std::cout << "Average: " << average << std::endl;


//Andreas code.
/*
    for(int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }
*/

//Eriks code.
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

