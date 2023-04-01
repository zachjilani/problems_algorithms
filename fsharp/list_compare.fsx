

let rec compare_lists lista listn =
match lista, listb with
| [], [] -> true
| x::xs, y::ys -> x = y && compare_lists xs ys
| _ -> false


lis1 = [2;1;3]
lis2 = [2;1;4]

compare_lists lis1 lis2
