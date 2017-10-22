/* Part of Cosmos by OpenGenus Foundation */

//
//  heap_sort.m
//  Created by DaiPei on 2017/10/9.
//

#import <Foundation/Foundation.h>

@interface HeapSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation HeapSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    int n = (int)array.count;
    
    // create the heap
    for (int i = n / 2; i >= 0; i--) {
        [self sink:array at:i to:n - 1];
    }
    
    // sort core
    for (int i = n - 1; i > 0; i--) {
        [self swap:array at:i and:0];
        [self sink:array at:0 to:i - 1];
    }
}

- (void)sink:(NSMutableArray<NSNumber *> *)array at:(NSUInteger)indexA to:(NSUInteger)indexB {
    NSUInteger pMax;
    while ((indexA + 1) * 2 - 1 <= indexB) {
        NSUInteger l = (indexA + 1) * 2 - 1;
        NSUInteger r = (indexA + 1) * 2;
        if (r <= indexB && [array[l] compare:array[r]] == NSOrderedAscending) {
            pMax = r;
        } else {
            pMax = l;
        }
        if ([array[indexA] compare:array[pMax]] == NSOrderedAscending) {
            [self swap:array at:indexA and:pMax];
            indexA = pMax;
        } else {
            break;
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
        NSMutableArray *array = [NSMutableArray array];
        for (int i = 0; i < 20; i++) {
            int ran = arc4random() % 20 - 10;
            [array addObject:@(ran)];
        }
        NSLog(@"before: %@", array);
        HeapSort *hs = [[HeapSort alloc] init];
        [hs sort:array];
        NSLog(@"after: %@", array);
    }
    return 0;
}
