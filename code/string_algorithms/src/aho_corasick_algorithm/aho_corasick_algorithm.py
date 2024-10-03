class StreamChecker:

    def __init__(self, words: List[str]):
        self.root = {'prefix': None, 'dict':None}
        
        #build Trie
        for word in words:
            node = self.root
            for char in word:
                if not char in node:
                    node[char] = {}
                node = node[char]
            node['word'] = True
                    
        #set prefix and dictionary pointers by BFS
        q = collections.deque([self.root])
        while q:
            node = q.popleft()
            for char in node:
                if len(char)==1:
                    child = node[char]
                    extendNode = node['prefix']
                    while extendNode and not char in extendNode:
                        extendNode = extendNode['prefix']
                    if extendNode:
                        child['prefix'] = extendNode[char]
                    else:
                        child['prefix'] = self.root
                    if 'word' in child['prefix']:
                        child['dict'] = child['prefix']
                    else:
                        child['dict'] = child['prefix']['dict']
                    q.append(child)
        
        #self.cur will traverse the Trie
        #while reading the stream
        self.cur = self.root

    def query(self, letter: str) -> bool:
        extendNode = self.cur
        while extendNode and not letter in extendNode:
            extendNode = extendNode['prefix']
        if extendNode:
            self.cur = extendNode[letter]
			#checks if current word is in words
			#or if the dictionary pointer is non-null
            if 'word' in self.cur or self.cur['dict']: 
                return True
            else:
                return False
        else:
            self.cur = self.root
            return False
