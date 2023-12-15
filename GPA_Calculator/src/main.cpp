#include <iostream>
#include <fstream>
#include <string>

#define GRADE_WEIGHT_FILE "..\\..\\temp\\grade_weight.txt"

int main()
{
    // --- Grade Weight Variables ---
    // Variables to hold the grade weight
    float apValue, aVal, amVal, bpVal, bVal, bmVal, cpVal, cVal, cmVal, dpVal, dVal, dmVal, fVal = 0.0;

    // Array to hold pointers to the 
    float* gradeWeight[13] = { &apValue, &aVal, &amVal, &bpVal, &bVal, &bmVal, &cpVal, &cVal, &cmVal, &dpVal, &dVal, &dmVal, &fVal };

    // --- Global Drive Variables ---
    bool done = false;
    int userInput = 0;
    int globalIndex = 0;

    // Main loop
    while (!done) {
        // Get user input for list options
        // ... Loop until valid
        do {
            // Print options
            std::cout << "\nList\n------------------------\n1. Grade Weight\n2. Current Grade Scale\n6. Exit\n------------------------";
            std::cout << "\n>>";

            // Get user input
            std::cin >> userInput;
        } while (userInput != 1 && userInput != 2 && userInput != 6);

        // Act on user input
        switch (userInput) {
        case 1: {
            // Print selection title
            std::cout << "\nGrade Weight\n";
            std::cout << "------------------------\n";

            // Loop through gathering
            for (int i = 0; i <= 5; i++) {
                // Skip E as it is not used as a letter grade
                if (i == 4) {
                    continue;
                }

                // Print plus, normal, and minus symbols
                for (int j = 1; j <= 3; j++) {
                    // Print the correct F
                    if (i == 5 && (j == 1 || j == 3)) {
                        continue;
                    }

                    // Print appropriate sign
                    switch (j) {
                    case 1:
                        // Print
                        std::cout << static_cast<char>(65 + i) << "+: ";

                        // Get user input
                        std::cin >> *gradeWeight[globalIndex];
                        globalIndex++;
                        break;
                    case 2:
                        // Print
                        std::cout << " " << static_cast<char>(65 + i) << ": ";

                        // Get user input
                        std::cin >> *gradeWeight[globalIndex];
                        globalIndex++;
                        break;
                    case 3:
                        // Print
                        std::cout << static_cast<char>(65 + i) << "-: ";

                        // Get user input
                        std::cin >> *gradeWeight[globalIndex];
                        globalIndex++;
                        break;
                    }
                }
            }

            // Open output file
            std::ofstream gradeWeightFile(GRADE_WEIGHT_FILE);

            // Check if the file is successfully opened
            if (gradeWeightFile.is_open()) {
                // Output grade weight values
                for (int i = 0; i < 13; i++) {
                    gradeWeightFile << *gradeWeight[i] << "\n";
                }
            }
            else {
                // Error of opening
                std::cout << "ERROR) Unable to output grade weight values!\n";
            }

            // Close file
            gradeWeightFile.close();
            std::cout << "------------------------\n";

            break;
        }
        case 2: {
            // Print selection title
            std::cout << "\nCurrent Grade Weight\n";
            std::cout << "------------------------\n";

            // Check if filled
            std::ifstream gradeWeightFile(GRADE_WEIGHT_FILE);
            std::string line;

            if (gradeWeightFile.is_open()) {
                gradeWeightFile >> line;

                if (line.empty()) {
                    std::cout << "ERROR) Enter grade weights first!\n";
                }
                else {
                    while (!line.empty() && !gradeWeightFile.eof()) {
                        std::cout << line << "\n";
                        gradeWeightFile >> line;
                    }
                }
            }

            std::cout << "------------------------\n";

            break;
        }
        case 6:
            done = true;
            break;
        }
    }
}