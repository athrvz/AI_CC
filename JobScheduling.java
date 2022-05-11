import java.util.*;

class Job {
	char id;
	int profit, deadline;

	Job(char id, int profit, int deadline) {
		this.id = id;
		this.profit = profit;
		this.deadline = deadline;
	}
}

class Scheduling {
	public void schedule(ArrayList <Job> arr, int t) {
		int n = arr.size();
		boolean slots[] = new boolean[t];
		char jobs[] = new char[t];
		Collections.sort(arr, (a, b) -> b.profit - a.profit);
		
		for(int i = 0; i < n; i++) {
			for(int j = Math.min(t - 1, arr.get(i).profit); j >= 0; j--) {
				if(slots[j] == false) {
					slots[j] = true;
					jobs[j] = arr.get(i).id;
					break;
				}
			}	
		}

		for(char c : jobs) {
			System.out.print(c + " ");
		}
	}
}

public class JobScheduling {

public static void main(String args[]) {
	ArrayList <Job> arr = new ArrayList <Job> ();
	arr.add(new Job('a', 10, 3));
	arr.add(new Job('b', 1, 1));
	arr.add(new Job('c', 5, 4));
	
	Scheduling sch = new Scheduling();
	sch.schedule(arr, 5);
}

}