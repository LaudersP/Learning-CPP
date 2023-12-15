#include <iostream>
#include <fstream>
#include <string>

#define GRADE_WEIGHT_FILE "..\\..\\temp\\grade_weight.txt"
#define GRADE_SCALE_FILE "..\\..\\temp\\grade_scale.txt"
#define CLASS_LIST_FILE "..\\..\\temp\\class_list.txt"

void printGradeItems(const std::string filepath) {
    // --- Check if filled ---
    std::ifstream gradeWeightFile(filepath);
    std::string line;

    // Check if file properly opens
    if (gradeWeightFile.is_open()) {
        // Grab a line for check
        gradeWeightFile >> line;

        // Check if the file has content
        if (line.empty()) {
            // Empty file
            std::cout << "ERROR) Enter grade weights first!\n";
        }
        else {
            // Loop through file
            while (!line.empty() && !gradeWeightFile.eof()) {
                // Loop through letters
                for (int i = 0; i <= 5; i++) {
                    // Skip E
                    if (i == 4) {
                        continue;
                    }
                    // Responsible to only printing a single F letter
                    else if (i == 5) {
                        std::cout << " " << static_cast<char>(65 + i) << ": " << line << "\n";
                    }
                    // Print A through D
                    else {
                        // Loop from + to - 
                        for (int j = 1; j <= 3; j++) {
                            switch (j) {
                            case 1:
                                std::cout << static_cast<char>(65 + i) << "+: " << line << "\n";
                                break;
                            case 2:
                                std::cout << " " << static_cast<char>(65 + i) << ": " << line << "\n";
                                break;
                            case 3:
                                std::cout << static_cast<char>(65 + i) << "-: " << line << "\n";
                                break;
                            }

                            gradeWeightFile >> line;
                        }
                    }

                }
            }
        }
    }
}

void inputGradeItems(const std::string filepath) {
    // Variables to hold grade values
    float apValue, aVal, amVal, bpVal, bVal, bmVal, cpVal, cVal, cmVal, dpVal, dVal, dmVal, fVal = 0.0;

    // Array to hold pointers to value variables
    float* valueList[13] = { &apValue, &aVal, &amVal, &bpVal, &bVal, &bmVal, &cpVal, &cVal, &cmVal, &dpVal, &dVal, &dmVal, &fVal };

    // Index variable
    int index = 0;

    // Loop through letters
    for (int i = 0; i <= 5; i++) {
        // Skip E as it is not used as a letter grade
        if (i == 4) {
            continue;
        }

        // Print plus, normal, minus symbol
        for (int j = 1; j <= 3; j++) {
            // Print correct F
            if (i == 5 && (j == 1 || j == 3)) {
                continue;
            }

            // Print appropriate sign
            switch (j) {
            case 1:
                // Print
                std::cout << static_cast<char>(65 + i) << "+: ";

                // Get user input
                std::cin >> *valueList[index];

                // Increase index
                index++;

                break;
            case 2:
                // Print
                std::cout << " " << static_cast<char>(65 + i) << ": ";

                // Get user input
                std::cin >> *valueList[index];

                // Increase index
                index++;

                break;
            case 3:
                // Print
                std::cout << static_cast<char>(65 + i) << "-: ";

                // Get user input
                std::cin >> *valueList[index];

                // Increase index
                index++;

                break;
            }
        }
    }

    // Open output file
    std::ofstream outputFile(filepath);

    // Check that the file was properly opened
    if (outputFile.is_open()) {
        // Output the values into file
        for (int i = 0; i < 13; i++) {
            // Check if it is the end of the file
            if (i == 12) {
                outputFile << *valueList[i];
            }
            else {
                outputFile << *valueList[i] << "\n";
            }
        }
    }
    else {
        std::cout << "ERROR) Unable to ouput values, please try again!\n";
    }

    // close file
    outputFile.close();
}

