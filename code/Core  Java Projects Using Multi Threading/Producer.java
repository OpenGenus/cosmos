public class Producer extends Thread {
	Company c;

	Producer(Company c) {
		this.c = c;
	}

	public void run() {
		int i = 1;
		while (true) {
			try {
				this.c.produceItem(i);
			} catch (Exception e) {
			}
			i++;
			try {
				Thread.sleep(1000);
			} catch (Exception e) {

			}
		}
	}
}