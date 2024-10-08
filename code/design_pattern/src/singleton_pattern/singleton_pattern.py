class SingletonClass:
    _instance = None

    def __new__(cls, *args, **kwargs):
        if not cls._instance:
            cls._instance = super(SingletonClass, cls).__new__(
                cls, *args, **kwargs
            )

        return cls._instance

    def foo(self):
        print("bar")


# Usage
s1 = SingletonClass()
s2 = SingletonClass()

print(s1 is s2)  # Output: True, both refer to the same instance

s1.foo()  # Output: bar
s2.foo()  # Output: bar
