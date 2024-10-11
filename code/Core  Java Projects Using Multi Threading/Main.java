class Main{
	public static void main(String args[]){
		Company c= new Company();
		Producer p= new Producer(c);
		Consumer cc = new Consumer(c);
		p.start();
		cc.start();
	}
}