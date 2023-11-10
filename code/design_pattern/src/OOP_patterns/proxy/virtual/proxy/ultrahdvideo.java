package virtual.proxy;

public class UltraHDVideo implements Video {
    public String name;

    public UltraHDVideo(String path) throws InterruptedException {
        this.name = path;
        loadVideo();
    }

    @Override
    public void play() {
        System.out.println("4k video is being played - " + name);
    }

    private void loadVideo() throws InterruptedException {
        Thread.sleep(5000);
        System.out.println("Video has been loaded - " + name);
    }
}
