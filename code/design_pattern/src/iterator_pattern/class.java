package iterator;



public class Class {

	private Student[] students = new Student[100];
	private int i = 0;
	private String class_name;
	
	public Class(String n) {
		this.class_name = n;
	}
	
	public String getName() {
		return this.class_name;
	}
	
	public void add(String name,int age) {
		Student s = new Student(name, age);
		students[i] = s;
		i++;
	}
	
	public ClassIterator iterator() {
		ClassIterator iterator = new ClassIterator(students);
		return iterator;
	}
	
}
