# Part of Cosmos by OpenGenus Foundation
from sys import version_info

if version_info[0] < 3:   # python 2 code
    def replace_0_5(user_input):
        try:
            if isinstance(int(user_input), int):
                int_to_str = str(user_input)
                modified = ''
                for i in int_to_str:
                    if i == '0':
                        modified += '5'
                    else:
                        modified += i
            return modified
        except Exception:
            print("You did not specify an integer")

    user_input = raw_input("Enter the number: ")
    new_str = replace_0_5(user_input)
    print("Modified number: " + new_str)

else:   # python 3 code
    def replace_0_5_iterative(user_input):
        modified = ''
        for i in user_input:
            if i == '0':
                modified += '5'
            else:
                modified += i
        return modified
              
    def replace_0_5_pythonic(user_input):
        return user_input.replace('0', '5')
 
    user_input = input('Enter the number: ')
    new_str = replace_0_5_pythonic(user_input)
    print('Modified number:', new_str)
