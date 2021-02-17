#include <vector>

using namespace std;


// some mountainarray class
class MountainArray
{
public:
    int get(int index) {return 1; }
    int length() {return 2;}
};

int binarysDesc(MountainArray &mountainArr, int start, int end, int target) {
    if (start > end) return -1;
    
    int mid = start + (end - start) / 2;
    if (mountainArr.get(mid) == target) return mid;
    
    if (target > mountainArr.get(mid))
        return binarysDesc(mountainArr, start, mid-1, target);
    else
        return binarysDesc(mountainArr, mid+1, end, target);
}

int binarysAsc(MountainArray &mountainArr, int start, int end, int target) {
    if (start > end) return -1;
    
    int mid = start + (end - start) / 2;
    if (mountainArr.get(mid) == target) return mid;
    
    if (target < mountainArr.get(mid))
        return binarysAsc(mountainArr, start, mid-1, target);
    else
        return binarysAsc(mountainArr, mid+1, end, target);
}


// binary search for the peak
int binaryPeak(MountainArray &mountainArr, int start, int end) {
    if (start > end) return -1;
    
    int mid =  ceil(start + (end - start) / (double)2);
    
    // guaranteed to be in the middle
    if (mountainArr.get(mid - 1) < mountainArr.get(mid) && mountainArr.get(mid) > mountainArr.get(mid+1))
        return mid;
    
        if (mountainArr.get(mid - 1) < mountainArr.get(mid) && mountainArr.get(mid) < mountainArr.get(mid+1))
            return binaryPeak(mountainArr, mid + 1, end);
    else return binaryPeak(mountainArr, start, mid - 1);
}

// binary search three times
int findInMountainArray(int target, MountainArray &mountainArr) {
    int n = mountainArr.length() - 1;
    int peak = binaryPeak(mountainArr, 0, n);

    int left = binarysAsc(mountainArr, 0, peak, target);
    int right = binarysDesc(mountainArr, peak + 1, n, target);
    
    if (left != -1) return left;
    else return right;
}

// arrays