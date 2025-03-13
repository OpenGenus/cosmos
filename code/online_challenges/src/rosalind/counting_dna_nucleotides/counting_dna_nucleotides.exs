defmodule CountingDnaNuleotides do
  def count_dna_nucleotides(strand) do
    points = String.codepoints(strand)
    Enum.reduce(points,%{:A => 0, :C => 0, :G => 0, :T => 0}, fn nucleotide, acc -> 
      IO.puts nucleotide
      case nucleotide do
        "A" ->
          acc = %{acc | :A => acc."A" + 1}
        "C" ->
          acc = %{acc | :C => acc."C" + 1}
        "G" ->
          acc = %{acc | :G => acc."G" + 1}
        "T" ->
          acc = %{acc | :T =>acc."T" + 1}
      end
    end)
  end
end
