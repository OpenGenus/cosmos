class Node{
	constructor(data){
		this.data = data;
		this.left = null;
		this.right = null;
	}
}

class Tree{

	constructor(){
		this.head  = null;
	}

	insert(data){
		let newNode = new Node(data);
		let checkNode = new Node;
		if(this.head == null){
			this.head = newNode;
			this.head.left = null;
			this.head.right = null;
		}
		else{
			checkNode = this.head;
			while(checkNode){
				if(data<checkNode.data){
					if(!checkNode.left){
						checkNode.left = newNode;
						break;
					}
					else{
						checkNode = checkNode.left;
					}
				}
				if(data>checkNode.data){
					if(!checkNode.right){
						checkNode.right = newNode;
						break;
					}
					else
						checkNode = checkNode.right;
				}
			}
		}
	}
	Inorder(node){
				if(!node)
					return;
				this.Inorder(node.left);
				console.log(node.data + " ");
				this.Inorder(node.right);
			
		}
	Preorder(node){
		if(!node)
			return;
		console.log(node.data);
		this.Preorder(node.left);
		this.Preorder(node.right);
	}

	Postorder(node){
		if(!node)
			return;
		console.log(node.data);
		this.Postorder(node.left);
		this.Postorder(node.right);
	}
}




let a= new Tree();
a.insert(6);
a.insert(4);
a.insert(2);
a.insert(3);
a.insert(8);
a.Inorder(a.head);

console.log();
a.Postorder(a.head);
console.log();
a.Preorder(a.head);

