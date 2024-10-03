public class Consumer extends Thread {
	Company c;

	Consumer(Company c) {
		this.c = c;
	}

	public void run() {
		while (true) {

			try {
				this.c.consumeItem();
				Thread.sleep(3000);
			} catch (Exception e) {
			}
		}
	}
}