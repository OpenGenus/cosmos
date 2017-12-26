class Minimax:

	def minimax_decision(gameState):
		max = float("-inf")

		for a in gameState.get_player_moves():
			v = gameState.forecast_move(a)
			if v > max:
				v = a
				best_move = a
		return best_move

	

	def min_value(gameState):
		v = float("inf")
		if(terminal_condition(gameState)):
			return -1
		else:
			for a in gameState.get_player_moves():
				v = min( v , max_value(gameState.forecast_move(a)))

		return v



	def max_value(gameState):
		v = float("-inf")
		if(terminal_condition(gameState)):
			return 1
		else:
			for a in gameState.get_player_moves():
				v = max(v , main_value(gameState.forecast_move(a)))
				

		return v
	

	def terminal_condition(gameState):
		if(len(gameState.get_player_moves()) == 0):
			return True
		else:
			return False
