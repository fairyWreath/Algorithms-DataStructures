#include <vector>

using namespace std;


bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    
    bool prev = false;
    
    for(int i = 0; i < flowerbed.size(); i++) {
        int flower = flowerbed[i];
        if (flower == 1 && !prev) prev = true;
        
        if(flower == 0 && prev) {
            prev = false;
            continue;
        }
        
        if(!prev) {
            if (i < flowerbed.size() - 1) {
                if (flowerbed[i + 1] != 1)      // if next not 1
                        count++;
            }
            else count++;       // last flower
            prev = true;
        }
    }
    
    return count >= n;
}

// array, greedy