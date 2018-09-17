class Solution {
public:
    string toLowerCase(string str) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
};
