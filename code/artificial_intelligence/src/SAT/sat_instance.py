from __future__ import division
from __future__ import print_function

class SATInstance(object):
    def parse_and_add_clause(self, line):
        clause = []
        for literal in line.split():
            negated = 1 if literal.startswith('~') else 0
            variable = literal[negated:]
            if variable not in self.variable_table:
                self.variable_table[variable] = len(self.variables)
                self.variables.append(variable)
            encoded_literal = self.variable_table[variable] << 1 | negated
            clause.append(encoded_literal)
        self.clauses.append(tuple(set(clause)))

    def __init__(self):
        self.variables = []
        self.variable_table = dict()
        self.clauses = []

    @classmethod
    def from_file(cls, file):
        instance = cls()
        for line in file:
            line = line.strip()
            if len(line) > 0 and not line.startswith('#'):
                instance.parse_and_add_clause(line)
        return instance

    def literal_to_string(self, literal):
        s = '~' if literal & 1 else ''
        return s + self.variables[literal >> 1]

    def clause_to_string(self, clause):
        return ' '.join(self.literal_to_string(l) for l in clause)

    def assignment_to_string(self, assignment, brief=False, starting_with=''):
        literals = []
        for a, v in ((a, v) for a, v in zip(assignment, self.variables)
                     if v.startswith(starting_with)):
            if a == 0 and not brief:
                literals.append('~' + v)
            elif a:
                literals.append(v)
return ' '.join(literals) 
