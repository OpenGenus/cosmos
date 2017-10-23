# Rail Fence Cipher

The rail fence cipher is a transposition cipher (a cipher in which text is shifted according to a regular system) whose name comes from the way it looks when being encoded.

## Encode

First, the text is written diagonally downwards. This is where the rail fence cipher gets it's name from: you can imagine the text being written along rails on a fence. If we were to encode the text "Lorem ipsum dolor sit amet", it would look like:

```
L . . . M . . . U . . . L . . . I . . . E .
. O . E . I . S . M . O . O . S . T . M . T
. . R . . . P . . . D . . . R . . . A . . .
```

Now, we read this off left to right, top to bottom like usual. This gets us "LMULIE OEISMOOSTMT RPDRA".

## Decode

To decode, we do the opposite: we take the encoded text and put it across the appropriate number of rails, getting us back to:

```
L . . . M . . . U . . . L . . . I . . . E .
. O . E . I . S . M . O . O . S . T . M . T
. . R . . . P . . . D . . . R . . . A . . .
```

Which we can now read diagnoally as "Lorem ipsum dolor sit amet".

## Sources and more info

- https://en.wikipedia.org/wiki/Rail_fence_cipher
- http://www.cs.trincoll.edu/~crypto/historical/railfence.html


---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
