// dynamic programming | boolean parenthesization | Java
// Part of Cosmos by OpenGenus Foundation

/*** Dynamic programming implementation of the boolean
 * parenthesization problem using 'T' and 'F' as characters
 * and '&', '|' and '^' as the operators
 ***/

class boolean_parenthesization{
    public static int boolean_parenthesization_(String symbols, String operators) {
        int noOfSymbols = symbols.length();
        int[][] trueMatrix = new int[noOfSymbols][noOfSymbols], falseMatrix = new int[noOfSymbols][noOfSymbols];

        for (int index=0; index < noOfSymbols; index++) {
            if (symbols.charAt(index) == 'T') {
                trueMatrix[index][index] = 1;
                falseMatrix[index][index] = 0;
            }else {
                trueMatrix[index][index] = 0;
                falseMatrix[index][index] = 1;
            }
        }

        for (int loopVar1=1; loopVar1 < noOfSymbols; loopVar1++) {
            for (int innerLoopVar1=0, innerLoopVar2=loopVar1; innerLoopVar2 < noOfSymbols; innerLoopVar1++, innerLoopVar2++) {
                trueMatrix[innerLoopVar1][innerLoopVar2] = 0;
                falseMatrix[innerLoopVar1][innerLoopVar2] = 0;
                int b, d, e;
                for (int a=0; a < loopVar1; a++){
                    b = innerLoopVar1 + a;
                    d = trueMatrix[innerLoopVar1][b] + falseMatrix[innerLoopVar1][b];
                    e = trueMatrix[b+1][innerLoopVar2] + falseMatrix[b+1][innerLoopVar2];

                    switch (operators.charAt(b)) {
                        case '|':
                            trueMatrix[innerLoopVar1][innerLoopVar2] += d * e - falseMatrix[innerLoopVar1][b] * falseMatrix[b+1][innerLoopVar2];
                            falseMatrix[innerLoopVar1][innerLoopVar2] += falseMatrix[innerLoopVar1][b] * falseMatrix[b+1][innerLoopVar2];
                            break;
                        case '&':
                            trueMatrix[innerLoopVar1][innerLoopVar2] += trueMatrix[innerLoopVar1][b] * trueMatrix[b+1][innerLoopVar2];
                            falseMatrix[innerLoopVar1][innerLoopVar2] += d * e - trueMatrix[innerLoopVar1][b] * trueMatrix[b+1][innerLoopVar2];
                            break;
                        case '^':
                            trueMatrix[innerLoopVar1][innerLoopVar2] += falseMatrix[innerLoopVar1][b] * trueMatrix[b+1][innerLoopVar2] + trueMatrix[innerLoopVar1][b] * falseMatrix[b+1][innerLoopVar2];
                            falseMatrix[innerLoopVar1][innerLoopVar2] += trueMatrix[innerLoopVar1][b] * trueMatrix[b+1][innerLoopVar2] + falseMatrix[innerLoopVar1][b] * falseMatrix[b+1][innerLoopVar2];;
                            break;
                    }
                }
            }
        }
        return trueMatrix[0][noOfSymbols - 1];
    }
    public static void main(String[] args){
        String symbols = "TFTTF";
        String operators = "|&|^";
        System.out.println(boolean_parenthesization_(symbols, operators));
    }
}
