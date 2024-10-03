EPSILON = ""
STACK_BASE = "$"


class DPDA(object):
	"""Class for Deterministic Pushdown Atomata"""
	def __init__(self, transitions, start, accepting):
		
		self.start = start
		self.accepting = accepting

		self.transitions = transitions

	def accepts(self, word, _warn=True):

		curr_state = self.start
		stack = [STACK_BASE]
		i = 0
		epsilon_visited = set()

		stack_top = stack.pop()
		while i < len(word) or EPSILON in self.transitions[(curr_state, stack_top)]:
			try:
				if EPSILON in self.transitions[(curr_state, stack_top)]:
					if _warn and len(self.transitions[(curr_state, stack_top)].keys()) > 1:
						print("WARNING: Non deterministic transitions. Output may be not as expected.")
					next_state, stack_pushes = self.transitions[(curr_state, stack_top)][EPSILON]
					if next_state in epsilon_visited:
						if _warn:
							print("WARNING: Word rejected because stuck in infinite loop.")
						return False
					epsilon_visited.add(next_state)
					curr_state = next_state
					stack.extend(stack_pushes)

				else:
					epsilon_visited = set()
					char = word[i]
					i += 1
					next_state, stack_pushes = self.transitions[(curr_state, stack_top)][char]
					curr_state = next_state
					stack.extend(stack_pushes)

				if _warn and stack[0] != STACK_BASE:
					raise IndexError

				stack_top = stack.pop()
			except IndexError:
				if _warn:
					print("WARNING: Stack constraints violated. Output may be not as expected.")
				return False
			except KeyError:
				if _warn:
					print("WARNING: Missing entry in transition assumed leading to dead state")
				return False

		return curr_state in self.accepting


def main():

	print("DPDA for words with equal number of a and b")
	dpda = DPDA(
			transitions={
				(1, STACK_BASE): {
					'a': (2, STACK_BASE + 'A'),
					'b': (3, STACK_BASE + 'B'),
				},
				(2, STACK_BASE): {
					EPSILON: (1, STACK_BASE),
				},
				(2, 'A'): {
					'a': (2, 'AA'),
					'b': (2, ''),
				},
				(3, STACK_BASE): {
					EPSILON: (1, STACK_BASE),
				},
				(3, 'B'): {
					'a': (3, ''),
					'b': (3, 'BB'),
				}
			},
			start=1,
			accepting=[1]
		)

	words = ["", "a", "aa", "aaba", "abab", "aaabaaabbbabbb"]

	print()
	print("Tests for DPDA:-")

	for word in words:
		print("'{}' accepted? {}".format(word, dpda.accepts(word, _warn=False)))


if __name__=='__main__':
	main()
