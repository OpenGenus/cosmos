# What are Prefix Notations?
Polish notation (PN), also known as Normal Polish notation (NPN), Łukasiewicz notation, Warsaw notation, Polish prefix notation or simply prefix notation, is a mathematical notation in which operators precede their operands, in contrast to the more common infix notation, in which operators are placed between operands, as well as reverse Polish notation (RPN), in which operators follow their operands.

# Application
 Prefix and Postfix notations are applied by computers while solving an expression, by converting that expression into either of those forms.

# Steps in converting Infix to Prefix
At first infix expression is reversed. Note that for reversing the opening and closing parenthesis will also be reversed.

```
for an example: The expression: A + B * (C - D)
after reversing the expression will be: ) D – C ( * B + A
```

**so we need to convert opening parenthesis to closing parenthesis and vice versa.**

After reversing, the expression is converted to postfix form by using infix to postfix algorithm. After that again the postfix expression is reversed to get the prefix expression.

# Algorithm
* Push “)” onto STACK, and add “(“ to end of the A
* Scan A from right to left and repeat step 3 to 6 for each element of A until the STACK is empty
* If an operand is encountered add it to B
* If a right parenthesis is encountered push it onto STACK
* If an operator is encountered then:
	 * Repeatedly pop from STACK and add to B each operator (on the top of STACK) which has same
        or higher precedence than the operator.
     * Add operator to STACK
* If left parenthesis is encountered then
	 * Repeatedly pop from the STACK and add to B (each operator on top of stack until a left parenthesis is encounterd)
	 * Remove the left parenthesis
* Exit  
