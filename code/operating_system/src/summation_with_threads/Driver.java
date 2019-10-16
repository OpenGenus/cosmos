public class Driver
{
	public static void main(String[] args) {
		if(args.length > 0){

				for(int j = 0; j< args.length; j++){
					if(Integer.parseInt(args[j]) > 0){
					Sum sumObj = new Sum();
					int upper = Integer.parseInt(args[j]);

					Runnable runnable = new Summation(upper, sumObj);

					Thread t1 = new Thread(runnable);

					t1.start();

					try{
						t1.join();
					}catch(InterruptedException e){
						throw new IllegalStateException(e);
					}

					System.out.println("The sum of "+upper+" is: "+sumObj.getSum());
				}
			}

		}
	}
}