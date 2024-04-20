#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Function to register a new user
bool registerUser() {
    string username, password;
    cout << "Register" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(username + ".txt");
    if (file) {
        cout << "Username already exists. Please try again." << endl;
        return false;
    }

    ofstream outfile(username + ".txt");
    if (outfile) {
        outfile << password << endl;
        cout << "Registration successful. You can now log in." << endl;
        return true;
    } else {
        cout << "Failed to create user file." << endl;
        return false;
    }
}

// Function to log in an existing user
bool loginUser() {
    string username, password, storedPassword;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(username + ".txt");
    if (!file) {
        cout << "User not found. Please register first." << endl;
        return false;
    }

    file >> storedPassword;
    if (storedPassword != password) {
        cout << "Incorrect password." << endl;
        return false;
    }

    cout << "**********************   Login successful.   *********************" << endl;
    return true;
}

// Function to ask anxiety-related questions and store responses
// 1st
int askAnxietyQuestions(const string& username) {
    vector<string> questions = {
        "1. Do you often feel excessively worried or anxious about various aspects of your life?",
        "2. Do you experience frequent panic attacks characterized by sudden and intense fear or discomfort?",
        "3. Are you constantly on edge or easily startled by minor stimuli?",
        "4. Do you avoid social situations or specific places or activities due to fear or anxiety?",
        "5. Do you have difficulty controlling your worries or irrational fears?",
        "6. Are you frequently tense or experience muscle tension, trembling, or sweating?",
        "7. Do you often experience racing thoughts or have difficulty concentrating?",
        "8. Do you frequently experience physical symptoms such as shortness of breath, rapid heartbeat, or stomach discomfort?",
        "9. Do you have difficulty falling or staying asleep due to anxious thoughts or worries?",
        "10. Do your anxiety symptoms significantly interfere with your daily life or activities?"
    };

    ofstream userFile(username + "_Anxiety.txt", ios::app); // Append mode

    int count = 0;
    for (const string& question : questions) {
        char response;
        cout << question << " (Y/N): ";
        cin >> response;
        while (response != 'Y' && response != 'y' && response != 'N' && response != 'n') {
            cout << "Invalid input. Please enter 'Y' or 'N': ";
            cin >> response;
        }
        userFile << question << " " << (response == 'Y' || response == 'y' ? "Yes" : "No") << endl;
        if (response == 'Y' || response == 'y') {
            count++;
        }
    }

    // Write the score into the file
    double percentage = static_cast<double>(count) / questions.size() * 100;
    userFile << "Score: " << percentage << "%" << endl;
    userFile << "---------------------------------------------" << endl;

    userFile.close();

    return count;
}

// Function to ask depressive-related questions and store responses
// 2nd
int askDepressiveQuestions(const string& username) {
   vector<string> questions = {
        "1. Do you often feel sad, hopeless, or empty for most of the day, nearly every day?",
        "2. Have you lost interest or pleasure in activities that you used to enjoy?",
        "3. Do you experience significant changes in appetite or weight, such as overeating or loss of appetite?",
        "4. Do you have difficulty sleeping, such as trouble falling asleep, staying asleep, or sleeping too much?",
        "5. Do you feel fatigued or have low energy levels most days?",
        "6. Do you experience feelings of worthlessness or excessive guilt?",
        "7. Do you have difficulty concentrating, making decisions, or remembering things?",
        "8. Do you have recurring thoughts of death or suicide, or have you made suicide attempts?",
        "9. Do you experience physical symptoms such as aches, pains, or digestive issues without a clear medical cause?",
        "10. Do your depressive symptoms significantly interfere with your daily life or functioning?"

        
    };

    ofstream userFile(username + "_Anxiety.txt", ios::app); // Append mode

    int count = 0;
    for (const string& question : questions) {
        char response;
        cout << question << " (Y/N): ";
        cin >> response;
        while (response != 'Y' && response != 'y' && response != 'N' && response != 'n') {
            cout << "Invalid input. Please enter 'Y' or 'N': ";
            cin >> response;
        }
        userFile << question << " " << (response == 'Y' || response == 'y' ? "Yes" : "No") << endl;
        if (response == 'Y' || response == 'y') {
            count++;
        }
    }

    // Write the score into the file
    double percentage = static_cast<double>(count) / questions.size() * 100;
    userFile << "Score: " << percentage << "%" << endl;
    userFile << "---------------------------------------------" << endl;

    userFile.close();

    return count;
}

