def tokenize(x):
    if(ord(x)>=ord('a') and ord(x)<=ord('z')):
        return ord(x)-97
    elif(ord(x)>=ord('A') and ord(x)<=ord('Z')):
        return ord(x)-39
    elif(x == ' '):
        return 52
    elif(x == '.'):
        return 53
    elif(x == ','):
        return 54
    elif(x == "'"):
        return 55
    elif(x == '?'):
        return 56
    elif(x == '!'):
        return 57
    elif(x == ';'):
        return 58
    elif(x == ":"):
        return 59
    elif(x == '\n'):
        return 60
    else:
        return "UNKNOWN"

def detokenize(x):
    if(x>=0 and x<=25):
        return chr(x+97)
    elif(x>=26 and x<=51):
        return chr(x+39)
    elif(x==52):
        return ' '
    elif(x==53):
        return '.'
    elif(x==54):
        return ','
    elif(x==55):
        return "'"
    elif(x==56):
        return '?'
    elif(x==57):
        return '!'
    elif(x==58):
        return ';'
    elif(x==59):
        return ':'
    elif(x==60):
        return '\n'
    else:
        return "UNKNOWN"

