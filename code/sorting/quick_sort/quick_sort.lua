function quicksort(t, start, endi)
	start, endi = start or 1, endi or #t
	--partition w.r.t. first element
	if(endi - start < 1) then return t end
	local pivot = start
	for i = start + 1, endi do
		if t[i] <= t[pivot] then
			if i == pivot + 1 then
				t[pivot], t[pivot + 1] = t[pivot + 1], t[pivot]
			else
				t[pivot], t[pivot + 1], t[i] = t[i], t[pivot], t[pivot + 1]
			end
			pivot = pivot + 1
		end
	end
	t = quicksort(t, start, pivot - 1)
	return quicksort(t, pivot + 1, endi)
end
