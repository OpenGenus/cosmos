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
    
    // find the max value
    NSNumber *m = @(INTMAX_MIN);
    for (NSNumber *val in array) {
        if (val.integerValue < 0) {
            return ;
        }
        if ([m compare:val] == NSOrderedAscending) {
            m = val;
        }
    }
    
    // record each element count
    int *freq = calloc(m.intValue + 1, sizeof(int));
    for (NSNumber *val in array) {
        freq[val.intValue]++;
    }
    
    // use freq to create sorted array
    int j = 0;
    for (int i = 0; i < m.intValue + 1; i++) {
        int count = freq[i];
        while (count) {
            array[j] = @(i);
            j++;
            count--;
        }
    }
}

@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSMutableArray *array = [NSMutableArray arrayWithCapacity:10];
        for (int i = 0; i < 10; i++) {
            int ran = arc4random() % 20;
            [array addObject:@(ran)];
        }
        NSLog(@"before: %@", array);
        CountingSort *cs = [[CountingSort alloc] init];
        [cs sort:array];
        NSLog(@"after: %@", array);
    }
    return 0;
}
