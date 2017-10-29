
/**
 * Builder Design Pattern
 * 
 * @author Andreas Loizou
 * @version 1.0
 * 
 */

class Sandwitch   {

  private cheese= false;
  private pepperoni = false;
  private butter = false;
  private lettuce = false;
  private tomato = false;

  public Sandwitch (SandwitchBuilder builder){
    this.cheese = builder.cheese;
    this.pepperoni = builder.pepperoni;
    this.butter = builder.butter;
    this.lettuce = builder. lettuce;
    this.tomato = bulder.tomato;
  }
}
