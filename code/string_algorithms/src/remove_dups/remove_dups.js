
const remove_dups = str => [...str].filter((c, i) => c !== str[i + 1]).join("");


console.log(remove_dups("lol"));
console.log(remove_dups("aabbccdd"));
console.log(remove_dups("llllllllllloooooooooooooolllllllllll"));