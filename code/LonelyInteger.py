# Part of Cosmos by OpenGenus Foundation
def lonely(l):
    if len(l) == 1 :
        return l[0] 

    x = 0 
    for ele in l :
        x = x ^ ele;

    return x 



def test() :
    testcases = [ [1,1,2,2,4] , [1] , [1,2,1,2,3,5,5] ]
    for test in testcases :
        print lonely(test) 


test() 
