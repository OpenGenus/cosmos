"""
Expectimax game playing algorithm
Alex Day
Part of Cosmos by OpenGenus Foundation
"""

from abc import ABC, abstractmethod
import math
from random import choice


class Board(ABC):
    @abstractmethod
    def terminal():
        """
        Determine if the current state is terminal
        Returns
        -------
        bool: If the board is terminal
        """
        return NotImplementedError()

    @abstractmethod
    def get_child_board(player):
        """
        Get all possible next moves for a given player
        Parameters
        ----------
        player: int
            the player that needs to take an action (place a disc in the game)
        Returns
        -------
        List: List of all possible next board states
        """
        return NotImplementedError()


def expectimax(player: int, board, depth_limit, evaluate):
    """
    expectimax algorithm with limited search depth.
    Parameters
    ----------
    player: int
        the player that needs to take an action (place a disc in the game)
    board: the current game board instance. Should be a class that extends Board
    depth_limit: int
        the tree depth that the search algorithm needs to go further before stopping
    evaluate: fn[Board, int]
        Some function that evaluates the board at the current position
    Returns
    -------
    placement: int or None
        the column in which a disc should be placed for the specific player
        (counted from the most left as 0)
        None to give up the game
    """
    max_player = player

    next_player = board.PLAYER2 if player == board.PLAYER1 else board.PLAYER1

    def value(board, depth_limit):
        """ Evaluate the board at the current state
        Args:
            board (Board): Current board state
            depth_limit (int): Depth limit
        Returns:
            float: Value of the board
        """
        return evaluate(player, board)

    def max_value(board, depth_limit: int) -> float:
        """ Calculate the maximum value for play if players acts optimally
        Args:
            player (int): Player token to maximize value of
            board (Board): Current board state
            depth_limit (int): Depth limit
        Returns:
            float: Maximum value possible if players play optimally
        """
        # Check if terminal or depth limit has been reached
        if depth_limit == 0 or board.terminal():
            # If leaf node return the calculated board value
            return value(board, depth_limit)

        # If not leaf then continue searching for maximum value
        best_value = -math.inf
        # Generate all possible moves for maximizing player and store the
        # max possible value while exploring down to terminal nodes
        for move, child_board in board.get_child_boards(player):
            best_value = max(best_value, min_value(child_board, depth_limit - 1))

        return best_value

    def min_value(board, depth_limit: int) -> float:
        """ Calculate a uniformly random move for the minplayer
        Args:
            player (int): Player token to minimize value of
            board (Board): Current board state
            depth_limit (int): Depth limit

        Returns:
            float: Minimum value possible if players play optimally
        """
        # Check if terminal or depth limit has been reached
        if depth_limit == 0 or board.terminal():
            # If leaf node return the calculated board value
            return value(board, depth_limit)

        # If not leaf then continue searching for minimum value
        # Generate all possible moves for minimizing player and store the
        # min possible value while exploring down to terminal nodes
        move, child_board = choice(board.get_child_boards(ext_player))
        return max_value(child_board, depth_limit - 1)

        return best_value

    # Start off with the best score as low as possible. We want to maximize
    # this for our turn
    best_score = -math.inf
    placement = None
    # Generate all possible moves and boards for the current player
    for pot_move, pot_board in board.get_child_boards(player):
        # Calculate the minimum score for the player at this board
        pot_score = min_value(pot_board, depth_limit - 1)
        # If this is greater than the best_score then update
        if pot_score > best_score:
            best_score = pot_score
            placement = pot_move

    return placement
