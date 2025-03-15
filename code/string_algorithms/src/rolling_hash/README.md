# cosmos #
Your personal library of every algorithm and data structure code that you will ever encounter


Collaborative effort by [OpenGenus](https://github.com/opengenus)

## Rolling Hash
* Want to find pattern P in very long string S
* Compare the  hash P to  hash a moving window of S with length  P

## Implementation Steps:
1. Hash P **O(|P|)**
2. Hash first |P| window of S **O(|P|)**
3. Roll over S, one window at a time **O(|S|)**
4. If hash of P matches window hash check if the full strings match **O(|P|)** 
* The runt ime of the last step is amortized, worst case it will be **O(|P|*|S|)** to compare each letter in each string. We will only have to do that when there is a hash collision - which means the hashes of P and the window are the same.

