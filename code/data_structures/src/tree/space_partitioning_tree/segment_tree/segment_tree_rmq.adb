with Ada.Integer_Text_IO, Ada.Text_IO;
use Ada.Integer_Text_IO, Ada.Text_IO;
-- Compile:
-- gnatmake segment_Tree_rmq


procedure segment_Tree_rmq is

INT_MAX: constant integer := 999999;
MAXN : constant integer := 100005;
v : array(0..MAXN) of integer;
tree: array(0..4*MAXN) of integer;
n : integer;
q : integer;
a : integer;
b : integer;
c : integer;

function min(a: integer; b: integer) return integer is

begin
	
	if a < b then return a;
	else return b;
	end if;
end min;

procedure build(node: integer; l: integer; r: integer) is

	mid: integer;

begin

	mid := (l + r)/2;
	
	if l = r then
		tree(node) := v(l);
		return;
	end if;

	build(2 * node, l, mid);
	build(2*node+1,mid+1,r);
	tree(node) := min( tree(2*node), tree(2*node + 1)); 
end build;


--Update procedure
procedure update(node: integer; l: integer; r: integer; pos: integer; val: integer) is

	mid: integer := (l + r)/2;

begin
	
	if l > pos or r < pos or l > r then
		return;
	end if;

	if(l = r) then
		tree(node) := val;
		return;
	end if;

	if pos <= mid then
		update(2*node,l,mid,pos,val);
	else
		update(2*node+1,mid+1,r,pos,val);
	end if;
	tree(node) := min( tree(2*node), tree(2*node + 1)); 
end update;


--Query function
function query(node : integer; l: integer; r: integer; x: integer; y: integer) return integer is
	
	mid: integer := (l + r)/2;
	p1: integer; 
	p2: integer; 
begin

	if l > r or l > y or r < x then
		return INT_MAX;
	end if;
	if x <= l and r <= y then
		return tree(node);
	end if;

	p1 := query(2*node,l,mid,x,y);
	p2 := query(2*node+1,mid+1,r,x,y);

	if p1 = INT_MAX then 
		return p2;
	end if;

	if p2 = INT_MAX then
		return p1;
	end if;

	return min(p1, p2);

end query;


begin
	Put_Line("Input the array range");
	Get(n);
	Put_Line("Input the values");
	for i in 1..n loop
		Get(v(i));
	end loop;


	build(1,0,n-1);

	Put_Line("Input the number of operations");

	Get(q);
	
	while q > 0 loop
		Put_Line("Input 0 to query and 1 to update");
		Get(a);
		Put_Line("Input the STARTING index of the query range");
		Get(b);
		Put_Line("Input the ENDING index of the query range");
		Get(c);

		if a = 0 then 
			Put_Line("Minimum value of the given range");
			Put(query(1,1,n,b,c));
			Put_Line("");
		elsif a = 1 then
			update(1,1,n,b,c);
		else
			Put_Line("Invalid Operation");
			q := q + 1;
		end if;
		q := q - 1;

	end loop;
end segment_Tree_rmq;



