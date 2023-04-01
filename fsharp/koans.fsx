//Advanced Koans

//The original Koans only gives out very few examples per concept.
//I designed some Lab questions similar to Koans for you to practice more. Question banks avaliable on Internet are too hard for beginnners.
//I cannot use any book related question banks as well, otherwise I have to set this book as a required textbook and you would need to buy it.
//The extra questions do not cover all the original Koan concepts. I picked out those that are the most commonly used and helpful for future bigger F# coding examples.
//Please let me know if you see errors in this file so I can update it.
//Referenced sources:
//Koans, Ninety-Nine F# problems, Project Eular, F# for Fun and Profit

//#########################
//Goal: fill in blanks to get every question run. Counts as a HW.
//All questions should work together. You do not need to comment out the parts you are done any more. If not, update variable names.
//When grading, we would see:
//Q0...Test Success
//Q1...Test Success and so on
//Submit a screenshot of your compiler black window and submit the source code.
//One question at a time. Comment out the questions you are done with.
//Based on Koans website, you now know the basics about function, tuple, and list in F#.
//#########################

let AssertEquality a b = if a<>b then printfn "Fail!" else printfn "Test Success!"

//Completed example:
let expected_value = 1 + 1
let actual_value = 2
printf "Q0..."
AssertEquality expected_value actual_value


//Q1
let expected_value1 = 5 + 6
let actual_value1 = 11
printf "Q1 ..."
AssertEquality expected_value1 actual_value1

//Q2
let myvar=40
let newvar = 80
printf "Q2 ..."
AssertEquality newvar 80

//Q3: nested function calls
let add a b =
  a + b

let res1 = add 3 6
let res2 = add 4 3
printf "Q3-1 ..."
AssertEquality res1 9
printf "Q3-2 ..."
AssertEquality res2 7

let addTwice x y =
  add (add x y) (add x y)

let restotal= addTwice 2 3
printf "Q3-3 ..."
AssertEquality restotal 10

//Q4
let mystr="Koans are puzzles."
let newstr="Koans are puzzles."
printf "Q4 ..."
AssertEquality mystr newstr

//Q5: nested function calls
let mystr5="Koans are puzzles."
let replaceEtoY (text:string) =
  text.Replace ('e', 'Y')
let newstr5= replaceEtoY mystr5
printf "Q5-1 ..."
AssertEquality newstr5 "Koans arY puzzlYs."

let replaceAEtoY(text:string)=
  replaceEtoY(text.Replace('a', 'Y'))
let finalstr=replaceAEtoY mystr
printf "Q5-2 ..."
AssertEquality finalstr "KoYns YrY puzzlYs."

//Q6: nested function definitions
//Compare this to Q3
let addTwice2 x y =
  //create a nested helper function
  let add2 a b =
    a+b

  //use the helper function
  add2 (add2 x y) (add2 x y)

let res=addTwice2 3 4
printf "Q6 ..."
AssertEquality res 14
//Why would this work?
//Try it out: If you do "let add2 a b = x +y" in Q8 instead, will it work? Why?
//Try it out: If you do "add2 (add2 a b) (add2 a b)" in Q8 instead, will it work? Why?

//Q7: Compare to Q5
let mystr7="Q7 Koans are puzzles."
let replaceAEtoY7 (text:string) =
  //create helper func
  let replaceEtoY7 (text:string) =
    text.Replace ("e", "Y")
  //use helper func
  replaceEtoY7 (text.Replace ("a","Y"))

let res7=replaceAEtoY7 mystr7
printf "Q7 ..."
AssertEquality res7 "Q7 KoYns YrY puzzlYs."
//Try it out: can you use "replaceAEtoY text" instead of "replaceAEtoY (text:string)"?
//Why? F# is a strongly typed language. Its complier needs your help some times to tell the variable type to do its job.


//Q8 multi input func can be changed to solo input func
let add2var x y=
  x + y

let addOneByOne x=
  //define the helper func
  let addHelper y =
    x+y
  //call the helper func to provide return value
  addHelper

