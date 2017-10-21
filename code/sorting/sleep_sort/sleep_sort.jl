count = 0

function sleep_and_print(n)
    global count
    sleep(n)
    count += 1
    println(n)
end

a = [5, 3, 6, 2, 3, 2, 2];
for i=1:length(a)
    @async sleep_and_print(a[i])
end

# wait for all threads to complete
while count != length(a)
    sleep(1)
end
