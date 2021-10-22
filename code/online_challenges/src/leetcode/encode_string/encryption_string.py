# -*- coding: utf-8 -*-
"""

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
"""

class Encryption:
	
  ## APPROACH : 2 Stacks
  def decodeString(self, string: str) -> str:        
        
	## TIME COMPLEXITY : O(N) 
	## SPACE COMPLEXITY : O(N)

        number = []
        string = []
        num = ""
        char = ""
        for i, ch in enumerate(string):
            if ch.isdigit():
                num += ch
            elif ch == "[":
                number.append(int(num))
                string.append(char)
                num = ""
                char = ""
            elif ch == "]":
                char =  string.pop() + number.pop() * char
            else:
                char += ch
        return char

String_object = Solution()
# testcases
String_object.decodeString("3[a]2[bc]")

String_object.decodeString("3[a2[c]]")

String_object.decodeString("2[abc]3[cd]ef")

String_object.decodeString("abc3[cd]xyz") 
