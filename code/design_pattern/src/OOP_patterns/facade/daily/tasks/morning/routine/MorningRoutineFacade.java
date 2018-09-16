package daily.tasks.morning.routine;

public class MorningRoutineFacade {
    public MorningRoutineFacade() {
        System.out.println("\n\n\t\tMorning Routine\n\n");
        new WakeUp();
        new Eat();
        new Dress();
        new Leave();
    }
}
