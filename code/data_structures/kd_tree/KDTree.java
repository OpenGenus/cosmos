import java.util.Comparator;
import java.util.HashSet;

public class KDTree
{
	int k;
	KDNode root;
	
	public KDTree(KDPoint[] points)
	{
		k = 2;
		root = createNode(points,0);
	}
	
	public KDNode createNode(KDPoint[] points,int level)
	{
		if(points.length == 0) return null;
		int axis = level % k;
		KDPoint median = null;
		Comparator<KDPoint> comparator = KDPoint.getComparator(axis);
		median = quickSelect(points,0,points.length-1,points.length/2+1,comparator);
		KDNode node = new KDNode(median,level);
		if(points.length>1){
			int tam = 0;
			for(int i=0;i<points.length;i++) if(comparator.compare(points[i], median)<0) tam++;
			KDPoint[] p1 = new KDPoint[tam];
			KDPoint[] p2 = new KDPoint[points.length-tam-1];
			int i1 = 0;
			int i2 = 0;
			for(int i=0;i<points.length;i++){
				if(points[i].equals(median)) continue;
				else if(comparator.compare(points[i], median)<0) p1[i1++] = points[i];
				else p2[i2++] = points[i];
			}
			KDNode l = createNode(p1, level+1);
			KDNode r = createNode(p2,level+1);
			if(l!=null) l.parent = node;
			if(r!=null) r.parent = node;
			node.left = l;
			node.right = r;
		}
		return node;
	}
	
	public int nearestNeighbor(KDPoint p,KDNode r,HashSet<KDNode> visitados)
	{		
		KDNode node = r;
		int res = Integer.MAX_VALUE;
		KDNode prev = null;
		while(node!=null){
			int axis = node.level%k;
			Comparator<KDPoint> comparator = KDPoint.getComparator(axis);
			prev = node;
			if(comparator.compare(p,node.point)<0 && node.left!=null) node = node.left;
			else if(comparator.compare(p,node.point)>0 && node.right!=null) node = node.right;
			else node = node.left!=null ? node.left:node.right;
		}
		node = prev;
		while(true){
			if(!node.point.equals(p)) res = Math.min(res, p.distance(node.point));
			int axis = node.level % k;
			KDNode r2 = null;
			if(Math.abs(p.coordinates[axis]-node.point.coordinates[axis])<res){
				r2 = prev !=null && node.left!=null && prev.equals(node.left) ? node.right:node.left; 
			}
			if(r2 != null && !visitados.contains(r2)){
				res = Math.min(res, nearestNeighbor(p, r2,visitados));
			}
			visitados.add(node);
			if(node.equals(r)) break;
			prev = node;
			node = node.parent;
		}
		return res;
	}
	
	public KDPoint quickSelect(KDPoint[] points,int left,int right,int k,Comparator<KDPoint> c)
	{
		while(true){
			int pivotIndex = left+right/2;
			int pivotNewIndex = partition(points,left,right,pivotIndex,c);
			int pivotDist = pivotNewIndex - left + 1;
			if(pivotDist == k){
				return points[pivotNewIndex];
			}else if(k<pivotDist){
				right= pivotNewIndex - 1;
			}else{
				k=k-pivotDist;
				left=pivotNewIndex + 1;
			}
		}
	}
	
	public int partition(KDPoint[] points,int left,int right,int pivotIndex,Comparator<KDPoint> c)
	{
		KDPoint pivotValue = points[pivotIndex];
		KDPoint aux = points[pivotIndex];
		points[pivotIndex] = points[right];
		points[right] = aux;
		int storeIndex = left;
		for(int i=left;i<right;i++){
			if(c.compare(points[i],pivotValue)<0){
				aux = points[storeIndex];
				points[storeIndex] = points[i];
				points[i] = aux;
				storeIndex++;
			}
		}
		aux = points[right];
		points[right] = points[storeIndex];
		points[storeIndex] = aux;
		return storeIndex;
	}	
	
	public class KDNode
	{
		KDPoint point;
		KDNode parent;
		KDNode left;
		KDNode right;
		int level;
		
		public KDNode(KDPoint p,int l)
		{
			point = p;
			level = l;
		}
		
		public boolean equals(Object o)
		{
			KDNode n = (KDNode) o;
			return point.equals(n.point);
		}
		
		public String toString()
		{
			return point.toString();
		}
	}
	
	public static class KDPoint
	{
		int[] coordinates;
		
		public KDPoint(int... coordinates)
		{
			this.coordinates = coordinates;
		}
		
		public static Comparator<KDPoint> getComparator(int axis)
		{
			final int a = axis;
			return new Comparator<KDPoint>(){
				public int compare(KDPoint n1,KDPoint n2){
					return n1.coordinates[a] - n2.coordinates[a];
				}
			};
		}
		
		public double euclideandistance(KDPoint p)
		{
			double res = 0;
			for(int i=0;i<coordinates.length;i++){
				res+= Math.pow(coordinates[i] - p.coordinates[i], 2);
			}
			return Math.sqrt(res);
		}
		
		public int distance(KDPoint p)
		{
			return Math.abs(coordinates[0]-p.coordinates[0])+Math.abs(coordinates[1]-p.coordinates[1]);
		}
		
		public boolean equals(Object o)
		{
			KDPoint n2 = (KDPoint) o;
			for(int i=0;i<coordinates.length;i++){
				if(coordinates[i]!=n2.coordinates[i]) return false;
			}
			return true;
		}
		
		public String toString()
		{
			StringBuilder res = new StringBuilder().append("(");
			for(int i=0;i<coordinates.length;i++) res.append(coordinates[i]+",");
			res.setLength(res.length()-1);
			res.append(")");
			return res.toString();
		}
	}
}