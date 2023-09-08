import java.applet.Applet;
import java.awt.Color;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;

public class GameOfLife extends Applet implements Runnable, GameOfLifeControlsListener {
  protected CellGridCanvas gameOfLifeCanvas;
  protected GameOfLifeGrid gameOfLifeGrid;
  protected int cellSize;
  protected int cellCols;
  protected int cellRows;
  protected int genTime;
  protected GameOfLifeControls controls;
  protected static Thread gameThread = null;

  public void init() {
    getParams();

   
    setBackground(new Color(0x999999));

   
    gameOfLifeGrid = new GameOfLifeGrid(cellCols, cellRows);
    gameOfLifeGrid.clear();
    
    gameOfLifeCanvas = new CellGridCanvas(gameOfLifeGrid, cellSize);

    controls = new GameOfLifeControls();
    controls.addGameOfLifeControlsListener( this );

        GridBagLayout gridbag = new GridBagLayout();
        setLayout(gridbag);
        GridBagConstraints canvasContraints = new GridBagConstraints();

        canvasContraints.fill = GridBagConstraints.BOTH;
        canvasContraints.gridx = GridBagConstraints.REMAINDER;
        canvasContraints.gridy = 0;
        canvasContraints.weightx = 1;
        canvasContraints.weighty = 1;
        canvasContraints.anchor = GridBagConstraints.CENTER;
        gridbag.setConstraints(gameOfLifeCanvas, canvasContraints);
        add(gameOfLifeCanvas);

        GridBagConstraints controlsContraints = new GridBagConstraints();
        canvasContraints.gridy = 1;
        canvasContraints.gridx = 0;
        controlsContraints.gridx = GridBagConstraints.REMAINDER;
        gridbag.setConstraints(controls, controlsContraints);
        add(controls);
    
        try {
      // Start with a shape (My girlfriend clicked "Start" on a blank screen and wondered why nothing happened).
      setShape( ShapeCollection.getShapeByName( "Glider" ) );
    } catch (ShapeException e) {
      // Ignore. Not going to happen.
    }
    setVisible(true);
    validate();
  }
 
  protected void getParams() {
    cellSize = getParamInteger( "cellsize", 11 );
    cellCols = getParamInteger( "cellcols", 50 );
    cellRows = getParamInteger( "cellrows", 30 );
    genTime  = getParamInteger( "gentime", 1000 );
  }

  protected int getParamInteger( String name, int defaultParam ) {
    String param;
    int paramInt;

    param = getParameter( name );
    if ( param == null )
      paramInt = defaultParam;
    else
      paramInt = Integer.valueOf(param).intValue();
    return paramInt;
  }

  public synchronized void start2() {
    controls.start();
    if (gameThread == null) {
      gameThread = new Thread(this);
      gameThread.start();
    }
  }

  public void stop() {
    controls.stop();
    gameThread = null;
  }

  public synchronized void run() {
    while (gameThread != null) {
      nextGeneration();
      try {
        Thread.sleep(genTime);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }

  public boolean isRunning() {
    return gameThread != null;
  }

  public void nextGeneration() {
    gameOfLifeGrid.next();
    gameOfLifeCanvas.repaint();
    showGenerations();
  }

  public void setShape( Shape shape ) {
    if ( shape == null )
      return;

    try {
      gameOfLifeCanvas.setShape( shape );
      reset();
    } catch (ShapeException e) {
      alert( e.getMessage() );
    }
  }
 
  public void reset() {
    stop(); // might otherwise confuse user
    gameOfLifeCanvas.repaint();
    showGenerations();
    showStatus( "" );
  }

  public String getAppletInfo() {
    return "Game Of Life v. 1.5\nCopyright 1996-2004 Edwin Martin";
  }

  private void showGenerations() {
    controls.setGeneration( gameOfLifeGrid.getGenerations() );
  }

  public void setSpeed( int fps ) {
    genTime = fps;
  }

  public void setCellSize( int p ) {
    cellSize = p;
    gameOfLifeCanvas.setCellSize( cellSize );
  }

  public int getCellSize() {
    return cellSize;
  }

  public void alert( String s ) {
    showStatus( s );
  }

  public void startStopButtonClicked( GameOfLifeControlsEvent e ) {
    if ( isRunning() ) {
      stop();
    } else {
      start2();
    }
  }

  public void nextButtonClicked(GameOfLifeControlsEvent e) {
    nextGeneration();
  }
  
  public void speedChanged(GameOfLifeControlsEvent e) {
    setSpeed( e.getSpeed() );
  }

  public void zoomChanged(GameOfLifeControlsEvent e) {
    setCellSize( e.getZoom() );
  }
  
  public void shapeSelected(GameOfLifeControlsEvent e) {
    String shapeName = (String) e.getShapeName();
    Shape shape;
    try {
      shape = ShapeCollection.getShapeByName( shapeName );
      setShape( shape );
    } catch (ShapeException e1) {
      // Ignore. Not going to happen.
    }
  }
}
