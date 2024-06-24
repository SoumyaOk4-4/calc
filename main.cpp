#include <iostream>
#include <string>
#include <vector>

void printHelp() {
    std::cout << "\n\t| cli-calc |\ncopyright(c)2024 \nAuthor-Soumya Chakraborty\n";
    std::cout << "Usage: calc [option] [arguments]\n";
    std::cout << "Options:\n";
    std::cout << "  -h, --help                          Show this help message\n";
    std::cout << "  -a, --addition <num1> <num2>        Add two numbers\n";
    std::cout << "  -s, --subtraction <num1> <num2>     Subtract two numbers\n";
    std::cout << "  -m, --multiplication <num1> <num2>  Multiply two numbers\n";
    std::cout << "  -d, --division <num1> <num2>        Divide two numbers\n";
}

void addNumbers(int num1, int num2) {
    std::cout << "Result of addition: " << num1 + num2 << "\n";
}

void subtractNumbers(int num1, int num2) {
    std::cout << "Result of subtraction: " << num1 - num2 << "\n";
}

void multiplyNumbers(int num1, int num2) {
    std::cout << "Result of multiplication: " << num1 * num2 << "\n";
}

void divideNumbers(int num1, int num2) {
    if (num2 == 0) {
        std::cerr << "Error: Cannot divide by zero.\n";
    } else {
        std::cout << "Result of division: " << num1 / num2 << "\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printHelp();
        return 0;
    }

    std::string option = argv[1];

    if (option == "-h" || option == "--help") {
        printHelp();
    } else if ((option == "-a" || option == "--addition") && argc == 4) {
        try {
            int num1 = std::stoi(argv[2]);
            int num2 = std::stoi(argv[3]);
            addNumbers(num1, num2);
        } catch (std::invalid_argument& e) {
            std::cerr << "Error: Invalid arguments for addition. Please provide two integers.\n";
            return 1;
        }
    } else if ((option == "-s" || option == "--subtraction") && argc == 4) {
        try {
            int num1 = std::stoi(argv[2]);
            int num2 = std::stoi(argv[3]);
            subtractNumbers(num1, num2);
        } catch (std::invalid_argument& e) {
            std::cerr << "Error: Invalid arguments for subtraction. Please provide two integers.\n";
            return 1;
        }
    } else if ((option == "-m" || option == "--multiplication") && argc == 4) {
        try {
            int num1 = std::stoi(argv[2]);
            int num2 = std::stoi(argv[3]);
            multiplyNumbers(num1, num2);
        } catch (std::invalid_argument& e) {
            std::cerr << "Error: Invalid arguments for multiplication. Please provide two integers.\n";
            return 1;
        }
    } else if ((option == "-d" || option == "--division") && argc == 4) {
        try {
            int num1 = std::stoi(argv[2]);
            int num2 = std::stoi(argv[3]);
            divideNumbers(num1, num2);
        } catch (std::invalid_argument& e) {
            std::cerr << "Error: Invalid arguments for division. Please provide two integers.\n";
            return 1;
        }
    } else {
        std::cerr << "Error: Invalid option or incorrect number of arguments. Use --help for usage information.\n";
        return 1;
    }

    return 0;
}
