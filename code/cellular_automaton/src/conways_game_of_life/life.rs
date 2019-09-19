//use rand
use std::io;
use std::io::{Read, Write};

//(X,Y)
struct ConWay {
    len: u32,
    board: Vec<bool>,
}
impl ConWay {
    pub fn new(size: u32) -> Self {
        let mut board: Vec<bool> = Vec::with_capacity((size * size) as usize);
        //init
        for _ in (0..size * size) {
            board.push(rand::random());
        }
        ConWay {
            len: size,
            board: board,
        }
    }
    fn get_index(&self, idx: u32) -> (u32, u32) {
        (idx % self.len, idx / self.len)
    }
    fn is_safe(&self, idx: i32) -> bool {
        if idx < 0 || idx >= self.len as i32 {
            false
        } else {
            true
        }
    }
    fn get_raw_index(&self, pos: (i32, i32)) -> i32 {
        if self.is_safe(pos.0) && self.is_safe(pos.1) {
            pos.0 + pos.1 * self.len as i32
        } else {
            -1
        }
    }
    pub fn life(&mut self) {
        let travel_table: [(i32, i32); 8] = [
            (0, 1),
            (1, 1),
            (1, 0),
            (1, -1),
            (0, -1),
            (-1, -1),
            (-1, 0),
            (-1, 1),
        ];
        for (idx, ele) in self.board.clone().iter_mut().enumerate() {
            let pos = self.get_index(idx as u32);
            let mut death = 0;
            let mut total = 0;
            for (x, y) in travel_table.iter() {
                let cur_pos = self.get_raw_index((pos.0 as i32 + x, pos.1 as i32 + y));
                if cur_pos >= 0 {
                    let cur = self.board[cur_pos as usize];
                    if !cur {
                        death += 1;
                    }
                    total += 1;
                }
            }
            //println!("idx: {}, death: {} , total: {}", idx, death, total);
            match ele {
                false => {
                    //dead
                    if death == 3 {
                        //println!("changed true");
                        self.board[idx as usize] = true;
                    }
                }
                true => {
                    //alive
                    let live = total - death;
                    if !(live == 2 || live == 3) {
                        //println!("changed false");
                        self.board[idx as usize] = false;
                    }
                }
            }
        }
    }
    pub fn print(&self) {
        //io::stdout().flush().unwrap();
        for (idx, val) in self.board.iter().enumerate() {
            match val {
                true => {
                    print!("1");
                }
                false => {
                    print!("0");;
                }
            }
            if idx % self.len as usize == (self.len - 1) as usize {
                println!();
            }
        }
    }
}
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("read_fail");
    let l: u32 = input.trim().parse().unwrap();
    let mut hello = ConWay::new(l);

    loop {
        hello.print();
        hello.life();
        input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        if input.trim() == "X" {
            break;
        }
    }
}
