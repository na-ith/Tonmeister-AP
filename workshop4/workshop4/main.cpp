#include <iostream>
#include <math.h>

// I've designed this structure to allow 8 booleans to be
// stored in one byte of data (allBools). There are
// three functions that allow you to read any of the bools,
// filp any of the bools or make a bool true of false.
struct multiBool
{
    // all the bools are stored in this byte
    // it's like an array of 8 booleans
    char allBools = 0;
    
    // returns any one of the 8 bools (0 <= a <= 7)
    bool returnBool(int a)
    {
        int sevenLSBs = allBools;
        if(allBools < 0)
        {
            if(a == 7)
            {
                return true;
            }
            else
            {
               sevenLSBs += 128;
            }
        }
        a++;
        int twoPower = pow(2, a);
        return((sevenLSBs % twoPower) > ((twoPower / 2) - 1));
    }
    
    // makes any  one of the 8 bools either true or false
    // (0 <= a <= 7), b = true or false
    void makeBool(int a, bool b)
    {
        if(a == 7)
        {
            
        }
        if(!returnBool(a))
        {
            allBools += b * pow(2, a);
        }
        else
        {
            allBools -= !b * pow(2, a);
        }
        return;
    }

    // inverts any one of the 8 bools (0 <= a <= 7)
    void flipBool(int a)
    {
        if(a == 7)
        {
            if(!returnBool(7))
            {
                allBools -= 128;
            }
            else
            {
                allBools += 128;
            }
            return;
        }
        if(!returnBool(a))
        {
            allBools += pow(2, a);
        }
        else
        {
            allBools -= pow(2, a);
        }
        return;
    }
};

int main(int argc, const char * argv[])
{
    //declare a multiBool
    multiBool eightBools;
    
    //make all 8 bools true
    for(int i = 0; i < 8; i++)
    {
        eightBools.makeBool(i, true);
    }
    
    // make the 1st, 4th, 7th and 8th bool false and then the 7th
    // bool true again
    eightBools.flipBool(0);
    eightBools.flipBool(3);
    eightBools.flipBool(6);
    eightBools.flipBool(6);
    eightBools.flipBool(7);
    
    //print out the bools in order (expect 0,1,1,0,1,1,1,0)
    for(int i = 0; i < 8; i++)
    {
        std::cout << "[" << i << "]: " << (eightBools.returnBool(i)) << std::endl;
    }
    
    int ref[2];
    int* pointers[2];
    
    ref[0] = 3651;
    ref[1] = -7;
    
    pointers[0] = &ref[0];
    pointers[1] = pointers[0] + 1;
    
    std::cout << "int 1 is: " << ref[0] <<std::endl;
    std::cout << "int 2 should be: " << *pointers[1] <<std::endl;
    std::cout << "pointer 1 is: " << pointers[0] <<std::endl;
    std::cout << "pointer 2 is: " << &ref[1] <<std::endl;
    
    return 0;
}