int main()
{
    // --- Global Drive Variables ---
    bool done = false;
    int userInput = 0;

    // Main loop
    while (!done) {
        // Get user input for list options
        // ... Loop until valid
        do {
            // Print options
            std::cout << "\nList\n------------------------\n";
            std::cout << "1. Grade Weight\n";
            std::cout << "2. Current Grade Weight\n";
            std::cout << "3. Grade Scale\n";
            std::cout << "4. Current Grade Scale\n";
            std::cout << "5. Add Class\n";
            std::cout << "6. Print Class List\n";
            std::cout << "7. Get GPA\n";
            std::cout << "8. Reset\n";
            std::cout << "9. Exit\n";
            std::cout << "------------------------\n>>";

            // Get user input
            std::cin >> userInput;
        } while (userInput < 1 || userInput > 9);

        // Act on user input
        switch (userInput) {
        case 1: {
            // Print selection title
            std::cout << "\nGrade Weight\n";
            std::cout << "------------------------\n";

            inputGradeItems(GRADE_WEIGHT_FILE);

            std::cout << "------------------------\n";
        }
        case 2: {
            // Print selection title
            std::cout << "\nCurrent Grade Weight\n";
            std::cout << "------------------------\n";

            printGradeItems(GRADE_WEIGHT_FILE);

            std::cout << "------------------------\n";

            break;
        }
        case 3: {
            // Print selection title
            std::cout << "\nGrade Scale\n";
            std::cout << "------------------------\n";

            inputGradeItems(GRADE_SCALE_FILE);

            std::cout << "------------------------\n";
        }
        case 4: {
            // Print selection title
            std::cout << "\nCurrent Grade Scale\n";
            std::cout << "------------------------\n";

            printGradeItems(GRADE_SCALE_FILE);

            std::cout << "------------------------\n";

            break;
        }
        case 5: {
            // Print selection title
            std::cout << "\nAdd Class\n";
            std::cout << "------------------------\n";

            // Variables for holding data values
            std::string classCode;
            bool codeValid = true;
            int creditHours = 0;
            float grade = 0.0;

            // Get the 'classCode'
            std::cout << "Class Code: ";

            // Get class code
            std::cin >> classCode;

            // Check that the 'classCode' correct length
            if (classCode.length() == 8) {
                // Loop through each element of 'classCode'
                for (int i = 0; i < 8; i++) {
                    // Check that first four elements are letters
                    if ((i < 4 && !isalpha(classCode[i])) || (i >= 4 && !isdigit(classCode[i]))) {
                        codeValid = false;
                        break;
                    }

                    // Upper case if needed
                    if (i < 4) {
                        classCode[i] = std::toupper(classCode[i]);
                    }
                }
            }

            // Cancel operation if code was invalid
            if (!codeValid) {
                std::cout << "------------------------\n";
                std::cout << "ERROR: Invalid class code!\n";
                break; 
            }

            // Get credit hours
            std::cout << "Credit Hours: ";
            std::cin >> creditHours;

            // Get grade
            std::cout << "Grade: ";
            std::cin >> grade;

            std::cout << "------------------------\n";

            // --- Create the Class List File ---

            // Check if the file is empty
            std::ifstream classListFile(CLASS_LIST_FILE);
            
            // Go to the end of the file
            classListFile.seekg(0, std::ios::end);

            // Get the position of the pointer in the file
            int fileSize = classListFile.tellg();

            // Close file
            classListFile.close();

            // Act based on if file is filled or not
            if (fileSize <= 0) {
                // Open file
                std::ofstream classListFile(CLASS_LIST_FILE);

                // Check the file is opened
                if (classListFile.is_open()) {
                    // Insert data
                    classListFile << classCode << "," << creditHours << "," << grade;
                }
            }
            else {
                // Open file in append mode
                std::ofstream classListFile(CLASS_LIST_FILE, std::ios::app);

                // Check the file is opened
                if (classListFile.is_open()) {
                    // Append data
                    classListFile << "\n" << classCode << "," << creditHours << "," << grade;
                }
            }

            // Close the file
            classListFile.close();

            break;
        }
        case 6: {
            // Print selection title
            std::cout << "\nPrint Class List\n";
            std::cout << "------------------------\n";

            // Variables
            std::string line;

            // Open the class list file
            std::ifstream classListFile(CLASS_LIST_FILE);

            // Loop through the file
            while (classListFile >> line) {
                std::cout << "Class: " << line[0] << line[1] << line[2] << line[3] << line[4] << line[5] << line[6] << line[7] << "\n";
                std::cout << "hours: " << line[9] << "\n";
                std::cout << "Grade: " << line[11] << "\n\n";
            }

            classListFile.close();

            std::cout << "------------------------\n";
            break;
        }
        case 7:
            // Print selection title
            std::cout << "\nGet GPA\n";
            std::cout << "------------------------\n";



            std::cout << "------------------------\n";
            break;
        case 8: {

        }
        case 9:
            done = true;
            break;
        }
    }
}