/*

// design pattern | OOP patterns | facade | daily | tasks | morning | routine | morningroutinefacade | JAVA
// Part of Cosmos by OpenGenus Foundation

*/


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
