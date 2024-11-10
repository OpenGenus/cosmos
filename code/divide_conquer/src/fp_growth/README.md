# FP-Growth

## Description
The FP-Growth is an efficient algorithm for frequent pattern mining. It uses a compact data structure named frequent-pattern tree(FP-Tree) to find frequent itemsets in a transaction database.

## Usage

### Python version

```
python fp_growth.py --input ./data/sample.txt --output output.csv --minsup 0.3
```
Arguments
- input: input data file name
- output: output data file name
- minsup: minimum support

## Example

#### Input Data
```
Milk,Bread,Beer,
Bread,Coffee,
Bread,Egg,
Milk,Bread,Coffee,
Milk,Egg,
Bread,Egg,
Milk,Egg,
Milk,Bread,Egg,Beer,
Milk,Bread,Egg,
```

#### Output Data
```
pattern,counts
Bread-Beer,2
Milk-Beer,2
Bread-Milk-Beer,2
Bread-Coffee,2
Bread-Milk,4
Bread-Egg,4
Milk-Egg,4
Bread-Milk-Egg,2
Milk,6
Bread,7
Beer,2
Coffee,2
Egg,6
```


---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a>
</p>

---