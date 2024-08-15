#include <iostream>
#include <string>
using namespace std;

void calculateBMI(int height, int weight, bool isMale) {
    
    double heightInMeters = height / 100.0;
    double bmi = weight / (heightInMeters * heightInMeters);
    cout << "Your BMI is: " << bmi << endl;

    const double maleRanges[] = {24, 27.5, 31}; 
    const string maleMessages[] = {"Underweight", "Normal weight", "Overweight", "Obese"};

    const double femaleRanges[] = {18.5, 24.9, 29.9}; 
    const string femaleMessages[] = {"Underweight", "Normal weight", "Overweight", "Obese"}; 

    const double* ranges = isMale ? maleRanges : femaleRanges; 
    const string* messages = isMale ? maleMessages : femaleMessages;

    
    if (bmi < ranges[0]) {
        cout << messages[0] << endl;
    }
    else if (bmi <= ranges[1]) {
        cout << messages[1] << endl;
    }
    else if (bmi <= ranges[2]) {
        cout << messages[2] << endl;
    }
    else {
        cout << messages[3] << endl;
    }
}

int main() {
    int gender, height, weight;

    cout << "Gender:" << endl;
    cout << "1. Male" << endl;
    cout << "2. Female" << endl;
    cout << "Choose Gender (1 or 2):" << endl;
    cin >> gender;

    if (gender != 1 && gender != 2) {
        cout << "Invalid gender selection!" << endl;
        return 1; 
    }

    cout << "Enter your height in cm:" << endl;
    cin >> height;

    cout << "Enter your weight in kg:" << endl;
    cin >> weight;

    calculateBMI(height, weight, gender == 1);

    return 0;
}
