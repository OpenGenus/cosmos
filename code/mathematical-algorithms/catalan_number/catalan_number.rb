def catalan(num)
  return 1 if num <= 1
  ans = 0
  i = 0

  while i < num
    first = catalan i
    second = catalan num - i - 1
    ans += (first * second)
    i += 1
  end
  ans
end

Integer x = 1
while x <= 10
  res = catalan x
  puts res
  x += 1
end
