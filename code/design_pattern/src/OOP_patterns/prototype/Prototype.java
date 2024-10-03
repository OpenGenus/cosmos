package design_pattern.src.OOP_patterns.prototype;

import java.util.ArrayList;
import java.util.List;

/**
 * Prototype pattern is used
 *      when the types of object to create is determined by a prototypical instance,
 *      which is cloned to produce a new instance
 *      Oftentimes, it is used to get a unique instance of the same object.
 *
 */
public class Prototype {

    public static void main(String[] args) {
        protoTypeExample();
    }

    private static void protoTypeExample() {
        String sql = "select * from movies where title = ?";
        List<String> parameters = new ArrayList<>();

        parameters.add("Star wars");

        Record record = new Record();

        StatementPrototype firstStatement = new StatementPrototype(
                sql, parameters, record
        );

        System.out.println(firstStatement.getSql());
        System.out.println(firstStatement.getParameters());
        System.out.println(firstStatement.getRecord());

        StatementPrototype secondStatement = firstStatement.clone();

        System.out.println(secondStatement.getSql());
        System.out.println(secondStatement.getParameters());
        // also return the same record object
        System.out.println(secondStatement.getRecord());
    }
}