// Function to ask stress-related questions and store responses
// 3rd
int askStressRelatedQuestions(const string& username) {
    vector<string> questions = {
        "1. Have you experienced or witnessed a traumatic event that continues to affect you emotionally?",
        "2. Do you frequently experience intrusive memories, flashbacks, or nightmares related to the traumatic event?",
        "3. Do you actively avoid reminders of the traumatic event, such as places, people, or activities?",
        "4. Do you feel constantly on guard, easily startled, or hypervigilant?",
        "5. Do you have difficulty concentrating or experiencing memory problems?",
        "6. Do you feel emotionally numb or disconnected from others?",
        "7. Do you experience intense feelings of fear, anger, or irritability?",
        "8. Do you have difficulty sleeping, experiencing insomnia, or restless sleep?",
        "9. Do you engage in risky behaviors or have difficulty controlling impulses?",
        "10. Do your stress-related symptoms significantly interfere with your daily life or functioning?"

        
    };

    ofstream userFile(username + "_Anxiety.txt", ios::app); // Append mode

    int count = 0;
    for (const string& question : questions) {
        char response;
        cout << question << " (Y/N): ";
        cin >> response;
        while (response != 'Y' && response != 'y' && response != 'N' && response != 'n') {
            cout << "Invalid input. Please enter 'Y' or 'N': ";
            cin >> response;
        }
        userFile << question << " " << (response == 'Y' || response == 'y' ? "Yes" : "No") << endl;
        if (response == 'Y' || response == 'y') {
            count++;
        }
    }

    // Write the score into the file
    double percentage = static_cast<double>(count) / questions.size() * 100;
    userFile << "Score: " << percentage << "%" << endl;
    userFile << "---------------------------------------------" << endl;

    userFile.close();

    return count;
}

// Function to ask substance use-related questions and store responses
// 4th
int askSubstanceUseQuestions(const string& username) {
    vector<string> questions = {
        "1. Do you frequently use alcohol, drugs, or other substances to cope with stress or emotional pain?",
        "2. Have you experienced cravings or strong urges to use substances, especially when stressed or upset?",
        "3. Have you tried unsuccessfully to cut down or control your substance use?",
        "4. Do you need to use increasing amounts of a substance to achieve the desired effect (tolerance)?",
        "5. Do you experience withdrawal symptoms when you stop using a substance or reduce your intake?",
        "6. Have you continued to use substances despite experiencing negative consequences in your life (e.g., health problems, relationship issues, legal trouble)?",
        "7. Do you spend a significant amount of time obtaining, using, or recovering from the effects of substances?",
        "8. Have you neglected responsibilities or important activities in favor of substance use?",
        "9. Have you experienced disruptions in your relationships or social life due to substance use?",
        "10. Do you want to cut down or quit using substances but find it difficult to do so?"

        
    };

    ofstream userFile(username + "_Anxiety.txt", ios::app); // Append mode

    int count = 0;
    for (const string& question : questions) {
        char response;
        cout << question << " (Y/N): ";
        cin >> response;
        while (response != 'Y' && response != 'y' && response != 'N' && response != 'n') {
            cout << "Invalid input. Please enter 'Y' or 'N': ";
            cin >> response;
        }
        userFile << question << " " << (response == 'Y' || response == 'y' ? "Yes" : "No") << endl;
        if (response == 'Y' || response == 'y') {
            count++;
        }
    }

    // Write the score into the file
    double percentage = static_cast<double>(count) / questions.size() * 100;
    userFile << "Score: " << percentage << "%" << endl;
    userFile << "---------------------------------------------" << endl;

    userFile.close();

    return count;
}

