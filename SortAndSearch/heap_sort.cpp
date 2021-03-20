#include <vector>
#include <iostream>

using namespace std;


    // heap sort :p
    
int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

int parent(int i) {
    return i / 2;
}

void heapify(vector<int>& arr, int i) {
    int l = left(i);
    int r = right(i);
    int n = arr.size();
    int largest = i;
    if (l <= n && arr[l - 1] > arr[i - 1])
        largest = l;
    if (r <= n && arr[r - 1] > arr[largest - 1])
        largest = r;
    if (largest != i) {
        swap(arr[i - 1], arr[largest - 1]);
        heapify(arr, largest);
    }
}

void heapify(vector<int>& arr, int i, int n) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l <= n && arr[l - 1] > arr[i - 1])
        largest = l;
    if (r <= n && arr[r - 1] > arr[largest - 1])
        largest = r;
    if (largest != i) {
        swap(arr[i - 1], arr[largest - 1]);
        heapify(arr, largest);
    }
}

void buildHeap(vector<int>& arr) {
    for(int i = 0; i < arr.size() / 2 ; i++) {
        heapify(arr, i + 1);                // i + 1 for 'normal' index
    }
}

void sortColors(vector<int>& nums) {
    // std::sort(nums.begin(), nums.end());        // ROFL
    
    // do LADAN"S HEAPSORT
    buildHeap(nums);
    int n = nums.size();
    // for(int i = nums.size() - 1; i > 0; i--) {
    //     swap(nums[0], nums[i]);
    //     cout << nums[0];
    //     n--;
    //     heapify(nums, 1, n);
    // }
    
}


int main() {
    vector<int> test{4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    buildHeap(test);

    for(int& tes :test) cout << tes  << " ";
}