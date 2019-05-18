import json
import pathlib
import collections
from datetime import datetime


def first_layer_files(directory):
    p = pathlib.Path(directory)
    files = []
    for file in p.iterdir():
        if file.is_file():
            files.append(str(file).split("/")[-1])
    return files


Path = collections.namedtuple("Entry", ("suffix", "group", "name"))
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

paths = []
original_paths = collections.defaultdict(str)
for path in pathlib.Path(__file__).parents[1].glob("code/**/**/*"):
    if (path.suffix
            and not any(elem in list(path.parts) for elem in avoid_dirs)
            and path.suffix.lower() not in avoid_extensions):
        original_paths[path.parts[-2]] = "/".join(path.parts[:-2])
        paths.append(
            Path(
                suffix=path.suffix.lstrip(".").lower(),
                group=path.parts[1].replace("-", " ").replace("_", " "),
                name=path.parts[-2].replace("-", " ").replace("_", " "),
            ))

metadata = dict()
for each in paths:
    x = each[-1].replace(" ", "_").rstrip()
    metadata["location"] = original_paths[x] + "/" + x
    metadata_path = "scripts/metadata/{}".format(metadata["location"])
    pathlib.Path(metadata_path).mkdir(parents=True, exist_ok=True)
    filename = pathlib.Path("{}/data.json".format(metadata_path))
    # if file doesn't exist set the link values
    if not filename.exists():
        metadata["opengenus_discuss"] = ""
        metadata["opengenus_iq"] = ""
    else:
        # retain previous values
        with open(filename) as fh:
            existing_data = json.load(fh)
        metadata["opengenus_discuss"] = existing_data["opengenus_discuss"]
        metadata["opengenus_iq"] = existing_data["opengenus_iq"]
    filename.touch(exist_ok=True)
    metadata["files"] = first_layer_files(metadata["location"])
    metadata["updated"] = datetime.today().strftime("%d-%m-%Y %H:%M:%S")
    json_dump = json.dumps(metadata, indent=2)
    filename.write_text(json_dump)
