package iterator;

public class ClassIterator implements Iterator<Student> {
	
	private Student[] student;
	private int i = 0;
	
	public ClassIterator(Student[] s){
		this.student = s;
	}
	
	@Override
	public boolean hasNext() {
		if( i < student.length && student[i] != null) 
			return true;
		else 
			return false;
	}

	@Override
	public Student next() {
		if(this.hasNext()){
			Student s = student[i];
			i++;
			return s;
		}else return null;		
	}

	
}
