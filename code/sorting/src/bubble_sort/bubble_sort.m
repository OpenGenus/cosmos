/* Part of Cosmos by OpenGenus Foundation */

//
//  BubbleSort.m
//  Created by DaiPei on 2017/10/9.
//

#import <Foundation/Foundation.h>

@interface BubbleSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation BubbleSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    for (int i = 0; i + 1 < array.count; i++) {
        BOOL swapped = NO;
        for (int j = 0; j < array.count-1-i; j++) {
            if ([array[j] compare:array[j + 1]] == NSOrderedDescending) {
                [self swap:array at:j and:j + 1];
                swapped = YES;
            }
        }
        if (!swapped) {
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
        BubbleSort *bs = [[BubbleSort alloc] init];
        [bs sort:array];
        NSLog(@"%@", array);
    }
    return 0;
}

