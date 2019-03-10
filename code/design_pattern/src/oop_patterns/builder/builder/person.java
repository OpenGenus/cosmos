package builder;

import java.util.Date;

public class Person {
    private String firstname;
    private String lastname;

    private Date birthdate;
    private Nationality nationality;
    private boolean isProgrammer;
    private Integer iq;
    private boolean isPoor;
    private boolean isPopular;
    private boolean isEmployed;

    Person(String firstname,
           String lastname,
           Date birthdate,
           Nationality nationality,
           boolean isProgrammer,
           Integer iq,
           boolean isPoor, boolean isPopular, boolean isEmployed) {
        this.firstname = firstname;
        this.lastname = lastname;
        this.birthdate = birthdate;
        this.nationality = nationality;
        this.isProgrammer = isProgrammer;
        this.iq = iq;
        this.isPoor = isPoor;
        this.isPopular = isPopular;
        this.isEmployed = isEmployed;
    }

    @Override
    public String toString() {
        return "Person{" +
                "firstname='" + this.firstname + '\'' +
                ", lastname='" + this.lastname + '\'' +
                ", birthdate=" + this.birthdate +
                ", nationality=" + this.nationality +
                ", isProgrammer=" + this.isProgrammer +
                ", iq=" + this.iq +
                ", isPoor=" + this.isPoor +
                ", isPopular=" + this.isPopular +
                ", isEmployed=" + this.isEmployed +
                '}';
    }
}
