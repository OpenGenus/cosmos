<?hh // strict

final class GameOfLife {

  const type TBoard = vec<vec<bool>>;

  public function __construct(
    private this::TBoard $board,
  ) {}

  <<__Memoize>>
  private function boardDimensions(): (int, int) {
    $rows = count($this->board);
    $columns = $rows > 0 ? count($this->board[0]) : 0;
    return tuple($rows, $columns);
  }

  public function play(int $ticks): void {
    list($_rows, $columns) = $this->boardDimensions();
    $separator = implode('', array_fill(0, $columns, '-'));

    $this->printBoard();
    while ($ticks-- > 0) {
      print $separator.PHP_EOL;
      $this->tick();
      $this->printBoard();
    }
  }

  public function tick(): void {
    $new_board = $this->board;
    foreach ($this->board as $i => $row) {
      foreach ($row as $j => $cell) {
        $neighbor_count = $this->aliveNeighborCount($i, $j);

        // Rules:
        // 1. Any live cell with fewer than two live neighbours dies, as if
        // caused by underpopulation.
        // 2. Any live cell with two or three live neighbours lives on to the
        // next generation.
        // 3. Any live cell with more than three live neighbours dies, as if by
        // overpopulation.
        // 4. Any dead cell with exactly three live neighbours becomes a live
        // cell, as if by reproduction.
        if ($cell && ($neighbor_count < 2 || $neighbor_count > 3)) {
          $new_board[$i][$j] = false;
        } else if ($neighbor_count === 3) {
          $new_board[$i][$j] = true;
        }
      }
    }
    $this->board = $new_board;
  }

  private function aliveNeighborCount(int $row, int $col): int {
    static $neighbors = array(
      tuple(-1, -1),
      tuple(-1,  0),
      tuple(-1,  1),
      tuple( 0, -1),
      tuple( 0,  1),
      tuple( 1, -1),
      tuple( 1,  0),
      tuple( 1,  1),
    );

    $count = 0;
    foreach ($neighbors as list($row_offset, $col_offset)) {
      if (idx(idx($this->board, $row + $row_offset), $col + $col_offset)) {
        $count++;
      }
    }

    return $count;
  }

  private function printBoard(): void {
    foreach ($this->board as $row) {
      print implode('', array_map($v ==> $v ? "\u{2592}" : "\u{2591}", $row)).PHP_EOL;
    }
  }
}

// Test running 'blinker' pattern.
(new GameOfLife(vec[
  vec[false, true , false],
  vec[false, true , false],
  vec[false, true , false],
]))->play(10);
