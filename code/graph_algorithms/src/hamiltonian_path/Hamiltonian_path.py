def Hamiltonian_path(adj, N):
    arr = [[False for i in range(1 << N)]
                 for j in range(N)]
 
    for i in range(N):
        arr[i][1 << i] = True
 
    for i in range(1 << N):
        for j in range(N):
            if ((i & (1 << j)) != 0):
                for k in range(N):
                    if ((i & (1 << k)) != 0 and
                             adj[k][j] == 1 and
                                     j != k and
                          arr[k][i ^ (1 << j)]):
                         
                        arr[j][i] = True
                        break
     
    #Check if Hamiltonian Path exists
    for i in range(N):
        if (arr[i][(1 << N) - 1]):
            return True
    return False
 
if __name__ == '__main__':
    # Sample Graph
    adj = [ [ 0, 1, 1, 1, 0 ] ,
            [ 1, 0, 1, 0, 1 ],
            [ 1, 1, 0, 1, 1 ],
            [ 1, 0, 1, 0, 0 ] ]
    
    N = len(adj)
    
    if (Hamiltonian_path(adj, N)):
        print("Hamiltonian Path Exists !")
    else:
        print("NO")
