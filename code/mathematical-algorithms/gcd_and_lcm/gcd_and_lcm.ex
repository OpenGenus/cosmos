# Part of Cosmos by OpenGenus Foundation
defmodule GCDandLCM do
  def gcd(x, 0), do: x
  def gcd(x, y), do: gcd(y, rem(x, y))

  def lcm(x, y), do: x * y / gcd(x, y)
end
