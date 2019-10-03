print("Enter a number to check if it is a power of 2: ")
n = parse(Int64, chomp(readline()))

if (n != 0) && (n & (n-1) == 0)
    println("YES")
else
    println("NO")
end
