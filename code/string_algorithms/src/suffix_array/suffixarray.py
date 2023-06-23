def suffixArray(word):
    suffixArray = []
    for counter in range(len(word), 0, -1): #for loop that counts in reverse order, starting from length of the word till 0
        suffixArray.append(word[0:counter]) #appending the substring from 0 to counter 
    return suffixArray
    
  
print(suffixArray(input("Enter a word to find suffix : "))) 
        
    