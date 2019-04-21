#!/usr/bin/env python3

import collections
import itertools
import pathlib
import argparse


Path = collections.namedtuple("Entry", ("suffix", "group", "name"))
paths = [
    Path(
        suffix=path.suffix.lstrip(".").lower(),
        group=path.parts[-3].replace("-", " ").replace("_", " "),
        name=path.parts[-2].replace("-", " ").replace("_", " "),
    )
    for path in pathlib.Path(__file__).parents[1].glob("code/*/*/*")
    if path.suffix and path.suffix.lower() != ".md"
]
suffixes = {path.suffix for path in paths}
suffixes = sorted(suffixes - {"", "md"})

name_max_len = max(max(len(path.group), len(path.name)) for path in paths)
suffix_max_len = max(len(path.suffix) for path in paths)

totals = collections.defaultdict(int)
group_stats = collections.defaultdict(int)
last_group = None
sort_key = lambda path: (path.group, path.name)  # noqa
paths = sorted(paths, key=sort_key)


def generate_txt():
    global paths, suffixes, name_max_len, suffix_max_len, totals, group_stats, last_group, sort_key

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
        alg_suffixes = {p.suffix for p in g}
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

    def print_group_stats():
        if group_stats:
            print("| |", end="")
            for suffix in suffixes:
                print(
                    " {} |".format(str(group_stats[suffix]).rjust(suffix_max_len)),
                    end="",
                )
            print()
            print()

    for (group, name), g in itertools.groupby(paths, key=sort_key):
        if group != last_group:
            print_group_stats()
            print()
            print("# {}".format(group.upper().ljust(name_max_len)))
            print("| {} | ".format(group.upper().ljust(name_max_len)), end="  ")
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

        print("| {} |".format(name), end="  ")
        alg_suffixes = {p.suffix for p in g}
        for suffix in suffixes:
            if suffix in alg_suffixes:
                totals[suffix] += 1
                group_stats[suffix] += 1
                value = "x"
            else:
                value = "."
            print(" {} | ".format(value), end="  ")
        print()

    print()
    print()
    tot_str = "TOTALS"
    print("| {} |".format(tot_str), end="  ")
    for suffix in suffixes:
        print(" {} |".format(str(totals[suffix]).rjust(suffix_max_len)), end="  ")
    print()
    print("| ", end="")
    print("-" * len(tot_str), end=" | ")
    for suffix in suffixes:
        print("-" * (suffix_max_len + 1), end=" | ")
    print()


def main():
    parser = argparse.ArgumentParser(
        description="Get statstics in txt or markdown. Make sure you are in root of cosmos repo before running"
    )
    parser.add_argument(
        "-f",
        "--format",
        help='Ouput can be "txt" for text file and "md" for markdown or "all" for all formats',
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
