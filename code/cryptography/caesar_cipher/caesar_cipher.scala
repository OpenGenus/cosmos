
/**
* caesar cipher implentation in scala
* @param plain_text text that needs to be encrypted. Supports ASCII alphabetic characters and spaces
* @param shift the number of the characters the alphabet should be shifted to create the desired cipher key
* @return encrypted string
*/
def caesar_cipher(plain_text:String,shift:Int):String={
	
	if(plain_text.length == 0)
		return ""
	
	def shift_alphabet(sh:Int):scala.collection.mutable.Map[Char,Char]={
		val alphabet = Array('a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ')
		val map = scala.collection.mutable.Map[Char,Char]()
		var shift:Int = sh; 

		for(i <- 0 until alphabet.length){
			shift = (sh + i) % 27 		
			map(alphabet(i)) = alphabet(shift)
		}


		return map
	}

	def checkUpper(c1:Char,c2:Char):Char={
		if(c1.toUpper == c1) return c2.toUpper else c2	
	}

	val shifted = shift_alphabet(shift)
	
	return (for(ch <- plain_text.toArray) yield checkUpper(ch,shifted.get(ch.toLower).get)).mkString
	
	
}

def test(){
	assert(caesar_cipher("Hello",3) == "Khoor")
}