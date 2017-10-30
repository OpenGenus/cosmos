/* Part of Cosmos by OpenGenus Foundation */

//
//  circle_sort.m
//  Created by DaiPei on 2017/10/15.
//

#import <Foundation/Foundation.h>

@interface CircleSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation CircleSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    while ([self sort:array low:0 high:(int)array.count - 1]) {}
}

- (BOOL)sort:(NSMutableArray<NSNumber *> *)array low:(int)low high:(int)high {
    BOOL swapped = NO;
    if (low == high) {
        return swapped;
    }
    int l = low, h = high;
    while (l < h) {
        if ([array[l] compare:array[h]] == NSOrderedDescending) {
            [self swap:array at:l and:h];
            swapped = YES;
        }
        l++;
        h--;
    }
    if (l == h) {
        if ([array[l] compare:array[l + 1]] == NSOrderedDescending) {
            [self swap:array at:l and:l + 1];
            swapped = YES;
        }
    }
    int mid = (low + high) / 2;
    BOOL left = [self sort:array low:low high:mid];
    BOOL right = [self sort:array low:mid + 1 high:high];
    
    return swapped || left || right;
}

- (void)swap:(NSMutableArray<NSNumber *> *)array at:(NSUInteger)indexA and:(NSUInteger)indexB {
    NSNumber *tmp = array[indexA];
    array[indexA] = array[indexB];
    array[indexB] = tmp;
}

@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSMutableArray *array = [NSMutableArray arrayWithCapacity:10];
        for (int i = 0; i < 30; i++) {
            int ran = arc4random() % 100 - 50;
            [array addObject:@(ran)];
        }
        NSLog(@"before: %@", array);
        CircleSort *cs = [[CircleSort alloc] init];
        [cs sort:array];
        NSLog(@"after: %@", array);
    }
    return 0;
}
