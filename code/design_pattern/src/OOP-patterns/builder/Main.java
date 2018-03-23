import builder.Nationality;
import builder.Person;
import builder.PersonBuilder;
import org.omg.CORBA.DynAnyPackage.InvalidValue;

import java.text.ParseException;

public class Main {

    public static void main(String[] args) {
        Person person = new PersonBuilder()
                .with(personBuilder -> {
                    personBuilder.setFirstname("Mr.");
                    personBuilder.setLastname("John");
                    personBuilder.setNationality(Nationality.En);
                    personBuilder.setProgrammer(true);
                    try {
                        personBuilder.setBirthdate("01-01-1900");
                    } catch (InvalidValue | ParseException invalidValue) {
                        invalidValue.printStackTrace();
                    }
                })
                .createPerson();

        System.out.println(person);
    }
}
