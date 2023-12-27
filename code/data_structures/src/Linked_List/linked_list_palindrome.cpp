// Check if the liked list is palindrome or not 
 bool checkpalindrome(vector<int> arr){
        int s = 0;
        int e = arr.size() -1;
        while(s<=e){
            if(arr[s] != arr[e]){
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }
 
    bool isPalindrome(Node *head)
    {
        vector<int>arr;
        Node* temp = head;
        while(temp != NULL){
            arr.push_back(temp -> data);
            temp = temp -> next;
        }
        return checkpalindrome(arr);
    }
