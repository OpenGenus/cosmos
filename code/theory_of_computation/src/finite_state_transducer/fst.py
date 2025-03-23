
class FST(object):
	"""Class for Finite State Transducer"""
	def __init__(self, transitions, start):
		
		self.start = start
		self.transitions = transitions

	def transform(self, word, _warn=True):

		curr_state = self.start
		output = ""

		for char in word:
			try:
				next_state, local_output = self.transitions[curr_state][char]
				curr_state = next_state
				output += local_output

			except KeyError:
				if _warn:
					print("WARNING: Missing entry in transition assumed leading to dead state with no output")
				return output

		return output


def main():

	print("FST for morse code to English using only A,B,C")
	fst = FST(
			transitions={
				1: {'.': (2, ''), '-': (3, ''), ' ': (1, '')},
				2: {'-': (4, '')},
				3: {'.': (5, '')},
				4: {' ': (1, 'A')},
				5: {'.': (6, ''), '-': (7, '')},
				6: {'.': (8, '')},
				7: {'.': (9, '')},
				8: {' ': (1, 'B')},
				9: {' ': (1, 'C')},
			},
			start=1,
		)

	words = [".- ", "-... ", "-.-. ", ".- -... ", "-.-. .- -... "]

	print()
	print("Tests for FST:-")

	for word in words:
		print("'{}' transforms to '{}'".format(word, fst.transform(word)))

if __name__=='__main__':
	main()
