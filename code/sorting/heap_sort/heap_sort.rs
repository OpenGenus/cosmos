// Part of Cosmos by OpenGenus Foundation

fn heapify(arr: &mut [i32], n: usize, i: usize){
    let mut largest = i; //largest as root
    let l = 2*i + 1; //left
    let r = 2*i + 2; //right

    //if child larger than root
    if l < n && arr[l as usize] > arr[largest as usize]{
        largest = l;
    }

    //if child larger than largest
    if r < n && arr[r as usize] > arr[largest as usize]{
        largest = r;
    }

    //if largest is not root
    if largest != i{
        let temp = arr[i as usize];
        arr[i as usize] = arr[largest as usize];
        arr[largest as usize] = temp;

        //recursively heapify
        heapify(arr, n, largest);
    }
}

fn heap_sort(arr: &mut [i32], n: usize){
    //build heap
    for i in (0..n / 2 - 1).rev(){
        heapify(arr, n, i);
    }

    for i in (0..n - 1).rev(){
        //move current root to end
        let temp = arr[i as usize];
        arr[i as usize] = arr[0];
        arr[0] = temp;

        heapify(arr, i, 0);
    }
}

fn print_array(arr: &mut [i32], n: usize){
    for i in (0..n).rev(){
        print!("{} ", arr[i as usize]);
    }
    println!("");
}

//test heap sort
fn main() {
    let mut arr: [i32; 8] = [1, 2, 3, 4, 5, 6, 7, 8];
    let n: usize = arr.len();

    heap_sort(&mut arr, n);

    println!("Sorted Array:");
    print_array(&mut arr, n);
}
