def fibonacci(n)
  case n
  when 0 then 0
  when 1 then 1
  else fibonacci(n-2) + fibonacci(n-1)
  end
end

def fibonacci_memoized(n)
  cache = { 0 => 0, 1 => 1 }
  if cache.has_key?(n)
    return cache.fetch(n)
  end
  cache[n] = fibonacci_memoized(n-2) + fibonacci_memoized(n-1)
  cache[n]
end

n = ARGV[0].to_i
puts fibonacci_memoized(n)