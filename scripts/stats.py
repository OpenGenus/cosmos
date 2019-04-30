#!/usr/bin/env python3

import collections
import itertools
import pathlib
import argparse
from datetime import datetime

Path = collections.namedtuple("Entry", ("suffix", "group", "name"))
avoid_extensions = [
    "",
    ".md",
    ".png",
    ".csv",
    ".class",
    ".data",
    ".in",
    ".jpeg",
    ".jpg",
    ".out",
    ".textclipping",
    ".properties",
    ".txt",
    ".sbt",
]
avoid_dirs = ["project", "test", "img", "image", "images"]
paths = []
original_paths = []
for path in pathlib.Path(__file__).parents[1].glob("code/**/**/*"):
    if (path.suffix
            and not any(elem in list(path.parts) for elem in avoid_dirs)
            and path.suffix.lower() not in avoid_extensions):
        original_paths.append(path.parts)
        paths.append(
            Path(
                suffix=path.suffix.lstrip(".").lower(),
                group=path.parts[1].replace("-", " ").replace("_", " "),
                name=path.parts[-2].replace("-", " ").replace("_", " "),
            ))

suffixes = {path.suffix for path in paths}
suffixes = sorted(suffixes - set(avoid_extensions))
extension_map = {
    "adb": "Ada",
    "bf": "BrainFuck",
    "c": "C",
    "clj": "Clojure",
    "cpp": "C++",
    "cr": "Crisp",
    "cs": "Visual C#",
    "elm": "Elm",
    "erl": "Erlang",
    "ex": "Elixir",
    "exs": "Elixir",
    "f": "Fortran",
    "fs": "Visual F#",
    "go": "Golang",
    "h": "C",
    "hpp": "C++",
    "hs": "Haskell",
    "htm": "HTML",
    "html": "HTML",
    "ipynb": "Jupyter Notebook",
    "java": "Java",
    "jl": "Julia",
    "js": "JavaScript",
    "kt": "Kotlin",
    "lua": "Lua",
    "m": "Objective-C",
    "ml": "ML",
    "nim": "Nim",
    "pde": "Processing Development Environment",
    "php": "PHP",
    "pl": "Perl",
    "purs": "PureScript",
    "py": "Python",
    "rb": "Ruby",
    "re": "Reason",
    "rkt": "Racket",
    "rs": "Rust",
    "ruby": "Ruby",
    "sc": "Scala",
    "scala": "Scala",
    "sh": "Shell Script",
    "sml": "Standard ML",
    "swift": "Swift",
    "ts": "TypeScript",
    "vb": "Visual Basic",
}
suffix_with_lang_name = set()
for ext in suffixes:
    lang = extension_map.get(ext, ext.upper())
    suffix_with_lang_name.add(lang)
suffixes = list(sorted(suffix_with_lang_name))

name_max_len = max(max(len(path.group), len(path.name)) for path in paths)
suffix_max_len = max(len(suffix) for suffix in suffixes)

totals = collections.defaultdict(int)
group_stats = collections.defaultdict(int)
last_group = None
sort_key = lambda path: (path.group, path.name)  # noqa
paths = sorted(paths, key=sort_key)


