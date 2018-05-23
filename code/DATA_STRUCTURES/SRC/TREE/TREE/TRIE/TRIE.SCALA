import collection.immutable.IntMap

object Trie {
    def apply(text: String): Trie = {
        if (text == "") {
            return new Trie(IntMap(), true)
        } else {
            return new Trie(IntMap(text.charAt(0).asInstanceOf[Int] -> apply(text.substring(1))), false)
        }
    }
}

case class Trie(kids: IntMap[Trie], isTerminalNode: Boolean) {
    def insert(text: String): Trie = {
        if (text == "") {
            this.copy(isTerminalNode = true)
        } else {
            val firstLetterInt = text.charAt(0).asInstanceOf[Int]
            val restOfText = text.substring(1)
            val newKid = 
                if (kids.contains(firstLetterInt))
                    kids(firstLetterInt).insert(restOfText)
                else
                    Trie(restOfText)

            this.copy(kids = kids + (firstLetterInt -> newKid))
        }
    }

    def hasText(text: String): Boolean = {
        if (text == "") {
            this.isTerminalNode
        } else {
            val firstLetterInt = text.charAt(0).asInstanceOf[Int]
            kids.contains(firstLetterInt) && kids(firstLetterInt).hasText(text.substring(1))
        }
    }

    def hasPrefix(prefix: String): Boolean = {
        if (prefix == "") {
            true
        } else {
            val firstLetterInt = prefix.charAt(0).asInstanceOf[Int]
            kids.contains(firstLetterInt) && kids(firstLetterInt).hasPrefix(prefix.substring(1))
        }
    }
}
