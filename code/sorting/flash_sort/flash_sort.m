/* Part of Cosmos by OpenGenus Foundation */

//
//  flash_sort.m
//  Created by DaiPei on 2017/10/17.
//

#import <Foundation/Foundation.h>

@interface FlashSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation FlashSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    // find the max and min item in array
    NSInteger max = INTMAX_MIN;
    NSInteger min = INTMAX_MAX;
    for (NSNumber *item in array) {
        if (item.integerValue > max) {
            max = item.integerValue;
        }
        if (item.integerValue < min) {
            min = item.integerValue;
        }
    }
    if (min == max) {
        return ;
    }
    
    // divide to m class
    NSInteger m = (NSInteger)(0.43 * array.count);
    double c = (double)(m - 1) / (double)(max - min);
    
    // after this loop pClass[k] point to under bound of class k, it means every element is moved to the right class
    int *pClass = (int *)calloc(m + 1, sizeof(int));
    for (NSNumber *item in array) {
        NSInteger k = (NSInteger)(c * (item.integerValue - min)) + 1;
        pClass[k]++;
    }
    for (int k = 1; k <= m; k++) {
        pClass[k] += pClass[k - 1];
    }
    
    // move every element to right class
    NSUInteger move = 0;
    NSUInteger j = 0;
    NSInteger k = m;
    while (move < array.count - 1) {
        while (j >= pClass[k]) {
            j++;
            k = (NSInteger)(c * (array[j].integerValue - min)) + 1;
        }
        NSInteger flash = array[j].integerValue;
        while (j < pClass[k]) {
            k = (NSInteger)(c * (flash - min)) + 1;
            pClass[k]--;
            NSInteger tmp = array[pClass[k]].integerValue;
            array[pClass[k]] = @(flash);
            flash = tmp;
            move++;
        }
    }
    
    // sort every class
    for (int i = 1; i < m; i++) {
        [self sortCore:array from:pClass[i] to:pClass[i + 1]];
    }
}

- (void)swap:(NSMutableArray<NSNumber *> *)array at:(NSUInteger)indexA and:(NSUInteger)indexB {
    NSNumber *tmp = array[indexA];
    array[indexA] = array[indexB];
    array[indexB] = tmp;
}

- (void)sortCore:(NSMutableArray<NSNumber *> *)array from:(NSUInteger)a to:(NSUInteger)b {
    if (a >= b) {
        return ;
    }
    for (NSUInteger i = a; i + 1 < b; i++) {
        NSUInteger p = i;
        for (NSUInteger j = i + 1; j < b; j++) {
            if ([array[p] compare:array[j]] == NSOrderedDescending) {
                p = j;
            }
        }
        [self swap:array at:p and:i];
    }
}

@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSMutableArray *array = [NSMutableArray arrayWithCapacity:20];
        for (int i = 0; i < 20; i++) {
            int ran = arc4random() % 100;
            [array addObject:@(ran)];
        }
        NSLog(@"before: %@", array);
        FlashSort *fs = [[FlashSort alloc] init];
        [fs sort:array];
        NSLog(@"after: %@", array);
    }
    return 0;
}
