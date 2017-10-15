/* Part of Cosmos by OpenGenus Foundation */
/* Added by Ondama */

/** Read a line of input **/
fn read () -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).expect("failed to read from stdin");
    input.trim().to_owned()
}

/** Display a message and parse input **/
fn prompt<T: std::str::FromStr + std::default::Default> (prompt: &str) -> T {
    println!("{}", prompt);
    let num = read();
    match num.parse() {
        Ok(i) => i,
        Err(..) => {
            eprintln!("'{}' is not valid, using default instead.", num);
            T::default()
        }
    }
}

/** Sort array **/
fn shaker_sort<T: std::cmp::PartialOrd + std::fmt::Debug> (arr: &mut Vec<T>) {
    let size = arr.len();
    for i in 0..size/2 {
        let mut swapped: bool = false;
        let k = size - i - 1;
        for j in i..k {
            let p = j;
            let q = p + 1;
            if arr[p] < arr[q] {
                arr.swap(p, q);
                swapped = true;
            }
        }
        for j in i..k {
            let p = k - j;
            let q = p - 1;
            if arr[p] > arr[q] {
                arr.swap(p, q);
                swapped = true;
            }
        }
        if !swapped {
            break;
        }
    }
}

/** Entry point **/
fn main () {
    // The size is a natural number
    let size = prompt::<usize>(&"Enter size of array:");
    // Fill array
    let mut arr = Vec::new();
    loop {
        let item = prompt::<i32>(&"Next array element:");
        arr.push(item);
        if arr.len() == size {
            break;
        }
    }
    // Sort array
    shaker_sort::<i32>(&mut arr);
    // Print sorted array
    println!("{:?}", arr);
}