// Function to ask eating disorder-related questions and store responses
// 5th
int askEatingDisorderQuestions(const string& username) {
    vector<string> questions = {
        "1. Do you have an intense fear of gaining weight or becoming fat, even if you are underweight?",
        "2. Do you engage in restrictive eating behaviors, such as severely limiting food intake or avoiding certain foods?",
        "3. Do you have a distorted body image, perceiving yourself as overweight even when you are underweight?",
        "4. Do you frequently weigh yourself or obsessively monitor your body shape or size?",
        "5. Do you experience episodes of binge eating, consuming large amounts of food in a short period while feeling out of control?",
        "6. Do you engage in compensatory behaviors to control your weight, such as self-induced vomiting, misuse of laxatives, or excessive exercise?",
        "7. o you experience guilt, shame, or disgust after binge eating episodes or engaging in compensatory behaviors?",
        "8. Do you hide or lie about your eating habits or behaviors?",
        "9. Have you experienced physical complications related to your eating behaviors, such as gastrointestinal problems or changes in menstrual cycles?",
        "10. Do your eating disorder symptoms significantly interfere with your daily life or functioning?"

    };

    ofstream userFile(username + "_Anxiety.txt", ios::app); // Append mode

    int count = 0;
    for (const string& question : questions) {
        char response;
        cout << question << " (Y/N): ";
        cin >> response;
        while (response != 'Y' && response != 'y' && response != 'N' && response != 'n') {
            cout << "Invalid input. Please enter 'Y' or 'N': ";
            cin >> response;
        }
        userFile << question << " " << (response == 'Y' || response == 'y' ? "Yes" : "No") << endl;
        if (response == 'Y' || response == 'y') {
            count++;
        }
    }

    // Write the score into the file
    double percentage = static_cast<double>(count) / questions.size() * 100;
    userFile << "Score: " << percentage << "%" << endl;
    userFile << "---------------------------------------------" << endl;

    userFile.close();

    return count;
}

int main() {
    int choice;
    cout << "Press 1 to login, 2 to register, or 3 to exit: ";
    cin >> choice;

    switch (choice) {
        case 1:
            if (!loginUser()) {
                cout << "Exiting program." << endl;
                return 0;
            }
            break;
        case 2:
            if (!registerUser()) {
                cout << "Exiting program." << endl;
                return 0;
            }
            break;
        case 3:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Exiting program." << endl;
            return 0;
    }

    string username;
    cout << "Enter your username: ";
    cin >> username;

    // Ask user to choose the problem type
    int problemChoice;
    cout << "Select a problem from the following list:" << endl;
    cout << "1. Anxiety Disorders" << endl;
    cout << "2. Depressive Disorders" << endl;
    cout << "3. Stress-Related Disorders" << endl;
    cout << "4. Substance Use Disorders" << endl;
    cout << "5. Eating Disorders" << endl;
    cout << "Enter the corresponding number: ";
    cin >> problemChoice;

    int yesCount = 0;
    switch (problemChoice) {
        case 1:
            cout << "You selected Anxiety Disorders." << endl;
            yesCount = askAnxietyQuestions(username);
            break;
        case 2:
            cout << "You selected Depressive Disorders." << endl;
            yesCount = askDepressiveQuestions(username);
            break;
        case 3:
            cout << "You selected Stress-Related Disorders." << endl;
            yesCount = askStressRelatedQuestions(username);
            break;
        case 4:
            cout << "You selected Substance Use Disorders." << endl;
            yesCount = askSubstanceUseQuestions(username);
            break;
        case 5:
            cout << "You selected Eating Disorders." << endl;
            yesCount = askEatingDisorderQuestions(username);
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
    }

    // Calculate percentage of "yes" answers and display the score
    double percentage = static_cast<double>(yesCount) / 10 * 100;
    cout << "Your score: " << percentage << "%" << endl;

    // Provide feedback based on the number of "yes" answers
    if (percentage >= 50) {
        cout << "While your score is above 50%, it's important to address any underlying issues with the help of a healthcare professional." << endl;
    } else {
        cout << "It appears that your symptoms may be significant. Seeking guidance from a healthcare provider is recommended." << endl;
    }

    return 0;
}
