from random import choice

choices = ["ROCK", "PAPER", "SCISSORS"]

# Rules: what each choice beats
wins_against = {
    "ROCK": "SCISSORS",
    "SCISSORS": "PAPER",
    "PAPER": "ROCK"
}

while True:
    print("\nRock\nPaper\nScissors!!!!!")
    player1 = input("Enter your choice: ").strip().upper()

    if player1 not in choices:
        print("Invalid choice. Please choose Rock, Paper, or Scissors.")
        continue

    player2 = choice(choices)

    print("SHOOT!!!")
    print(f"Player 2 played {player2}")

    if player1 == player2:
        print("Tied")
    elif wins_against[player1] == player2:
        print("Player 1 wins 🎉")
    else:
        print("Player 2 wins 🤖")

    print("---------------------------------------")
    flag = input("Do you want to continue? (yes/no): ").strip().lower()

    if flag != "yes":
        print("Thanks for playing!")
        break
