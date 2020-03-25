T = int(raw_input());

while(T>0):
    T -= 1;
    ans=1;
    
    N, k = map(int, raw_input().split());
    
    if(N==k):
        print(ans);
    else:
        N = N-1;
        k = k-1;
        
        if(k>N/2):
            k = N-k;
         
        ans=1;    
        for i in range(k):
            ans = ans*(N-i);
            ans = ans/(i+1);
        
        print(ans);    
        