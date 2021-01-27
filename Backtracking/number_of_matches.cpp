

// the final match count is always n - 1 where n is the numberof teams, 
// below is just a nice recursive implementation(whice is not required but still nice)
int numberOfMatches(int n) {
    if (n == 1) return 0;
    
    int teams;
    int num;        // number of matches
    if (n % 2 == 0) {
        teams = n/2;
        num = n/2;
    }
    else {
        teams = n/2 + 1;
        num= n/2;
    }
    
    return numberOfMatches(teams) + num;
}

// O(n)
int numberOfMatches2(int n) {
    return n - 1;
}

// backtracking 