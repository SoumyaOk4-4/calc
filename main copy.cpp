#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printHelp()
{
    cout << "\n\t| cli-calc |\ncopyright(c)2024 \nAuthor-Soumya Chakraborty\n";
    cout << "Usage: calc [option] [arguments]\n";
    cout << "Options:\n";
    cout << "  -h, --help                          Show this help message\n";
    cout << "  -a, --addition <num1> <num2>        Add two numbers\n";
    cout << "  -s, --subtraction <num1> <num2>     Subtract two numbers\n";
    cout << "  -m, --multiplication <num1> <num2>  Multiply two numbers\n";
    cout << "  -d, --division <num1> <num2>        Divide two numbers\n";
}

void addNumbers(int num1, int num2)
{
    cout << "Result of addition: " << num1 + num2 << "\n";
}

void subtractNumbers(int num1, int num2)
{
    cout << "Result of subtraction: " << num1 - num2 << "\n";
}

void multiplyNumbers(int num1, int num2)
{
    cout << "Result of multiplication: " << num1 * num2 << "\n";
}

void divideNumbers(int num1, int num2)
{
    if (num2 == 0)
    {
        cerr << "Error: Cannot divide by zero.\n";
    }
    else
    {
        cout << "Result of division: " << num1 / num2 << "\n";
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printHelp();
        return 0;
    }

    string option = argv[1];

    if (option == "-h" || option == "--help")
    {
        printHelp();
    }
    else if ((option == "-a" || option == "--addition") && argc == 4)
    {
        int num1 = stoi(argv[2]);
        int num2 = stoi(argv[3]);
        addNumbers(num1, num2);
    }
    else if ((option == "-s" || option == "--subtraction") && argc == 4)
    {
        int num1 = stoi(argv[2]);
        int num2 = stoi(argv[3]);
        subtractNumbers(num1, num2);
    }
    else if ((option == "-m" || option == "--multiplication") && argc == 4)
    {
        int num1 = stoi(argv[2]);
        int num2 = stoi(argv[3]);
        multiplyNumbers(num1, num2);
    }
    else if ((option == "-d" || option == "--division") && argc == 4)
    {
        int num1 = stoi(argv[2]);
        int num2 = stoi(argv[3]);
        divideNumbers(num1, num2);
    }
    else
    {
        cerr << "Error: Invalid option or incorrect number of arguments. Use --help for usage information.\n";
        return 1;
    }

    return 0;
}
