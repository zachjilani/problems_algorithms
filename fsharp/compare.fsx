(*
Please write a function which can compare whether 2 input lists are equal
to each other using F# tail recursion. You need to include both the function
definition, a few test cases, and use AssertEquality to test if your
function can process the test cases correctly. Though F# allows direct list comparison
with =, you need to use tail recursion to go over the list items
one by one by yourself to practice the technique.

Here are a few testing cases that you can use:
[] and [] are equal to each other and return true
[1;2] and [1;2;3] are not equal
[2;1;3] and [2;1;4] are not equal
[2;1;3;4] and [2;1;3;4] are equal
[3;4] and [3] are not equal
*)

let AssertEquality inputTuple =
  match inputTuple with
  | (a,b) when a=b -> printfn "Test Success!"
  | _ -> printf "Fail"


let rec compare_lists lista listb =
  match lista, listb with
  | [], [] -> true
  | x::xs, y::ys -> x = y && compare_lists xs ys
  | _ -> false

let lis1 = [2;1;3]
let lis2 = [2;1;4]


compare_lists lis1 lis2

AssertEquality (lis1, [2;1;4])