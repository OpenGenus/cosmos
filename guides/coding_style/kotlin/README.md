# Cosmos Guides
> Your personal library of every algorithm and data structure code that you will ever encounter

# Kotlin Style Guide
([Source](https://kotlinlang.org/docs/reference/))

## Coding Conventions

## Index
- [Naming Style](#naming-style)
- [Colon](#colon)
- [Lambdas](#lambdas)
- [Class Header Formatting](#class-header-formatting)
- [Unit](#unit)
- [Functions vs Properties](#functions-vs-properties)

### Naming Style
* Use camelCase (and avoid underscores) for names
* Types start with upper case
* Methods and properties start with lower case
* Use four space indentation
* Public functions should have documentation such that it appears in Kotlin Doc

### Colon
* Use a space before the colon where a colon separates type and supertype
* Do not use a space where colon separates instance and type

```
interface Foo<out T : Any> : Bar {
    fun foo(a: Int): T
}
```

### Lambdas
* In lambda expressions, spaces should be used around the curly brace
* Spaces should also be placed around the arrow which separates the parameters from the body
* Whenever possible, a lambda should be passed outside of parentheses

```
list.filter { it > 10 }.map { element -> element * 2 }
```

* In short and nested lambdas, you should use the it convention instead of declaring the parameter explicitly
* In nested lambdas with parameters, parameters should be always declared explicitly.

### Class Header Formatting
* Classes with a few arguments can be written in a single line:

```
class Person(id: Int, name: String)
```

* Classes with longer headers should place each primary constructor argument is in a separate line with indentation. Additionally, the closing parenthesis should be on a new line.
* If using inheritance, the superclass constructor call or list of implemented interfaces should be located on the same line as the closing parenthesis:

```
class Person(
    id: Int,
    name: String,
    surname: String
) : Human(id, name) {
    // ...
}
```

* For multiple interfaces, the superclass constructor call should be located first and then each interface should be located on a separate line:

```
class Person(
    id: Int,
    name: String,
    surname: String
) : Human(id, name),
    KotlinMaker {
    // ...
}
```

* Constructor parameters can use either the regular indent or the continuation indent (double the regular indent).

### Unit
If a function returns Unit, the return type should be omitted:

```
fun foo() { // ": Unit" is omitted here

}
```

### Functions vs Properties
In some cases, functions with no arguments might be interchangeable with read-only properties. Although the semantics are similar, there are some stylistic conventions on when to prefer one to another. Prefer a property over a function when the underlying algorithm:
* does not throw any Exceptions
* has a O(1) complexity
* is cheap to calculate (or caсhed on the first run)
* returns the same result over invocations


---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
