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
        NSUInteger leftIndex = (indexA + 1) * 2 - 1;
        NSUInteger rightIndex = (indexA + 1) * 2;
        if (rightIndex <= indexB) {
            if ([array[leftIndex] compare:array[rightIndex]] == NSOrderedDescending) {
                pMax = leftIndex;
            } else {
                pMax = rightIndex;
            }
        } else {
            pMax = leftIndex;
        }
        if ([array[indexA] compare:array[pMax]] == NSOrderedAscending) {
            [self swap:array at:indexA and:pMax];
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
        int n = 0;
        NSLog(@"What is the size of the array?");
        scanf("%d", &n);
        NSMutableArray *array = [NSMutableArray arrayWithCapacity:n];
        NSLog(@"Enter elements of the array one by one:");
        for (int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            [array addObject:@(tmp)];
        }
        HeapSort *hs = [[HeapSort alloc] init];
        [hs sort:array];
        NSLog(@"%@", array);
    }
    return 0;
}
