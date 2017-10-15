/* Part of Cosmos by OpenGenus Foundation */

//
//  cycle_sort.m
//  Created by DaiPei on 2017/10/15.
//

#import <Foundation/Foundation.h>

@interface CycleSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation CycleSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    for (int cycleStart = 0; cycleStart + 1 < array.count; cycleStart++) {
        int pos = cycleStart;
        NSNumber *value = array[cycleStart];
        // count all smaller elements on the right side
        for (int i = cycleStart + 1; i < array.count; i++) {
            if ([value compare:array[i]] == NSOrderedDescending) {
                pos++;
            }
        }
        
        // continue when value in right position
        if (pos == cycleStart) {
            continue;
        }
        
        // ignore all duplicate elements
        while ([value compare:array[pos]] == NSOrderedSame) {
            pos++;
        }
        
        // put the value to the right position
        [self swap:array at:pos and:cycleStart];
        
        // cycle angain with the new value
        while (pos != cycleStart) {
            pos = cycleStart;
            value = array[cycleStart];
            
            // count all smaller elements on the right side of new value =
            for (int i = cycleStart + 1; i < array.count; i++) {
                if ([value compare:array[i]] == NSOrderedDescending) {
                    pos++;
                }
            }
            
            // break when new value in right position
            if (pos == cycleStart) {
                break;
            }
            
            // ignore all duplicate elements
            while ([value compare:array[pos]] == NSOrderedSame) {
                pos++;
            }
            
            // put new value to the right position
            [self swap:array at:pos and:cycleStart];
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
        for (int i = 0; i < 10; i++) {
            int ran = arc4random() % 100 - 50;
            [array addObject:@(ran)];
        }
        NSLog(@"before: %@", array);
        CycleSort *cs = [[CycleSort alloc] init];
        [cs sort:array];
        NSLog(@"after: %@", array);
    }
    return 0;
}

