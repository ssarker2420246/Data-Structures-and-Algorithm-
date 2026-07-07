#include <iostream>
using namespace std;

struct Student {
    string name;
    int id;
    double cgpa;
};

// Divide & Conquer function
Student findTopStudent(Student arr[], int left, int right) {

    // Base case
    if (left == right) {
        return arr[left];
    }

    int mid = (left + right) / 2;

    // Divide
    Student leftTop = findTopStudent(arr, left, mid);
    Student rightTop = findTopStudent(arr, mid + 1, right);

    // Conquer (compare)
    if (leftTop.cgpa > rightTop.cgpa)
        return leftTop;
    else
        return rightTop;
}

int main() {
    Student students[] = {
        {"Alice", 101, 3.5},
        {"Bob", 102, 3.9},
        {"Charlie", 103, 3.7},
        {"David", 104, 3.8}
    };

    int n = sizeof(students) / sizeof(students[0]);

    Student top = findTopStudent(students, 0, n - 1);

    cout << "Top Student:\n";
    cout << "Name: " << top.name << endl;
    cout << "ID: " << top.id << endl;
    cout << "CGPA: " << top.cgpa << endl;

    return 0;
}
