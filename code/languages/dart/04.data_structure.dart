void main() {
  // Create a list named nameList
  List nameList = ['ikram', 'jahidul', 'habib', 'zahid', 'sharmin'];

  // Add an item to the list
  nameList.add('forhad');

  // Remove an item from the list
  nameList.removeAt(0);

  // To get the lenght of the list
  // we use list.length
  print(nameList.length);

  // Creating a loop to print all the items
  for (int i = 0; i < nameList.length; i = i + 1) {
    print(nameList[i]);
  }

  // Map stores a key, value pair
  Map studentMap = {
    'name': 'Ikram', 
    'age': 23,
  };
  
  Map studentMap2 = {
    'name': 'Forhad',
    'age': 25,
  };
  
  // Add the map to a list
  List studentList = [studentMap,studentMap2];
  print(studentList);
  
}
