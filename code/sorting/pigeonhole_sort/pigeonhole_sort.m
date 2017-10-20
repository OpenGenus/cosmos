/* Part of Cosmos by OpenGenus Foundation */

//
//  pigeonhole_sort.m
//  Created by DaiPei on 2017/10/19.
//

#import <Foundation/Foundation.h>

@interface PigeonholeSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation PigeonholeSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    
    // find the max and min value in array
    NSNumber *max = @(INTMAX_MIN);
    NSNumber *min = @(INTMAX_MAX);
    for (NSNumber *item in array) {
        if ([max compare:item] == NSOrderedAscending) {
            max = item;
        }
        if ([min compare:item] == NSOrderedDescending) {
            min = item;
        }
    }
    
    // put element to right hole
    int range = max.intValue - min.intValue + 1;
    NSMutableArray<NSMutableArray *> *holes = [NSMutableArray array];
    for (int i = 0; i < range; i++) {
        [holes addObject:[NSMutableArray array]];
    }
    for (NSNumber *item in array) {
        [holes[item.intValue - min.intValue] addObject:item];
    }
    
    // use holes to make sorted array
    int index = 0;
    for (NSMutableArray *hole in holes) {
        for (NSNumber *item in hole) {
            array[index++] = item;
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
        PigeonholeSort *ps = [[PigeonholeSort alloc] init];
        [ps sort:array];
        NSLog(@"after: %@", array);
    }
    return 0;
}
