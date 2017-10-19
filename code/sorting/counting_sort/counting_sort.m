/* Part of Cosmos by OpenGenus Foundation */

//
//  counting_sort.m
//  Created by DaiPei on 2017/10/15.
//

#import <Foundation/Foundation.h>

@interface CountingSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation CountingSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    
    // find the max and min value
    NSNumber *max = @(INTMAX_MIN);
    NSNumber *min = @(INTMAX_MAX);
    for (NSNumber *val in array) {
        if ([max compare:val] == NSOrderedAscending) {
            max = val;
        }
        if ([min compare:val] == NSOrderedDescending) {
            min = val;
        }
    }
    
    // calculate every element position
    int range = max.intValue - min.intValue + 1;
    int *position = calloc(range, sizeof(int));
    for (NSNumber *val in array) {
        position[val.intValue - min.intValue]++;
    }
    for (int i = 1; i < range; i++) {
        position[i] += position[i - 1];
    }
    
    // put every element to right position
    int j = 0;
    for (int i = 0; i < range; i++) {
        while (j < position[i]) {
            array[j] = @(i + min.intValue);
            j++;
        }
    }
}

@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSMutableArray *array = [NSMutableArray arrayWithCapacity:10];
        for (int i = 0; i < 10; i++) {
            int ran = arc4random() % 20 - 10;
            [array addObject:@(ran)];
        }
        NSLog(@"before: %@", array);
        CountingSort *cs = [[CountingSort alloc] init];
        [cs sort:array];
        NSLog(@"after: %@", array);
    }
    return 0;
}

