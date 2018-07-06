from dfa import DFA # located at code/theory_of_computation/src/deterministic_finite_automaton/dfa.py

EPSILON = ''

class NFA(object):
	"""Class for Non-deterministic Finite Atomata"""
	def __init__(self, transitions, start, accepting):
		
		self.start = start
		self.accepting = accepting

		self.transitions = transitions

	def accepts(self, word, _start=None, _marked=set(), _warn=True):

		if _start is None:
			curr_state = self.start
		else:
			curr_state = _start

		if EPSILON in self.transitions[curr_state] and curr_state not in _marked:

			new_marked = _marked.copy()
			new_marked.add(curr_state)

			for next_state in self.transitions[curr_state][EPSILON]:

				if self.accepts(word, _start=next_state, _marked=new_marked, _warn=_warn):
					return True

		if len(word) == 0:
			return curr_state in self.accepting

		else:
			try:
				choices = self.transitions[curr_state][word[0]]

				new_marked = set()

				for choice in choices:

					if self.accepts(word[1:], _start=choice, _marked=new_marked, _warn=_warn):
						return True

				return False

			except KeyError:
				if _warn:
					print("WARNING: Missing entry in transition assumed leading to dead state")
				return False

	def remove_epsilon(self):

		epsilon_closure = {}
		changed_closures = set()

		for state, state_transitions in self.transitions.items():

			epsilon_closure[state] = set(state_transitions.get(EPSILON, [])+[state])
			changed_closures.add(state)


		while len(changed_closures) > 0:

			new_changed_closures = set()

			for state, state_eps_transitions in epsilon_closure.items():

				for next_state in state_eps_transitions.intersection(changed_closures):
					
					next_state_eps_transitions = epsilon_closure[next_state]
					
					if not next_state_eps_transitions.issubset(state_eps_transitions):
						new_changed_closures.add(state)
						state_eps_transitions.update(next_state_eps_transitions)

			changed_closures = new_changed_closures

		new_transitions = {}

		for state in self.transitions.keys():

			state_actions = set()
			for eps_state in epsilon_closure[state]:
				state_actions.update(self.transitions[eps_state].keys())

			state_actions.discard(EPSILON)
			new_state_transitions = dict((action, set()) for action in state_actions)

			for eps_state in epsilon_closure[state]:

				for action, next_states in self.transitions[eps_state].items():

					if action != EPSILON:

						for next_state in next_states:

							new_state_transitions[action].update(epsilon_closure[next_state])
					

			new_transitions[state] = new_state_transitions

		new_accepting = set()
		for acc_state in self.accepting:
			new_accepting.update(epsilon_closure[acc_state])
		
		if not epsilon_closure[self.start].isdisjoint(self.accepting):
			new_accepting.add(self.start)

		return NFA(
				transitions=new_transitions,
				start=self.start,
				accepting=new_accepting
			)


	def determinize(self, remove_epsilon=True):

		if remove_epsilon:
			base_nfa = self.remove_epsilon()
		else:
			base_nfa = self


		actions = set()

		for out_transitions in base_nfa.transitions.values():
			actions.update(out_transitions.keys())

		dfa_start = frozenset([base_nfa.start])
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
						dfa_next_state.update(base_nfa.transitions[nfa_state][action])
					except KeyError:
						pass
				dfa_next_state = frozenset(dfa_next_state)
				if dfa_next_state not in mappings:
					mappings[dfa_next_state] = len(mappings) + 1
					dfa_states_left.add(dfa_next_state)
				dfa_transitions[mappings[dfa_state]][action] = mappings[dfa_next_state]

		dfa_accepting = [mappings[dfa_state] for dfa_state in mappings.keys() if not dfa_state.isdisjoint(base_nfa.accepting)]

		return DFA(
				transitions=dfa_transitions,
				start=1,
				accepting=dfa_accepting
			)


def main():

	print("Automata that accepts strings with 'a' in 3rd, 4th or 5th positions from last")

	nfa_with_epsilon = NFA(
			transitions={
				1: {'a': [1, 2], 'b': [1]},
				2: {'a': [3], 'b': [3], '': [3]},
				3: {'a': [4], 'b': [4], '': [4]},
				4: {'a': [5], 'b': [5]},
				5: {'a': [6], 'b': [6]},
				6: {},
			},
			start=1,
			accepting=[6]
		)

	words = ["a", "b", "ab", "bb", "baa", "aba", "abba", "bbba", "aaabbba", "aaabbbba"]
	print()
	print("Tests for NFA with epsilon:-")

	for word in words:
		print("'{}' accepted? {}".format(word, nfa_with_epsilon.accepts(word, _warn=False)))

	nfa_wo_epsilon = nfa_with_epsilon.remove_epsilon()
	
	print()
	print("Tests for NFA without epsilon:-")

	for word in words:
		print("'{}' accepted? {}".format(word, nfa_wo_epsilon.accepts(word, _warn=False)))


	print()
	print("Tests for DFA, obtained by determinizing NFA without epsilon:-")
	dfa = nfa_wo_epsilon.determinize(remove_epsilon=False)

	for word in words:
		print("'{}' accepted? {}".format(word, dfa.accepts(word, _warn=False)))

	print()
	print("Number of states in NFA with epsilon: ", len(nfa_with_epsilon.transitions))
	print("Number of states in NFA without epsilon: ", len(nfa_wo_epsilon.transitions))
	print("Number of states in DFA: ", len(dfa.transitions))


if __name__=='__main__':
	main()
