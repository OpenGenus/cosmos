// Robin Karp algorithm  
// Key idea -  generate a rolling hash.
// Once the rolling hash is a the same - we need to match character by character. 

uint64_t startHash (string & s, int start, int end) {
    uint64_t hash = 0;
    int p = 17;
    
    for (int i = start; i < end+1; i++) {
        hash = hash+(s[i]*(pow(p, i-start)));
    }
    
    return hash;
}

uint64_t rollingHash(string & s, uint64_t prev_hash, int start, int end) {
    // Check for start and end in the range in  the calling function. 
    
    uint64_t hash = prev_hash;
    int p = 17;
    hash = (hash - s[start-1])/p;
    hash = hash + (s[end]*(pow(p,end-start)));
    return hash;
}

bool charCompare(string & hay, string & need, int start, int end) {
    int hay_s = start;
    int need_s = 0;
    while (need_s < need.size()) {
        if (hay[hay_s+need_s] == need[need_s]) {
            need_s++;
            continue;
        } else {
            break;
        }
    }
    if (need_s == need.size()) {
        return true;
    }
    return false;
}

int strStr(string haystack, string needle) {
    
        int hay_size = haystack.size();
        int need_size = needle.size();
        
        if (need_size == 0) return 0;
        if (hay_size < need_size) return-1;
        
        uint64_t need_hash = startHash(needle, 0, need_size-1);
        uint64_t hay_hash = 0;
        
        // hay_hash = startHash(haystack, 0, needle.length()-1);
        
        for (int i = 0; i < hay_size - need_size + 1; i++) {
            if (i == 0)  { 
                hay_hash = startHash(haystack, i, i+need_size-1);
            } else {
                hay_hash = rollingHash(haystack, hay_hash, i, i+need_size-1);
            }
            if (hay_hash == need_hash) {
                // do a char by char comparison.
                if (charCompare(haystack, needle, i ,i+need_size-1)) {
                    return i;
                }
            }
        }
        return -1;           
}
