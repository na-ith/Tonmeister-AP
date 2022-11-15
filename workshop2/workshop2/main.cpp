#include <iostream>

void exmp1()
{
    //declaration
    int a, b;
    int resultSum;
    int resultSubtraction;
    
    //initialisation
    a = 5;
    b = 2;
    
    //processing
    resultSum = a + b;
    resultSubtraction = a - b;
    
    std::cout << "Sum: " << resultSum << std::endl;
    std::cout << "Difference: " << resultSubtraction << std::endl;
    
    return;
}

void exmp2()
{
    int a, b;
    
    //uninitialised variables will be whatever was at that memory before (i think)
    std::cout << "Content of a: " << a << std::endl;
    std::cout << "Content of b: " << b << std::endl;
    
    return;
}

void exmp3()
{
    int a = 5;
    int b(3);
    int c{2};
    int result;
    
    a += b; //expect a to be 8
    result = a - c; //expect result to be 6
    
    std::cout << "result: " << result << std::endl;
    
    return;
}

#include <math.h>

void exmp4()
{
    //declare variables
    double voltage, dBu, dBv;
    
    //input voltage
    voltage = 8.;
    
    //calculate dbu and dbv
    dBu = 20 * log10(voltage / 0.775);
    dBv = 20 * log10(voltage);
    
    std::cout << "dBu: " << dBu << std::endl;
    std::cout << "dBv: " << dBv << std::endl;
    
    return;
}

#include <string>
#include <sstream>

void guessAge()
{
    const int age = 20;
    std::string rawGuess;
    int guess = 0;
    
    while(guess != age)
    {
        std::cout << "Guess my age.\n";
        getline(std::cin, rawGuess);
        std::stringstream(rawGuess) >> guess;
        if(guess == age)
        {
            std::cout << "Correct\n";
        }
        else if(guess > age)
        {
            std::cout << "Lower\n";
        }
        else
        {
            std::cout << "Higher\n";
        }
    }
    
    return;
}

void guessNum()
{
    int secretNumber = 284;
    std::string rawGuess;
    int guess = 0, numberOfGuesses = 0;
    
    while(guess != secretNumber)
    {
        numberOfGuesses++;
        std::cout << "Guess the secret number: ";
        getline(std::cin, rawGuess);
        std::stringstream(rawGuess) >> guess;
        if(guess == secretNumber)
        {
            std::cout << "Correct in " << numberOfGuesses << " guesses!\n";
        }
        else if(guess > secretNumber)
        {
            std::cout << "Lower\n";
        }
        else
        {
            std::cout << "Higher\n";
        }
    }
}

int main(int argc, const char * argv[])
{
    
    guessNum();
    
    return 0;
}
