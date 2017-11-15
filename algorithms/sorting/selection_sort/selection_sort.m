/* Part of Cosmos by OpenGenus Foundation */

//
//  selection_sort.m
//  Created by DaiPei on 2017/10/9.
//

#import <Foundation/Foundation.h>

@interface SelectionSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation SelectionSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
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
        SelectionSort *ss = [[SelectionSort alloc] init];
        [ss sort:array];
        NSLog(@"%@", array);
    }
    return 0;
}

