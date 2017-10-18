/* Part of Cosmos by OpenGenus Foundation */

fn main() {
    let mut arr: Vec<u32> = vec![34, 3212, 51, 52, 612, 456, 12, 31, 412, 123, 1, 3];

    println!("Unsorted: {:?}", arr);

    radix_sort(&mut arr);

    println!("Sorted:   {:?}", arr);
}

fn radix_sort(input: &mut [u32]) {
    if input.len() == 0 {
        return;
    }

    // initialize buckets
    let mut buckets: Vec<Vec<u32>> = Vec::with_capacity(10);
    for _ in 0..10 {
        buckets.push(Vec::new());
    }

    // count how many digits the longest number has
    // unwrap is safe here because we return in case of an empty input
    let count: usize = input.iter()
        .max()
        .unwrap()
        .to_string()
        .len();
    let mut divisor: u32 = 1;

    for _ in 0..count {
        for num in input.iter() {
            let temp = (num / divisor) as usize;
            buckets[temp % 10].push(*num);
        }

        let mut j: usize = 0;
        for k in 0..10 {
            for x in buckets[k].iter() {
                input[j] = *x;
                j += 1;
            }
            buckets[k].clear();
        }

        divisor *= 10;
    }
}
