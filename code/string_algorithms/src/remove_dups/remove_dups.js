const removeDups = str => [...str].filter((c, i) => c !== str[i + 1]).join("");

console.log(removeDups("lol"));
console.log(removeDups("aabbccdd"));
console.log(removeDups("llllllllllloooooooooooooolllllllllll"));
