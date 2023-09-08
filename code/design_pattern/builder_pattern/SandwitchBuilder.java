
/**
 * Builder Design Pattern
 * 
 * @author Andreas Loizou
 * @version 1.0
 * 
 */

Class SandwitchBuilder{
  private cheese= false;
  private pepperoni = false;
  private butter = false;
  private lettuce = false;
  private tomato = false;

  public void SandwitchBuilder(){

  }

  public SandwitchBuilder addCheese(){
    this.cheese = true;
    return this;
  }

  public SandwitchBuilder addPapperoni(){
    this.pepperoni = true;
    return this;
  }

  public SandwitchBuilder addButter(){
    this.butter = true;
    return this;
  }

  public SandwitchBuilder addLettuce(){
    this.lettuce = true;
    return this;
  }

  public SandwitchBuilder addTomato(){
    this.tomato = true;
    return this;
  }

  public Sandwitch build(){
    return new Sandwitch(this);
  }
}
