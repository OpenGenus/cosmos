class Bubble_sort{
  public static int[] bubble_sort(int[] list){
	  int length= list.length;
	  for(int i=length-1;i>=0;i--){
	    for(int j=length-i;j>0;j--){
		    if(j>=length){
		      break;
		    }
        if(list[j]<list[j-1]){
		      int tmp=list[j];
		      list[j]=list[j-1];
		      list[j-1]=tmp;
		    }
      }
	  }
	  return list;
  }
  
  public static void main(String args[]){
	  int[] list={3456,456,678,4,0,0,0,345,57,65,45,3456,4,784,7,4,453,345,45,565,67,55,34346,1};
	  list=bubble_sort(list);
	  for(int i=0;i<list.length;i++){
	    System.out.println(list[i]);
	  }
	return;
}
