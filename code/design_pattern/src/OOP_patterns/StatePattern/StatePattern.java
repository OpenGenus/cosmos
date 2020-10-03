package StatePattern;
interface State{
	public void goNext();//go to the next state
}
class StartState implements State{
	public void goNext() {
		System.out.println("Start state");
	}
}
class StopState implements State{
	public void goNext() {
		System.out.println("Stop state");
	}
}
class Context implements State{
	private State currentState;

	public void goNext() {
		currentState.goNext();
	}
	
	public void setState(State state){
		this.currentState = state;
	}
	public State getState(){
		return this.currentState;
	}
}
class StatePattern{
	public static void main(String[] args) {
		Context context = new Context();
		State startState = new StartState();
		State stopState = new StopState();
		context.setState(startState);
		context.goNext();
		context.setState(stopState);
		context.goNext();
	}
}
