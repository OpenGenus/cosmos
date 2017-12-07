/* Part of Cosmos by OpenGenus Foundation */

//
//  shaker_sort.m
//  Created by DaiPei on 2017/10/9.
//

#import <Foundation/Foundation.h>

@interface ShakerSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation ShakerSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    BOOL swapped = NO;
    for (int i = 0; i < array.count / 2; i++) {
        for (int j = i; j + 1 < array.count - i; j++) {
            if ([array[j] compare:array[j + 1]] == NSOrderedDescending) {
                [self swap:array at:j and:j + 1];
                swapped = YES;
            }
        }
        for (int j = (int)array.count - i - 2; j > i; j--) {
            if ([array[j] compare:array[j - 1]] == NSOrderedAscending) {
                [self swap:array at:j and:j - 1];
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
        ShakerSort *ss = [[ShakerSort alloc] init];
        [ss sort:array];
        NSLog(@"%@", array);
    }
    return 0;
}

