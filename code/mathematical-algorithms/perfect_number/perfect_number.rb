def perfect i
    sum = 0
    for n in 1..i-1
      if i % n == 0
        sum += n
      end
    end

    if sum == i
      p `#{i} is perfect number`
    else
      p `#{i} isn't perfect number`
    end
end

puts "Enter the number to check: "
perfect gets.chomp.to_i
