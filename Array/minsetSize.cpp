#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

// create map and sort map

vector<pair<int, int> > sort(map<int, int>& M) 
{ 

    // Declare vector of pairs 
    vector<pair<int, int> > A; 

    // Copy key-value pair from Map 
    // to vector of pairs 
    for (auto& it : M) { 
        A.push_back(it); 
    } 

    auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
        //  descending order
        return a.second > b.second; 
    };
    
    // Sort using comparator function 
    std::sort(A.begin(), A.end(), cmp); 

    return A;
} 

int minSetSize(vector<int>& arr) {
    
    // use ordered map
    map<int, int> hashmap;
    
    for(int& i : arr)
        hashmap[i]++;
    
//    vector<pair<int, int>> V = sort(hashmap);
    
    int count = 0;
    int n = arr.size();
    int curr = n;
    
    //  cout << n << endl << endl;
    // for a more general case(without the actual value of the set, just amount)
    // use vector only containing frequencies
    vector<int> freqs;
    for(auto& p : hashmap)
        freqs.push_back(p.second);
    std::sort(freqs.begin(), freqs.end(), greater<int>());
    
    for(auto& freq : freqs) {
        count++;
        curr -= freq;
        if (curr <= n/2) break;
    }
    
    
    // for(auto& p : V) {
    //     count++;
        //   curr -= p.second;
        // //  cout << p.second << endl;
        //   if (curr <= n / 2) break;
    // }
    
    
    return count;
}

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    int res = minSetSize(v);

    cout << endl << res;
}


// arrays, greedy