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
                print(
                    "WARNING: Missing entry in transition assumed leading to dead state"
                )
                return False

        return curr_state in self.accepting

    def minimize(self):

        actions = set()

        for state, state_transitions in self.transitions.items():
            actions.update(state_transitions.keys())

        reachable_states = set()
        new_states_reached = set([self.start])

        while new_states_reached:

            reachable_states.update(new_states_reached)
            newer_states_reached = set()

            while new_states_reached:

                state = new_states_reached.pop()

                try:
                    for next_state in self.transitions[state].values():
                        if next_state not in reachable_states:
                            newer_states_reached.add(next_state)

                except KeyError:
                    pass

            new_states_reached = newer_states_reached

        try:
            for state in reachable_states:
                for action in actions:
                    next_state = self.transitions[state][action]
        except KeyError:
            reachable_states.add(None)

        partitions = [set(), set()]
        partition_number = {}

        for state in reachable_states.intersection(self.accepting):
            partitions[0].add(state)
            partition_number[state] = 0

        for state in reachable_states.difference(self.accepting):
            partitions[1].add(state)
            partition_number[state] = 1

        n_since_change = 0

        while n_since_change < len(partitions):

            i = 0

            while i < len(partitions):

                for action in actions:

                    next_state_partition_numbers = {
                        partition_number[self.transitions[state].get(action)]
                        for state in partitions[i]
                    }

                    if len(next_state_partition_numbers) > 1:

                        n_since_change = 0
                        new_partition_numbers = {}
                        new_partition_numbers[next_state_partition_numbers.pop()] = i

                        for number in next_state_partition_numbers:
                            new_partition_numbers[number] = len(partitions)
                            partitions.append(set())

                        partition_copy = set(partitions[i])
                        partitions[i] = set()

                        for state in partition_copy:
                            number = partition_number[
                                self.transitions[state].get(action)
                            ]
                            partition_number[state] = new_partition_numbers[number]
                            partitions[number].add(state)
                    else:
                        n_since_change += 1

                i += 1

        new_states = range(1, len(partitions) + 1)
        new_transitions = dict([(state, {}) for state in new_states])
        new_accepting = []

        for state in new_states:
            old_state = next(iter(partitions[state - 1]))
            if old_state in self.accepting:
                new_accepting.append(state)
            for action in actions:
                new_transitions[state][action] = (
                    partition_number[self.transitions[old_state].get(action)] + 1
                )

        new_start = partition_number[self.start] + 1

        new_dfa = DFA(
            transitions=new_transitions, start=new_start, accepting=new_accepting
        )

        return new_dfa


def main():

    print("Automata for strings of even length")
    dfa = DFA(
        transitions={
            1: {"a": 2, "b": 2},
            2: {"a": 3, "b": 3},
            3: {"a": 4, "b": 4},
            4: {"a": 1, "b": 1},
            5: {"a": 2, "b": 3},
        },
        start=4,
        accepting=[2, 4],
    )

    words = ["", "a", "aa", "aaa", "abab"]

    print()
    print("Tests for DFA:-")

    for word in words:
        print("'{}' accepted? {}".format(word, dfa.accepts(word)))

    minimized_dfa = dfa.minimize()

    print()
    print("Tests for minimized DFA:-")

    for word in words:
        print("'{}' accepted? {}".format(word, minimized_dfa.accepts(word)))

    print()
    print("Number of states in DFA: ", len(dfa.transitions))
    print("Number of states in minimized DFA: ", len(minimized_dfa.transitions))


if __name__ == "__main__":
    main()
