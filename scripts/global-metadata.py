import json
import pathlib
import collections

avoid_extensions = [
    "",
    # ".md",
    # ".png",
    # ".csv",
    # ".class",
    # ".data",
    # ".in",
    # ".jpeg",
    # ".jpg",
    # ".out",
    # ".textclipping",
    # ".properties",
    # ".txt",
    # ".sbt",
]
avoid_dirs = ["project", "test", "img", "image", "images"]

global_metadata = collections.defaultdict(dict)
original_paths = collections.defaultdict(str)
for path in pathlib.Path(__file__).parents[1].glob(
        "scripts/metadata/code/**/**/*"):
    if (path.suffix
            and not any(elem in list(path.parts) for elem in avoid_dirs)
            and path.suffix.lower() not in avoid_extensions):
        original_paths[path.parts[-2]] = "/".join(path.parts[:-2])

for algo in original_paths:
    filename = pathlib.Path("{}/{}/data.json".format(original_paths[algo],
                                                     algo))
    with open(filename) as fh:
        existing_data = json.load(fh)
    global_metadata[original_paths[algo].split('/')[-2]][algo] = existing_data

filename = pathlib.Path("scripts/global_metadata.json")
json_dump = json.dumps(global_metadata, indent=2)
filename.write_text(json_dump)
