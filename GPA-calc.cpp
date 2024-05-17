#include <iostream>
#include <map>
#include <string>
#include <limits>
#include <algorithm>

std::map<std::string, float> quality_points = {
    {"A", 4.0}, {"A-", 3.7}, {"B+", 3.3}, {"B", 3.0}, {"B-", 2.7}, 
    {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7}, {"D+", 1.3}, {"D", 1.0}, 
    {"D-", 0.7}, {"F", 0}
};

std::string to_uppercase(const std::string &str){
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

std::string calc_Grade(int grade) {
    if (grade <= 59) return "F";
    if (grade <= 61) return "D-";
    if (grade <= 63) return "D";
    if (grade <= 66) return "D+";
    if (grade <= 69) return "C-";
    if (grade <= 73) return "C";
    if (grade <= 76) return "C+";
    if (grade <= 79) return "B-";
    if (grade <= 83) return "B";
    if (grade <= 86) return "B+";
    if (grade <= 89) return "A-";
    return "A";
}

std::map<std::string, float> credit_input() {
    std::map<std::string, float> course_array;
    std::string grade;
    float credits;
    int n;
    std::cout << "How many courses did you wish to add? ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "Grade: ";
        std::cin >> grade;
        grade = to_uppercase(grade);
        std::cout << "Credits (default: 3) ";
        std::cin >> credits;
        
        course_array[grade] = credits;
    }
    return course_array;
}

float GPA(const std::map<std::string, float>& courses) {
    float total_points = 0;
    float total_credits = 0;

    for (const auto& course : courses) {
        std::string grade = course.first;
        float credits = course.second;

        // Sum total quality points
        total_points += quality_points[grade] * credits;
        // Sum total credits
        total_credits += credits;
    }

    if (total_credits == 0) return 0; // Avoid division by zero

    return total_points / total_credits;
}

int main() {
    std::map<std::string, float> courses = credit_input();
    float gpa = GPA(courses);

    std::cout << "Your GPA is: " << gpa << std::endl;

    return 0;
}
