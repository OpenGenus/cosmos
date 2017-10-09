/* Part of Cosmos by OpenGenus Foundation */

//
//  BubbleSort.m
//  Created by DaiPei on 2017/10/9.
//

#import <Foundation/Foundation.h>

@interface BubbleSort : NSObject

- (void) bubbleSort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation BubbleSort

- (void) bubbleSort:(NSMutableArray<NSNumber *> *)array {
    for (int i = 0; i < array.count-1; i++) {
        BOOL swapped = NO;
        for (int j = 0; j < array.count-1-i; j++) {
            if ([array[j] compare:array[j + 1]] == NSOrderedDescending) {
                NSNumber *tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                swapped = YES;
            }
        }
        if (!swapped) {
            break;
        }
    }
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
        [bs bubbleSort:array];
        NSLog(@"%@", array);
    }
    return 0;
}
