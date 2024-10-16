# CSS Basics: Padding

## Table of contents

[1. CSS Padding for Individual Sides](src/Individual_sides.html)

[2. Shorthand Property](src/Shorthand_1.html)

[3. Inherit Keyword](src/Inherit.html)

[4. CSS Box Model with Padding](src/BoxModel.html)

CSS Padding property is used to create spacing between content of HTML Element and the border(if specified) around it.

**Syntax:**
```html
<style>
    HTML_element
    {
        border: {width} {style} {color};
        padding: {value(s)};
    }
</style>
<HTML_element> Content </HTML_element>
```

**Example:**
```html
<style>
    #el
    {
        border: 2px solid black;
        padding: 40px;
    }
</style>
<h1 id="el"> Heading with Padding specified </h1>
<h1 style="border:2px solid black;"> Heading without padding </h1>  
```

CSS Padding property takes following input as its value:

* Length: Number followed by a unit (px,cm etc.)
* Percentage: Number followed by % sign.
* Inherit Keyword: Inherit padding value from parent HTML element.

