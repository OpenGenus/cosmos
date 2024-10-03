proc tower_of_hanoi(n: int, fromPeg, toPeg, aux: string) =
    if n >= 1:
      tower_of_hanoi(n-1, fromPeg, aux, toPeg)
      echo "Move ", n ," from: ", fromPeg, " to ", toPeg
      tower_of_hanoi(n-1, aux, toPeg, fromPeg)

# Run: nim c -r <file_name>.nim  
tower_of_hanoi(5, "A", "B", "C")
  