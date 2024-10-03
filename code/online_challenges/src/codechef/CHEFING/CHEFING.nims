import strutils, sets, sequtils

let tests_num: int = stdin.readLine.parseInt

for test_idx in 0..<tests_num:
    let dishes_num = stdin.readLine.parseInt

    var result: HashSet[char] = toHashSet(@(stdin.readLine()))
    for dish_idx in 0..dishes_num-2:
        result = result * toHashSet(@(stdin.readLine()))

    result.card.echo
