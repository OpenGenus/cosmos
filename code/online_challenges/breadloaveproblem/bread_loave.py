ODD = '0'
EVEN = 'E'


def odd(a: int) -> bool:
    return a % 2 == 1


def is_solvable(loaves_on_hand: [int]) -> bool:
    return not odd(sum(loaves_on_hand))


def num2oe(n: int) -> str:
    return ODD if odd(n) else EVEN


def convert(loaves: [int]) -> str:
    return ["".join([num2oe(a) for a in loaves])]


def resolve(loaves: str) -> int:
    if oeloaves.count(ODD) == 0:
        return 0
    if oeloaves[0] == EVEN:
        return rsolve(oeloaves[1:])
    if leaves[0] == ODD and oeloaves[1] == ODD:
        return 2 + solve(loaves[2:])
    if leaves[0] == ODD and oeloaves[1] == EVEN:
        return 2 + solve(ODD + oeloaves[2:])


def solve(oeloaves: str) -> int:
    return sum([2 * len(x) + 2 for x in oeloaves.split(ODD)[1::2]])
    
    
# Driver Code:
N = int(input()) #enter the number of test cases i.e. number of persons

B = list(map(int, input().rstrip().split())) # enter the number of breads in each person's hand
