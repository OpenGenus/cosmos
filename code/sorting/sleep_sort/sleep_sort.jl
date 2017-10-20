a = [5, 3, 6, 2, 3, 2, 2];

count = 0

function sleep_and_print(i)
    global count
    sleep(a[i])
    count += 1
    println(a[i])
end

for i=1:length(a)
    @async sleep_and_print(i)
end

# wait for all threads to complete
while count != length(a)
    sleep(1)
end
