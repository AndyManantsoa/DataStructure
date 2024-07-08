using System;

public class Fibonacci{

    public void Fibo(int n){
        Console.Write("Fibonnaci series : 0 1 ");
        int a=0,b=1,sum=0;

        for(int i=2;i<n;i++){
            sum=a+b;
            Console.Write(sum+" ");
            a=b;
            b=sum;
        }
        Console.WriteLine("the Nth term is :"+sum);
    }
    public static void Main(string[] args){
        Console.WriteLine("Enter the number of terms: ");
        int n = int.Parse(Console.ReadLine());
            Fibonacci f = new Fibonacci();
            f.Fibo(n);
    }
}