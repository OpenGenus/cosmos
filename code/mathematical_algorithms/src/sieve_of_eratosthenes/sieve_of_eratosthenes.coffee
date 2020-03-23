SieveOfEratosthenes = (n) ->
    prime = Array(n + 1).fill(true)

    i = 2
    while i*i <= n
        if prime[i] is true
            for j in [2 * i...n] by i
                prime[j] = false

        i += 1

    string = ""
    for i in [2...n]
        if prime[i] is true
            string += i + " "

    console.log string

    0 # Return 0


n = 30

console.log "Following are the prime numbers smaller than or equal to " + n
SieveOfEratosthenes n


### Output
Following are the prime numbers smaller than or equal to 30
2 3 5 7 11 13 17 19 23 29
###
