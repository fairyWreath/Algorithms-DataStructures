#include <vector>
#include <iostream>

using namespace std;

int partition(vector<int>& arr, int p, int r) {
    // pivot, choose first element
    int x = arr[p]; 
    int i = p - 1;
    int j = r + 1;
    while(true) {
        do {
            j--;
        } while(!(arr[j] <= x));
        do {
            i++;
        } while(!(arr[i] >= x));
        if (i < j) std::swap(arr[i], arr[j]);
        else  return j;         // if return last, choose first element as pivot
    }
}

void quickSort(vector<int>& arr, int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        cout << p << endl;
        quickSort(arr, p, q);
        quickSort(arr, q + 1, r);
    }
}


vector<int> sortArray(vector<int>& nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
}

int main() {
    vector<int> s{10, 9, 8};
    quickSort(s, 0, s.size() - 1);
    for(auto& num : s) cout << num;
}