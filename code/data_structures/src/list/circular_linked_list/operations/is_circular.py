# uses try block so dont have to check if reached the end, provides faster runtime. credit-leetcode
def is_circular(self, head):
    """
	function checks if a link list has a cycle or not
	"""
    try:
        slow = head
        fast = head.next

        while slow is not fast:
            slow = slow.next
            fast = fast.next.next
        return True
    except:
        return False
