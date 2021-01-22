 #include <unordered_map>
 #include <vector>
 #include <queue>       // for max heap

 using namespace std;
 
 class npair {
    public:
    npair(int vals, int freqs) : val(vals), freq(freqs) {}
    int val;
    int freq;
    int getfreq() const {return freq;}
    int getval() const {return val;}
};


// create functor for max heap
class compare {
    public:
int operator() (const npair& p1, const npair& p2)
{
    return p1.getfreq() < p2.getfreq();
}
};



vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> result;
    unordered_map<int, int> hasht;
    
    for(int& num : nums) {
        if (hasht.find(num) == hasht.end())
            hasht[num] = 0;
        else
            hasht[num]++;
    }
    
    priority_queue<npair, vector<npair>, compare> heap;
    
    for(auto& p : hasht) {
        heap.push(npair(p.first, p.second));
    }
    
    for(int i = 0; i < k; i++) {
        result.push_back(heap.top().getval());
        heap.pop();
    }
    
    return result;
}


// related topics: heap, hash tables