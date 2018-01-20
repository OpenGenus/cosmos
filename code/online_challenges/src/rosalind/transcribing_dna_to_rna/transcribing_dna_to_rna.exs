defmodule TranscribingDnaToRna do
  def transcribe(strand) do
    strand = String.codepoints(strand)
    new_strand = Enum.map(strand, fn nucleotide -> 
      case nucleotide do
        "T" -> 
          "U"
        _ -> 
          nucleotide
      end
    end)
    List.to_string(new_strand)
  end
end
