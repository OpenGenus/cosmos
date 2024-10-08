//defining node//
struct TreeNode<T> {
    value: T,
    left: Option<Box<TreeNode<T>>>,
    right: Option<Box<TreeNode<T>>>,
}
//creating tree//
struct BinaryTree<T> {
    root: Option<Box<TreeNode<T>>>,
}
//operations//
impl<T: PartialEq> BinaryTree<T> {
    fn insert(&mut self, value: T) {
        let new_node = Box::new(TreeNode {
            value,
            left: None,
            right: None,
        });
        match self.root.as_mut() {
            None => self.root = Some(new_node),
            Some(node) => node.insert(new_node),
        }
    }
}

impl<T: PartialEq> TreeNode<T> {
    fn insert(&mut self, new_node: Box<TreeNode<T>>) {
        if new_node.value < self.value {
            match self.left.as_mut() {
                None => self.left = Some(new_node),
                Some(node) => node.insert(new_node),
            }
        } else {
            match self.right.as_mut() {
                None => self.right = Some(new_node),
                Some(node) => node.insert(new_node),
            }
        }
    }
}
//search
impl<T: PartialEq> BinaryTree<T> {
    fn insert(&mut self, value: T) {
        let new_node = Box::new(TreeNode {
            value,
            left: None,
            right: None,
        });
        match self.root.as_mut() {
            None => self.root = Some(new_node),
            Some(node) => node.insert(new_node),
        }
    }
}

impl<T: PartialEq> TreeNode<T> {
    fn insert(&mut self, new_node: Box<TreeNode<T>>) {
        if new_node.value < self.value {
            match self.left.as_mut() {
                None => self.left = Some(new_node),
                Some(node) => node.insert(new_node),
            }
        } else {
            match self.right.as_mut() {
                None => self.right = Some(new_node),
                Some(node) => node.insert(new_node),
            }
        }
    }
}
//deletion
impl<T: PartialEq> BinaryTree<T> {
    fn delete(&mut self, value: T) {
        match self.root.as_mut() {
            None => {}
            Some(node) => node.delete(value),
        }
    }
}

impl<T: PartialEq> TreeNode<T> {
    fn delete(&mut self, value: T) -> Option<Box<TreeNode<T>>> {
        if value < self.value {
            self.left.as_mut().and_then(|node| node.delete(value))
        } else if value > self.value {
            self.right.as_mut().and_then(|node| node.delete(value))
        } else {
            if self.left.is_none() && self.right.is_none() {
                None
            } else if self.left.is_none() {
                self.right.take()
            } else if self.right.is_none() {
                self.left.take()
            } else {
                let successor = self.right.as_mut().unwrap().find_min();
                self.value = successor.value;
                successor.delete(successor.value)
            }
        }
    }

    fn find_min(&mut self) -> &mut TreeNode<T> {
        match self.left.as_mut() {
            None => self,
            Some(node) => node.find_min(),
        }
    }
}
//tranversal
impl<T: std::fmt::Display> BinaryTree<T> {
    fn inorder(&self) {
        match self.root.as_ref() {
            None => {}
            Some(node) => node.inorder(),
        }
    }
}

impl<T: std::fmt::Display> TreeNode<T> {
    fn inorder(&self) {
        if let Some(left) = &self.left {
            left.inorder();
        }
        println!("{}", self.value);
        if let Some(right) = &self.right {
            right.inorder();
        }
    }
}
