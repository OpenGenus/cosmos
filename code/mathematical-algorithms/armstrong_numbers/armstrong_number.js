function armstrong_number(value)
{

  var sum = 0;
  var duplicate_value = value;

  while (duplicate_value != 0)
  {
    sum += Math.pow(duplicate_value % 10, 3);
    duplicate_value = Math.floor(duplicate_value / 10);
  }

  if (sum == value)
  {
    return true;
  }
  else {
    return false;
  }
}
