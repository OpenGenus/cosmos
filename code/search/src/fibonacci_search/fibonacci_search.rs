/*
 * Part of Cosmos by OpenGenus Foundation
 */

use std::cmp::{min, PartialOrd, PartialEq};

fn fib_search<T>(arr: &[T], subject: &T) -> Option<usize> where T: PartialOrd, T: PartialEq {
    let mut fib1 = 0;
    let mut fib2 = 1;
    let mut fib = fib1 + fib2;

    // get smallest fib number smaller or equal to the length of the array
    while fib < arr.len() {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    let mut offset = -1isize;

    // Loop until the index of the element is found
    while fib > 1 {
        // check that we inspect a valid array location
        let i = min(offset + fib2 as isize, (arr.len() - 1) as isize) as usize;

        if arr[i] < *subject {
            // if the subject is greater, inspect from the current position to the end
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i as isize;
        } else if arr[i] > *subject {
            // if the subject is smaller, inspect from the current offset to the current position
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else {
            // element found
            return Some(i);
        }
    }

    // check the last element
    if fib1 == 1 && offset + 1 < arr.len() as isize && arr[(offset + 1) as usize] == *subject {
        Some((offset + 1) as usize)
    } else {
        None
    }
}

