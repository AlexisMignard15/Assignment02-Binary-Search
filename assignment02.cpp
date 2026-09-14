#include <iostream>
#include <vector>
#include <string>

using namespace std;

int iterativeBinarySearch(const vector<int>& data, int target,
                          int& comparisons) {
    int left = 0;
    int right = static_cast<int>(data.size()) - 1;
    comparisons = 0;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        comparisons++;

        if (data[middle] == target) {
            return middle;
        }

        if (data[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int recursiveBinarySearchHelper(const vector<int>& data, int target,
                                int left, int right, int& comparisons) {
    if (left > right) {
        return -1;
    }

    int middle = left + (right - left) / 2;
    comparisons++;

    if (data[middle] == target) {
        return middle;
    }

    if (data[middle] < target) {
        return recursiveBinarySearchHelper(
            data, target, middle + 1, right, comparisons
        );
    }

    return recursiveBinarySearchHelper(
        data, target, left, middle - 1, comparisons
    );
}

int recursiveBinarySearch(const vector<int>& data, int target,
                          int& comparisons) {
    comparisons = 0;

    return recursiveBinarySearchHelper(
        data,
        target,
        0,
        static_cast<int>(data.size()) - 1,
        comparisons
    );
}

int linearSearch(const vector<int>& data, int target, int& comparisons) {
    comparisons = 0;

    for (int i = 0; i < static_cast<int>(data.size()); i++) {
        comparisons++;

        if (data[i] == target) {
            return i;
        }
    }

    return -1;
}

void runTest(const vector<int>& data, int target,
             const string& description) {
    int iterativeComparisons;
    int recursiveComparisons;
    int linearComparisons;

    int iterativeIndex =
        iterativeBinarySearch(data, target, iterativeComparisons);

    int recursiveIndex =
        recursiveBinarySearch(data, target, recursiveComparisons);

    int linearIndex =
        linearSearch(data, target, linearComparisons);

    cout << description << " (target = " << target << ")\n";

    cout << "  Iterative binary search: index = "
         << iterativeIndex
         << ", comparisons = "
         << iterativeComparisons << '\n';

    cout << "  Recursive binary search: index = "
         << recursiveIndex
         << ", comparisons = "
         << recursiveComparisons << '\n';

    cout << "  Linear search:           index = "
         << linearIndex
         << ", comparisons = "
         << linearComparisons << "\n\n";
}

int main() {
    const vector<int> data =
        {3, 7, 11, 18, 24, 31, 42, 56, 68, 79, 91};

    cout << "Sorted data: ";

    for (int value : data) {
        cout << value << ' ';
    }

    cout << "\n\n";

    runTest(data, 3, "Test 1: First element");
    runTest(data, 91, "Test 2: Last element");
    runTest(data, 31, "Test 3: Middle element");
    runTest(data, -5, "Test 4: Missing value below the range");
    runTest(data, 50, "Test 5: Missing value inside the range");

    return 0;
}
