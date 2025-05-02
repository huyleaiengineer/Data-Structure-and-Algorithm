public class GenerateAllSubArr
{
    void show1DArr(int a[])
    {
        for (int i : a)
            System.out.print(i + " ");
        System.out.println();
    }
    
    void generate(int a[])
    {
        int n = a.length;
        int dem = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                for (int k = i; k <= j; ++k){
                    System.out.printf("%d ", a[k]);
                    dem++;
                }
                System.out.println();
            }
                
        }
        System.out.printf("Number of sub arrs = %d\n",dem);
    }
    
    public void main()
    {
        int a[] = {1, 2, 3, 4, 5, 6};
        generate(a);
        /// So luong subarr = n*(n+1)/2
        /// n = 6 --> 21 subarrs
        
    }
}

/*
1 
1 2 
1 2 3
1 2 3 4
1 2 3 4 5 6
2 
2 3 
....
6

*/