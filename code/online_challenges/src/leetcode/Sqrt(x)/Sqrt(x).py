# Part of Cosmos by OpenGenus Foundation

def sqrt(x: int) -> int:
    
    """
    Returns the integer square root of x.
    Example: print(sqrt(16)) => 4
    """
    
    if x < 2:
        return x

    left, right = 1, x // 2
    
    while left <= right:
        
        mid = (left + right) // 2
        
        if mid * mid == x:
            return mid
        
        elif mid * mid < x:
            left = mid + 1
            
        else:
            right = mid - 1
            
    return right