def generate_txt():
    global paths, suffixes, name_max_len, suffix_max_len, totals, group_stats, last_group, sort_key

    print("This is the progress list of Cosmos | Updated on: {}".format(
        datetime.today().strftime("%Y-%m-%d")))
    print()

    def print_group_stats():
        if group_stats:
            print(" " * name_max_len, end="  ")
            for suffix in suffixes:
                print("-" * (suffix_max_len + 1), end=" ")
            print()
            print(" " * name_max_len, end="  ")
            for suffix in suffixes:
                print(str(group_stats[suffix]).rjust(suffix_max_len), end="  ")
            print()
            print()

    for (group, name), g in itertools.groupby(paths, key=sort_key):
        if group != last_group:
            print_group_stats()
            print()
            print(group.upper().ljust(name_max_len), end="  ")
            for suffix in suffixes:
                print(suffix.rjust(suffix_max_len), end="  ")
            print()
            print("-" * name_max_len, end="- ")
            for suffix in suffixes:
                print("-" * (suffix_max_len + 1), end=" ")
            print()
            last_group = group
            group_stats = collections.defaultdict(int)

        print(name.ljust(name_max_len), end="  ")
        alg_suffixes = {extension_map[p.suffix] for p in g}
        for suffix in suffixes:
            if suffix in alg_suffixes:
                totals[suffix] += 1
                group_stats[suffix] += 1
                value = "x"
            else:
                value = "."
            print(value.rjust(suffix_max_len), end="  ")
        print()

    print_group_stats()

    print()
    print("=" * name_max_len, end="= ")
    for suffix in suffixes:
        print("=" * (suffix_max_len + 1), end=" ")
    print()
    print("TOTALS:".rjust(name_max_len), end="  ")
    for suffix in suffixes:
        print(str(totals[suffix]).rjust(suffix_max_len), end="  ")
    print()


def generate_markdown():
    global paths, suffixes, name_max_len, suffix_max_len, totals, group_stats, last_group, sort_key

    print(
        "This is the progress list of [Cosmos](https://github.com/OpenGenus/cosmos/) | Updated on: {}"
        .format(datetime.today().strftime("%Y-%m-%d")))
    print()

    def print_group_stats():
        if group_stats:
            print("| |", end="")
            for suffix in suffixes:
                print(
                    " {} |".format(
                        str(group_stats[suffix]).rjust(suffix_max_len)),
                    end="",
                )
            print()
            print()

    for (group, name), g in itertools.groupby(paths, key=sort_key):
        if group != last_group:
            print_group_stats()
            print()
            category_dir = group.replace(" ", "_")
            print(
                "# [{}](https://github.com/OpenGenus/cosmos/tree/master/code/{})"
                .format(group.upper(), category_dir))
            print(
                "| {} | ".format(group.upper().ljust(name_max_len)), end="  ")
            for suffix in suffixes:
                print("{} | ".format(suffix.rjust(suffix_max_len)), end="  ")
            print()
            print("| ", end="")
            print("-" * name_max_len, end="- | ")
            for suffix in suffixes:
                print("-" * (suffix_max_len + 1), end=" | ")
            print()
            last_group = group
            group_stats = collections.defaultdict(int)

        original_name = name.replace(" ", "_")
        name_path = ""
        for x in original_paths:
            if x[-2] == original_name:
                name_path = "https://github.com/OpenGenus/cosmos/tree/master/{}".format(
                    "".join([
                        y + "/" for pos, y in enumerate(x) if pos != len(x) - 1
                    ]))
                break

        print("| [{}]({}) |".format(name, name_path), end="  ")
        alg_suffixes = {extension_map[p.suffix] for p in g}
        for suffix in suffixes:
            if suffix in alg_suffixes:
                totals[suffix] += 1
                group_stats[suffix] += 1
                value = "✔️"
            else:
                value = "."
            print(" {} | ".format(value), end="  ")
        print()

    print()
    print()
    tot_str = "TOTALS"
    print("| {} |".format(tot_str), end="  ")
    for suffix in suffixes:
        print(
            " {} |".format(str(totals[suffix]).rjust(suffix_max_len)),
            end="  ")
    print()
    print("| ", end="")
    print("-" * len(tot_str), end=" | ")
    for suffix in suffixes:
        print("-" * (suffix_max_len + 1), end=" | ")
    print()


def main():
    parser = argparse.ArgumentParser(
        description=
        "Get statstics in txt or markdown. Make sure you are in root of cosmos repo before running"
    )
    parser.add_argument(
        "-f",
        "--format",
        help=
        'Ouput can be "txt" for text file and "md" for markdown or "all" for all formats',
        default="all",
    )
    results = parser.parse_args()
    choice = results.format
    if choice == "txt":
        generate_txt()
    elif choice == "md":
        generate_markdown()
    else:
        generate_txt()
        generate_markdown()


if __name__ == "__main__":
    main()
