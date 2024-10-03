import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class binarytree {
private class node {
	int data;
	node left;
	node right;
	
	public node(int data,node right,node left){
		this.data=data;
		this.left = left;
		this.right = right;	
	}
}
private node root;
private int size;

public binarytree(){
	Scanner scn = new Scanner(System.in);
	this.root = takeinput(scn, null, false);
}
private node takeinput(Scanner scn, node parent,boolean isleft){
	if (parent==null){
		System.out.println("Enter data for root node ");
	}
	else{
		if (isleft){
			System.out.println("Enter data for left child of "+parent.data);
		}
		else{
			System.out.println("Enter data for right child of "+parent.data);
		}
	}
	int childdata = scn.nextInt();
	node child = new node(childdata,null,null);
	this.size++;
	System.out.println("DO U WANT TO ADD LEFT CHILD FOR "+childdata);
	boolean lefchoice= scn.nextBoolean();
	if (lefchoice){
		child.left = this.takeinput(scn, child, true); 
	}
	System.out.println("DO U WANT TO ADD RIGHT CHILD FOR "+childdata);
	boolean richoice= scn.nextBoolean();
	if (richoice){
		child.right = this.takeinput(scn, child, false); 
	}
	return child;
}
public int size(){
	return this.size;
}
public boolean isempty(){
	return this.size()==0;
}
public void display(){
	System.out.println(this);
}
@Override
public String toString(){
	return this.toString(this.root);
}
private String toString(node node){
	if (node == null) {
		return "";
	}

	String retVal = "";

	if (node.left != null) {
		retVal += node.left.data + " => ";
	} else {
		retVal += "END" + " => ";
	}

	retVal += node.data;

	if (node.right != null) {
		retVal += " <= " + node.right.data;
	} else {
		retVal += " <= " + "END";
	}

	retVal += "\n";

	retVal += this.toString(node.left);
	retVal += this.toString(node.right);

	return retVal;

}
	public int height(){
		return this.height(this.root);
	}
	private int height(node node){
		int height=-1;
		int h1=this.height(node.left);
		int h2=this.height(node.right);
		if (h1>h2)
		height = h1;
		else 
		height = h2;
		height = height +1;
		return height;
	}
}
