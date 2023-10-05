using System.Collections.Generic;

public class MyStack
{

    private Queue<int> queue;

    public MyStack()
    {
        queue = new Queue<int>();
    }

    public void Push(int x)
    {
        queue.Enqueue(x);
        int size = queue.Count;
        while (size > 1)
        {
            queue.Enqueue(queue.Dequeue());
            size--;
        }
    }

    public int Pop()
    {
        return queue.Dequeue();
    }

    public int Top()
    {
        return queue.Peek();
    }

    public bool Empty()
    {
        return queue.Count == 0;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.Push(x);
 * int param_2 = obj.Pop();
 * int param_3 = obj.Top();
 * bool param_4 = obj.Empty();
 */