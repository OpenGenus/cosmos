fn find_waiting_time(bt: &[i32]) -> Vec<i32> {
    let mut wt = Vec::with_capacity(bt.len());
    // Waiting time for first process is 0
    wt.push(0);
    
    for i in 1..bt.len() {
        let last_wt = wt.last().cloned().unwrap();
        wt.push(bt[i - 1] + last_wt);
    }
    
    wt
}

fn find_turnaround_time(bt: &[i32], wt: &[i32]) -> Vec<i32> {
    let mut tat = Vec::with_capacity(bt.len());
    
    for i in 0..bt.len() {
        tat.push(bt[i] + wt[i]);
    }
    
    tat
}

fn find_avg_time(processes: &[i32], burst_times: &[i32]) {
    if processes.len() != burst_times.len() {
        return;
    }
    
    let n = processes.len();
    
    let wt = find_waiting_time(burst_times);
    
    let tat = find_turnaround_time(burst_times, &wt);
    
    println!("Processes\tBurst Time\tWaiting Time\t Turn around time");
    
    let total_wt = wt.iter().fold(0, |acc, &t| acc + t);
    let total_tat = tat.iter().fold(0, |acc, &t| acc + t);
    // Calculate total waiting ntime and total turn around time
    for i in 0..n {
        println!("{}\t{}\t{}\t{}", i + 1, burst_times[i], wt[i], tat[i]);
    }
    
    println!("Average waiting time: {}", total_wt / n as i32);
    println!("Average turn around time: {}", total_tat / n as i32);
}

fn main() {
    let processes = vec![1, 2, 3];
    let burst_time = vec![10, 5, 8];
    
    find_avg_time(&processes, &burst_time);
}
