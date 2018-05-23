/* Part of Cosmos by OpenGenus Foundation */

//
//  bead_sort.m
//  Created by DaiPei on 2017/10/12.
//

#import <Foundation/Foundation.h>

@interface BeadSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation BeadSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    NSNumber *max = @(INTMAX_MIN);
    int n = (int)array.count;
    // find the max value
    for (int i = 0; i < n; i++) {
        if ([max compare:array[i]] == NSOrderedAscending) {
            max = array[i];
        }
    }
    int m = max.intValue;
    int8_t *beads = calloc(m * n, sizeof(int8_t));
    // put beads
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j < array[i].intValue) {
                beads[i * m + j] = 1;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        // count beads
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += beads[i * m + j];
            beads[i * m + j] = 0;
        }
        // move down beads
        for (int i = n - sum; i < n; i++) {
            beads[i * m + j] = 1;
        }
    }
    // put sorted value in array using beads
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (beads[i * m + j] == 0) {
                break;
            }
        }
        array[i] = @(j);
    }
}

@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSMutableArray *array = [NSMutableArray arrayWithCapacity:3];
        for (int i = 0; i < 10; i++) {
            uint32_t ran = arc4random() % 10;
            [array addObject:@(ran)];
        }
        NSLog(@"before: %@", array);
        BeadSort *bs = [[BeadSort alloc] init];
        [bs sort:array];
        NSLog(@"after: %@", array);
    }
    return 0;
}
