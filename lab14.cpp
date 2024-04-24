#include <iostream>
using namespace std;

bool interpolationSearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right && x >= arr[left] && x <= arr[right]) {
        int pos = left + ((double)(right - left) / (arr[right] - arr[left])) * (x - arr[left]);
        if (arr[pos] == x)
            return true;
        if (arr[pos] < x)
            left = pos + 1;
        else
            right = pos - 1;
    }
    return false;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    int perfect_numbers[] = { 6, 28, 496, 8128, 33550336 };
    int perfect_count = sizeof(perfect_numbers) / sizeof(perfect_numbers[0]);

    int num;
    cout << "Enter the number to search: ";
    cin >> num;

    if (interpolationSearch(perfect_numbers, perfect_count, num))
        cout << num << " is a perfect number." << endl;
    else
        cout << num << " is not a perfect number." << endl;

    return 0;
}