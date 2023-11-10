public class Company {
	int n = 0;
	boolean flag = true;

	synchronized public void produceItem(int n) throws Exception {
		if (!flag) {
			wait();
		}
		this.n = n;
		System.out.println("Item : " + n + " Produced");
		flag = false;
		notify();
	}

	synchronized public int consumeItem() throws Exception {
		if (flag) {
			wait();
		}
		System.out.println("Item : " + n + " Consumed");
		notify();
		flag = true;
		return this.n;
	}
}