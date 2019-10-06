tests_num = int(input())
for test_idx in range(tests_num):
    dishes_num = int(input())
    dishes = []
    counter = []
    result = set(input())
    for dish_idx in range(dishes_num-1):
        result = result & set(input())
            
    print(len(result))

## Test
# 2
# 3
# abcaa
# bcbd
# bgc
# 3
# quick
# brown
# fox    
## Result
# 2
# 0