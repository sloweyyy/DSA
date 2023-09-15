using System;


class Program
{
    static void Main(string[] args)
    {
        // var numbers = new int[3];
        // for (int i = 0; i < numbers.Length; i++)
        // {
        //     numbers[i] = int.Parse(System.Console.ReadLine());
        // }
        //
        // for (int i = 0; i < numbers.Length; i++)
        // {
        //     System.Console.WriteLine(numbers[i]);
        // }
        var numbers = new[] { 3, 7, 9, 2, 14, 6 };
        // Length
        Console.WriteLine("Length: " + numbers.Length);

        // IndexOf()
        int numberToFind = 9;
        int index = Array.IndexOf(numbers, numberToFind);

        if (index != -1)
        {
            Console.WriteLine(numberToFind + " found at index: " + index);
        }
        else
        {
            Console.WriteLine(numberToFind + " not found in the array.");
        }

        // Clear()
        Array.Clear(numbers, 0, 2);




    }
}
