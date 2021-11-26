/*

// design pattern | OOP patterns | proxy | virtual | proxy | videoproxy | JAVA
// Part of Cosmos by OpenGenus Foundation

*/


package virtual.proxy;

public class VideoProxy implements Video {

    public String name;
    public Video realVideo;

    public VideoProxy(String name) {
        this.name = name;
    }

    @Override
    public void play() {
        try {
            this.realVideo = new UltraHDVideo(name);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        realVideo.play();
    }
}
