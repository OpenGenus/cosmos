// Part of Cosmos by OpenGenus Foundation

// Activity selection problem

import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class ActivitySelection {
	static void activitySelection(List<Activity> activities, int n) {
		Collections.sort(activities, new ActivityComparator());
		
		System.out.println("Following activities are selected");
		
		int i= 0, j;
		System.out.println(activities.get(i));
		
		for (j = 1; j < n; j++){
			if (activities.get(j).start >= activities.get(i).finish){
				System.out.println(activities.get(j));
				i = j;
			}
		}
	}
	
	public static void main(String args[]) {
		List<Activity> activities = new ArrayList<Activity>();
		activities.add(new Activity(5, 9));
		activities.add(new Activity(1, 2));
		activities.add(new Activity(3, 4));
		activities.add(new Activity(0, 6));
		activities.add(new Activity(5, 7));
		activities.add(new Activity(8, 9));
		
		activitySelection(activities, 6);
	}
}

class Activity {
	int start;
	int finish;
	
	Activity(int start, int finish) {
		this.start = start;
		this.finish = finish;
	}
	
	@Override
    public String toString() {
        return String.format("{start=%d, finish=%d}", start, finish);
    }
}

class ActivityComparator implements Comparator<Activity> {
    @Override
    public int compare(Activity a, Activity b) {
        return a.finish < b.finish ? -1 : a.finish == b.finish ? 0 : 1;
    }
}