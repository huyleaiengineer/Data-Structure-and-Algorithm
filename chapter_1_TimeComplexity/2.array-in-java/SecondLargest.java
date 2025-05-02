public class SecondLargest{
    
    int secondLarget(int a[])
    {
        int n = a.length;
        int largest = Integer.MIN_VALUE;
        int second = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] > largest)
            {
                second = largest;
                largest = a[i];
            }
            else if (a[i] < largest && a[i] > second)
                second = a[i];
        }
        return second;
    }
    
    public void main()
    {
        int a[] = {1, 2, 3, 4, -2, 3, 5, 8};
        System.out.println(secondLarget(a));
        int b[] = {1, 1};
        System.out.println(secondLarget(b));
        
        /// find 2nd largest 
        
        
    }
}