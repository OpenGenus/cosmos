/* Part of Cosmos by OpenGenus Foundation */

//
//  intro_sort.m
//  Created by DaiPei on 2017/10/22.
//

#import <Foundation/Foundation.h>

@interface IntroSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation IntroSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    [self sortCore:array from:0 to:(int)array.count - 1 depth:(int)(log((double)array.count))];
}

- (void)sortCore:(NSMutableArray<NSNumber *> *)array from:(int)a to:(int)b depth:(int)depth {
    if (a < b) {
        if (depth == 0) {
            [self heapSort:array from:a to:b];
        } else {
            if ([self isSorted:array from:a to:b]) {
                return ;
            }
            int div = [self partition:array low:a high:b];
            [self sortCore:array from:a to:div - 1 depth:depth - 1];
            [self sortCore:array from:div + 1 to:b depth:depth - 1];
        }
    }
}

// quick sort core
- (int)partition:(NSMutableArray<NSNumber *> *)array low:(int)low high:(int)high {
    int mid = (low + high) / 2;
    [self swap:array at:mid and:high];
    int p1 = low, p2 = low;
    while (p2 < high) {
        if ([array[p2] compare:array[high]] == NSOrderedAscending) {
            [self swap:array at:p1 and:p2];
            p1++;
        }
        p2++;
    }
    [self swap:array at:p1 and:high];
    return p1;
}

// heap sort part
- (void)heapSort:(NSMutableArray<NSNumber *> *)array from:(int)a to:(int)b {
    
    // create the heap
    for (int i = (a + b) / 2; i >= a; i--) {
        [self sink:array at:i from:a to:b];
    }
    
    // sort core
    for (int i = b; i > a; i--) {
        [self swap:array at:i and:a];
        [self sink:array at:a from:a to:i - 1];
    }
}

- (void)sink:(NSMutableArray<NSNumber *> *)array at:(int)x from:(int)a to:(int)b {
    int b1 = b - a + 1;
    int i = x;
    int i1 = i - a + 1;
    while (i1 * 2 <= b1) {
        int l1 = 2 * i1;
        int r1 = 2 * i1 + 1;
        int l = l1 + a - 1;
        int r = r1 + a - 1;
        int p;
        if (r <= b && [array[r] compare:array[l]] == NSOrderedDescending) {
            p = r;
        } else {
            p = l;
        }
        if ([array[i] compare:array[p]] == NSOrderedAscending) {
            [self swap:array at:i and:p];
            i = p;
            i1 = i - a + 1;
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

- (BOOL)isSorted:(NSMutableArray<NSNumber *> *)array from:(int)a to:(int)b {
    for (int i = a + 1; i <= b; i++) {
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
            IntroSort *is = [[IntroSort alloc] init];
            [is sort:array];
            NSLog(@"after: %@", array);
            if (![is isSorted:array from:0 to:(int)array.count - 1]) {
                NSLog(@"ATTENTION!!!!!!!!!!!!!!");
                @throw [NSException exceptionWithName:@"array is not sorted" reason:nil userInfo:nil];
            }
            
        }
    }
    return 0;
}
