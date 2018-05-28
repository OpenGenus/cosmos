# cosmos
> Your personal library of every algorithm and data structure code that you will ever encounter

Part of Cosmos by OpenGenus Foundation

It uses the following Table called Tabula Recta to find the ciphertext. The simple intersection of the row and column is the ciphertext. Let's say for eg. T is the Key and E is the original Plaintext, then the intersection of T column and E row is the ciphertext i.e. X. The plaintext and key-length must be the same. Running Key Cipher is similar to Vigenere Cipher. The difference lies in how the key is chosen; the Vigenere cipher uses a short key that repeats, whereas the running key cipher uses a long key such as an excerpt from a book. This means the key does not repeat, making cryptanalysis more difficult. 

     A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
     ---------------------------------------------------
 A   A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
 B   B C D E F G H I J K L M N O P Q R S T U V W X Y Z A
 C   C D E F G H I J K L M N O P Q R S T U V W X Y Z A B
 D   D E F G H I J K L M N O P Q R S T U V W X Y Z A B C
 E   E F G H I J K L M N O P Q R S T U V W X Y Z A B C D
 F   F G H I J K L M N O P Q R S T U V W X Y Z A B C D E
 G   G H I J K L M N O P Q R S T U V W X Y Z A B C D E F
 H   H I J K L M N O P Q R S T U V W X Y Z A B C D E F G
 I   I J K L M N O P Q R S T U V W X Y Z A B C D E F G H
 J   J K L M N O P Q R S T U V W X Y Z A B C D E F G H I
 K   K L M N O P Q R S T U V W X Y Z A B C D E F G H I J
 L   L M N O P Q R S T U V W X Y Z A B C D E F G H I J K
 M   M N O P Q R S T U V W X Y Z A B C D E F G H I J K L
 N   N O P Q R S T U V W X Y Z A B C D E F G H I J K L M
 O   O P Q R S T U V W X Y Z A B C D E F G H I J K L M N
 P   P Q R S T U V W X Y Z A B C D E F G H I J K L M N O
 Q   Q R S T U V W X Y Z A B C D E F G H I J K L M N O P
 R   R S T U V W X Y Z A B C D E F G H I J K L M N O P Q
 S   S T U V W X Y Z A B C D E F G H I J K L M N O P Q R
 T   T U V W X Y Z A B C D E F G H I J K L M N O P Q R S
 U   U V W X Y Z A B C D E F G H I J K L M N O P Q R S T
 V   V W X Y Z A B C D E F G H I J K L M N O P Q R S T U
 W   W X Y Z A B C D E F G H I J K L M N O P Q R S T U V
 X   X Y Z A B C D E F G H I J K L M N O P Q R S T U V W
 Y   Y Z A B C D E F G H I J K L M N O P Q R S T U V W X
 Z   Z A B C D E F G H I J K L M N O P Q R S T U V W X Y


---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
