
class DFA(object):
	"""Class for Deterministic Finite Atomata"""
	def __init__(self, transitions, start, accepting):
		
		self.start = start
		self.accepting = accepting

		self.transitions = transitions

	def accepts(self, word):

		curr_state = self.start

		for char in word:
			try:
				curr_state = self.transitions[curr_state][char]
			except KeyError:
				print("WARNING: Missing entry in transition assumed leading to dead state")
				return False

		return curr_state in self.accepting

def main():

	# Automata for strings containing 'aaa'
	dfa = DFA(
			transitions={
				1: {'a': 2, 'b': 1},
				2: {'a': 3, 'b': 1},
				3: {'a': 4, 'b': 1},
				4: {'a': 4, 'b': 4},
			},
			start=1,
			accepting=[4]
		)

	words = ["a", "aa", "aaa", "abab", "abaaab"]

	for word in words:
		print("{} accepted? {}".format(word, dfa.accepts(word)))


if __name__=='__main__':
	main()