#include <iostream>
using namespace std;

// Function to check if a character is a vowel
bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Divide and Conquer function
int countVowels(string &s, int left, int right) {
    // Base case
    if (left > right)
        return 0;

    if (left == right)
        return isVowel(s[left]) ? 1 : 0;

    // Divide
    int mid = (left + right) / 2;

    // Conquer
    int leftCount = countVowels(s, left, mid);
    int rightCount = countVowels(s, mid + 1, right);

    // Combine
    return leftCount + rightCount;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int result = countVowels(str, 0, str.length() - 1);

    cout << "Total vowels: " << result << endl;

    return 0;
}
