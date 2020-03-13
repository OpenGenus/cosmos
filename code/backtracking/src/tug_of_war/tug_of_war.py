# Python program for Tug of War using Backtracking

# Checks possible solution by calling recursion 
def TOW(array, n, current_elements, no_of_selected_elements, solution, min_diff, Sum, current_sum, current_pos): 
    
    # If out of bound 
    if (current_pos == n): 
        return
    
    # Checks that the numbers of elements left are not less than the number of elements required to form the solution 
    if ((int(n / 2) - no_of_selected_elements) > (n - current_pos)): 
        return

    # cases when current element is not included in the solution 
    TOW(array, n, current_elements, no_of_selected_elements, solution, min_diff, Sum, current_sum, current_pos + 1) 

    # Add the current element to the solution set
    no_of_selected_elements += 1
    current_sum = current_sum + array[current_pos] 
    current_elements[current_pos] = True

    # checks if a solution is obtained
    if (no_of_selected_elements == int(n / 2)): 
        # checks if the solution obtained is better than the best so far 
        if (abs(int(Sum / 2) - current_sum) < min_diff[0]): 
            min_diff[0] = abs(int(Sum / 2) - current_sum) 
            for i in range(n): 
                solution[i] = current_elements[i] 
    else: 
        
        # consider the cases where current element is included in the solution 
        TOW(array, n, current_elements, no_of_selected_elements, solution, min_diff, Sum, current_sum, current_pos + 1) 
    # removes current element before calling this function again 
    current_elements[current_pos] = False

def TugofWar(array, n): 
    #A boolean array that indicates the presence of an element in current set 
    #True indicates the presence and vice versa
    current_elements = [None] * n 
    # The indicator array for final solution 
    solution = [None] * n 
    min_diff = [99999999999] 
    Sum = 0
    for i in range(n): 
        Sum += array[i] 
        current_elements[i] = solution[i] = False 
    #Calling the recursive function TOW() 

    TOW(array, n, current_elements, 0, 
        solution, min_diff, Sum, 0, 0) 

    # Print the solution 
    print("The first subset is: ") 
    for i in range(n): 
        if (solution[i] == True): 
            print(array[i], end = " ") 
    print() 
    print("The second subset is: ") 
    for i in range(n): 
        if (solution[i] == False): 
            print(array[i], end = " ") 
 
if __name__ == '__main__': 
    lst = []
    n = int(input("Enter the number of elements : "))
    print("Enter the numbers : ")
    for i in range(0 , n):
           ele = int(input())
           lst.append(ele)
    TugofWar(lst, n) 


#SAMPLE INPUT AND OUTPUT
'''
SAMPLE 1
Enter the number of elements : 6
Enter the numbers :
12 
45
87
1
45
6
The first subset is: 
45 45 6 

The second subset is: 
12 87 1

SAMPLE 2
Enter the number of elements : 7
Enter the numbers :
23
45
12
1
0
76
89
The first subset is: 
45 1 76 

The second subset is: 
23 12 0 89
'''
