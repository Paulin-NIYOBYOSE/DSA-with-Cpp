#include <iostream>  // Include the iostream library for input/output operations
using namespace std;  // Use the standard namespace to avoid prefixing 'std::' for standard functions

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    bool swapped;  // A flag to track if any elements were swapped in the inner loop
    // Outer loop for iterating over each element
    for (int i = 0; i < n - 1; i++) {
        swapped = false;  // Reset swapped flag at the beginning of each iteration
        // Inner loop to compare adjacent elements and bubble the largest element to the end
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {  // If current element is greater than next element, swap them
                swap(arr[j], arr[j + 1]);  // Swap the elements if they are in the wrong order
                swapped = true;  // Mark that a swap has occurred
            }
        }
        // If no elements were swapped during the inner loop, the array is already sorted
        if (!swapped)  // No swaps means the array is sorted, so break out of the outer loop
            break;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {  // Loop to go through each element in the array
        cout << arr[i] << " ";  // Print each element followed by a space
    }
    cout << endl;  // Print a newline after printing all elements
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};  // Array to be sorted
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the number of elements in the array

    bubbleSort(arr, n);  // Call the bubbleSort function to sort the array
    cout << "Sorted array: ";  // Output message before printing the sorted array
    printArray(arr, n);  // Call the printArray function to print the sorted array

    return 0;  // Return 0 to indicate the program ended successfully
}
