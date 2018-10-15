use std::hash::{Hash, Hasher};
use std::collections::hash_map::DefaultHasher;
use std::fmt;

trait HashFunc {
    type Key;
    type Value;
    fn new(key: Self::Key, value: Self::Value) -> Self;
    fn get_value(&self) -> &Self::Value;
    fn get_key(&self) -> &Self::Key;
}
struct HashTable<K, V> {
    list: Vec<Vec<HashPair<V, K>>>,
    mindex: u64,
    size: u64,
}
impl<K, V> HashTable<K, V>
where
    K: Hash + PartialEq + fmt::Display,
    V: fmt::Display,
{
    fn new(index: u64) -> Self {
        let mut empty_vec = Vec::new();
        for _ in 0..index {
            empty_vec.push(Vec::new());
        }
        HashTable {
            list: empty_vec,
            size: 0,
            mindex: index,
        }
    }
    fn hash(&self, key: &K) -> u64 {
        let mut hasher = DefaultHasher::new();
        key.hash(&mut hasher);
        hasher.finish() % self.mindex
    }
    fn get(&self, key: K) -> Option<&V> {
        let index = self.hash(&key);
        if let Some(list) = self.list.get(index as usize) {
            if let Some(ele) = list.iter().find(|x| *x.get_key() == key) {
                Some(ele.get_value())
            } else {
                None
            }
        } else {
            None
        }
    }
    fn put(&mut self, key: K, value: V) {
        let index = self.hash(&key);
        if let Some(lin_list) = self.list.get_mut(index as usize) {
            let insert_value = HashPair::new(key, value);
            if let Some(index) = lin_list.iter().position(
                |x| *x.get_key() == insert_value.key,
            )
            {
                lin_list.remove(index);
            }
            lin_list.push(insert_value);
            self.size += 1;
        }
    }
    fn remove(&mut self, key: K) {
        let index = self.hash(&key);
        if let Some(lin_list) = self.list.get_mut(index as usize) {
            lin_list.retain(|x| *x.get_key() != key);
            self.size -= 1;
        }
    }
    fn size(&self) -> u64 {
        self.size
    }
    fn print(&self) {
        for index in 0..self.mindex {
            if let Some(lin_list) = self.list.get(index as usize) {
                for inner_index in 0..lin_list.len() {
                    print!("{} ", lin_list.get(inner_index).unwrap());
                }
            }
        }
        println!();
    }
}
struct HashPair<T, K> {
    key: K,
    value: T,
}
impl<T, K> fmt::Display for HashPair<T, K>
where
    T: fmt::Display,
    K: fmt::Display,
{
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "({}, {})", self.key, self.value)
    }
}
impl<T, K> HashFunc for HashPair<T, K> {
    type Key = K;
    type Value = T;
    fn get_value(&self) -> &Self::Value {
        &self.value
    }
    fn get_key(&self) -> &Self::Key {
        &self.key
    }
    fn new(key: Self::Key, value: Self::Value) -> Self {
        HashPair {
            key: key,
            value: value,
        }
    }
}

const MINDEX: u64 = 128;

fn main() {
    let mut test = HashTable::new(MINDEX);
    test.put("hello", "bye");
    test.put("what's up", "dude");
    test.remove("hell");
    test.print();
}
