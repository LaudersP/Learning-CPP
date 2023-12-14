#include <iostream>

int main()
{
    // --- Grade Weight Variables ---
    // Variables to hold the grade weight
    float apValue, aVal, amVal, bpVal, bVal, bmVal, cpVal, cVal, cmVal, dpVal, dVal, dmVal, fVal = 0.0;

    // Array to hold pointers to the 
    float* gradeWeight[13] = { &apValue, &aVal, &amVal, &bpVal, &bVal, &bmVal, &cpVal, &cVal, &cmVal, &dpVal, &dVal, &dmVal, &fVal };
    bool filled = false;

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
        case 1:
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
            filled = true;
            std::cout << "------------------------\n";

            break;

        case 2:
            // Print selection title
            std::cout << "\nCurrent Grade Weight\n";
            std::cout << "------------------------\n";

            // Check if filled
            if (filled) {
                // Reset globalIndex
                globalIndex = 0;

                // Loop through letter grades
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
                            std::cout << static_cast<char>(65 + i) << "+: " << *gradeWeight[globalIndex] << "\n";
                            globalIndex++;
                            break;
                        case 2:
                            std::cout << " " << static_cast<char>(65 + i) << ": " << *gradeWeight[globalIndex] << "\n";
                            globalIndex++;
                            break;
                        case 3:
                            std::cout << static_cast<char>(65 + i) << "-: " << *gradeWeight[globalIndex] << "\n";
                            globalIndex++;
                            break;
                        }
                    }
                }
            }
            else {
                std::cout << "ERROR) List is empty, please add grade weight!\n";
            }
            
            std::cout << "------------------------\n";

            break;
        case 6:
            done = true;
            break;
        }
    } 
}