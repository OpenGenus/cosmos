/* Part of Cosmos by OpenGenus Foundation */

//
//  median_sort.m
//  Created by DaiPei on 2017/10/27.
//

#import <Foundation/Foundation.h>

@interface MedianSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation MedianSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    [self recursiveSort:array left:0 right:array.count - 1];
}

- (void)recursiveSort:(NSMutableArray<NSNumber *> *)array left:(NSUInteger)left right:(NSUInteger)right {
    if (left < right) {
        NSUInteger pivot = [self pivot:array left:left right:right];
        pivot = [self partition:array left:left right:right pivot:pivot];
        if (pivot != 0) {
            [self recursiveSort:array left:left right:pivot - 1];
        }
        [self recursiveSort:array left:pivot + 1 right:right];
    }
}

- (NSUInteger)pivot:(NSMutableArray<NSNumber *> *)array left:(NSUInteger)left right:(NSUInteger)right {
    NSUInteger count = right - left + 1;
    if (count < 6) {
        return [self median5:array left:left right:right];
    }
    for (NSUInteger subLeft = left; subLeft < right; subLeft += 5) {
        NSUInteger subRight = subLeft + 4;
        if (subRight > right) {
            subRight = right;
        }
        NSUInteger median = [self median5:array left:subLeft right:subRight];
        [self swap:array at:median and:left + (subLeft - left) / 5];
    }
    return [self select:array left:left right:left + (count - 1) / 5 ofK:left + count / 10];
}

- (NSUInteger)median5:(NSMutableArray<NSNumber *> *)array left:(NSUInteger)left right:(NSUInteger)right {
    NSUInteger mid = (left + right) / 2;
    for (NSUInteger i = left; i < right; i++) {
        NSUInteger p = i;
        for (NSUInteger j = i + 1; j <= right; j++) {
            if ([array[p] compare:array[j]] == NSOrderedDescending) {
                p = j;
            }
        }
        [self swap:array at:i and:p];
        if (i >= mid) {
            break;
        }
    }
    return mid;
}

- (NSUInteger)select:(NSMutableArray<NSNumber *> *)array left:(NSUInteger)left right:(NSUInteger)right ofK:(NSUInteger)k {
    if (left == right) {
        return left;
    }
    while (YES) {
        NSUInteger piv = [self pivot:array left:left right:right];
        piv = [self partition:array left:left right:right pivot:piv];
        if (piv == k) {
            break;
        } else if (piv < k) {
            left = piv + 1;
        } else {
            right = piv - 1;
        }
    }
    return k;
}

- (NSUInteger)partition:(NSMutableArray<NSNumber *> *)array left:(NSUInteger)left right:(NSUInteger)right pivot:(NSUInteger)pivot {
    NSUInteger p1 = left;
    NSUInteger p2 = left;
    [self swap:array at:pivot and:right];
    while (p1 < right) {
        if ([array[right] compare:array[p1]] == NSOrderedDescending) {
            [self swap:array at:p1 and:p2];
            p2++;
        }
        p1++;
    }
    [self swap:array at:right and:p2];
    return p2;
}

- (void)swap:(NSMutableArray<NSNumber *> *)array at:(NSUInteger)indexA and:(NSUInteger)indexB {
    NSNumber *tmp = array[indexA];
    array[indexA] = array[indexB];
    array[indexB] = tmp;
}

@end

@interface SortTester : NSObject

+ (BOOL)isSorted:(NSArray<NSNumber *> *)array;

@end

@implementation SortTester

+ (BOOL)isSorted:(NSArray<NSNumber *> *)array {
    for (int i = 1; i < array.count; i++) {
        if ([array[i] compare:array[i - 1]] == NSOrderedAscending) {
            return NO;
        }
    }
    return YES;
}

@end

int main(int argc, const char * argv[]) {
    for (int j = 0; j < 100; j++) {
        @autoreleasepool {
            NSMutableArray *array = [NSMutableArray array];
            for (int i = 0; i < 20; i++) {
                int ran = arc4random() % 20 - 10;
                [array addObject:@(ran)];
            }
            NSLog(@"before: %@", array);
            MedianSort *ms = [[MedianSort alloc] init];
            [ms sort:array];
            NSLog(@"after: %@", array);
            assert([SortTester isSorted:array]);
        }
    }
    return 0;
}
