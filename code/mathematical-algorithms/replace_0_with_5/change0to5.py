# Part of Cosmos by OpenGenus Foundation

# python 2 code:
user_input = raw_input("Enter the number: ")
try:
  if isinstance(int(user_input), int):
    int_to_str = str(user_input)
    modified = ''
    for i in range(len(int_to_str)):
      if int_to_str[i] == '0':
        modified += '5'
      else:
        modified += int_to_str[i]

  print("Modified number: " + modified)

except Exception:
  print("You did not specify an integer")

  
# python 3 code:
user_input = int(input('Enter the number: '))
string_input = str(user_input)
modified = string_input.replace('0', '5')
print("Modified number: " + modified)
  