let res91 = add2var 5 6
let intermediateFn =addOneByOne 5
//return a function with 5 baked in
//translate to math: intermediateFn (h) = 5 + h
let res92=intermediateFn  6 // translate to math: res2=intermediateFn(6)=5+6
printf "Q8 ..."
AssertEquality res91 res92


//Q9: two ways of writing a func with 2 variable inputs
let func1 x1 n = //method 1
  x1+n
let func2 n = //method 2
  fun x -> x+n

let Q9res1=func1 2 3
let Q9res2=func2 2 3
printf "Q9 ..."
AssertEquality Q9res1 Q9res2
//method 1 is clearer for user to directly call it
//method 2 is clearer to be used as a nested helper function if you want to reuse it with pipe
//See below Q11 and Q12

//Q10: pipe
let addTwoNumbers x y  =

    //create a nested helper function
    let add n =
       fun x -> x + n

    // use the helper function
    x |> add y //meaning: send x through a pipe and perform add y

let Q10Sum2= addTwoNumbers 6 7
printf "Q10 ..."
AssertEquality Q10Sum2 13

//Q11
let addThreeNumbers x y z =

    //create a nested helper function
    let add11 n =
       fun x -> x + n

    // use the helper function
    x |> add11 y |> add11 z //meaning: send x through a pipe; perform add y; send the result through a pipe; perform add z.

let Q11Sum3=addThreeNumbers 5 6 7
printf "Q11 ..."
AssertEquality Q11Sum3 18

//Q12
//you can define the helper func outside:
let add12 y=
  fun x -> x + y

let addThreeNumShort x y z =
  x |> add12 y |> add12 z
let Sum3Short = addThreeNumShort 5 6 7
printf "Q12 ..."
AssertEquality Q11Sum3 Sum3Short

//Q13
//you can also write it in Q3 style
let addQ13 a b =
  a+b

let addThreeNumQ13 x y z =
  addQ13 (addQ13 x y) z
let Sum3Q13 = addThreeNumQ13 5 6 7
printf "Q13 ..."
AssertEquality Sum3Q13 Sum3Short


//Do not write very deeply nested functions. It is super hard to understand
//BAD example: this one does not even run since f3 and f5 are never called !!
//let f x =
//    let f2 y =
//        let f3 z =
//            x * z
//        let f4 z =
//            let f5 z =
//                y * z
//            let f6 () =
//                y * x
//            f6()
//        f4 y
//    x * f2 x

//### Challenge question (not required):
//can you fix the above function and make it run with input you give it?
//can you convert the fixed function to a more elegant style like Q13?


//Q14 match is a more elegant way to write if-else in functional programming
let testEqual a b =
  if a<>b
  then printfn "Fail"
  else printfn "TestSuccess!"

//change it by using match
let testEqualNew inputTuple =
  match inputTuple with
  | (a,b) when a=b -> printfn "TestSuccess!"
  | _ -> printf "Fail"
printf "Q14-1 ..."
testEqual 10 10
//printf "Q14-2 ..."
//testEqualNew 10 10
printf "Q14-3 ..."
testEqualNew (10,10)
//Now you know what match does, we will use the second way to write AssertEquality in future labs

//Q15
// can you write a function that tests whether 3 elements are equal without using if-else?
let testEqual3 inputTuple  =
    match inputTuple with
    | (a,b,c) when a=b && b=c -> printf "TestSuccess!"
    | _ -> printf "Fail";
printf "Q15 ..."
testEqual3 (2,2,2)

//Q16 List.tail
let lis=[1;2;3;4;5]
let myLast1 lis=
  lis|> List.tail

let tail1=myLast1 lis
printf "Q16 ..."
AssertEquality tail1 [2;3;4;5]

//Q17 Find the last element of a list
let myLast3 lis=
  lis|> List.rev |> List.head

let tail3=myLast3 lis
printf "Q17 ..."
AssertEquality tail3 5



