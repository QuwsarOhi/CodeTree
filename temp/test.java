// LightOJ
// 1127 - Funny Knapsack

import java.util.*;

public class test {
	static long w;
    static int n;
	static Vector<Long> first = new Vector<Long>();
	static Vector<Long> second = new Vector<Long>();
    static Vector<Long> v = new Vector<Long>();
    
    static void recur(int pos, int sz, long sum, boolean t) {
        if(sum > w) return;
        
        if(pos > sz) {
            if(t) first.add(sum);
            else second.add(sum);
            return;
        }
        recur(pos+1, sz, sum+v.get(pos), t);
        recur(pos+1, sz, sum, t);
	}
    
    static int lowerBound(long val) {
        int l = 0, r = second.size()-1, ret = -1;
        
        while(l <= r) {
            int mid = (l+r)/2;
            if(second.get(mid) <= val) {
                ret = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return ret;
    }
    
    public static void main(String[] args) {
		int t;
        
		Scanner input = new Scanner(System.in);
		t = input.nextInt();
		
		for(int Case = 1; Case <= t; ++Case) {
			n = input.nextInt();
			w = input.nextLong();
			
			for(int i = 0; i < n; ++i)
				v.add(input.nextLong());
            
            recur(0, n/2 - 1, 0, true);;
            if(n/2 <= n-1)
                recur(n/2, n-1, 0, false);
            
            Collections.sort(first);
            Collections.sort(second);
            
            int ans = 0;
            for(int i = 0; i < first.size(); ++i) {
                int pos = lowerBound(w - first.get(i));
                ans += pos + 1;
            }

            System.out.printf("Case %d: %d\n", Case, ans);
            
            v.clear();
            first.clear();
            second.clear();
		}
    }
}
