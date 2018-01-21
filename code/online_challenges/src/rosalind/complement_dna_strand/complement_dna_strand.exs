defmodule ComplementDnaStrand do
  def complement(strand) do
    strand = strand |> String.reverse |> String.codepoints
    Enum.map(strand, fn nucleotide -> 
      case nucleotide do 
        "A" -> "T"
        "T" -> "A"
        "G" -> "C"
        "C" -> "G"
      end
    end) 
    |> List.to_string
  end
end

IO.puts ComplementDnaStrand.complement("")
