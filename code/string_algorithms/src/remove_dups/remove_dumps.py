# Part of Cosmos by OpenGenus Foundation


def remove_dups(string):
    res = string[0]
    for ch in string:
        if res[-1] != ch:
            res += ch
    return res

string_ = input('Enter string: ')
res_str = remove_dups(string_)
print('Resultant string: ', res_str)
