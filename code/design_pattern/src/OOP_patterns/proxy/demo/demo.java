package demo;

import protection.proxy.User;
import protection.proxy.UserProxy;
import virtual.proxy.UltraHDVideo;
import virtual.proxy.Video;
import virtual.proxy.VideoProxy;

public class Demo {
    public void protectionProxyRun() {
        User rob = new UserProxy("Robert", "123");
        User david = new UserProxy("David", "pass");
        User gangplank = new UserProxy("Gangplank", "12312312");

        rob.login();
        david.login();
        gangplank.login();

        rob.download();
        david.download();
        gangplank.login();

        rob.upload();
        david.upload();
        gangplank.upload();
    }

    public void virtualProxyRun() throws InterruptedException {
        System.out.println("Trying the proxy version first - 3 videos and playing just 1");
        long startTime = System.currentTimeMillis();

        Video v1 = new VideoProxy("Erik Mongrain - Alone in the mist");
        Video v2 = new VideoProxy("Antoine Dufour - Drowning");
        Video v3 = new VideoProxy("Jake McGuire - For Scale The Summit");

        v3.play();
        long endTime = System.currentTimeMillis();

        long duration = (endTime - startTime);

        System.out.println("It took " + (duration / 1000) + " seconds to run");
        System.out.println("Now for the not-proxy version");
        startTime = System.currentTimeMillis();

        Video v4 = new UltraHDVideo("Erik Mongrain - Alone in the mist");
        Video v5 = new UltraHDVideo("Antoine Dufour - Drowning");
        Video v6 = new UltraHDVideo("Jake McGuire - For Scale The Summit");

        v6.play();

        endTime = System.currentTimeMillis();

        duration = endTime - startTime;

        System.out.println("It took " + (duration / 1000.0) + " seconds to run");
    }
}
