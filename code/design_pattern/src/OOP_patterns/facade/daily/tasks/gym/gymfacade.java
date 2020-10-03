package daily.tasks.gym;

public class GymFacade {
    public GymFacade() {
        System.out.println("\n\n\t\tGym Routine\n\n");
        new Deadlift();
        new BenchPress();
        new Squat();
    }
}
