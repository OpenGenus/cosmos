/**
 * Simple Factory Design Pattern
 * 
 * @author Andreas Loizou
 * @date 29 October 2017
 * @version 1.0
 * 
 */

interface Window
{
    public float getWidth();
    public float getHeight();
}

class GlassWindow implements Window{
    private float width;
    private float height;

    public GlassWindow(float width, float height){
        this.width = width;
        this.height = height;
    }

    public float getWidth(){
        return width;
    }

    public float getHeight(){
        return height;
    }
}
