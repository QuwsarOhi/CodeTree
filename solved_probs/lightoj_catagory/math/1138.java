import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//import java.util.Scanner;
//import java.math.*;                                 // Remove unwanted libraries if memory is strict!

public class Main {
    
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() throws IOException {
            while (st == null || !st.hasMoreElements())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }
        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
        String nextLine() throws IOException {
            String str = "";
            str = br.readLine();
            return str;
    }}
 
    
    static long FactorialCount(long n, int p) {      // Returns how many value of p is present in n!
        long ret = 0, r = p;                        // returns number of trailing zero of n! if p = 5
        while(n/r != 0) {
            ret += n/r;
            r *= p;
        }
        return ret;
    }
    
    static long LowerBound(int key) {
        long lo = 0, hi = (long)1e9, ret = -1;
        boolean found = false;
        
        while(lo <= hi) {
            long mid = (lo+hi)>>1;
            long tmp = FactorialCount(mid, 5);
            
            if(tmp >= key) {
                ret = mid;
                if(tmp == key)
                    found = true;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return found == true ? ret:-1;
    }
            
        
    public static void main(String[] args) throws IOException {             // exception is for fileIO
        //PrintWriter pw = new PrintWriter(new File("out"));
        //pw.printf("Writing in file");                                     // File Output Method
        //Scanner input = new Scanner(new File("in"));                      // File Input Method (Use System.in of STDIN input)

        
        //Scanner input = new Scanner(System.in);
        FastReader fr = new FastReader();
        
        int t = fr.nextInt();
        
        for(int Case = 1; Case <= t; ++Case) {
            int q = fr.nextInt();
            long ret = LowerBound(q);
            
            if(ret == -1)
                System.out.printf("Case %d: impossible\n", Case);
            else
                System.out.printf("Case %d: %d\n", Case, ret);
        }
        
        //pw.close();
    }
}
