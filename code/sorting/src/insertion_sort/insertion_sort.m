/* Part of Cosmos by OpenGenus Foundation */

//
//  insertion_sort.m
//  Created by DaiPei on 2017/10/9.
//

#import <Foundation/Foundation.h>

@interface InsertionSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *) array;

@end

@implementation InsertionSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    for (int i = 1; i < array.count; i++) {
        NSNumber *k = array[i];
        int j;
        for (j = i; j > 0 && [k compare:array[j - 1]] == NSOrderedAscending; j--) {
            array[j] = array[j - 1];
        }
        array[j] = k;
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
        [is sort:array];
        NSLog(@"%@", array);
    }
    return 0;
}

