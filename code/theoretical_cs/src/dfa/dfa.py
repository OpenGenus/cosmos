
class DFA(object):
	"""Class for Deterministic Finite Atomata"""
	def __init__(self, states, alphabet, transitions, start, accepting, add_dead_state=False):
		
		assert start in states
		assert accepting.issubset(states)
		self.start = start
		self.accepting = accepting

		if not add_dead_state:

			self.states = states
			self.alphabet = alphabet
			self.transitions = transitions

			for state, state_transition in transitions.items():

				assert state in states
				assert state_transition.keys().issubset(alphabet)

				for letter, next_state in state_transition.items():

					assert letter in alphabet
					assert next_state in states

		else:

			self.states = set(states)
			self.states.add("DEAD")


def main():

	# Automata for strings containing 'aaa'
	dfa = DFA(
			states=[1, 2, 3, 4],
			alphabet=['a', 'b'],
			transitions={
				1: {'a': 2, 'b': 1},
				2: {'a': 3, 'b': 1},
				3: {'a': 4, 'b': 1},
				4: {'a': 4, 'b': 4},
			},
			start=1,
			accepting=set([4])
		)


if __name__=='__main__':
	main()