
class NFA(object):
	"""Class for Non-deterministic Finite Atomata"""
	def __init__(self, transitions, start, accepting):
		
		self.start = start
		self.accepting = accepting

		self.transitions = transitions

	def accepts(self, word, _start=None):

		if _start is None:
			curr_state = self.start
		else:
			curr_state = _start

		if len(word) == 0:
			return curr_state in self.accepting

		else:
			try:
				choices = self.transitions[curr_state][word[0]]

				for choice in choices:

					if self.accepts(word[1:], _start=choice):
						return True

				return False

			except KeyError:
				print("WARNING: Missing entry in transition assumed leading to dead state")
				return False


def main():

	# Automata for strings containing 'aaa'
	nfa = NFA(
			transitions={
				1: {'a': [1, 2], 'b': [1]},
				2: {'a': [3]},
				3: {'a': [4]},
				4: {'a': [4], 'b': [4]},
			},
			start=1,
			accepting=[4]
		)

	words = ["a", "aa", "aaa", "abab", "abaaab"]

	for word in words:
		print("{} accepted? {}".format(word, nfa.accepts(word)))


if __name__=='__main__':
	main()