package builder;

import org.omg.CORBA.DynAnyPackage.InvalidValue;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.function.Consumer;

public class PersonBuilder {
    private String firstname;
    private String lastname;

    private Date birthdate;
    private Nationality nationality = Nationality.Ro;
    private boolean isProgrammer = false;
    private Integer iq = 100;
    private boolean isPoor = false;
    private boolean isPopular = false;
    private boolean isEmployed = true;

    public PersonBuilder with(Consumer<PersonBuilder> builderFunction) {
        builderFunction.accept(this);
        return this;
    }

    public Person createPerson() {
        return new Person(firstname, lastname, birthdate, nationality, isProgrammer, iq, isPoor,
                isPopular, isEmployed);
    }

    public void setFirstname(String firstname) {
        this.firstname = firstname;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }

    public void setBirthdate(String birthdate) throws InvalidValue, ParseException {
        SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy");
        Date d = sdf.parse("01-01-1950");
        Date date = sdf.parse(birthdate);
        if (date.after(d))
            this.birthdate = date;
        else throw new InvalidValue("You're too old!!");
    }

    public void setNationality(Nationality nationality) {
        this.nationality = nationality;
    }

    public void setProgrammer(boolean isProgrammer) {
        this.isProgrammer = isProgrammer;
    }

    public void setIq(Integer iq) throws InvalidValue {
        if (iq < 30)
            throw new InvalidValue("Don't try anything crazy.");

        this.iq = iq;
    }

    public void setPoor(boolean isPoor) {
        this.isPoor = isPoor;
    }

    public void setPopular(boolean isPopular) {
        this.isPopular = isPopular;
    }

    public void setEmployed(boolean isEmployed) {
        this.isEmployed = isEmployed;
    }


}
