//  divide conquer | quick sort | Java
//  Part of Cosmos by OpenGenus Foundation

public class QuickSort {
	private int []v;
	private int n;

	public String toString() {
		String result = "";

		for(int i = 0; i < n; i++) {
			result += v[i] + " ";
		}

		return result;
	}

	public void quickSort(QuickSort v, int left, int right) {
		int i = left, j = right;
		int aux;
		int pivot = (left + right) / 2;

		while(i <= j) {
			while(v.v[i] < v.v[pivot]) {
				i++;
			}
			while(v.v[j] > v.v[pivot]) {
				j--;
			}
			if(i <= j) {
				aux = v.v[i];
				v.v[i] = v.v[j];
				v.v[j] = aux;
				i++;
				j--;
			}
		}

		if(left < j) {
			quickSort(v, left, j);
		}
		if(i < right) {
			quickSort(v, i, right);
		}

	}

	public static void main(String []args) {
		QuickSort obj = new QuickSort();
		obj.n = 10;
		obj.v = new int[10];

		for(int i = 0; i < 10; i++) {
			obj.v[i] = 10 - i;
		}

		System.out.println(obj);
		obj.quickSort(obj, 0, obj.n - 1);
		System.out.println(obj);
	}

}
