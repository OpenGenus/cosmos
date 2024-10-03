# CockTail Sort! 🍸 # 
# Basically, this algorithm try to solve the "Rabbits and Turtles" issue from bubble sort
# I recomend this two videos to understand better the algorithm and the problem.

# https://www.youtube.com/watch?v=xli_FI7CuzA ==> About Bubble Sort
# https://www.youtube.com/watch?v=Xmx_6YRBaq8&t=150s ==> About Cocktail Sort

# A hi from Brazil! ~ Caio 

def cocktail_sort(array):
    counter = len(array)
    while counter > 0: 
        # Normal Bubble Sort Algorithm (left -> right)
        for i in range(len(array) - 1):
            if array[i] > array[i + 1]: 
                array[i], array[i + 1] = array[i + 1], array[i] # Switch Positions
                
        # Bubble Sort In the Other Way (right -> left)
        for j in range(-1, len(array), -1):
             if array[j] < array[j - 1]:
                array[j], array[j - 1] = array[j - 1], array[j] # Switch Positions
        counter -= 1
    return array

example_array = [3, 4, 2, 0, 5, 6, 7, 1]
print(example_array)
ordened_array = cocktail_sort(example_array)
print(ordened_array)
