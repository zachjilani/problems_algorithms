// F# Lab 4 -- Tail Recursion practice
// Functional programming languages use Tail Recursion to replace the loops in C++/Python.
// In the previous labs/HWs, you already practiced match … with. Here you will do a few more practices on Tail Recursion so that you can code “loop”.
// The group project needs you to go over a list and do calculations, so you will need to use Tail Recursion. Please complete the tail recursion questions in this part first and then start doing the project.
// Submission
// Submit 1 .txt file+1 screenshot of the output results, solo submission
// Grading
// Count as 5pt HW. 9 questions total, each 0.5pt. Submission of some code that does not run is 0.5pt. You need to submit working code and comment out the parts that have bugs. You can print out messages saying: “I completed Q6, but cannot fix a bug on …” for partial credits.
// Questions
// With the loop syntax and idea firmly ingrained, it is hard to use tail recursion to do a loop. Please just imitate the style of the example by:
// --with the input list, get the head of the list out
// --have a result accumulator
// --if the head=…, call the function itself by passing tail + resultAccumulator as inputs
// --if the head=…, call the function itself by passing tail + resultAccumulator as inputs
// --Depends on the difference of the head element, you can either add a number into the resultAccumulator or not.
// With the technical googling practice we did, you might already found out that imitate coding example from online resources to get the code to work is another soft skill that programmers need to practice.

//Q0 AssertEquality using match…with
let AssertEquality inputTuple =
  match inputTuple with
  | (a,b) when a=b -> printfn "Equal"
  | _ -> printf "Not Equal"

//NOTE: all the below questions require Tail Recursion + Match with

//Q1 remember the example from PPT: grab the even numbers out from a list
let rec getEven mylis accumulator=
  match mylis with
  | [] -> accumulator
  | head::tail when head%2=0 -> getEven tail (head::accumulator)
  |_::tail -> getEven tail accumulator

let mylis=[1..6]
let result=getEven mylis []
printf "Q1..."
AssertEquality (result, [6;4;2])
let result1=result |> List.rev
AssertEquality (result1, [2;4;6])

//make sure the recursive function call is the VERY LAST step of your calculation to avoid stack overflow
//Always use a result accumulator to remember the result of each step
//getEven tail (head::accumulator) instead of head::getEven tail

//Q2 modify Q1 so that you can put the reverse the result list in the function call directly
let rec getEven2 mylis accumulator=
  match mylis with
  | [] -> accumulator |> List.rev
  | head::tail when head%2=0 -> getEven2 tail (head::accumulator)
  |_::tail -> getEven2 tail accumulator
let result2=getEven2 mylis []
printf "Q2..."
AssertEquality (result2, [2;4;6])

//Q3 modify Q2 and create the below function which will grab the odd numbers out from a list
let rec getOdd lis accumulator =
  match lis with
  | [] -> accumulator |> List.rev
  | head::tail when head%2<>0 -> getOdd tail (head::accumulator)
  |_::tail -> getOdd tail accumulator
let result3=getOdd mylis []
printf "Q3..."
AssertEquality (result3, [1;3;5])

//Q4 Get the sum of all the even numbers in a list
let rec getEvenSum mylis sumAcc=
  match mylis with
  | [] -> sumAcc
  | head::tail when head%2=0 -> getEvenSum tail sumAcc + head
  | head::tail -> getEvenSum tail sumAcc
let result4=getEvenSum mylis 0
printf "Q4..."
AssertEquality (result4, 12)

//Q5 calculate the square of each number in the input list
let rec getSqr mylis sqrLis=
  match mylis with
  | [] -> sqrLis |> List.rev
  | head::tail -> getSqr tail ((head*head)::sqrLis)
let result5=getSqr mylis []
printf "Q5..."
AssertEquality (result5, [1;4;9;16;25;36])

//Q6 Calculate factorial of n
//n! = 1*2*3*...*(n-1)*n
let rec factorial n ftRes=
  match n with
  | 0 -> ftRes
  | 1 -> ftRes
  | _ -> factorial (n-1) (ftRes*n)

let result6=factorial 5 1
printf "Q6..."
AssertEquality (result6, 120)

//Q7 You can merge the 2 "if statements" of the pattern 0 and 1 together like below:
let rec factorial1 n ftRes=
  match n with
  | 0 | 1 -> ftRes
  | _ ->  factorial1 (n-1) (ftRes*n)

let result7=factorial1 5 1
printf "Q7..."
AssertEquality (result7, 120)

//Q8 to help user call this function easier by using "factorial 5" instead of "factorial1 5 1" 
//(so that the API user do not need to worry about giving us the accumulator as the second func input),
//we can wrap the recursive function call inside of regular function that looks nicer
let nicer_factorial n = 
  let rec factorial1 n ftRes=
    match n with 
    | 0 | 1 -> ftRes
    | _ -> factorial (n-1) (ftRes*n)
  factorial 5 1

let result8=nicer_factorial 5
printf "Q8..."
AssertEquality (result8, 120)
