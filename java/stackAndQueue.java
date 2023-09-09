package Java;

public class stackAndQueue{
    public static void main(String[] args) {
        System.out.println("hello");
    }

    public class Stack<T>{
        private Object[] data;
        private int size;
        private int capacity;

        public Stack(int capacity){
            this.capacity = capacity;
            this.data = new Object[capacity];
            this.size = 0;
        }

        public boolean isEmpty(){
            return size == 0;
        }

        public boolean isFull(){
            return size == capacity;
        }

        public int size(){
            return size;
        }

        public void push(T item){
            if(isFull()){
                System.out.println("Stack is full");
                return;
            }
            data[size++] = item;
        }
        @SuppressWarnings("unchecked")
        public T pop(){
            if(isEmpty()){
                System.out.println("Stack is empty");
                return null;
            }
            T item = (T) data[--size];
            data[size] = null;
            return item;
        }

        @SuppressWarnings("unchecked")
        public T peek(){
            if(isEmpty()){
                System.out.println("Stack is empty");
                return null;
            }
            return (T) data[size - 1];
        }
    }

    public class Queue<T>{
        private Object[] data;
        private int size;
        private int capacity;
        private int front;
        private int rear;

        public Queue(int capacity){
            this.capacity = capacity;
            this.size = 0;
            this.data = new Object[capacity];
            this.front = 0;
            this.rear = -1;
        }

        public boolean isEmpty(){
            return size == 0;
        }

        public boolean isFull(){
            return size == capacity;
        }

        public int size(){
            return size;
        }

        public void enqueue(T item){
            if(isFull()){
                System.out.println("Queue is full");
                return;
            }
            rear = (rear + 1) % capacity;
            data[rear] = item;
            size++;
        }
         @SuppressWarnings("unchecked")
        public T dequeue(){
            if(isEmpty()){
                System.out.println("Queue is empty");
                return null;
            }
            T item = (T) data[front];
            data[front] = null;
            front = (front + 1) % capacity;
            size--;
            return item;
        }
        @SuppressWarnings("unchecked")
        public T peek(){
            if(isEmpty()){
                System.out.println("Queue is empty");
                return null;
            }
            return (T) data[front];
        }
    }
}
