public class naiveStockBuyAndSale{
    int maximumProfit(int a[])
    {
        int n = a.length;
        int maxProfit = 0;
        for (int i = 1; i < n; ++i)
            if (a[i] > a[i-1])
                maxProfit += a[i]-a[i-1];
        return maxProfit;
        
    }
    public void main()
    {
        int prices[] = { 100, 180, 260, 310, 40, 535, 695 };
        System.out.println(maximumProfit(prices));
    }
}