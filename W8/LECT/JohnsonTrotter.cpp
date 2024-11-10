#include <iostream>
#include <vector>

using namespace std;

// Structure for elements with a direction
struct Element {
    int value;
    bool direction; // true for left, false for right
};

// Function to initialize elements with default direction (left)
vector<Element> initializeElements(int n) {
    vector<Element> elements;
    for (int i = 1; i <= n; i++) {
        elements.push_back({i, true}); // true = left
    }
    return elements;
}

// Utility function to print current permutation
void printPermutation(const vector<Element>& elements) {
    for (const auto& elem : elements) {
        cout << elem.value << " ";
    }
    cout << endl;
}

// Debug function to print directions of elements
void printDirections(const vector<Element>& elements) {
    for (const auto& elem : elements) {
        cout << elem.value << "(" << (elem.direction ? "L" : "R") << ") ";
    }
    cout << endl;
}

// Function to find the largest movable element
int findLargestMovable(const vector<Element>& elements) {
    int largestIndex = -1;
    int largestValue = -1;

    for (int i = 0; i < elements.size(); i++) {
        int neighborIndex = i + (elements[i].direction ? -1 : 1); // Move directionally
        if (neighborIndex >= 0 && neighborIndex < elements.size() &&
            elements[i].value > elements[neighborIndex].value && 
            elements[i].value > largestValue) {
            largestIndex = i;
            largestValue = elements[i].value;
        }
    }
    return largestIndex;
}

// Function to reverse the direction of elements larger than the given value
void reverseDirections(vector<Element>& elements, int value) {
    for (auto& elem : elements) {
        if (elem.value > value) {
            elem.direction = !elem.direction;
            cout << "Reversing direction of " << elem.value << " to " << (elem.direction ? "L" : "R") << endl;
        }
    }
}

// Johnson-Trotter algorithm to generate all permutations
void johnsonTrotter(int n) {
    vector<Element> elements = initializeElements(n);

    // Print the initial permutation and directions
    cout << "Initial permutation: ";
    printPermutation(elements);
    cout << "Directions: ";
    printDirections(elements);

    while (true) {
        int largestMovableIndex = findLargestMovable(elements);
        
        // If no movable element, end the algorithm
        if (largestMovableIndex == -1) break;

        // Swap the largest movable element in its direction
        int neighborIndex = largestMovableIndex + (elements[largestMovableIndex].direction ? -1 : 1);
        cout << "Moving " << elements[largestMovableIndex].value << " from index " << largestMovableIndex
             << " to " << neighborIndex << " ("
             << (elements[largestMovableIndex].direction ? "left" : "right") << ")" << endl;

        swap(elements[largestMovableIndex], elements[neighborIndex]);

        // Reverse direction of elements greater than the moved element
        reverseDirections(elements, elements[neighborIndex].value);

        // Print the current permutation and updated directions
        cout << "Permutation: ";
        printPermutation(elements);
        cout << "Directions: ";
        printDirections(elements);
        cout << "-----------------------------" << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    johnsonTrotter(n);

    return 0;
}
