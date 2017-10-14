/* Part of Cosmos by OpenGenus Foundation */

//
//  bogo_sort.m
//  Created by DaiPei on 2017/10/14.
//

#import <Foundation/Foundation.h>

@interface BogoSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation BogoSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    while (![self isSorted:array]) {
        [self shuffle:array];
    }
}

- (BOOL)isSorted:(NSMutableArray<NSNumber *> *)array {
    if (array.count <= 1) {
        return YES;
    }
    for (int i = 1; i < array.count; i++) {
        if ([array[i] compare:array[i - 1]] == NSOrderedAscending) {
            return NO;
        }
    }
    return YES;
}

- (void)shuffle:(NSMutableArray<NSNumber *> *)array {
    for (int i = 0; i < array.count; i++) {
        int j = arc4random() % array.count;
        [self swap:array at:i and:j];
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
        BogoSort *bs = [[BogoSort alloc] init];
        [bs sort:array];
        NSLog(@"%@", array);
    }
    return 0;
}
