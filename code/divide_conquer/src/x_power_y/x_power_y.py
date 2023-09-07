# Without function
# Works only if a >= 0 and b >= 0  
def pow(a,b): 
    if(b==0): 
        return 1
          
    answer=a 
    increment=a 
      
    for i in range(1,b): 
        for j in range (1,a): 
            answer+=increment 
        increment=answer 
    return answer 
  
# driver code 
print(pow(5,3)) 
