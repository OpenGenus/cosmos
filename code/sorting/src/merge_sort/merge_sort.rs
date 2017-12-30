// Part of Cosmos by OpenGenus Foundation

/// A program that defines an unsorted vector,
/// and sorts it using a merge sort implementation.
fn main() {
    let mut arr = vec![4, 5, 9, 1, 3, 0, 7, 2, 8];

    merge_sort(&mut arr);
    println!("Sorted array: {:?}", arr)
}

/// Sort the given array using merge sort.
/// The given array is `modified`.
fn merge_sort(arr: &mut Vec<i32>) {
    let size = arr.len();
    let mut buffer = vec![0; size];

    merge_split(arr, 0, size, &mut buffer);
}

/// Initiate a merge sort by splitting the given `arr`.
/// The given vector is split recursively between `start` (inclusive) and
/// `end` (exclusive), and merged again in the proper order to sort the vector.
///
/// The `buffer` vector is used to temporarily move slices to, and has the same
/// size.
fn merge_split(arr: &mut Vec<i32>, start: usize, end: usize, buffer: &mut Vec<i32>) {
    if end - start > 1 {
        // Determine the split index
        let split = (start + end) / 2;

        // Split and merge sort
        merge_split(arr, start, split, buffer);
        merge_split(arr, split, end, buffer);
        merge(arr, buffer, start, split, end);
        merge_copy(buffer, arr, start, end);
    }
}

/// Merges two slices called left and right from `src` into `dest` in the
/// correct order to sort them.
///
/// The slices are defined by their indices:
/// - Left: from `start` (inclusive) to `split` (exclusive).
/// - Right: from `split` (inclusive) to `end` (exclusive).
///
/// Only the `dest` vector is modified.
fn merge(src: &Vec<i32>, dest: &mut Vec<i32>, start: usize, split: usize, end: usize) {
    // Define cursor indices for the left and right part that will be merged
    let mut left = start;
    let mut right = split;

    // Merge the parts into the destination in the correct order
    for i in start..end {
        if left < split && (right >= end || src[left] <= src[right]) {
            dest[i] = src[left];
            left += 1;
        } else {
            dest[i] = src[right];
            right += 1;
        }
    }
}

/// Copy elements from the `src` vector into `dest`.
/// Start at element `start` (included) and copy until element `end` (excluded).
///
/// Only the `dest` vector is modified.
fn merge_copy(src: &Vec<i32>, dest: &mut Vec<i32>, start: usize, end: usize) {
    (start..end).for_each(|i| dest[i] = src[i]);
}
