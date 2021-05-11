# Cascasding StyleSheets (CSS)

CSS is used to add styling options to webpages written in normal HTML files.
CSS style options are pairs of **property:value**.

There are three ways to add CSS style options in HTML files.

## 1. Inline CSS 

Writing CSS style options within HTML tag.

```html
<{HTML_element} style="property:value;property:value,...">
```

## 2. Internal CSS

Writing entire CSS code in `<style>` HTML element at the `<head>` of HTML file.
This method uses Id and Class attributes of HTML to define the style for those HTML elements.

```html
<head>
<style>
  
HTML-element {property:value;property:value,...}

#idvalue {property:value;property:value,...}
  
.classname {property:value;property:value,...}  
  
</style>
<head>
```

## 3. External CSS

Writing CSS code in an external .css file and linking it in the HTML file.
The link is provided in the HTML `head` tag.

```html
<head>
  <link rel="stylesheet" href="{path to external css file}">
</head>
```

<hr>

## Table of contents

[* CSS Borders](border/)

[* CSS Margins](Margin/)

[* CSS Padding](Padding/)

[* CSS Position](Position/)

[* CSS Position: Z-index](Z_index/)

[* CSS Layout](Layout/)
