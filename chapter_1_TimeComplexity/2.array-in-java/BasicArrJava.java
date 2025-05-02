import java.util.Arrays;

public class BasicArrJava{
    
    void duplicateMatrix(int [][] a, int [][]b, int [][]c)
    {
        for (int i = 0; i < a.length; ++i)
        {
            for (int j = 0; j < a[i].length; j++)
            {
                c[i][j] = 0;
                for (int k = 0; k < a.length; ++k)
                    c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    
    void show2DArr(int a[][])
    {
        int n = a.length;
        int m = a[0].length;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                System.out.print(a[i][j] + " ");
            System.out.println();
        }
    }
    
    void show1DArr(int a[])
    {
        for (int i : a)
            System.out.print(i + " ");
        System.out.println();
    }
    
    public void basicArrOperation()
    {
        /// How to create an array
        int []a = {1, 2, 3, 9, -2, 8};
        int n = a.length;
        System.out.println("Length of array a = "+n);
        
        int [][]b = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 8}
                    };
        int [][]c = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 8}
                    };
        int [][]d = new int[b.length][b.length];
        
        duplicateMatrix(b, c, d);
        show2DArr(d);
        
        System.out.print("arr before sorting: ");
        show1DArr(a);
        
        System.out.print("arr after sorting: ");
        Arrays.sort(a);
        show1DArr(a);
        
    }
}