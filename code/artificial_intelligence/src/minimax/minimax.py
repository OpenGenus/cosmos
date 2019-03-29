import operator
import time


class IllegalMoveException(Exception):
    pass


def new_copy(in_list):
    if isinstance(in_list, list):
        return list(map(new_copy, in_list))
    else:
        return in_list


class GameState(object):
    def __init__(self, board, turn, move_count=0):
        self.board = board
        self.turn = turn
        self.move_count = move_count

        assert len(board) == len(board[0])
        self.n = len(board)

        # Once a move is made, these will record the x and y index of the move most recently made on the board,
        # as well as whose turn it was when the move was made.
        self.x = None
        self.y = None

    def switch_turn(self):
        self.turn = "X" if self.turn == "O" else "O"

    def move(self, x, y):
        if self.board[y][x] != None:
            raise IllegalMoveException(
                "there is already a symbol placed at this location (x = {}, y = {})".format(
                    x, y
                )
            )
        # record move (for indication of most recent move when printing board)
        self.x = x
        self.y = y

        # make move and switch turn
        self.board[y][x] = self.turn
        self.switch_turn()

        # update move_count
        self.move_count += 1

    def __str__(self):
        ret = "\n"
        for y in range(self.n):
            for x in range(self.n):
                if y == self.y and x == self.x:
                    ret += " ({}) |".format(self.board[y][x])
                else:
                    ret += "  {}  |".format(self.board[y][x] or " ")
            ret = ret[:-1] + "\n" + "-" * self.n * 6 + "\n"

        result = self.check_winner()
        if result in ("X", "O"):
            ret += "\nWinner: {}".format(result)
        elif result == "draw":
            ret += "\nThe game is a draw."
        else:  # no winner yet
            ret += "\nTurn to move: {}".format(self.turn)

        return ret

    def check_winner(self):
        # check row
        for y in range(self.n):
            win = self.board[y][0]
            if win == None:
                continue
            for x in range(self.n):
                if self.board[y][x] != win:
                    break
            else:
                return win

        # check column
        for x in range(self.n):
            win = self.board[0][x]
            if win == None:
                continue
            for y in range(self.n):
                if self.board[y][x] != win:
                    break
            else:
                return win

        # check forward diagonal
        win = self.board[0][0]
        if win != None:
            for z in range(1, self.n):
                if self.board[z][z] != win:
                    break
            else:
                return win

        # check backward diagonal
        win = self.board[0][self.n - 1]
        if win != None:
            for y in range(1, self.n):
                if self.board[y][self.n - y - 1] != win:
                    break
            else:
                return win

        if self.move_count == self.n ** 2:
            return "draw"

        return None

    def next_states_and_moves(self):
        """
		return a list of tuples, where each tuple contains:
			- a state immediately reachable from the current game state
			- another tuple with the x and y coordinates of the move required to create that state
		"""
        states = []
        for y in range(self.n):
            for x in range(self.n):
                if self.board[y][x] == None:
                    new_state = GameState(
                        new_copy(self.board), self.turn, move_count=self.move_count
                    )
                    new_state.move(x, y)
                    states.append((new_state, (x, y)))
        return states

    def evaluate(self, symbol):
        """
		return an estimate of how desirable of a position this position is (for the player with the provided symbol)
		for each player, this heuristic looks at each row, column, and diagonal; if the row/column/diagonal is not obstructed
		by pieces belonging to the other player, the player's value is increased according to how many pieces they have on that
		row/column/diagonal
		the overall value is the player's value minus the opponent's value
		"""
        other_symbol = "X" if symbol == "O" else "O"

        player_total = 0
        opponent_total = 0

        for total, own, other in (
            (player_total, symbol, other_symbol),
            (opponent_total, other_symbol, symbol),
        ):

            # rows
            for y in range(self.n):
                benefit = 0
                for x in range(self.n):
                    if self.board[y][x] == None:
                        continue
                    elif self.board[y][x] == own:
                        benefit += 1
                    elif self.board[y][x] == other:  # this row is obstructed
                        break
                else:
                    total += benefit  # row is unobstructed

            # ccolumns
            for x in range(self.n):
                benefit = 0
                for y in range(self.n):
                    if self.board[y][x] == None:
                        continue
                    elif self.board[y][x] == own:
                        benefit += 1
                    elif self.board[y][x] == other:  # this column is obstructed
                        break
                else:
                    total += benefit  # column is unobstructed

            # forward diagonal
            benefit = 0
            for z in range(1, self.n):
                if self.board[z][z] == None:
                    continue
                elif self.board[z][z] == own:
                    benefit += 1
                elif self.board[z][z] == other:  # this diagonal is obstructed
                    break
                else:
                    total += benefit  # diagonal is unobstructed

            # backward diagonal
            benefit = 0
            for y in range(1, self.n):
                if self.board[y][self.n - y - 1] == None:
                    continue
                elif self.board[y][self.n - y - 1] == own:
                    benefit += 1
                elif (
                    self.board[y][self.n - y - 1] == other
                ):  # this diagonal is obstructed
                    break
            else:
                total += benefit  # diagonal is unobstructed

            return player_total - opponent_total


