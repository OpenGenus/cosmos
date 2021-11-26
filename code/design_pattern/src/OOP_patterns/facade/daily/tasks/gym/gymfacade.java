/*

// design pattern | OOP patterns | facade | daily | tasks | gym | gymfacade | JAVA
// Part of Cosmos by OpenGenus Foundation

*/


package daily.tasks.gym;

public class GymFacade {
    public GymFacade() {
        System.out.println("\n\n\t\tGym Routine\n\n");
        new Deadlift();
        new BenchPress();
        new Squat();
    }
}
