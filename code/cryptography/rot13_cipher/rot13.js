function rot13(text){
  return text.replace(/[a-z]/gi, function(char){
    return String.fromCharCode((char<="Z"?90:122)>=(char=char.charCodeAt(0)+13)?char:char-26);
  });
} 
