/* Part of Cosmos by OpenGenus Foundation */

//
//  quick_sort.m
//  Created by DaiPei on 2017/10/10.
//

#import <Foundation/Foundation.h>

@interface QuickSort : NSObject

- (void)sort:(NSMutableArray<NSNumber *> *)array;

@end

@implementation QuickSort

- (void)sort:(NSMutableArray<NSNumber *> *)array {
  [self sort:array low:0 high:array.count - 1];
}

- (void)sort:(NSMutableArray<NSNumber *> *)array low:(NSUInteger)low high:(NSUInteger)high {
	if (low < high) {
		NSUInteger div = [self partition:array low:low high:high];
		if (div != 0) {
			[self sort:array low:low high:div - 1];
		}
		[self sort:array low:div + 1 high:high];
	}
}

- (NSUInteger)partition:(NSMutableArray<NSNumber *> *)array low:(NSUInteger)low high:(NSUInteger)high {
	NSUInteger mid = (low + high) / 2;
	[self swap:array at:mid and:high];
	NSUInteger p1 = low, p2 = low;
	while (p2 < high) {
		if ([array[p2] compare:array[high]] == NSOrderedAscending) {
					[self swap:array at:p1 and:p2];
					p1++;
		}
		p2++;
	}
	[self swap:array at:p1 and:high];
	return p1;
}

- (void)swap:(NSMutableArray<NSNumber *> *)array at:(NSUInteger)indexA and:(NSUInteger)indexB {
	NSNumber *tmp = array[indexA];
	array[indexA] = array[indexB];
	array[indexB] = tmp;
}

@end

int main(int argc, const char * argv[]) {
	@autoreleasepool {
		NSMutableArray *array = [NSMutableArray arrayWithCapacity:100];
		for (int i = 0; i < 100; i++) {
			uint32_t ran = arc4random() % 1000;
			[array addObject:@(ran)];
		}
		NSLog(@"Enter elements of the array one by one:");
		QuickSort *qs = [[QuickSort alloc] init];
		[qs sort:array];
		NSLog(@"%@", array);
	}
	return 0;
}

