# What's the stats script?
The stats script deals with generating a progress list of the cosmos repo, by taking into account all algorithms currently existing in the repo and categorizing them based on the languages used to implement them.

# What's the metadata generator script?
The metadata generator script deals with generating metadata(like location, files in category, last updated etc) for all categories of algorithms currently existing in the repository. The metadata is stored in the metadata directory inside the scripts directory, and it retains the directory hierarchy of the corresponding category as it's in the code directory.

# How to run?
**make sure that you're in the cosmos root directory**

### for generating the stats output in txt file :-
```bash
python3 scripts/stats.py -f txt > ./scripts/STATS.txt
```

### for generating the stats output in md file :-
```bash
python3 scripts/stats.py -f md > ./scripts/STATS.md
```

### for generating the metadata :-
```bash
python3 scripts/metadata-generator.py
```

