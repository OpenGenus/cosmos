/* Part of Cosmos by OpenGenus Foundation */

//
//  comb_sort.m
//  Created by DaiPei on 2017/10/15.
//

#import <Foundation/Foundation.h>

@interface CombSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation CombSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    NSUInteger gap = array.count;
    BOOL swapped = YES;
    double const shrinkFactor = 0.8;
    while (gap >= 1 || swapped) {
        swapped = NO;
        if (gap >= 1) {
            gap = (NSUInteger)(gap * shrinkFactor);
        }
        for (int i = 0; i + gap < array.count; i++) {
            if ([array[i] compare:array[i + gap]] == NSOrderedDescending) {
                [self swap:array at:i and:i + gap];
                swapped = YES;
            }
        }
    }
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
        CombSort *cs = [[CombSort alloc] init];
        [cs sort:array];
        NSLog(@"after: %@", array);
    }
    return 0;
}
