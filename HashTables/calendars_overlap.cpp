#include <map>
#include <vector>

using namespace std;



/*
MOST IMPORTANT: control what is entered
make sure that ends do not overlap
-> compare start time of the exisiting booking with the end of the new booking
-> if end less than start then OK


*/

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto itr = books.upper_bound(start);
        
        if (itr == books.end() || end <= itr->second ) {
            books[end] = start;
            return true;
        }
        else return false;
    }
    
    // brute force
//     bool book(int start, int end) {
//            for(auto& book : booked) {
//                if (book.first <= start && start < book.second || 
//                   book.first < end && end <= book.second || 
//                   start < book.first && end >= book.second) {
//                    return false;
//                }
//            }
        
//         booked.push_back(make_pair(start, end));
//         return true;
//     }
    
    // end, start
    map<int, int> books;
    // vector<pair<int, int>> booked;
    
};

// arrays, hash tables