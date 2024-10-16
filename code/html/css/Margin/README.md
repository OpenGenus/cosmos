# CSS Basics: Margins

## Table of contents:

[1. Setting individual side margin](src/Individual.html)

[2. Shorthand property for CSS Margins](src/Shorthand_4.html)

[3. Auto-Keyword](src/Auto_keyword.html)

[4. Margin Inherit](src/Inherit_keyword.html)

[5. Margin Collapse](src/Margin_collapse.html)

CSS Margin property is used to create space between webpage border and HTML Element's border (if defined using CSS Border property).

**Syntax:**
```html
<style>
    #idvalue
    {
        border: {width} {style} {color};
        margin: {value}
    }
</style>
<{html_element} id="idvalue"> {content} </{html_element}>
```

**Example:**
```html
<style>
    #margin1 
    {
    border: 2px solid black;
    text-align:center;
    margin: 100px;
    }
</style>
<h1 id="margin1"> Generic Heading with defined margin</h1>
<h1> Normal heading </h1>
```
The Margin property can be defined in following ways:

1. Length
2. Percentage
3. Auto 
4. Inherit
