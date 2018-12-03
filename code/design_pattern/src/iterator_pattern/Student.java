package iterator;

public class Student {
	
	private String name;
	private int age;
	
	public Student(String n, int a) {
		this.name = n;
		this.age = a;
	}
	
	public String getName() {
		
		return this.name;
		
	}
	
	public void print() {
		System.out.println("Student: " + this.name + " Age: " + this.age);
	}
}
