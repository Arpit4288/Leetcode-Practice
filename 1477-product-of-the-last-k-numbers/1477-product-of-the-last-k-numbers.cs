public class ProductOfNumbers {

    List<int> p;
    public ProductOfNumbers() {
        p = new List<int>();
    }
    
    public void Add(int num) {
        p.Add(num);
    }
    
    public int GetProduct(int k) {
        int ans = 1;
        int i = p.Count() - 1;
        while(k > 0){
            ans *= p[i];
            i--;
            k--;
        }
        return ans;
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.Add(num);
 * int param_2 = obj.GetProduct(k);
 */