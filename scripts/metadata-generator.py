import json
import pathlib
import collections

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
original_paths = collections.defaultdict(str)
for path in pathlib.Path(__file__).parents[1].glob("code/**/**/*"):
    if (
        path.suffix
        and not any(elem in list(path.parts) for elem in avoid_dirs)
        and path.suffix.lower() not in avoid_extensions
    ):
        original_paths[path.parts[-2]] = "/".join(path.parts[:-2])
        paths.append(
            Path(
                suffix=path.suffix.lstrip(".").lower(),
                group=path.parts[1].replace("-", " ").replace("_", " "),
                name=path.parts[-2].replace("-", " ").replace("_", " "),
            )
        )

metadata = collections.defaultdict(str)
for each in paths:
    x = each[-1].replace(" ", "_").rstrip()
    metadata_path = "metadata/{}".format(x)
    pathlib.Path(metadata_path).mkdir(parents=True, exist_ok=True)
    filename = pathlib.Path("{}/data.json".format(metadata_path))
    filename.touch(exist_ok=True)
    metadata["location"] = original_paths[x] + "/" + x
    json_dump = json.dumps(metadata, indent=2)
    filename.write_text(json_dump)
