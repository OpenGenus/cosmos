// Part of Cosmos by OpenGenus Foundation
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class MinimumCoins {
    private static List<Integer> minimumCoins(Integer value, List<Integer> denominations) {
        List<Integer> result = new ArrayList<>();

        // Assuming list of denominations is sorted in descending order
        for(Integer curDenom : denominations) {
            while (curDenom <= value){
                result.add(curDenom);
                value -= curDenom;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        List<TestScenario> scenarios = Arrays.asList(
            new TestScenario(100, Arrays.asList(50, 25, 10, 5, 1),      Arrays.asList(50, 50)),
            new TestScenario(101, Arrays.asList(50, 25, 10, 5, 1),      Arrays.asList(50, 50, 1)),
            new TestScenario(77,  Arrays.asList(50, 25, 10, 5, 1),      Arrays.asList(50, 25, 1, 1)),
            new TestScenario(38,  Arrays.asList(50, 25, 10, 5, 1),      Arrays.asList(25, 10, 1, 1, 1)),
            new TestScenario(17,  Arrays.asList(50, 25, 10, 5, 1),      Arrays.asList(10, 5, 1, 1)),
            new TestScenario(3,   Arrays.asList(50, 25, 10, 5, 1),      Arrays.asList(1, 1, 1)),
            new TestScenario(191, Arrays.asList(100, 50, 25, 10, 5, 1), Arrays.asList(100, 50, 25, 10, 5, 1))
        );

        for (TestScenario scenario : scenarios) {
            List<Integer> actual = minimumCoins(scenario.value, scenario.denoms);
            if (!actual.equals(scenario.result)) {
                System.out.println("Test Failed: Value: " + scenario.value
                                 + ", Denominations: " + scenario.denoms
                                 + ", Expected Result: " + scenario.result
                                 + ", Actual Result: " + actual);
            }
        }
    }

    private static class TestScenario {
        public int value;
        public List<Integer> denoms;
        public List<Integer> result;

        public TestScenario(int value, List<Integer> denoms, List<Integer> result) {
            this.value = value;
            this.denoms = denoms;
            this.result = result;
        }
    }
}