# special feature verbose mode -> to trace what is happening
import sys


class postfix:
    def __init__(self, verbose=False):
        self._stack = []
        self._verbose = verbose
        pass

    def evaluate(self, post_fix_string):
        if self._verbose:
            print("[!] Postfix Evaluation Started For :", post_fix_string)

        for x in post_fix_string:
            try:
                self._stack.append(int(x))
                if self._verbose:
                    print("[!] Pushed ", x, " in stack -> ", self._stack)
            except ValueError:
                self._act(x)

        if self._verbose:
            print("[!] Answer is : ", self._stack[0])
            return self._stack[0]
        else:
            return self._stack[0]

    def _act(self, operand):
        b = self._stack.pop()
        a = self._stack.pop()

        if self._verbose:
            print(
                "[!] Popped last two values from stack, a = {} and b = {} -> ".format(
                    a, b
                ),
                self._stack,
            )

        if operand == "+":
            self._stack.append(a + b)
            if self._verbose:
                print(
                    "[!] Performed {} + {} and Pushed in stack -> ".format(a, b),
                    self._stack,
                )
        elif operand == "/":
            try:
                self._stack.append(a // b)
                if self._verbose:
                    print(
                        "[!] Performed {} // (integer division) {} and Pushed in stack -> ".format(
                            a, b
                        ),
                        self._stack,
                    )
            except ZeroDivisionError:
                if self._verbose:
                    print(
                        "[x] Error : Divide By Zero at a = {} and b = {} with current stack state -> ".format(
                            a, b
                        ),
                        self._stack,
                    )
                sys.exit(1)

        elif operand == "-":
            self._stack.append(a - b)
            if self._verbose:
                print(
                    "[!] Performed {} - {} and Pushed in stack -> ".format(a, b),
                    self._stack,
                )
        elif operand == "*":
            self._stack.append(a * b)
            if self._verbose:
                print(
                    "[!] Performed {} * {} and Pushed in stack -> ".format(a, b),
                    self._stack,
                )

        pass

    pass


p_fix1 = postfix()
p_fix2 = postfix(verbose=True)  # with verbose mode
print("------ Without Verbose Mode ------")
print("Answer is", p_fix1.evaluate("12+3*1-"))

print("\n\n------ With Verbose Mode ------")
p_fix2.evaluate("1234+-/2+0/3-")  # raising exception intentionally
