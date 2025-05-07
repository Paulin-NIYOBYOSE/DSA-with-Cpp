#include <iostream>  // Include the iostream library for input/output operations
using namespace std;  // Use the standard namespace to avoid prefixing 'std::' for standard functions

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    // Start iterating from the second element (index 1), as the first element is trivially sorted
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // The element to be inserted into the sorted portion of the array
        int j = i - 1;  // j is the index of the last element of the sorted portion

        // Move elements of arr[0..i-1] that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {  // While elements are greater than the key, shift them right
            arr[j + 1] = arr[j];  // Shift the element to the right to make space for the key
            j = j - 1;  // Move the index of the sorted portion one step left
        }
        arr[j + 1] = key;  // Place the key at the correct position in the sorted portion
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {  // Loop through each element in the array
        cout << arr[i] << " ";  // Print the element followed by a space
    }
    cout << endl;  // Print a newline after all elements
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};  // The array to be sorted
    int n = sizeof(arr);  // Calculate the number of elements in the array

    insertionSort(arr, n);  // Call the insertionSort function to sort the array
    cout << "Sorted array: ";  // Output message before printing the sorted array
    printArray(arr, n);  // Call the printArray function to print the sorted array

    return 0;  // Return 0 to indicate that the program finished successfully
}
