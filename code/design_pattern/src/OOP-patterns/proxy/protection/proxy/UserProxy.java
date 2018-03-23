package protection.proxy;

import java.util.Objects;

public class UserProxy implements User {
    private String username;
    private String password;
    Boolean isLogged;
    private User user;

    public UserProxy(String username, String password) {
        this.username = username;
        this.password = password;
    }


    @Override
    public void login() {
        if (Objects.equals(RegisteredUsers.registered.get(username), password)){
            this.user = new ValidUser(username, password);
            System.out.println("Login successful - welcome back, " + this.username + " !");
        }
        else
            System.out.println("Invalid credentials for " + this.username + " !");

    }

    @Override
    public void download() {
        if (this.user == null)
            System.out.println("User credentials invalid " + this.username + "!");
        else
            user.download();
    }

    @Override
    public void upload() {
        if (this.user == null)
            System.out.println("User credentials invalid " + this.username + " !");
        else
            user.upload();
    }
}
