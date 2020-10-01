// Part of Cosmos by OpenGenus
// find_leap_year takes in 2 years as start and end value
// and returns a vector containing the leap years between the given years.
// [start, end); end year in not included
fn find_leap_years(start: i32, end: i32) -> Vec<i32> {
    (start..end)
        .filter(|y| (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        .collect()
}

#[test]
fn name() {
    assert_eq!(
        find_leap_years(2000, 2018),
        vec![2000, 2004, 2008, 2012, 2016]
    );
}
