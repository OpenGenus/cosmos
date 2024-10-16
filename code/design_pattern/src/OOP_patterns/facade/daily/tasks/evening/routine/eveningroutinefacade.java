package daily.tasks.evening.routine;

public class EveningRoutineFacade {
    public EveningRoutineFacade() {
        System.out.println("\n\n\t\tEvening Routine\n\n");
        new Eat();
        new TakeAShower();
        new WriteCode();
        new WatchYoutubeVideos();
    }
}
