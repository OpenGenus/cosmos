# What's the stats script?
The stats script deals with generating a progress list of the cosmos repo, by taking into account all algorithms currently existing in the repo and categorizing them based on the languages used to implement them.

# How to run?
**make sure that you're in the cosmos root directory**

### for generating the output in txt file :-
```bash
python3 scripts/stats.py -f txt > ./scripts/STATS.txt
```

### for generating the output in md file :-
```bash
python3 scripts/stats.py -f md > ./scripts/STATS.md
```
