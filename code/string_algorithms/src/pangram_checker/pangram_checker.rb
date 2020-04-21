def pangram?(candidate)
  ([*'a'..'z'] - candidate.downcase.chars).empty?
end
