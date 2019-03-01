# Part of Cosmos by OpenGenus Foundation


class Job:
    def __init__(self, name, profit, deadline):
        self.name = name
        self.profit = profit
        self.deadline = deadline


def job_scheduling(jobs):
    jobs = sorted(jobs, key=lambda job: job.profit)
    max_deadline = max([job.deadline for job in jobs])
    scheduling = [jobs.pop()]
    while len(jobs) != 0 and len(scheduling) < max_deadline:
        new_job = jobs.pop()
        if new_job.deadline - len(scheduling) > 0:
            scheduling.append(new_job)
    return scheduling
