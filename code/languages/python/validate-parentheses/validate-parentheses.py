def validateParentheses(parentheses):
    queue=[]
    for ch in parentheses:
        #enqueue for open-character
        if ch in ('(','{','['):
            queue.append(ch)
        #dequeue for close-character    
        elif ch in (')','}',']'):
            pre_ch = queue.pop()
            #Validate for matching pair open and close character
            if ( ch==')' and pre_ch!='(' ) or ( ch==']' and pre_ch!='[' ) or ( ch=='}' and pre_ch!='{' ) : 
                return False
        #any different character        
        else:
            return False
    #any remain character
    if (len(queue) > 0):
        return False
    #Success
    return True


parentheses = input('Enter a string to validate:')
print(validateParentheses(parentheses))
