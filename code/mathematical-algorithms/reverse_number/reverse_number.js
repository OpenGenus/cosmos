function reverse_number(value) {
    var str = "" + value;
    var res = "";
    for (var i = str.length - 1; i >= 0; i--) {
      res += str[i];
    }
   
    return parseInt(res);
  }

  console.log(reverse_number(123456789));
