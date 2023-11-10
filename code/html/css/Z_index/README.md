# CSS Position: Z-index property

When HTML elements are positioned explicitly, they may overlap with each other.
The Z-index property is used to specify the **Stack order** of HTML elements.

The higher the value of the HTML element in the stack, the more forward is its position.
HTML elements can have either a positive stack or a negative stack.

**Syntax**
```css
z-index: auto|number|initial|inherit;
```

**Rule: An element with greater stack order is always in front of element with lower stack order.**

**Note: If two elements overlap with each other and z-index is not specified explicitly, then the element defined later in the HTML source code has higher stack order.**

**Note: Z-index only works on elements whose CSS position property has been defined.**

![Example](img/z_index.png)

