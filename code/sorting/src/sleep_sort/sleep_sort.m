/* Part of Cosmos by OpenGenus Foundation */

//
//  sleep_sort.m
//  Created by DaiPei on 2017/10/12.
//

#import <Foundation/Foundation.h>

@interface SleepSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation SleepSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
    dispatch_group_t group = dispatch_group_create();
    for (int i = 0; i < array.count; i++) {
        dispatch_queue_t queue = dispatch_queue_create("com.my.queue", NULL);
        dispatch_group_async(group, queue, ^{
            usleep(array[i].unsignedIntValue * 1000);
            NSLog(@"%@", array[i]);
        });
    }
    dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
}

@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSMutableArray *array = [NSMutableArray arrayWithCapacity:100];
        for (int i = 0; i < 100; i++) {
            uint32_t ran = arc4random() % 1000;
            [array addObject:@(ran)];
        }
        SleepSort *ss = [[SleepSort alloc] init];
        [ss sort:array];
    }
    return 0;
}
