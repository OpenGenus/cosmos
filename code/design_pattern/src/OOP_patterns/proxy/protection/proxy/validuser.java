package protection.proxy;

class ValidUser implements User {
    String username;
    String password;

    ValidUser(String username, String password) {
        this.username = username;
        this.password = password;
    }

    @Override
    public void login() {
        System.out.println(">" + this.username + ": Successfully logged, welcome!");
    }

    @Override
    public void download() {
        System.out.println(">" + this.username + ": Downloading");
    }

    @Override
    public void upload() {
        System.out.println(">" + this.username + ": Uploading");
    }
}
