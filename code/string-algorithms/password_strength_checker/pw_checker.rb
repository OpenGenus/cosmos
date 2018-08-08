# Part of Cosmos by OpenGenus Foundation

def check_pass(password)
  pattern_numbers = /[0-9]/
  pattern_upcase = /[A-Z]/
  pattern_downcase = /[a-z]/
  pattern_special_char = /\W/

  has_number = pattern_numbers =~ password
  has_upcase_letter = pattern_upcase =~ password
  has_downcase_letter = pattern_downcase =~ password
  has_especial_char = pattern_special_char =~ password
  has_min_length = password.size >= 8

  is_strong_pass = !has_number.nil? && (has_min_length != false) && !has_upcase_letter.nil? &&
   !has_downcase_letter.nil? && !has_especial_char.nil?

  puts "The password doesn't have the minimum length" if !has_min_length
  puts "The password doesn't have a number digit" if has_number.nil?
  puts "The password doesn't have any uppercase letter" if has_upcase_letter.nil?
  puts "The password doesn't have any lowercase letter" if has_downcase_letter.nil?
  puts "The password doesn't have any special character" if has_especial_char.nil?

  is_strong_pass
end

password = "XmkA78Ji#"
puts check_pass password
