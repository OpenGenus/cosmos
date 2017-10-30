# created by AnkDos
# You can Simply use '**' to cube ,ex. 3**3=27 ,so cube(remainder) can be written as (reminder**3)
def cube(num)
  num * num * num
end

def Is_armstrong(num)
  quotient = 1
  reminder = 0
  sum = 0
  hold = num
  while quotient > 0
    quotient = num / 10
    reminder = num % 10
    sum += cube(reminder)
    num = quotient
  end
  hold == sum
end

puts Is_armstrong(153).to_s # output => true
