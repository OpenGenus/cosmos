package design_pattern.src.OOP_patterns.prototype;

import java.util.List;

public class StatementPrototype implements Cloneable {

    private String sql;
    private List<String> parameters;
    Record record;

    public StatementPrototype(String sql, List<String> parameters, Record record) {
        this.sql = sql;
        this.parameters = parameters;
        this.record = record;
    }

    // Cloneable forced us to implement the clone() method
    public StatementPrototype clone() {
        try {
            return (StatementPrototype) super.clone();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return null;
    }

    public String getSql() {
        return sql;
    }

    public List<String> getParameters() {
        return parameters;
    }

    public Record getRecord() {
        return record;
    }
}

class Record {

}
