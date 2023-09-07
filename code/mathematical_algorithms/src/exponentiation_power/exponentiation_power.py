def pow(a,b):
    '''
    INPUT: int a, int b
    This function computes a to the power b
    Here it uses logic of divide in half and multiple efficiently
    OUTPUT: return float answer for a**b
    '''
    
    if(b==0): # exit condition
        return 1

    temp = pow(a,b//2)   # recursively call pow function for b/2

    if(b%2==0):          
        return(temp*temp)
    else:
        return(a*temp*temp)



