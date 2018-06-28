from dfa import DFA

class NFA(object):
	"""Class for Non-deterministic Finite Atomata"""
	DEAD = -1
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

	def determinize(self):

		states = set(self.transitions.keys())

		actions = set()
		for state, out_transitions in self.transitions.items():
			actions.update(out_transitions.keys())

		dfa_start = frozenset([self.start])
		dfa_states_left = set([dfa_start])
		mappings = {dfa_start: 1}

		dfa_transitions = {}

		while len(dfa_states_left) > 0:
			dfa_state = dfa_states_left.pop()
			dfa_transitions[mappings[dfa_state]] = {}
			for action in actions:
				dfa_next_state = set()
				for nfa_state in dfa_state:
					try:
						dfa_next_state.update(self.transitions[nfa_state][action])
					except KeyError:
						pass
				dfa_next_state = frozenset(dfa_next_state)
				if dfa_next_state not in mappings:
					mappings[dfa_next_state] = len(mappings) + 1
					dfa_states_left.add(dfa_next_state)
				dfa_transitions[mappings[dfa_state]][action] = mappings[dfa_next_state]

		dfa_accepting = [mappings[dfa_state] for dfa_state in mappings.keys() if not dfa_state.isdisjoint(self.accepting)]

		return DFA(
				transitions=dfa_transitions,
				start=1,
				accepting=dfa_accepting
			)


def main():

	print("Automata that accepts strings with 'a' as 3rd character from last")

	nfa = NFA(
			transitions={
				1: {'a': [1, 2], 'b': [1]},
				2: {'a': [3], 'b': [3]},
				3: {'a': [4], 'b': [4]},
				4: {},
			},
			start=1,
			accepting=[4]
		)

	words = ["a", "aa", "aaa", "abab", "abaaab"]

	print()
	print("Tests for NFA:-")

	for word in words:
		print("{} accepted? {}".format(word, nfa.accepts(word)))

	print()
	print("Tests for DFA, obtained by determinizing NFA:-")
	dfa = nfa.determinize()

	for word in words:
		print("'{}' accepted? {}".format(word, dfa.accepts(word)))

	print()
	print("Number of states in NFA: ", len(nfa.transitions))
	print("Number of states in DFA: ", len(dfa.transitions))


if __name__=='__main__':
	main()