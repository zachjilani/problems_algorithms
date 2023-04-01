

let create_job_list jobCount =
  let rand = System.Random()
  [for i in 1..jobCount do yield rand.Next() % 10]
let resultList = create_job_list 5
let printJobs = lazy(
  for x in resultList do
    printfn "%d" x
  )

printfn "The Jobs are"
printJobs.Force()
type Queue (list:List<int>) =
  new(jobSize:int) = Queue(create_job_list jobSize)
  member val Q = list with get, set
  member this.Enqueue (num:int) =
   printfn "Added task No. %d to the job queue" num
   this.Q <- this.Q@[num]
  member this.Dequeue =
   if this.Q.Length = 0 then printfn "No more jobs to do right now."
   else
   let head = this.Q.Head
   this.Q <- this.Q.Tail
   printfn "Completed task No. %d" head

let p = Queue(0)
let rec JobSim lis =
  match lis with
  |[] -> printfn "JobSim Completed"
  |head::tail when head%2=0 ->
    p.Dequeue
    JobSim tail
  |head::tail ->
    p.Enqueue head
    JobSim tail

JobSim resultList


