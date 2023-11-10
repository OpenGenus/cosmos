import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Hillclimber {

    private double[][] distances;
    private int[] shortestRoute;
    private static final int NUMBER_OF_CITIES = 100;


    public Hillclimber() {
        distances = new double[NUMBER_OF_CITIES][NUMBER_OF_CITIES];
    }

    public static void main(String[] args) {
        Hillclimber hillclimber = new Hillclimber();
        hillclimber.fillList();



        hillclimber.shortestRoute = hillclimber.getShortestRouteStart();

        hillclimber.calculateShortestDistance();


    }

    /**
     * calculate the current fitness when getting the route as an array of integers, which city to visit first
     *
     * @param route array of integers, current route
     * @return distance of the route, lower is better
     */
    private float fitness(int[] route) {
        float currentFitness = 0;
        for (int i = 0; i < route.length - 1; i++) {
            currentFitness += distanceFromAtoB(route[i],route[i+1]);
        }
        return currentFitness;
    }

    /**
     * returns a random route that passes every city
     * @return
     */
    private int[] getShortestRouteStart(){
        List<Integer> numbers = new ArrayList<>();
        for(int i = 0;i<100; i++){
            numbers.add(i);
        }
        Collections.shuffle(numbers);
        int[] shortestRoute = numbers.stream().mapToInt(i->i).toArray();

        return shortestRoute;

    }

    public double distanceFromAtoB(int positionA, int positionB){
        return distances[positionA][positionB];
    }


    @Override
    public String toString() {
        String order = "";
        double distance = 0;
        for(int i =0;i<shortestRoute.length-1;i++){
            order += shortestRoute[i] + ", ";
            distance += distanceFromAtoB(shortestRoute[i],shortestRoute[i+1]);
        }
        return order + "\n total distance = "+ distance;
    }

    /**
     * swap the position of 2 cities on the route
     *
     * @param currentRoute
     * @return
     */
    private int[] moveOneStepAtRandom(int[] currentRoute) {
        int[] currentRouteCopy = Arrays.copyOf(currentRoute, currentRoute.length);

        int position1 = (int) (Math.random()*100);
        int position2 = (int) (Math.random()*100);
        currentRouteCopy[position1] = currentRoute[position2];
        currentRouteCopy[position2] = currentRoute[position1];
        return currentRouteCopy;
    }

    /**
     * find the shortest distance
     */
    private void calculateShortestDistance() {
        float lastFitness = fitness(shortestRoute);
        double threshold = lastFitness/9;
        int i = 0;
        do {
            i++;

            int[] lastRoute= Arrays.copyOf(shortestRoute, shortestRoute.length);

            shortestRoute = moveOneStepAtRandom(shortestRoute);
            if (fitness(shortestRoute) < lastFitness) {
                lastFitness = fitness(shortestRoute);
            } else {
                shortestRoute = lastRoute;

            }
        }
        while (lastFitness > threshold && i<50000); //TODO: find the Threshold
    }



    /** Initializes the list with random distances between each of the cities
     *
     */
    private void fillList() {
        for (int i = 0; i < NUMBER_OF_CITIES; i++) {

            for (int j = i; j < NUMBER_OF_CITIES; j++) {
                if (i == j) {
                    distances[i][j] = 0;
                } else {
                    distances[i][j] = Math.random()*100;
                    distances[j][i] = distances[i][j];
                }
            }
        }


    }


}
