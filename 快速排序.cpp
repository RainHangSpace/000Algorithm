#include <vector>
#include <iostream>
using namespace std;

void swap(vector<int>& arr, int i, int j) {
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

void quickSort(vector<int>& arr, int L, int R) {
    if (L >= R)return;
    int base = arr[L];
    int right = R, left = L;
    while (left < right) {
        while (left < right && arr[right] >= base)--right;
        if (left < right) arr[left++] = arr[right];
        while (left < right && arr[left] <= base) ++left;
        if (left < right) arr[right--] = arr[left];
    }
    arr[left] = base;
    quickSort(arr, L, left - 1);
    quickSort(arr, left + 1, R);
}

vector<int> getLeastNumbers(vector<int>& arr, int k) {
    quickSort(arr, 0, arr.size() - 1);
    return vector<int>(arr.begin(), arr.begin() + k);
}
int main() {
    vector<int> vec{ 5,2,3,1 };
    quickSort(vec, 0, vec.size() - 1);
    for (auto i : vec) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}