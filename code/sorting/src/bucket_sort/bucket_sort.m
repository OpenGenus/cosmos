/* Part of Cosmos by OpenGenus Foundation */

//
//  bucket_sort.m
//  Created by DaiPei on 2017/10/14.
//

#import <Foundation/Foundation.h>

#define DEFAULT_STEP 5

@interface BucketSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;
- (void)sort:(NSMutableArray<NSNumber *> *)array withStep:(NSUInteger)step;

@end

@implementation BucketSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    [self sort:array withStep:DEFAULT_STEP];
}

- (void)sort:(NSMutableArray<NSNumber *> *)array withStep:(NSUInteger)step {
    // find the max value
    NSNumber *max = @(INTMAX_MIN);
    NSNumber *min = @(INTMAX_MAX);
    for (int i = 0; i < array.count; i++) {
        if ([array[i] compare:max] == NSOrderedDescending) {
            max = array[i];
        }
        if ([array[i] compare:min] == NSOrderedAscending) {
            min = array[i];
        }
    }
    // calculate buckets count
    NSUInteger n = (max.integerValue - min.integerValue) / step + 1;
    NSMutableArray<NSMutableArray *> *buckets = [NSMutableArray arrayWithCapacity:n];
    for (int i = 0; i < n; i++) {
        [buckets addObject:[NSMutableArray array]];
    }
    // put value to buckets
    for (int i = 0; i < array.count; i++) {
        NSUInteger j = (array[i].integerValue - min.integerValue) / step;
        [buckets[j] addObject:array[i]];
    }
    // sort value in each bucket
    for (int i = 0; i < n; i++) {
        [self sortCore:buckets[i]];
    }
    // put sorted value back to origin array
    NSUInteger index = 0;
    for (int i = 0; i < n; i++) {
        NSMutableArray *bucket = buckets[i];
        for (int j = 0; j < bucket.count; j++) {
            array[index++] = bucket[j];
        }
    }
}

- (void)sortCore:(NSMutableArray<NSNumber *> *)array {
    for (int i = 0; i + 1 < array.count; i++) {
        int p = i;
        for (int j = i + 1; j < array.count; j++) {
            if ([array[j] compare:array[p]] == NSOrderedAscending) {
                p = j;
            }
        }
        [self swap:array at:i and:p];
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
        for (int i = 0; i < 100; i++) {
            int ran = arc4random() % 100 - 50;
            [array addObject:@(ran)];
        }
        NSLog(@"before: %@", array);
        BucketSort *bs = [[BucketSort alloc] init];
        [bs sort:array withStep:10];
        NSLog(@"after: %@", array);
    }
    return 0;
}
