#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
            std::cout << "ERROR) No data found!\n";
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
        std::cout << "ERROR) Unable to ouput data, please try again!\n";
    }

    // close file
    outputFile.close();
}

void resetFile(const std::string FILEPATH) {
    // Open file
    std::ofstream file(FILEPATH);

    // Check it is opened
    if (!file.is_open()) {
        std::cout << "ERROR) Unable to reset file, please try again!\n";
    } 

    // Close the file
    file.close();
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
            // Open file
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

            // Go to the end of the file
            classListFile.seekg(0, std::ios::end);

            // Get the position of the pointer in the file
            int fileSize = classListFile.tellg();

            // Check if files empty
            if (fileSize <= 0) {
                std::cout << "ERROR) No data found!\n";
                std::cout << "------------------------\n";
                break;
            }

            // Clear flag from end of the file
            classListFile.clear();

            // Move to the beginning
            classListFile.seekg(0, std::ios::beg);

            // Loop through the file
            while (classListFile >> line) {
                // Create stringsteam from input line
                std::istringstream ss(line);

                // Variables to hold data
                std::string classCode, hours, grade;

                // Read and store class code
                std::getline(ss, classCode, ',');

                // Read and store hours
                std::getline(ss, hours, ',');

                // Read and store grade
                std::getline(ss, grade, ',');

                // Print data
                std::cout << "Class: " << classCode << "\n";
                std::cout << "Hours: " << hours << "\n";
                std::cout << "Grade: " << grade << "\n\n";
            }

            classListFile.close();

            std::cout << "------------------------\n";
            break;
        }
        case 7: {
            // Print selection title
            std::cout << "\nGet GPA\n";
            std::cout << "------------------------\n";

            // Variable to hold the data
            std::string line;
            float data;

            // Array to hold grade weight values
            float gradeWeights[13];

            // Array to hold grade scale minimum values
            float gradeScale[13];

            // --- Grab grade weights ---
            // Open the file
            std::ifstream gradeWeightFile(GRADE_WEIGHT_FILE);

            // Check if the file is open
            if (gradeWeightFile.is_open()) {
                // Loop through the file
                for (int i = 0; i < 13; i++) {
                    // Grab data
                    gradeWeightFile >> data;

                    // Set data into array
                    gradeWeights[i] = data;
                }
            }

            // Close file
            gradeWeightFile.close();

            // --- Grab grade scale ---
            // Open the file
            std::ifstream gradeScaleFile(GRADE_SCALE_FILE);

            // Check if the file is open
            if (gradeScaleFile.is_open()) {
                // Loop through the file
                for (int i = 0; i < 13; i++) {
                    // Grab data
                    gradeScaleFile >> data;

                    // Set data into array
                    gradeScale[i] = data;
                }
            }

            // Close the file
            gradeScaleFile.close();

            // --- Get number of classes ---
            // Variables
            int lineCount = 0;

            // Open the file
            std::ifstream classListFile(CLASS_LIST_FILE);

            // Check if the file is open
            if (classListFile.is_open()) {
                // Scan through the file
                while (classListFile >> line) {
                    lineCount++;
                }
            }

            // Check if the class list is empty
            if (lineCount == 0) {
                std::cout << "ERROR) No data found!\n------------------------\n";
                break;
            }
            
            // --- Get class based data ---
            // Allocate memory for an array to hold class credit hours
            float* classHours = new float[lineCount];

            // Allocate memory for an array to hold class grade
            float* classGrades = new float[lineCount];

            // Clear flag from end of the file
            classListFile.clear();

            // Move to the beginning
            classListFile.seekg(0, std::ios::beg);

            // Loop through the 'classListFile' to grab data
            for (int i = 0; i < lineCount; i++) {
                // Grab data line
                classListFile >> line;

                // Create stringsteam from input line
                std::istringstream ss(line);

                // Variables to hold data
                std::string classCode, hours, grade;

                // Read and store class code
                std::getline(ss, classCode, ',');

                // Read and store hours
                std::getline(ss, hours, ',');

                // Read and store grade
                std::getline(ss, grade, ',');

                // Convert strings to floats
                classHours[i] = std::stof(hours);
                classGrades[i] = std::stof(grade);
            }

            // --- Calculate total quality points ---
            // Variable for keeping running total of quality points
            float qualityPoints = 0;

            for (int i = 0; i < lineCount; i++) {
                if (classGrades[i] >= gradeScale[0]) {
                    qualityPoints += classHours[i] * gradeWeights[0];
                }
                else if (classGrades[i] >= gradeScale[1]) {
                    qualityPoints += classHours[i] * gradeWeights[1];
                }
                else if (classGrades[i] >= gradeScale[2]) {
                    qualityPoints += classHours[i] * gradeWeights[2];
                }
                else if (classGrades[i] >= gradeScale[3]) {
                    qualityPoints += classHours[i] * gradeWeights[3];
                }
                else if (classGrades[i] >= gradeScale[4]) {
                    qualityPoints += classHours[i] * gradeWeights[4];
                }
                else if (classGrades[i] >= gradeScale[5]) {
                    qualityPoints += classHours[i] * gradeWeights[5];
                }
                else if (classGrades[i] >= gradeScale[6]) {
                    qualityPoints += classHours[i] * gradeWeights[6];
                }
                else if (classGrades[i] >= gradeScale[7]) {
                    qualityPoints += classHours[i] * gradeWeights[7];
                }
                else if (classGrades[i] >= gradeScale[8]) {
                    qualityPoints += classHours[i] * gradeWeights[8];
                }
                else if (classGrades[i] >= gradeScale[9]) {
                    qualityPoints += classHours[i] * gradeWeights[9];
                }
                else if (classGrades[i] >= gradeScale[10]) {
                    qualityPoints += classHours[i] * gradeWeights[10];
                }
                else if (classGrades[i] >= gradeScale[11]) {
                    qualityPoints += classHours[i] * gradeWeights[11];
                }
                else if (classGrades[i] >= gradeScale[12]) {
                    qualityPoints += classHours[i] * gradeWeights[12];
                }
            }

            // --- Calculate total hours ---
            // Variable to hold total class hours
            float totalHours = 0;

            // Add hours together
            for (int i = 0; i < lineCount; i++) {
                totalHours += classHours[i];
            }

            // --- Calculate GPA --- 
            float GPA = qualityPoints / totalHours;

            // Print GPA
            std::cout << "GPA: " << GPA << "\n";

            std::cout << "------------------------\n";

            // Deallocate memory for classHours
            delete[] classHours;

            // Deallocate memory for classGrade
            delete[] classGrades;

            break;
        }
        case 8: {
            // Get user input for list options
            // ... Loop until valid
            do {
                // Print options
                std::cout << "\nReset\n------------------------\n";
                std::cout << "1. Grade Weight\n";
                std::cout << "2. Grade Scale\n";
                std::cout << "3. Class List\n";
                std::cout << "4. Reset All\n";
                std::cout << "9. Return\n";
                std::cout << "------------------------\n>>";

                // Get user input
                std::cin >> userInput;
            } while (userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4 && userInput != 9);

            // Confirm decision
            char confirm;
            if (userInput != 9) {
                std::cout << "Confirm reset of ";
            }

            // Act on user input
            switch (userInput) {
            case 1: {
                // Finish confirm message
                std::cout << "GRADE WEIGHT (y/n): ";
                
                // Get input
                std::cin >> confirm;

                // Act on input
                if (confirm == 'y') {
                    // Reset file
                    resetFile(GRADE_WEIGHT_FILE);
                }

                break;
            }
            case 2: {
                // Finish confirm message
                std::cout << "GRADE SCALE (y/n): ";

                // Get input
                std::cin >> confirm;

                // Act on input
                if (confirm == 'y') {
                    // Reset file
                    resetFile(GRADE_SCALE_FILE);
                }

                break;
            }
            case 3: {
                // Finish confirm message
                std::cout << "CLASS LIST (y/n): ";

                // Get input
                std::cin >> confirm;

                // Act on input
                if (confirm == 'y') {
                    // Reset file
                    resetFile(CLASS_LIST_FILE);
                }

                break;
            }
            case 4: {
                // Finish confirm message
                std::cout << "ALL (y/n): ";

                // Get input
                std::cin >> confirm;

                // Act on input
                if (confirm == 'y') {
                    // Reset files
                    resetFile(GRADE_SCALE_FILE);
                    resetFile(GRADE_WEIGHT_FILE);
                    resetFile(CLASS_LIST_FILE);
                }

                break;
            }
            case 9:
                break;
            }

            break;
        }
        case 9:
            done = true;
            break;
        }
    }
}