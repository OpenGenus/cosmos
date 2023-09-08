
/**
 * Builder Design Pattern
 * 
 * @author Andreas Loizou
 * @version 1.0
 * 
 */

public class BuilderPattern{

public static void main(String[] args){

Sandwitch sandwitch = (new SandwitchBuilder())
                      .addCheese()
                      .addButter()
                      .addLetuce()
                      .build();

}
}
