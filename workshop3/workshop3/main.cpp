#include <iostream>

#define HEIGHT 3
#define WIDTH 5

void task1and2()
{
    int group[HEIGHT][WIDTH];
    int n, m;
    for(n = 0; n < HEIGHT; n++)
    {
        for(m = 0; m < WIDTH; m++)
        {
            group[n][m] = (n + 1) * (m + 1);
        }
    }
    
    //loops that print out the multidimentional array
    n = 0; m = 0;
    for(n = 0; n < HEIGHT; n++)
    {
        for(m = 0; m < WIDTH; m++)
        {
            std::cout << group[n][m] << ",";
        }
        std::cout << "\n";
    }
    
    return;
}

#include <string>
#include <sstream>
void recordASale(int& a)
{
    a--;
    if(a < 0)
    {
        std::cout << "Out of stock... Can't make sale!\n";
        a++;
    }
    return;
}

void recordAnEntry(int& a)
{
    a++;
    return;
}

void requestCurrentStock(int& a)
{
    std::cout << "Current stock is: " << a << std::endl;
    return;
}

void entriesAndSales()
{
    int currentStock = 10;
    std::string userOpperation;
    bool going = true;
    while(going)
    {
        std::cout << "Enter:\n1 to record a sale.\n2 to record an entry.\n3 to request current stock\n";
        getline(std::cin, userOpperation);
        if(userOpperation == "1")
        {
            recordASale(currentStock);
        }
        else if(userOpperation == "2")
        {
            recordAnEntry(currentStock);
        }
        else if(userOpperation == "3")
        {
            requestCurrentStock(currentStock);
        }
        else
        {
            going = false;
        }
    }
    return;
}

int main(int argc, const char * argv[])
{
    // task1and2();
    entriesAndSales();
    
    return 0;
}