class GameDriver(object):
    def __init__(self):
        symbol = input("Choose your symbol (X/O)\n")
        while symbol != "X" and symbol != "O":
            symbol = input("Could not understand your answer. Please enter X or O.\n")

        self.player_symbol = symbol

        n = input(
            "\nChoose the size of your board (enter a positive integer, this will be the height and width of your board\n"
        )
        while not n.isdigit() or int(n) < 1:
            n = input("Please enter a positive integer\n")
        n = int(n)

        first = input("\nWould you like to start? (Y/N)\n")
        while first != "Y" and first != "N":
            first = input("Could not understand your answer. Please enter Y or N.\n")

        print(
            "\nThank you. To enter your moves, enter the index of your move on the board, with indices defined as follows:\n"
        )

        col_width = n
        indices_str = ""

        all_n = range(1, n ** 2 + 1)
        rows = [all_n[i : i + n] for i in range(0, n ** 2, n)]

        for row in rows:
            row = [str(i) for i in row]
            indices_str += "|".join(word.center(col_width) for word in row) + "\n"
            indices_str += "-" * (col_width + 1) * n + "\n"
        indices_str = indices_str[: -1 * (col_width + 1) * n - 1]

        print(indices_str)

        input("\nPress Enter to continue!\n")

        if first == "Y":
            self.game = GameState(
                [[None for _ in range(n)] for _ in range(n)], self.player_symbol
            )
        else:
            self.game = GameState(
                [[None for _ in range(n)] for _ in range(n)],
                "X" if self.player_symbol == "O" else "O",
            )

        self.start()

    def player_move(self):
        move = input("Enter the index of your move.\n")
        while True:
            while not move.isdigit() or int(move) > self.game.n ** 2 or int(move) < 1:
                move = input(
                    "Please enter an integer greater than or equal to 1 and less than or equal to {}.\n".format(
                        self.game.n ** 2
                    )
                )

            move = (
                int(move) - 1
            )  # easier to calculate x and y this way, since arrays representing game board are 0-indexed
            y = int(move / self.game.n)
            x = move % self.game.n

            if self.game.board[y][x] != None:
                print("There is already a piece in that location on the board.")
                move = ""
            else:
                break
        self.game.move(x, y)

    def computer_move(self):
        """
		pick first possible move from list of states
		"""

        delay = 0.5
        print("Thinking...")
        time.sleep(delay)
        print(".")
        time.sleep(delay)
        print(".")
        time.sleep(delay)
        print(".\n")
        time.sleep(delay)

        # TODO: how deep to look? maybe base this on a difficulty parameter specified by user?
        move = self.minimax(self.game, 6, True, float("-inf"), float("+inf"))[1]
        self.game.move(*move)

    def minimax(self, board, level, comp_turn, alpha, beta):
        winner = board.check_winner()
        if winner == "draw":
            return 0, None
        elif winner == self.player_symbol:
            return -1, None
        elif winner != None:
            return 1, None

        if level == 0:
            # TODO: normalize this between -1 and 1. Also come up with a better way to identify player/computer symbols
            return -1 * board.evaluate(self.player_symbol), None

        states_and_moves = board.next_states_and_moves()
        best_move = None
        if comp_turn:
            for state, move in states_and_moves:
                score = self.minimax(state, level - 1, False, alpha, beta)[0]
                if score > alpha:
                    alpha = score
                    best_move = move
                if alpha >= beta:
                    break
            return alpha, best_move
        else:
            for state, move in states_and_moves:
                score = self.minimax(state, level - 1, True, alpha, beta)[0]
                if score < beta:
                    beta = score
                    best_move = move
                if alpha >= beta:
                    break
            return beta, best_move

    def start(self):
        while True:
            if self.game.turn == self.player_symbol:
                self.player_move()
            else:
                self.computer_move()
            print(self.game)
            if self.game.check_winner():
                break


if __name__ == "__main__":
    GameDriver()
