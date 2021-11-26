# string algorithms | pangram checker | pangram | RUBY
// Part of Cosmos by OpenGenus Foundation

=end


def pangram?(candidate)
  ([*'a'..'z'] - candidate.downcase.chars).empty?
end
