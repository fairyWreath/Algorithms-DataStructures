#include <vector>
#include <unordered_set>

using namespace std;

// basically detect a cycle
bool isHappy(int n) {
    unordered_set<int> st;
    
    while(true){
        if(st.find(n)!=st.end())return false;//if cycle then break
        st.insert(n);
        
        long long squreSum = 0;
        
        while(n){
            squreSum+=(pow(n%10,2));
            n/=10;
        }
        
        if(squreSum==1) return true;
        n = squreSum;
    }
    
}
// hash table, math