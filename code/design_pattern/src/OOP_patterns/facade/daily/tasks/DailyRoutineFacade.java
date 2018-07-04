package daily.tasks;

import daily.tasks.evening.routine.EveningRoutineFacade;
import daily.tasks.gym.GymFacade;
import daily.tasks.job.JobFacade;
import daily.tasks.morning.routine.MorningRoutineFacade;

public class DailyRoutineFacade {
    public DailyRoutineFacade() {
        new MorningRoutineFacade();
        new JobFacade();
        new GymFacade();
        new EveningRoutineFacade();
    }
}
