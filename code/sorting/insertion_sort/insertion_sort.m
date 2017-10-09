//
//  insertion_sort.m
//  oc_for_cosmos
//
//  Created by DaiPei on 2017/10/9.
//  Copyright © 2017年 DaiPei. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface InsertionSort : NSObject

- (void)insertionSort:(NSMutableArray<NSNumber *> *) array;

@end

@implementation InsertionSort

- (void)insertionSort:(NSMutableArray<NSNumber *> *)array {
    for (int i = 1; i < array.count; i++) {
        for (int j = i; j > 0 && [array[j] compare:array[j - 1]] == NSOrderedAscending; j--) {
            NSNumber *tmp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = tmp;
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
        InsertionSort *is = [[InsertionSort alloc] init];
        [is insertionSort:array];
        NSLog(@"%@", array);
    }
    return 0;
}
