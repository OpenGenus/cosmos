package iterator;



public class Main {

	public static void main(String[] args) {
		Class class1 = new Class("class1");
		class1.add("student1",12);
		class1.add("student2",15);
		class1.add("student3",16);
			
		ClassIterator it = class1.iterator();
		
		while (it.hasNext()) {
			Student student = it.next();
			student.print();
		}
	}

}
