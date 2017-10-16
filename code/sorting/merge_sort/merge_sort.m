/* Part of Cosmos by OpenGenus Foundation */

//
//  merge_sort.m
//  Created by DaiPei on 2017/10/10.
//

#import <Foundation/Foundation.h>

@interface MergeSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation MergeSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    [self sort:array withLow:0 high:array.count - 1];
}

- (void)sort:(NSMutableArray<NSNumber *> *)array withLow:(NSUInteger)low high:(NSUInteger)high {
    if (low < high) {
        NSUInteger mid = (low + high) / 2;
        [self sort:array withLow:low high:mid];
        [self sort:array withLow:mid + 1 high:high];
        [self merge:array withLow:low mid:mid high:high];
    }
}

- (void)merge:(NSMutableArray<NSNumber *> *)array withLow:(NSUInteger)low mid:(NSUInteger)mid high:(NSUInteger)high {
    NSArray *tmpArray = [array copy];
    
    NSUInteger i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if ([tmpArray[i] compare:tmpArray[j]] == NSOrderedAscending) {
            array[k] = tmpArray[i];
            i++;
        } else {
            array[k] = tmpArray[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        array[k] = tmpArray[i];
        i++;
        k++;
    }
    while (j <= high) {
        array[k] = tmpArray[j];
        j++;
        k++;
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
        MergeSort *ms = [[MergeSort alloc] init];
        [ms sort:array];
        NSLog(@"%@", array);
    }
    return 0;
}
