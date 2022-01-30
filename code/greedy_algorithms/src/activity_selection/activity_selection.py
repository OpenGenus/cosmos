"""
 Part of Cosmos by OpenGenus Foundation

 Activity Selection Problem

"""


class Activity:
    def __init__(self, start, finish):
        self.start = start
        self.finish = finish

    def __lt__(self, other):
        return self.finish < other.finish

    def __repr__(self):
        return "( %s, %s )" % (self.start, self.finish)


def activity_selection(activity_arr):
    selected_activities = []

    if activity_arr:
        activity_arr.sort()
        selected = activity_arr[0]

        selected_activities.append(selected)

        for activity in activity_arr:
            if activity.start >= selected.finish:
                selected = activity
                selected_activities.append(selected)

    return selected_activities


activity_arr = [
    Activity(5, 9),
    Activity(1, 2),
    Activity(3, 4),
    Activity(0, 6),
    Activity(5, 7),
    Activity(8, 9),
]

print(activity_selection(activity_arr))
