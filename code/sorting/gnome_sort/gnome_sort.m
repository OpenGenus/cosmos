/* Part of Cosmos by OpenGenus Foundation */

//
//  gnome_sort.m
//  Created by DaiPei on 2017/10/16.
//

#import <Foundation/Foundation.h>

@interface GnomeSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation GnomeSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    if (array.count <= 1) {
        return ;
    }
    int index = 0;
    while (index < array.count) {
        if (index == 0) {
            index++;
        }
        if ([array[index] compare:array[index - 1]] == NSOrderedAscending) {
            [self swap:array at:index and:index - 1];
            index--;
        } else {
            index++;
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
        NSMutableArray *array = [NSMutableArray arrayWithCapacity:10];
        for (int i = 0; i < 10; i++) {
            int ran = arc4random() % 20;
            [array addObject:@(ran)];
        }
        NSLog(@"before: %@", array);
        GnomeSort *gs = [[GnomeSort alloc] init];
        [gs sort:array];
        NSLog(@"after: %@", array);
    }
    return 0;
}
